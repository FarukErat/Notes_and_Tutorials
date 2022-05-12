class Program{
    static void Main(){
        int i = 0;              // for the while loop to work
        int count = 21;         // the number of times to print colors
        bool isRed = true;      // whether or not to print red
        while (i++ < count){    // loop till i is less than count
            Console.WriteLine(isRed ? "Red" : "Yellow");    // if isRed is true, print red, else print yellow
            if (i % 10 == 0)                                // when i is divisible by 10 
                isRed = !isRed;                             // toggle isRed
        }
    }
}
