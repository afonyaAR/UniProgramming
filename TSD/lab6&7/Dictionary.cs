using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab6
{
    internal class Dictionary<TKey, TValue>
    {
        private List<TKey> keys;
        private List<TValue> values;

        public Dictionary()
        {
            keys = new List<TKey>();
            values = new List<TValue>();
        }

        public void Add(TKey key, TValue value)
        {
            if (keys.Contains(key))
            {
                throw new ArgumentException("An element with the same key already exists in the dictionary.");
            }
            keys.Add(key);
            values.Add(value);
        }

        public bool ContainsKey(TKey key)
        {
            return keys.Contains(key);
        }

        public bool Remove(TKey key)
        {
            int index = keys.IndexOf(key);
            if (index == -1)
            {
                return false;
            }
            keys.RemoveAt(index);
            values.RemoveAt(index);
            return true;
        }

        public bool TryGetValue(TKey key, out TValue value)
        {
            int index = keys.IndexOf(key);
            if (index == -1)
            {
                value = default(TValue);
                return false;
            }
            value = values[index];
            return true;
        }

        public TValue this[TKey key]
        {
            get
            {
                int index = keys.IndexOf(key);
                if (index == -1)
                {
                    throw new KeyNotFoundException();
                }
                return values[index];
            }
            set
            {
                int index = keys.IndexOf(key);
                if (index == -1)
                {
                    Add(key, value);
                }
                else
                {
                    values[index] = value;
                }
            }
        }

        public int Count
        {
            get { return keys.Count; }
        }

        public ICollection<TKey> Keys
        {
            get { return keys; }
        }

        public ICollection<TValue> Values
        {
            get { return values; }
        }
    }
}
