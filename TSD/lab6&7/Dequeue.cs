using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    internal class Dequeue<T>
    {
        private Node<T> head;
        private Node<T> tail;

        public void AddFirst(T value)
        {
            Node<T> newNode = new Node<T>(value);

            if (head == null)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode.Next = head;
                head.Prev = newNode;
                head = newNode;
            }
        }

        public void AddLast(T value)
        {
            Node<T> newNode = new Node<T>(value);

            if (tail == null)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode.Prev = tail;
                tail.Next = newNode;
                tail = newNode;
            }
        }

        public T RemoveFirst()
        {
            if (head == null)
                throw new InvalidOperationException("Deque is empty");

            T value = head.Value;

            if (head == tail)
            {
                head = null;
                tail = null;
            }
            else
            {
                head = head.Next;
                head.Prev = null;
            }

            return value;
        }

        public T RemoveLast()
        {
            if (tail == null)
                throw new InvalidOperationException("Deque is empty");

            T value = tail.Value;

            if (head == tail)
            {
                head = null;
                tail = null;
            }
            else
            {
                tail = tail.Prev;
                tail.Next = null;
            }

            return value;
        }

        public bool IsEmpty()
        {
            return head == null;
        }

        public void ShowDequeue()
        {
            Node<T> temp = head;
            while (temp.Next != null)
            {
                Console.Write(temp.Value + " ");
                temp = temp.Next;
            }

            Console.WriteLine(temp.Value);
        }

        private class Node<T>
        {
            public T Value { get; private set; }
            public Node<T> Prev { get; set; }
            public Node<T> Next { get; set; }

            public Node(T value)
            {
                Value = value;
            }
        }
    }
}
