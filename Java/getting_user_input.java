import java.util.Scanner;

class MyClass {
    public static void main(String[] args) {
        System.out.println("Enter something");
        Scanner myVar = new Scanner(System.in);
        System.out.println(myVar.nextLine());
        myVar.close();
    }
}
