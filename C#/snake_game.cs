class Program
{
    const int TABLE_ROWS = 30;
    const int TABLE_COLS = 80;
    // right, down, left, up
    static readonly int[,] DIRECTIONS = new int[,] { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
    class Point
    {
        public int Row { get; set; }
        public int Col { get; set; }
        public Point(int row = 0, int col = 0)
        {
            Row = row;
            Col = col;
        }
    }
    class Snake
    {
        private int length = 5;
        private int direction = 2; // 0 - right, 1 - down, 2 - left, 3 - up
        private char[,] table = new char[TABLE_ROWS, TABLE_COLS];
        private List<Point> body = new List<Point>();
        private Point head;
        public Snake()
        {
            for (int i = 0; i < TABLE_ROWS; i++)
            {
                for (int j = 0; j < TABLE_COLS; j++)
                {
                    table[i, j] = ' ';
                }
            }
            body.Add(new Point(15, 38));
            body.Add(new Point(15, 39));
            body.Add(new Point(15, 40));
            body.Add(new Point(15, 41));
            body.Add(new Point(15, 42));
            for (int i = 0; i < body.Count; i++)
            {
                table[body[i].Row, body[i].Col] = '*';
            }
            head = body[0];
            table[head.Row, head.Col] = 'O';
            AddFood();
        }
        public void Move()
        {
            Point newHead = new Point(head.Row + DIRECTIONS[direction, 0], head.Col + DIRECTIONS[direction, 1]);
            if (newHead.Row < 0 || newHead.Row >= TABLE_ROWS || newHead.Col < 0 || newHead.Col >= TABLE_COLS)
            {
                Console.WriteLine("Out of bounds!\nGame over!");
                Console.WriteLine("Score: {0}", length - 5);
                Console.WriteLine("Press any key to exit...");
                Console.ReadKey(true);
                Environment.Exit(0);
            }
            if (table[newHead.Row, newHead.Col] == '*')
            {
                Console.WriteLine("You ate yourself!\nGame over!");
                Console.WriteLine("Score: {0}", length - 5);
                Console.WriteLine("Press any key to exit...");
                Console.ReadKey(true);
                Environment.Exit(0);
            }
            if (table[newHead.Row, newHead.Col] == ' ')
            {
                table[body[body.Count - 1].Row, body[body.Count - 1].Col] = ' ';
                Console.SetCursorPosition(body[body.Count - 1].Col, body[body.Count - 1].Row);
                Console.Write(' ');
                body.RemoveAt(body.Count - 1);
            }
            else
            {
                length++;
                AddFood();
            }
            body.Insert(0, newHead);
            head = newHead;
            table[head.Row, head.Col] = 'O';
            table[body[1].Row, body[1].Col] = '*';
            Console.SetCursorPosition(head.Col, head.Row);
            Console.Write('O');
            Console.SetCursorPosition(body[1].Col, body[1].Row);
            Console.Write('*');
        }
        public void ChangeDirection(int newDirection)
        {
            if (newDirection < 0 || newDirection > 3)
            {
                throw new Exception("Invalid direction!");
            }
            if (Math.Abs(newDirection - direction) == 2)
            {
                return;
            }
            direction = newDirection;
        }
        public void PrintTable()
        {
            char obstacle = '#';
            // table
            Console.CursorVisible = false;
            Console.Clear();
            for (int i = 0; i < TABLE_COLS + 2; i++)
            {
                Console.Write(obstacle);
            }
            Console.WriteLine();
            for (int i = 0; i < TABLE_ROWS; i++)
            {
                Console.Write(obstacle);
                for (int j = 0; j < TABLE_COLS; j++)
                {
                    Console.Write(" ");
                }
                Console.Write(obstacle);
                Console.WriteLine();
            }
            for (int i = 0; i < TABLE_COLS + 2; i++)
            {
                Console.Write(obstacle);
            }
            // snake
            Console.SetCursorPosition(head.Col, head.Row);
            Console.Write('O');
            for (int i = 1; i < body.Count; i++)
            {
                Console.SetCursorPosition(body[i].Col, body[i].Row);
                Console.Write('*');
            }
            // food
            AddFood();
        }
        public void AddFood()
        {
            Random random = new Random();
            int row = random.Next(1, TABLE_ROWS - 1);
            int col = random.Next(1, TABLE_ROWS - 1);
            while (table[row, col] != ' ')
            {
                row = random.Next(0, TABLE_ROWS);
                col = random.Next(0, TABLE_COLS);
            }
            table[row, col] = '$';
            Console.SetCursorPosition(col, row);
            Console.Write('$');
            // add score
            Console.SetCursorPosition(0, TABLE_ROWS + 2);
            Console.Write("Score: {0}", length - 5);
        }
    }
    static void Main()
    {
        Snake snake = new Snake();
        snake.PrintTable();
        Thread move = new Thread(() =>
        {
            while (true)
            {
                try
                {
                    snake.Move();
                    Thread.Sleep(300);
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    break;
                }
            }
        });
        move.Start();
        while (true)
        {
            ConsoleKeyInfo key = Console.ReadKey(true);
            switch (key.Key)
            {
                case ConsoleKey.RightArrow:
                    snake.ChangeDirection(0);
                    break;
                case ConsoleKey.DownArrow:
                    snake.ChangeDirection(1);
                    break;
                case ConsoleKey.LeftArrow:
                    snake.ChangeDirection(2);
                    break;
                case ConsoleKey.UpArrow:
                    snake.ChangeDirection(3);
                    break;
                case ConsoleKey.Escape:
                    Console.WriteLine("Game over!");
                    Environment.Exit(0);
                    break;
                default:
                    continue;
            }
        }
    }
}
