class Program
{
    static bool isNumeric(string? input)
    {
        if (input == null)
        {
            return false;
        }
        foreach (char c in input)
        {
            if (c < '0' || c > '9')
            {
                return false;
            }
        }
        return true;
    }
    static void formatDigits(ref string digits)
    {
        // get rid of leading zeros
        while (digits[0] == '0' && digits.Length > 1)
        {
            digits = digits.Substring(1);
        }
        // reverse the digits for easier processing
        digits = new string(digits!.ToCharArray().Reverse().ToArray());
    }
    static void printNumber(string digits)
    {
        // check if the number is zero
        if (digits.Length == 1 && digits[0] == '0')
        {
            Console.WriteLine("sifir");
            return;
        }

        // main loop
        for (int j = digits.Length - 1; j >= 0; j--)
        {
            switch (j % 3)
            {
                // ones
                case 0:
                    switch (digits[j])
                    {
                        case '1': if (j != 3) Console.Write("bir "); break;
                        case '2': Console.Write("iki "); break;
                        case '3': Console.Write("uc "); break;
                        case '4': Console.Write("dort "); break;
                        case '5': Console.Write("bes "); break;
                        case '6': Console.Write("alti "); break;
                        case '7': Console.Write("yedi "); break;
                        case '8': Console.Write("sekiz "); break;
                        case '9': Console.Write("dokuz "); break;
                    }
                    break;
                // tens
                case 1:
                    switch (digits[j])
                    {
                        case '1': Console.Write("on "); break;
                        case '2': Console.Write("yirmi "); break;
                        case '3': Console.Write("otuz "); break;
                        case '4': Console.Write("kirk "); break;
                        case '5': Console.Write("elli "); break;
                        case '6': Console.Write("altmis "); break;
                        case '7': Console.Write("yetmis "); break;
                        case '8': Console.Write("seksen "); break;
                        case '9': Console.Write("doksan "); break;
                    }
                    break;
                // hundreds
                case 2:
                    switch (digits[j])
                    {
                        case '2': Console.Write("iki "); break;
                        case '3': Console.Write("uc "); break;
                        case '4': Console.Write("dort "); break;
                        case '5': Console.Write("bes "); break;
                        case '6': Console.Write("alti "); break;
                        case '7': Console.Write("yedi "); break;
                        case '8': Console.Write("sekiz "); break;
                        case '9': Console.Write("dokuz "); break;
                    }
                    if (digits[j] != '0') Console.Write("yuz ");
                    break;
            }
            switch (j)
            {
                case 3: Console.Write("bin "); break;
                case 6: Console.Write("milyon "); break;
                case 9: Console.Write("milyar "); break;
                case 12: Console.Write("trilyon "); break;
                case 15: Console.Write("katrilyon "); break;
                case 18: Console.Write("kentilyon "); break;
                default: break;
            }
        }
    }
    static void numToTurkish(string? digits)
    {
        // check if the input is valid
        if (digits![0] == '-')
        {
            if (!isNumeric(digits.Substring(1)))
            {
                Console.WriteLine("Invalid input!");
                return;
            }
            Console.Write("eksi ");
            digits = digits.Substring(1);
        }
        else if (!isNumeric(digits))
        {
            Console.WriteLine("Invalid input!");
            return;
        }

        // format the digits
        formatDigits(ref digits);

        // print the number
        printNumber(digits);
    }
    static void Main()
    {
        // hold digits of a number in an array
        Console.WriteLine("Enter a number: ");
        string? digits = Console.ReadLine();

        // print the number in Turkish
        numToTurkish(digits);
    }
}
