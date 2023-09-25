namespace WorkoutProject.Models;

public class MongoDBSettingsModel
{
    public string ConnectionURI { get; set; } = null!;
    public string DatabaseName { get; set; } = null!;
    public Dictionary<string, string> Collections { get; set; } = null!;
}
