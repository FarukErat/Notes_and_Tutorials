class Machine {
    public void start() {
        System.out.println("Starting...");
    }
}

class MyClass {
    public static void main(String[] args) {
        Machine m1 = new Machine() {
            // Overriding the start method
            // This is an anonymous inner class
            // The @Override annotation is used to make your code easier to understand
            // because it makes it more obvious when methods are overridden.
            @Override
            public void start() {
                System.out.println("Wooooo");
            }
        };
        m1.start(); // Prints "Wooooo"
        // The modification is applicable only to the current object, and not the class
        // itself
        // So if we create another object of that class
        // the start method's implementation will be the one defined in the class.
        Machine m2 = new Machine();
        m2.start(); // Prints "Starting..."
    }
}