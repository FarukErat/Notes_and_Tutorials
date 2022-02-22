abstract class Animal {
    int legs = 0;
    // since this is an abstract class, we can't instantiate it
    // but we can use it as a base class for other classes
    // that inherit from it
    // a real world example would be a class that represents animals
    // and a class that represents dogs
    // when we create a dog, we can use the Animal class as a base class
    // and then we can override the methods that we need to change
    // but when we say animal, it can be any animal
    // so its properties are not certain
    abstract void makeSound();
    // Every Animal makes a sound, but each has a different way to do it.
    // That's why we define an abstract class Animal,
    // and leave the implementation of how they make sounds to the subclasses.
    // This is used when there is no meaningful definition for the method in the superclass.
}

class Cat extends Animal {
    public void makeSound() {
        System.out.println("Meow");
    }
}

public class MyClass {
    public static void main(String[] args) {
        Cat c = new Cat();
        c.makeSound();
    }
}
