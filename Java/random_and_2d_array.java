// importing necessary libraries for random number generation
import java.util.Random;

public class MyClass {
    public static void main(String[] args) {
        
        // defining constant variables for row and column
        final int ROW = 3;
        final int COL = 5;

        // creating an instance of Random class
        Random rand = new Random();

        // creating a 2 dimensional array of integers
        int[][] sample = new int[ROW][COL];

        // looping through the array
        for (int i = 0; i < ROW * COL; i++) {
            // assigning random values to the array
            sample[i / COL][i % COL] = rand.nextInt(10);
        }

        // looping through the rows
        for (int i = 0; i < ROW; i++) {
            // looping through the columns
            for (int j = 0; j < COL; j++) {
                // printing the array
                System.out.print(sample[i][j] + " ");
            }
            // printing a new line
            System.out.println();
        }
        
        /* output:
         * 7 0 5 3 7
         * 9 9 7 8 9
         * 9 8 5 2 0
         */
    }
}
