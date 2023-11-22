#include <iostream>
#include <fstream>
#include <string>
#include "Van.h"
#include "Stack.h"
using namespace std;

Stack<Van> TrainFromKeyboard(const int size) 
{
    Stack<Van> train(size);
    for (int i = 0; i < size; i++)
    {
        bool type;
        cout << "Van " << i << " type(0/1): ";
        cin >> type;

        int number;
        cout << "Van number: ";
        cin >> number;

        train.push(*new Van(type, number));
    }

    return train;
}

Stack<Van> TrainFromFile(string file)
{
    ifstream ifs(file, ios::in);
    string unused;
    int numLines = 0;
    while (getline(ifs, unused))
    {
        numLines++;
    }

    if (!ifs)
    {
        cerr << file << " cant be opened for reading";
        exit(1);
    }

    ifs.seekg(0);
    Stack<Van> train(numLines);
    for (int i = 0; i < numLines; i++)
    {
        string line;
        getline(ifs, line, ' ');
        bool type = line != "0";
        getline(ifs, line);
        int number = stoi(line);
        
        train.push(*new Van(type, number));
    }

    return train;
}

int main()
{

    const int size = 5;
    //Stack<Van> train = TrainFromKeyboard(size);
    Stack<Van> train = TrainFromFile("train.txt");

    Stack<Van> train0(size);
    Stack<Van> train1(size);

    for (int i = 0; i < size; i++)
    {
        Van van = train.peek();
        if (van.VanType())
        {
            train1.push(van);
            train.pop();
        }
        else
        {
            train0.push(van);
            train.pop();
        }
    }

    for (int i = 0; i < size; i++)
    {
        train1.peek().VanInfo();
        train1.pop();
    }

    /*for (int i = 0; i < size; i++)
    {
        train.peek().VanInfo();
        train.pop();
    }*/
}

