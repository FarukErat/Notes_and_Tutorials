public class LearnStatic {

    private static String str = "GeeksforGeeks";

    static {
        System.out.println("LearnStatic: Static block initialized.");
    }

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
    }
}
