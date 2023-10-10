#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Counting how much of current symbols in text
/// </summary>
/// <param name="text"></param>
/// <param name="symbol"></param>
/// <returns>(int) number of symbols in text</returns>
int NumberOfCharInString(string text, char symbol)
{
    int count = 0;
    cout << "Length: " << text.length() << endl;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == symbol)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    string text;
    char symbol;

    cout << "Enter a text: ";
    cin >> text;

    cout << "Enter a symbol: ";
    cin >> symbol;

    cout << "Number of " << symbol << " in text: " << NumberOfCharInString(text, symbol);
}
