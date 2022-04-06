import java.util.Scanner;

class MyClass {
    // public to be accessible from everywhere
    // static to be accessible without creating an object
    public static void main(String[] args) { // main method is the entry point for all java programs
        System.out.println("Enter something"); // print to console
        Scanner myVar = new Scanner(System.in); // instantiate scanner object to read from console
        System.out.println("You entered: " + myVar.nextLine());
        myVar.close(); // close scanner object
    }
}
