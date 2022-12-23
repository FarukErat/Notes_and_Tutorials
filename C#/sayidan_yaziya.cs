class Program
{
    static void Main()
    {
        // hold digits of a number in an array
        Console.WriteLine("Enter a number: ");
        string? digits = Console.ReadLine();
        if (digits == null)
        {
            Console.WriteLine("Invalid input!");
            return;
        }
        // reverse the string for easier processing
        digits = new string(digits.ToCharArray().Reverse().ToArray());
        // print the number verbaly
        for (int j = digits.Length - 1; j >= 0; j--)
        {
            switch (j % 3)
            {
                // birler basamagi
                case 0:
                    switch (digits[j])
                    {
                        case '1': Console.Write("bir "); break;
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
                // onlar basamagi
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
                // yuzler basamagi
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
                    Console.Write("yuz ");
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
}
