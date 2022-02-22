class Vehicle {
    private String color;

    // in cpp, only one constructor is able to do all the initialization
    // with default parameters
    // in java, we should use multiple constructors to do the same thing

    // Constructor with no arguments, which is the default constructor
    Vehicle() {
        this.setColor("Red");
    }

    // Constructor with one argument
    Vehicle(String c) {
        this.setColor(c);
    }

    // Setter
    public void setColor(String c) {
        this.color = c;
    }

    // Getter
    public String getColor() {
        return color;
    }
}

class MyClass {
    public static void main(String[] args) {
        // color will be "Red"
        Vehicle v1 = new Vehicle();
        System.out.println(v1.getColor());

        // color will be "Green"
        Vehicle v2 = new Vehicle("Green");

        System.out.println(v2.getColor());
    }
}