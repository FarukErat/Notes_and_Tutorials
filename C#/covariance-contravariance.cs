using System;

// COVARIANCE
// Base Produce() can be replaced with Derived Produce()
// Derived Produce() cannot replaced with Base Produce()
Base Produce()
{
    return new Base("foo");
}
Derived Produce()
{
    return new Derived("foo", "bar");
}

// CONTRAVARIANCE
// void Consume(Derived x) can be replaced with void Consume(Base x)
// void Consume(Base x) cannot replaced with void Consume(Derived x)
void Consume(Base x)
{
    Console.WriteLine(x.Foo);
}
void Consume(Derived x)
{
    Console.WriteLine(x.Foo);
    Console.WriteLine(x.Bar);
}

record Base(string Foo);
record Derived(string Foo, string Bar) : Base(Foo);
