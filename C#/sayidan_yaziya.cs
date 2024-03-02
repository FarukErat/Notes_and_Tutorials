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
        Console.WriteLine();
    }

    private static void PrintWithReverseIndex(string digits)
    {
        int reverseIndex;
        for (int i = 0; i < digits.Length; i++)
        {
            reverseIndex = digits.Length - 1 - i;
            PrintDigit(digits[i], reverseIndex, digits.Length);
        }
    }

    private static void PrintByReversingString(string digits)
    {
        digits = new string(digits.Reverse().ToArray());
        for (int i = digits.Length - 1; i >= 0; i--)
        {
            PrintDigit(digits[i], i, digits.Length);
        }
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

        string toPrint = (index % 3) switch
        {
            // ones
            0 => digit switch
            {
                '1' => (index != 3 || length > 4) ? "bir " : "",
                '2' => "iki ",
                '3' => "üç ",
                '4' => "dört ",
                '5' => "beş ",
                '6' => "altı ",
                '7' => "yedi ",
                '8' => "sekiz ",
                '9' => "dokuz ",
                _ => ""
            },
            // tens
            1 => digit switch
            {
                '1' => "on ",
                '2' => "yirmi ",
                '3' => "otuz ",
                '4' => "kırk ",
                '5' => "elli ",
                '6' => "altmış ",
                '7' => "yetmiş ",
                '8' => "seksen ",
                '9' => "doksan ",
                _ => ""
            },
            // hundreds
            2 => digit switch
            {
                '2' => "iki ",
                '3' => "üç ",
                '4' => "dört ",
                '5' => "beş ",
                '6' => "altı ",
                '7' => "yedi ",
                '8' => "sekiz ",
                '9' => "dokuz ",
                _ => ""
            },
            _ => "",
        };

        if ((index % 3 == 2) && (digit != '0'))
        {
            toPrint += "yüz ";
        }

        // powers of 1,000
        toPrint += index switch
        {
            3 => "bin ",
            6 => "milyon ",
            9 => "milyar ",
            12 => "trilyon ",
            15 => "katrilyon ",
            18 => "kentilyon ",
            21 => "sekstilyon ",
            24 => "septilyon ",
            27 => "oktilyon ",
            30 => "nonilyon ",
            33 => "desilyon ",
            _ => ""
        };
        Console.Write(toPrint);
    }
}
