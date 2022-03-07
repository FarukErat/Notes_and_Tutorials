namespace SoloLearn
{
    class Program
    {
        static void Sqr(int x)
        {
            x = x * x;
        }
        // with ref keyword, reference and valaue are passed
        static void SqrByRef(ref int x)
        {
            x = x * x;
        }
        // with out keyword, only reference is passed
        // therefore, parameters should be initialized in the method
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
