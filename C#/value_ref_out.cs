namespace SoloLearn
{
    class Program
    {
        static void Sqr(int x)
        {
            x = x * x;
        }
        static void SqrByRef(ref int x)
        {
            x = x * x;
        }
        // out parameters are passed by reference
        // they are the same as ref parameters with the exception
        // that out parameters should be initialized in the method
        static void OnlyAssign(out int x)
        {
            // x = x * x;
            x = 4;
            x = x * x;
        }
        static void Main(string[] args)
        {
            int a = 3;

            Sqr(a);
            Console.WriteLine(a); // 3
            SqrByRef(ref a);
            Console.WriteLine(a); // 9
            OnlyAssign(out a);
            Console.WriteLine(a); // 16
        }
    }
}
