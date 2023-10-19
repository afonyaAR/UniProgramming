#include "Student.h"

Student::Student(string surname,
	string initials,
	int groupNumber,
	int* grades)
{
	this->surname = surname;
	this->initials = initials;
	this->groupNumber = groupNumber;
	for (int i = 0; i < 5; i++)
	{
		this->grades[i] = grades[i];
	}
}

Student::Student()
{
	this->surname = "unknown";
	this->initials = "unknown_unknown";
	this->groupNumber = 0;
	for (int i = 0; i < 5; i++)
	{
		this->grades[i] = 0;
	}
}
ostream& operator<<(ostream& stream, Student obj)
{
	cout << obj.surname << ", ";
	cout << obj.initials << ", ";
	cout << obj.groupNumber << ", ";
	for (int i = 0; i < 5; i++) 
	{
		cout << obj.grades[i] << " ";
	}
	cout << endl;
	return stream;
}

istream& operator>>(istream& stream, Student& obj) 
{
	cout << "Enter a surname: ";
	stream >> obj.surname;
	cout << "Enter an initials (Name_MiddleName): ";
	stream >> obj.initials;
	cout << "Enter a group number: ";
	stream >> obj.groupNumber;
	for (int i = 0; i < 5; i++) 
	{
		cout << "Enter a grade (" << 5 - i << " left): ";
		stream >> obj.grades[i];
	}
	return stream;
}

string Student::GetSurname() 
{
	return surname;
}

string Student::GetInitials() 
{
	return initials;
}

int Student::GetGroupNumber() 
{
	return groupNumber;
}

int* Student::GetGrades() 
{
	return grades;
}

void Student::StudentInfo() 
{
	cout << "surname: " << surname << endl;
	cout << "initials: " << initials << endl;
	cout << "group number: " << groupNumber << endl;
	cout << "grades: ";
	for (int i = 0; i < 5; i++) 
	{
		cout << grades[i] << " ";
	}
	cout << endl;
}
