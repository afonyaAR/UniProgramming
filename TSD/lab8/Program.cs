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
            tree.Add(2);
            tree.Add(7);
            tree.Add(1);
            tree.Add(3);
            tree.Add(5);
            tree.Add(4);
            tree.Remove(2);
            Console.WriteLine(tree.Contains(2));
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
            
            return root.Find(new Node<T>(value));
        }
        public void Remove(T value)
        {
            if (Find(value) == null)
            {
                Console.WriteLine("Nema...");
                return;
            }

            Node<T> node = Find(value);
            if (node.Right == null)
            {
                node = node.Left;
            }
            else
            {
                Node<T> supNode;
                node = node.Right;
                while (node.Left != null)
                {
                    node 
                    supNode = supNode.Left;
                }
                T temp = supNode.Value;
                supNode = null;
                node.Value = temp;
            }
            Count--;
        }
        public void SymmetricRound(BinaryTree<T> tree)
        {

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
