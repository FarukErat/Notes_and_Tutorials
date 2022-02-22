namespace SoloLearn
{
    class Program
    {
        static int Area(int h, int w)
        {
            return h * w;
        }
        static void Main(string[] args)
        {
            int res = Area(w: 5, h: 8);
            Console.WriteLine(res); // 40
        }
    }
}
