using System.Diagnostics;

namespace lab2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите размер массива: ");
            int len = int.Parse(Console.ReadLine());

            Console.Write("Введите метод создания массива (random, manual, example): ");
            string method = Console.ReadLine().ToLower();
            int[] array_1 = get_arr(method, len);
            int[] array_2 = new int[array_1.Length];
            array_1.CopyTo(array_2, 0);
            Stopwatch stopwatch = new Stopwatch();

            //начальный массив
            show_arr("начальный", array_1);
            Console.WriteLine();

            //замер времени выполнения метода прямого включения
            stopwatch.Start();
            InsertionSort(array_1);
            show_arr("прямое включение", array_1);
            stopwatch.Stop();
            Console.WriteLine($"Затраченное время в милисекундах: {stopwatch.Elapsed.TotalMilliseconds}\n");

            //замер времени выполнения метода шейкера
            stopwatch.Restart();
            ShakerSort(array_2);
            //show_arr("шейкер", array_2);
            stopwatch.Stop();
            Console.WriteLine($"Затраченное время в милисекундах: {stopwatch.Elapsed.TotalMilliseconds}\n");
        }

        //сортировка с помощью прямого включения
        static void InsertionSort(int[] arr)
        {
            int count = 0;
            int count1 = 0;

            for (int i = 1; i < arr.Length; i++)
            {
                show_arr("InsSort", arr);

                //находим j-й индекс в отсортрованной части массива
                int temp = arr[i];
                int j_index = -1;

                for (int j = 0; j <= i; j++)
                {
                    count1++;
                    if (temp <= arr[j])
                    {
                        j_index = j;
                        break;
                    }
                }

                //смещение части массива [j, i-1] на один вправо
                int arr_first = arr[j_index];
                int temp_;

                for (int j = j_index; j < i; j++)
                {
                    temp_ = arr[j + 1];
                    arr[j + 1] = arr_first;
                    arr_first = temp_;
                    count++;
                }

                //вставка необходимого числа в массив
                arr[j_index] = temp;
            }
            Console.WriteLine($"Количество перестановок InsertionSort: {count}");
            Console.WriteLine($"Количество сравнений InsertionSort: {count1}");
        }

        //шейкерная сортировка
        static void ShakerSort(int[] arr)
        {
            int e_left = 0;
            int e_right = arr.Length;
            int count = 0;
            int count1 = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                show_arr("ShaSort", arr);

                int temp;

                if (i % 2 == 0)
                {
                    for (int j = e_left; j < e_right - 1; j++)
                    {
                        count1++;
                        if (arr[j] > arr[j + 1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                            count++;
                        }
                    }
                    e_right--;
                }
                else
                {

                    for (int j = e_right - 1; j > e_left; j--)
                    {
                        count1++;
                        if (arr[j] < arr[j - 1])
                        {
                            temp = arr[j];
                            arr[j] = arr[j - 1];
                            arr[j - 1] = temp;
                            count++;
                        }
                    }
                    e_left++;
                }
            }
            Console.WriteLine($"Количество перестановок ShakerSort: {count}");
            Console.WriteLine($"Количество сравнений ShakerSort: {count1}");
        }

        //вывод маасива на проверку
        static void show_arr(string name, int[] arr)
        {
            Console.Write($"Массив \"{name}\" : ");
            foreach (int i in arr)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();
        }

        static int[] get_arr(string method, int len)
        {
            int[] arr = new int[len];

            switch (method)
            {
                case "random":
                    Random rnd = new Random();

                    for (int i = 0; i < len; i++)
                    {
                        arr[i] = rnd.Next(50);
                    }
                    break;
                case "manual":
                    Console.WriteLine($"Введите элементы массива ({len} элемента/ов):");

                    for (int i = 0; i < len; i++)
                    {
                        Console.Write($"{i + 1}: ");
                        arr[i] = Convert.ToInt16(Console.ReadLine());
                    }
                    break;
                case "example":
                default:
                    arr = new int[] { 1, 2, 3, 4, 5, 9, 8, 7, 6 };
                    break;
            }
            return arr;
        }
    }
}
