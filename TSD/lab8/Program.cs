using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab8
{
    internal class Program
    {
        static void Main(string[] args)
        {
        }
    }

    class BinaryTree<T>
    {
        private Node<T> head;
        public BinaryTree(T value)
        {
            
        }

        public void Add(T value)
        {
            if (head == null) 
            {  
                head = new Node<TNode>(value);
            }
            else
            {
                if (value > head.Value)
                {

                }
            }
        }
        class Node<TNode> : IComparable<TNode>
        where TNode : IComparable<TNode>
        {
            public TNode Value { get; private set; }
            public TNode Left { get; set; }
            public TNode Right { get; set; }
            public Node(TNode value) { Value = value; }

            public int CompareTo(TNode other)
            {
                return Value.CompareTo(other);
            }
        }
    }
}
