using System;
using System.Collections.Generic;

// COVARIANCE
// accessing an instance of Derived through an instance of Base is safe since a Derived is also a Base
IEnumerable<Base> bases = new List<Derived>();
// accessing an instance of Base through an instance of Derived is NOT safe, since not every Base is a Derived
//IEnumerable<Derived> deriveds = new List<Base>();

// CONTRAVARIANCE
// BaseAction can handle any instance of Base, which is why it can handle instances of Derived
Action<Base> baseAction = o => Console.WriteLine(o.ToString());
Action<Derived> derivedAction = baseAction;
// derivedAction does NOT handle all subtypes of Base
// baseAction = derivedAction;

record Base;
record Derived : Base;
