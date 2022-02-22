class Robot {
    int id;

    Robot(int i) {
        id = i;
        Brain b = new Brain();
        b.think(); // outputs "1 is thinking"
    }

    private class Brain {
        public void think()  {
            System.out.println(id + " is thinking");
        }
    }
}

public class MyClass {
    public static void main(String[] args) {
        Robot r = new Robot(1);
    }
}