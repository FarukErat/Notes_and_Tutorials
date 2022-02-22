interface Animal {
    // interface class means that it has only abstract methods
    // a class having all abstract methods and variables is called an interface
    // Some specifications for interfaces:
    // - Defined using the interface keyword.
    // - May contain only static final variables.
    // - Cannot contain a constructor because interfaces cannot be instantiated.
    // - Interfaces can extend other interfaces.
    // - A class can implement any number of interfaces.
    public void eat();

    public void makeSound();
}

class Cat implements Animal {
    public void makeSound() {
        System.out.println("Meow");
    }

    public void eat() {
        System.out.println("omnomnom");
    }
}

public class MyClass {
    public static void main(String[] args) {
        Cat c = new Cat();
        c.eat();
    }
}