// Java program to demonstrate restriction on static methods
// Static methods and variables are loaded before the instance
// thus, they will be unaware of the instance variables and methods

class Test {
    // static variable
    static int a = 10;

    // instance variable
    int b = 20;

    // static method
    static void m1() {
        a = 20;
        System.out.println("from m1");

        // Cannot make a static reference to the non-static field b
        b = 10; // compilation error

        // Cannot make a static reference to the
        // non-static method m2() from the type Test
        m2(); // compilation error

        // Cannot use super in a static context
        System.out.println(super.a); // compiler error

        // Cannot use this in a static context
        System.out.println(this.a); // compiler error
    }

    // instance method
    void m2() {
        System.out.println("from m2");
    }

    public static void main(String[] args) {
        // main method
    }
}
