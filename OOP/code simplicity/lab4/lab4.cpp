#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// Function to determine if a string is a palindrome.
/// </summary>
/// <param name="str">- string which you want to check</param>
/// <returns>is it palindrome or not (bool)</returns>
bool IsPalindrome(const string& str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        // Check characters from both ends of the string
        if (str[i] != str[str.length() - 1 - i])
        {
            // If the characters do not match, return false
            return false;
        }
    }
    // If all characters match, return true
    return true;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (IsPalindrome(input))
    {
        cout << input << " is a palindrome" << endl;
    }
    else
    {
        cout << input << " is not a palindrome" << endl;
    }

    return 0;
}