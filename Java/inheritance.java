class A {
    public A() {
        System.out.println("New A");
    }
}

class B extends A {
    public B() {
        System.out.println("New B");
    }
}

class MyClass {
    public static void main(String[] args) {
        B obj = new B();
    }
}