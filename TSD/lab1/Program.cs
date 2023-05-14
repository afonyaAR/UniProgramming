using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите максимальную степень: ");
            int n = Convert.ToInt32(Console.ReadLine()) + 1;
            int[] coeffs = new int[n];
            int[] coeffsReverse = new int[n];
            int res1 = 0;
            int res2 = 0;
            Console.Write("Введите x: ");
            int x = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                Console.Write($"{i}: ");
                coeffs[n-i-1] = Convert.ToInt32(Console.ReadLine());
            }
            coeffs.CopyTo(coeffsReverse, 0);
            Array.Reverse(coeffsReverse);

            for (int i = n - 1; i > -1; i--)
            {
                res1 = x * res1 + coeffsReverse[i];
            }
            Console.WriteLine($"Результат (обратный цикл): {res1}");

            int tempI = 0;

            while (tempI < n)
            {
                res2 = x * res2 + coeffs[tempI];
                tempI++;
            }
            Console.WriteLine($"Результат (цикл while): {res2}");
        }
    }
}
