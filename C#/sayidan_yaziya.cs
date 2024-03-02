namespace ConvertNumericToVerbal;

class Turkish
{
    public static void Print(string? digits, bool reverseIndex = true)
    {
        // check if the input is valid
        if (!IsValidNumber(digits))
        {
            Console.WriteLine("Invalid input!");
            return;
        }

        // format the digits
        FormatDigits(ref digits!);

        // set the encoding to UTF-8
        Console.OutputEncoding = System.Text.Encoding.UTF8;

        // print the number
        if (reverseIndex)
        {
            PrintWithReverseIndex(digits);
        }
        else
        {
            PrintByReversingString(digits);
        }
    }

    private static void PrintWithReverseIndex(string digits)
    {
        int reverseIndex;
        for (int i = 0; i < digits.Length; i++)
        {
            reverseIndex = digits.Length - 1 - i;
            PrintDigit(digits[i], reverseIndex, digits.Length);
        }
        Console.WriteLine();
    }

    private static void PrintByReversingString(string digits)
    {
        digits = new string(digits.Reverse().ToArray());
        for (int i = digits.Length - 1; i >= 0; i--)
        {
            PrintDigit(digits[i], i, digits.Length);
        }
        Console.WriteLine();
    }

    private static bool IsValidNumber(string? input)
    {
        if (string.IsNullOrEmpty(input))
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

    private static void FormatDigits(ref string digits)
    {
        // get rid of leading zeros
        int i = 0;
        while (i < digits.Length - 1 && digits[i] == '0')
        {
            i++; // count the number of leading zeros
        }
        digits = digits[i..];
    }

    private static void PrintDigit(char digit, int index, int length)
    {
        // check if the number is zero
        if (length == 1 && digit == '0')
        {
            Console.Write("sıfır");
            return;
        }

        switch (index % 3)
        {
            // ones
            case 0:
                switch (digit)
                {
                    case '1': if (index != 3 || length > 4) Console.Write("bir "); break;
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
                switch (digit)
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
                switch (digit)
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
                if (digit != '0') Console.Write("yüz ");
                break;
        }
        // powers of 1,000
        switch (index)
        {
            case 3: Console.Write("bin "); break;
            case 6: Console.Write("milyon "); break;
            case 9: Console.Write("milyar "); break;
            case 12: Console.Write("trilyon "); break;
            case 15: Console.Write("katrilyon "); break;
            case 18: Console.Write("kentilyon "); break;
            case 21: Console.Write("sekstilyon "); break;
            case 24: Console.Write("septilyon "); break;
            case 27: Console.Write("oktilyon "); break;
            case 30: Console.Write("nonilyon "); break;
            case 33: Console.Write("desilyon "); break;
            default: break;
        }
    }
}
