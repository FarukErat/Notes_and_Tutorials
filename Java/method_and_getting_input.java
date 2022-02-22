// importing necessary libraries to get input
import java.util.Scanner;

public class MyClass {
    // creating a method for the main method a function for the class
    // to calculate square of a number
    static int square(int x) {
        return x * x;
    }

    public static void main(String[] args) {
        int num;
        // instantiating a scanner object
        Scanner sc = new Scanner(System.in);
        // getting input from the user
        System.out.println("Enter a number: ");
        num = sc.nextInt();
        // calling the square method
        System.out.println("Square of the number is: " + square(num));
        // closing the scanner object
        sc.close();
    }
}
