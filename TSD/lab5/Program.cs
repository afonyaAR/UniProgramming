using System;
using System.Collections.Generic;
using System.IO;

namespace lab5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Дан текстовый файл.Используя полустатические структуры, переписать
            //содержимое его строк в новый текстовый файл, перенося при этом в конец каждой
            //строки все входящие в нее цифры, сохраняя исходный порядок следования среди
            //цифр и среди остальных символов строки.

            string path1 = @"..\..\TextFile1.txt";
            string path2 = @"..\..\TextFile2.txt";
            
            string[] lines = File.ReadAllLines(path1);
            //Вставка чисел в файл
            //InsertRandomNums(lines);
            //File.WriteAllLines(path1, lines);
            Queue<char> numsInText = new Queue<char>();

            for (int i = 0; i < lines.Length; i++)
            {
                for (int j = 0; j < lines[i].Length; j++)
                {
                    if (char.IsDigit(lines[i][j]))
                    {
                        numsInText.Enqueue(lines[i][j]);
                    }
                }

                lines[i] += " ";
                foreach (char elem in numsInText)
                {
                    int indexOfChar = lines[i].IndexOf(elem);
                    if (lines[i].IndexOf(elem) != -1)
                    {
                        lines[i] = lines[i].Remove(indexOfChar, 1);
                    }
                    lines[i] += elem.ToString();
                }
                numsInText.Clear();
            }
            File.WriteAllLines(path2, lines);
        }

        public static void InsertRandomNums(string[] lines)
        {
            Random rnd = new Random();
            for (int i = 0; i < lines.Length; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (lines[i] == "")
                    {
                        break;
                    }
                    string substring = Convert.ToString(rnd.Next(100));
                    int place = rnd.Next(lines[i].Length);
                    lines[i] = lines[i].Trim(null).Insert(place, substring);
                }
            }
        }
    }
}