#include <iostream>

double Div(double n1, double n2)
{
	if (n2 == 0.0L)
		throw "Division by zero!";
	return n1 / n2;
}

double AddWithInc(double n1, double n2)
{
	return n1 + n2 + 1;
}

int main()
{

}