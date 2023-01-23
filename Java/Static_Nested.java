public class LearnStatic {

    private static String str = "GeeksforGeeks";

    // this will be executed when the class is loaded into the memory
    // and before the main method is called
    static {
        System.out.println("LearnStatic: Static block initialized.");
    }

    // this will not be executed when the class is loaded into the memory
    // but can be called with instanciation of the class
    static void disp() {
        System.out.println("LearnStatic: Static method called.");
    }

    // this will be executed when the class is instanciated
    LearnStatic() {
        System.out.println("LearnStatic: Constructor called.");
    }

    static class MyNestedClass {

        MyNestedClass() {
            System.out.println("MyNestedClass: Constructor called.");
        }

        public void disp() {
            System.out.println(str);
        }
    }

    public static void main(String args[]) {
        LearnStatic.MyNestedClass obj = new LearnStatic.MyNestedClass();
        obj.disp();
        // LearnStatic: Static block initialized.
        // MyNestedClass: Constructor called.
        // GeeksforGeeks
    }
}
