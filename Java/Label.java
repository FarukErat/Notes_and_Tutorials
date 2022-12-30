public class Label {
    public static void main(String[] args) {
        int i = 0;
        outerLoop: while (true) {
            i++;
            System.out.println("Outer loop iteration " + i);
            innerLoop: for (int j = 0; j < 5; j++) {
                if (j > 3) {
                    break innerLoop;
                }
                System.out.println("-Inner loop iteration " + j);
            }
            if (i > 3) {
                break outerLoop;
            }
        }
        // output:
        /*
         * Outer loop iteration 1
         * -Inner loop iteration 0
         * -Inner loop iteration 1
         * -Inner loop iteration 2
         * -Inner loop iteration 3
         * Outer loop iteration 2
         * -Inner loop iteration 0
         * -Inner loop iteration 1
         * -Inner loop iteration 2
         * -Inner loop iteration 3
         * Outer loop iteration 3
         * -Inner loop iteration 0
         * -Inner loop iteration 1
         * -Inner loop iteration 2
         * -Inner loop iteration 3
         * Outer loop iteration 4
         * -Inner loop iteration 0
         * -Inner loop iteration 1
         * -Inner loop iteration 2
         * -Inner loop iteration 3
         */
    }
}
