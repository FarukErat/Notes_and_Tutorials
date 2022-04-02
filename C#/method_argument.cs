namespace SoloLearn
{
    class Program
    {
        static int Area(int height, int width)
        {
            return height * width;
        }
        static void Main(string[] args)
        {
            int res = Area(width: 5, height: 8);
            Console.WriteLine(res); // 40
        }
    }
}
