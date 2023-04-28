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

        public void Add(T value)
        {
            Node<T> newNode = new Node<T>(value);

            if (root == null) 
            {  
                root = newNode;
            }
            else
            {
                root.Add(newNode);
            }
        }
        public Node<T> Find (T value)
        {
            if (root == null) { return null; }
            
            return root.Find(new Node<T>(value));
        }
        public void Remove(T value)
        {
            if (Find(value) == null)
            {
                Console.WriteLine("Nema...");
            }
            else
            {
                Node<T> node = Find(value);

            }
        }
        public class Node<TNode> where TNode : T
        {
            public TNode Value { get; private set; }
            public Node<TNode> Left { get; set; }
            public Node<TNode> Right { get; set; }
            public Node(TNode value) { Value = value; }

            public void Add(Node<TNode> node)
            {
                if (node.Value.CompareTo(Value) < 0)
                {
                    if (Left == null) Left = node;
                    else Left.Add(node);
                }
                else if (node.Value.CompareTo(Value) > 0)
                {
                    if (Right == null) Right = node;
                    else Right.Add(node);
                }
            }

            public Node<TNode> Find(Node<TNode> node)
            {
                if (node.Value.CompareTo(Value) == 0)
                {
                    return node;
                }

                if (node.Value.CompareTo(Value) < 0)
                {
                    if (Left == null) return null;
                    return Left.Find(node);
                }
                else
                {
                    if (Right == null) return null;
                    return Right.Find(node);
                }
            }
        }
    }
}
