public class MyClass {
    public static void main(String[] args) {
        try {
            int a[] = new int[2];
            System.out.println(a[5]);
        } catch (Exception e) {
            System.out.println("An error occurred");
        }
        // Output: An error occurred
        // The exception is caught and handled by the catch block
    }
}