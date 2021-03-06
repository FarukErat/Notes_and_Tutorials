// example taken from https://docs.microsoft.com/en-us/dotnet/csharp/fundamentals/types/classes

using System;

public class Person
{
    // Constructor that takes no arguments:
    public Person()
    {
        Name = "unknown";
    }

    // Constructor that takes one argument:
    public Person(string name)
    {
        Name = name;
    }

    // Auto-implemented readonly property:
    public string Name { get; }

    // Method that overrides the base class (System.Object) implementation.
    public override string ToString()
    {
        return Name;
    }
}
/*public*/ class TestPerson // class name does not have to match file name
{
    // Main method is the entry point for all C# programs.
    // Being static, it can be called without creating an instance of the class.
    static void Main()
    {
        // Call the constructor that has no parameters.
        Person person1 = new Person();
        Console.WriteLine(person1.Name);

        // Call the constructor that has one parameter.
        var person2 = new Person("Sarah Jones");
        Console.WriteLine(person2.Name);
        // Get the string representation of the person2 instance.
        Console.WriteLine(person2);
    }
}
// Output:
// unknown
// Sarah Jones
// Sarah Jones
