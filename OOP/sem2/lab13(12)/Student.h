#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
private:
	string surname;
	string initials;
	int groupNumber;
	int grades[5];
public:
	Student(string,
		string initials,
		int groupNumber,
		int* grades);
	Student();
	friend ostream& operator<<(ostream& stream, Student obj);
	friend istream& operator>>(istream& stream, Student& obj);
	string GetSurname();
	string GetInitials();
	int GetGroupNumber();
	int* GetGrades();
	void StudentInfo();
};