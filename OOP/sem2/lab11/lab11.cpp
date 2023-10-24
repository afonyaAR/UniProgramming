#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream ifs;

    ifs.open("textfile.txt", ios::in);

    if (!ifs)
    {
        cerr << "textfile.txt cant be opened for reading";
        exit(1);
    }

    string* sentences = new string[3];
    for (int i = 0; i < 3; i++)
    {
        getline(ifs, sentences[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << sentences[2 - i] << endl;
    }

    ifs.close();
}

