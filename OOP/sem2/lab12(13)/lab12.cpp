#include <iostream>
#include <fstream>
#include "Student.h"

void Sort(Student* students, const int t_size)
{
    for (int i = 0; i < t_size; i++)
    {
        for (int j = i + 1; j < t_size; j++)
        {
            if (students[i].GetGroupNumber() > students[j].GetGroupNumber())
            {
                Student temp = students[j];
                students[j] = students[i];
                students[i] = temp;
            }
        }
    }
}

void FindGoodStudents(Student* students, const int t_size)
{
    int count = 0;
    for (int i = 0; i < t_size; i++)
    {
        int sum = 0;
        int* grades = students[i].GetGrades();
        for (int j = 0; j < 5; j++)
        {
            sum += grades[j];
        }

        if (sum / 5. > 4.0)
        {
            cout << students[i].GetSurname() << ", " << students[i].GetGroupNumber() << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "there is no good students in class";
    }
}

void WriteStudents(Student* students, int t_size)
{
    ofstream ofs("students.bin", ios::binary | ios::out);
    for (int i = 0; i < t_size; i++)
    {

        ofs.write((char*)&students[i], sizeof(students[i]));
    }
}

Student* ReadStudents(int t_size)
{
    ifstream ifs("students.bin", ios::binary | ios::in);
    Student* students = new Student[t_size];
    for (int i = 0; i < t_size; i++)
    {
        ifs.read((char*)&students[i], sizeof(Student));
    }
    return students;
}

int main()
{
    const int t_size = 5;

    /*Student* students = new Student[t_size]
    {
        Student("Alesha", "VR", 221, new int[5] { 5, 4, 5, 5, 5 }),
        Student("Vasya", "PH", 211, new int[5] { 1, 2, 2, 3, 2 }),
        Student("Ilya", "IA", 211, new int[5] { 4, 4, 5, 4, 4 }),
        Student("Anton", "AP", 621, new int[5] { 3, 4, 5, 5, 5 }),
        Student("Andrei", "MR", 321, new int[5] { 4, 5, 4, 4, 4 }),
    };*/

    Student* students = new Student[t_size];
    for (int i = 0; i < t_size; i++) 
    {
        cout << "Enter a student " << i + 1 << "." << endl;
        cin >> students[i];
    }

    /*Student* students = ReadStudents(t_size);*/

    Sort(students, t_size);

    FindGoodStudents(students, t_size);

    for (int i = 0; i < t_size; i++)
    {
        cout << students[i] << endl;
    }

    WriteStudents(students, t_size);
}