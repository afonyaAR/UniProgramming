#include <iostream>
#include <typeinfo>
#include <stdio.h>
#include <vector>
using namespace std;

void def3()
{
	vector<bool> a{ 1, 1, 1, 1 };
	auto b = a.begin();
	auto c = *b;
	cout << is_same<decltype(b), bool>();
	vector<int> d{ 1, 1, 1, 1 };
	auto e = d.begin();
	auto f = *e;
	cout << is_same<decltype(f), int>();
	vector<long> g{ 1, 1, 1, 1 };
	auto h = g.begin();
	auto i = *h;
	cout << is_same<decltype(i), short>();
}

void def4()
{
	int list[] = { 1, 2, 3, 4, 5, 6 };
	for (int i = 1; i < 6; i++)
		list[i] = list[i - 1];
	for (int i = 0; i < 6; i++)
		cout << list[i] << " ";
}

int foo(int* a, int* b)
{
	int sum = *a + *b;
	*b = *a;
	return *a = sum - *b;
}
void def5()
{
	int i = 0, j = 1, k = 2, l;
	l = i++ || foo(&j, &k);
	printf("%d %d %d %d", i, j, k, l);
}

template <typename T> void P(const T& x) { std::cout << x; }
#define F1(a,b) a > b ? a : b
#define F2(a,b) (((a)<(b))?(a):(b))
void def6()
{
	int a = 2, b = 3, c = 0;
	c = 1 + F1(a, b);
	P(a); P(b); P(c);
	c = F2(++a, ++b);
	P(a); P(b); P(c);
}

void def7()
{
	int grade = 95;
	std::cout << (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
}

void def16()
{
	string flk = "Not a very good idea";
	size_t i;
	while ((i = flk.find(' ')) != string::npos)
		flk.erase(i, 1);
	flk[1] = 'e';
	flk.erase(2, 2);
	flk.erase(5, 1);
	size_t size = flk.size();
	flk.resize(size - 4, '/0');
	cout << flk;
}

void def17()
{
	int val1 = 42;
	float val2 = 3.;
	double val3 = 5.6;
	bool val4 = true;
	short val5 = 5;
	cout << val1 % val4 << endl;
	cout << val1 % val5;
	//cout << val1 % val2;
	//cout << val3 % val2;
}

void def18()
{
	int i = 1;
	do
	{
		cout << i;
		i++;
		if (i < 3) continue;
		cout << '4';
		if (i < 2)
		{
			cout << 5;
			break;
		}
		break;
	} while (false);
}

void Sum(int a, int b, int& c)
{
	a = b + c;
	b = a + c;
	c = a + b;
}
void def19()
{
	int x = 2, y = 3;
	Sum(x, y, y);
	cout << x << " " << y;
}

double Quiz(int quizArray[], int df = 3)
{
	double vlz = 0.0;
	for (int a = 0; a < df; a++)
		vlz += quizArray[a];
	return vlz / static_cast<unsigned>(df);
}
void def20()
{
	int arr[] = { 0, 1, 2, 3, 4, 5 };
	unsigned n = sizeof(arr) / sizeof(arr[0]);
	cout << (int)Quiz(arr) << Quiz(arr, n - 1);
}

class Foo
{
public:
	Foo(int x)
	{

	}
};
void def_1()
{
	auto a = 166LL;
	auto b = 'a' + true;
	auto c = Foo(3);
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
}

void def_2()
{
	string str("Test string");
	for (string::iterator it = str.begin(); it != str.end() - 4; ++it)
		cout << *it;
}

void def_3()
{
	try
	{
		throw 'a';
	}
	catch (int param)
	{
		cout << "int exception\n";
	}
	catch (...)
	{
		cout << "default exception\n";
	}
	cout << "After Exception";
}

void def_4()
{
	short m1 = 10;
	int d = 2;
	cout << (int)(m1 * d);
}

//class A
//{
//	int id;
//	static int count;
//public:
//	A()
//	{
//		count++;
//		id = count;
//		cout << "constructor for id" << id << endl;
//	}
//	~A()
//	{
//		cout << "destructor for id" << id << endl;
//	}
//};
//int A::count = 0;
//
//void def_5()
//{
//	A a[3];
//}

class A
{
private:
	int a;
public:
	A() { a = 4; }
	friend class B;
	friend class C;
};

class B
{
private:
	int a;
public:
	B() { a = 2; }
	void showA(A& x)
	{
		cout << "B::b=" << x.a;
	}
};

class C
{
private:
	int a;
public:
	C() { a = 6; }
	void showA(A& x)
	{
		cout << "C::c=" << x.a;
	}
};

int main()
{
	int a[] = { 1,2,3,4,5,6 };
	int* ptr = (a + 1);
	cout << *(ptr-1);
}