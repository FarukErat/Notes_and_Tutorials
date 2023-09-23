using MongoDB.Driver;
using WorkoutProject.Models;

namespace WorkoutProject.Services;

public interface IMongoDBService
{
    public IMongoCollection<UserModel> GetCollection(string collectionName);
    public Task CreateAsync(UserModel user);
    public Task<UserModel> FindByUsernameAsync(string userName);
}