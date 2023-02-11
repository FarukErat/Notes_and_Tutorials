class Program
{
    static void Main()
    {
        var Jhon = new Person();               // constructor called
        Jhon.Name = "Jhon";                    // set called
        Console.WriteLine(Jhon.Name = "Tom");  // set called, "Tom", (get is not called, "Tom" is passed to Console.WriteLine)
        Jhon.Age = 25;                         // set called
        Jhon.Age = Jhon.Age + 1;               // get called, set called
        Jhon.Age++;                            // get called, set called
    }
}

class Person
{
    public Person() { Console.WriteLine("constructor called"); }
    private int age = 0;
    private string name = "unknown";
    private int daysLived => age * 365;
    public string Name
    {
        get { Console.WriteLine("get called"); return name; }
        set { Console.WriteLine("set called"); name = value; }
    }
    public int Age { get { Console.WriteLine("get called"); return age; } set { Console.WriteLine("set called"); if (value <= 0) age = 0; else age = value; } }
    public int DaysLived { get { Console.WriteLine("get called"); return daysLived; } }
}
