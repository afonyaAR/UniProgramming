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

    class BinaryTree<T> where T : IComparable<T>
    {
        private Node<T> root;
        public BinaryTree(T value)
        {
            
        }

        public void Add(T value)
        {
            Node<T> newNode = new Node<T>(value);
            if (root == null) 
            {  
                root = newNode;
                return;
            }

            while (true)
            {
                if (value.CompareTo(root.Value) > 0)
                {
                    if (root.Left == null)
                    {
                        root.Left = newNode;
                    }
                    root = newNode;
                }
                else
                {

                }
            }
        }
        class Node<TNode> where TNode : IComparable<TNode>
        {
            public TNode Value { get; private set; }
            public Node<TNode> Left { get; set; }
            public Node<TNode> Right { get; set; }
            public Node(TNode value) { Value = value; }
        }
    }
}
