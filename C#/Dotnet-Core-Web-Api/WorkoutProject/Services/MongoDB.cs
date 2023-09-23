using WorkoutProject.Models;
using Microsoft.Extensions.Options;
using MongoDB.Driver;

namespace WorkoutProject.Services;

public class MongoDBService : IMongoDBService
{
    private readonly Dictionary<string, IMongoCollection<UserModel>> _collectionMapping;

    public MongoDBService(IOptions<MongoDBSettingsModel> mongoDBSettings)
    {
        MongoClient client = new MongoClient(mongoDBSettings.Value.ConnectionURI);
        IMongoDatabase database = client.GetDatabase(mongoDBSettings.Value.DatabaseName);

        _collectionMapping = new Dictionary<string, IMongoCollection<UserModel>>();
        foreach (var collectionEntry in mongoDBSettings.Value.Collections)
        {
            _collectionMapping[collectionEntry.Key] = database.GetCollection<UserModel>(collectionEntry.Value);
        }
    }
    public IMongoCollection<UserModel> GetCollection(string collectionName)
    {
        if (!_collectionMapping.ContainsKey(collectionName))
        {
            throw new ArgumentException($"Collection {collectionName} does not exist.");
        }
        return _collectionMapping[collectionName];
    }

    public async Task CreateAsync(UserModel user)
    {
        await _collectionMapping["Users"].InsertOneAsync(user);
        return;
    }
    
    public async Task<UserModel> FindByUsernameAsync(string userName)
    {
        var filter = Builders<UserModel>.Filter.Eq("Username", userName);
        return await _collectionMapping["Users"].Find(filter).FirstOrDefaultAsync();
    }
}