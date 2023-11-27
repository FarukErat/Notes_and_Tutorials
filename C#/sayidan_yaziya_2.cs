class Program
{
    static bool IsNumeric(string? input)
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
    static void FormatDigits(ref string digits)
    {
        // get rid of leading zeros
        int i = 0;
        while (i < digits.Length - 1 && digits[i] == '0')
        {
            i++; // count the number of leading zeros
        }
        digits = digits[i..];
    }
    static void PrintNumber(string digits)
    {
        // check if the number is zero
        if (digits.Length == 1 && digits[0] == '0')
        {
            Console.WriteLine("sıfır");
            return;
        }

        // main loop
        int reverseIndex;
        for (int j = 0; j < digits.Length; j++)
        {
            reverseIndex = digits.Length - 1 - j;
            switch (reverseIndex % 3)
            {
                // ones
                case 0:
                    switch (digits[j])
                    {
                        case '1': if (reverseIndex != 3) Console.Write("bir "); break;
                        case '2': Console.Write("iki "); break;
                        case '3': Console.Write("üç "); break;
                        case '4': Console.Write("dört "); break;
                        case '5': Console.Write("beş "); break;
                        case '6': Console.Write("altı "); break;
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
                        case '4': Console.Write("kırk "); break;
                        case '5': Console.Write("elli "); break;
                        case '6': Console.Write("altmış "); break;
                        case '7': Console.Write("yetmiş "); break;
                        case '8': Console.Write("seksen "); break;
                        case '9': Console.Write("doksan "); break;
                    }
                    break;
                // hundreds
                case 2:
                    switch (digits[j])
                    {
                        case '2': Console.Write("iki "); break;
                        case '3': Console.Write("üç "); break;
                        case '4': Console.Write("dört "); break;
                        case '5': Console.Write("beş "); break;
                        case '6': Console.Write("altı "); break;
                        case '7': Console.Write("yedi "); break;
                        case '8': Console.Write("sekiz "); break;
                        case '9': Console.Write("dokuz "); break;
                    }
                    if (digits[j] != '0') Console.Write("yüz ");
                    break;
            }
            switch (reverseIndex)
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
    static void NumToTurkish(string? digits)
    {
        // check if the input is valid
        if (digits![0] == '-')
        {
            if (!IsNumeric(digits.Substring(1)))
            {
                Console.WriteLine("Invalid input!");
                return;
            }
            Console.Write("eksi ");
            digits = digits[1..];
        }
        else if (!IsNumeric(digits))
        {
            Console.WriteLine("Invalid input!");
            return;
        }

        // format the digits
        FormatDigits(ref digits);

        // print the number
        PrintNumber(digits);
    }
    static void Main()
    {
        // set the encoding to UTF-8
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        // hold digits of a number in an array
        Console.WriteLine("Enter a number: ");
        string? digits = Console.ReadLine();

        // print the number in Turkish
        NumToTurkish(digits);
    }
}
