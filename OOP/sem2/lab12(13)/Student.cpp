#include "Student.h"
#include <sstream>

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
	return stream;
}

istream& operator>>(istream& stream, Student& obj)
{
	if (stream.bad() || stream.fail()) 
	{
		cerr << "Error." << endl;
		exit(0);
	}

	while (1)
	{
		cout << "Enter a surname: ";
		getline(stream, obj.surname);
		bool bRejected = false;

		if (obj.surname == "")
			bRejected = true;

		for (unsigned int nIndex = 0; nIndex < obj.surname.length() && !bRejected; nIndex++)
		{
			if (isalpha(obj.surname[nIndex]))
				continue;

			bRejected = true;
		}

		if (bRejected) 
		{
			cout << "Surname cant be writed like this try another one." << endl;
		}
		else 
		{
			break;
		}
	}

	while (1)
	{
		cout << "Enter an initials (Name_MiddleName): ";
		getline(stream, obj.initials);
		int count = 0;
		bool bRejected = false;

		for (unsigned int nIndex = 0; nIndex < obj.initials.length() && !bRejected; nIndex++)
		{
			if (isalpha(obj.initials[nIndex]))
				continue;

			if (obj.initials[nIndex] == ' ') 
			{
				count++;
				continue;
			}

			bRejected = true;
		}

		if (count != 1)
			bRejected = true;

		if (bRejected)
		{
			cout << "Name_MiddleName cant be writed like this try another one." << endl;
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		cout << "Enter a group number: ";
		string gNum;
		getline(stream, gNum);

		bool bValid = true;
		for (unsigned int nIndex = 0; nIndex < gNum.length(); nIndex++)
			if (!isdigit(gNum[nIndex]))
			{
				bValid = false;
				break;
			}
		if (!bValid) 
		{
			cout << "Group number cant be writed like this try another one." << endl;
			continue;
		}

		stringstream strStream;
		strStream << gNum;
		strStream >> obj.groupNumber;

		if (obj.groupNumber <= 0)
		{
			cout << "Group number cant be writed like this try another one." << endl;
			continue;
		}

		break;
	}

	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			cout << "Enter a grade (" << 5 - i << " left): ";
			string gNum;
			getline(stream, gNum);

			bool bValid = true;

			if (!isdigit(gNum[0]) || gNum.length() != 1)
			{
				bValid = false;
			}

			if (!bValid)
			{
				cout << "Grade cant be writed like this try another one." << endl;
				continue;
			}

			stringstream strStream;
			strStream << gNum;
			strStream >> obj.grades[i];

			if (obj.grades[i] <= 0 || obj.grades[i] > 5)
			{
				cout << "Grade cant be writed like this try another one." << endl;
				continue;
			}

			break;
		}
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
