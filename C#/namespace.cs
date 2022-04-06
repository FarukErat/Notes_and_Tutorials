//  taken from https://www.programiz.com/csharp-programming/namespaces#:~:text=Namespaces%20are%20used%20in%20C%23,Classes

/*
Namespaces are not mandatory in a C# program,
but they do play an important role in writing cleaner codes and managing larger projects.

Let's understand the concept of namespace with a real life scenario.
We have a large number of files and folders in our computer.
Imagine how difficult it would be to manage them if they are placed in a single directory.
This is why we put related files and folders in a separate directory.
This helps us to manage our data properly.

The concept of namespace is similar in C#.
It helps us to organize different members by putting related members in the same namespace.

Namespace also solves the problem of naming conflict.
Two or more classes when put into different namespaces can have same name.
*/

using System;

// Nested Namespace
namespace MyNamespace
{
    namespace Nested
    {
        public class SampleClass
        {
            public static void myMethod()
            {
                Console.WriteLine("Nested Namespace Example");
            }
        }
    }
}

namespace MyProgram
{
    public class MyClass
    {
        public static void Main()
        {
            MyNamespace.Nested.SampleClass.myMethod();
        }
    }
}
