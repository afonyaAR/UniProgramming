using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace lab8
{
    internal class Program
    {
        static void Main(string[] args)
        {
            BinaryTree<int> tree = new BinaryTree<int>();
            tree.Add(6);
            tree.Add(22);
            tree.Add(7);
            tree.Add(10);
            tree.Add(-3);
            tree.Add(5);
            tree.Add(4);
            Console.WriteLine(tree.Contains(5));
            tree.SymmetricRound();
        }
    }

    class BinaryTree<T> where T : IComparable<T>
    {
        private Node<T> root;
        public int Count { get; private set; }

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
            Count++;
        }
        public Node<T> Find (T value)
        {
            if (root == null) { return null; }
            
            return root.Find(value);
        }
        public void Remove(T value)
        {
            Node<T> node = Find(value);

            if (node == null)
            {
                Console.WriteLine("Nema...");
                return;
            }

            if (node.Right == null)
            {
                node = node.Left;
            }
            else
            {
                Node<T> newNode = node.Right;
                Node<T> parent = null;
                while (newNode.Left != null)
                {
                    parent = newNode;
                    newNode = newNode.Left;
                }
                node.Value = newNode.Value;
                parent.Left = null;
            }
            Count--;
        }
        public void SymmetricRound()
        {
            root.Traversal();
        }
        public bool Contains(T value) { return (Find(value) != null); }
        public void Clear() { root = null; Count = 0; }

        public class Node<TNode> where TNode : T
        {
            public TNode Value { get; set; }
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

            public Node<TNode> Find(TNode value)
            {
                if (value.CompareTo(Value) == 0)
                {
                    return this;
                }

                if (value.CompareTo(Value) < 0)
                {
                    if (Left == null) return null;
                    return Left.Find(value);
                }
                else
                {
                    if (Right == null) return null;
                    return Right.Find(value);
                }
            }

            public void Traversal()
            {
                Left?.Traversal();
                Console.WriteLine(Value);
                Right?.Traversal();
            }
        }
    }
}
