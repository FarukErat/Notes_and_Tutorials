import java.io.File;
import java.util.Scanner;
import java.util.Formatter;

public class MyClass {
    public static void main(String[] args) {
        try {
            Formatter f = new Formatter("test.txt");
            f.format("%s %s %s", "1", "John", "Smith \r\n");
            f.format("%s %s %s", "2", "Amy", "Brown");
            f.close();

            File x = new File("test.txt");
            Scanner sc = new Scanner(x);
            while (sc.hasNext()) {
                System.out.println(sc.next());
            }
            sc.close();
        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}