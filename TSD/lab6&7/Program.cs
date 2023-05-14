using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //дек словарь
            List<int> list = new List<int>();
            Dequeue<int> dek = new Dequeue<int>();
            dek.AddLast(1);
            dek.AddLast(2);
            dek.AddLast(2);
            dek.AddFirst(3);
            dek.AddFirst(3);
            dek.AddFirst(3);
            dek.ShowDequeue();
        }
    }
}
