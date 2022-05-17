class Program
{
    static void Main()
    {
        // if (fptr = fileopen(filename) == NULL)
        var Jhon = new Person();
        Console.WriteLine(Jhon.Name);
        Jhon.Name = "Jhon"; // Jhon.setName("Jhon");
        Console.WriteLine(Jhon.Name);
        Console.WriteLine(Jhon.Name = "Tom");
        Console.WriteLine(Jhon.Age);
        Jhon.Age = 25;
        Console.WriteLine(Jhon.Age);
        Console.WriteLine(Jhon.DaysLived);
        Jhon.Age++;
        Console.WriteLine(Jhon.DaysLived);
    }
}

class Person
{
    private int age = 0;
    private string name = "Unknown";
    private int daysLived => age * 365;
    public string Name
    {
        get { Console.WriteLine("get called"); return name; }
        set { Console.WriteLine("set called"); name = value; }
    }
    public int Age { get { return age; } set { if (value <= 0) age = 0; else age = value; } }
    public int DaysLived { get { return daysLived; } } // readonly
}
