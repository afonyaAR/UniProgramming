#include <iostream>
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

int main()
{
    //Student st1 = Student("Alesha", "Azar_Romanovich", 6, new int[5]{3, 2, 2, 5, 3});
    const int t_size = 5;
    Student* students = new Student[t_size];

    for (int i = 0; i < t_size; i++) 
    {
        cout << "Enter a student " << i + 1 << ": \n";
        cin >> students[i];
    }

    Sort(students, t_size);

    FindGoodStudents(students, t_size);
}
