#include<iostream>
#include"Course.h"
using namespace std;
Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];

}

Course::~Course()
{
	delete[] students;
}
string Course::getCourseName()const
{
	return courseName;
}
string* Course::checkCapacity()const 
{
	int newCapacity;
	string*newStudents;
	
	if (numberOfStudents >= capacity)
	{
		newCapacity = capacity * 2;

		newStudents = new string[newCapacity];
		for (int i = 0; i < numberOfStudents - 1; i++)
			newStudents[i] = students[i];
		return newStudents;
	}
	else
		return students;
}
void Course::addStudent(const string& name)
{
	numberOfStudents++;
	students=checkCapacity();
	students[numberOfStudents-1] = name;
	
	
}
void Course::dropStudent(const string& name)
{
	
	for (int i = 0; i < numberOfStudents-1; i++)
	{
		if (students[i] == name)
		{
			students[i] = students[i + 1];
			students[i + 1] = name;
			
		}
	}
	if (students[numberOfStudents-1] == name)
	{
		students[numberOfStudents-1] = "";
		numberOfStudents--;
	}
}
void Course::clear()
{
	delete[] students;
}

string* Course::getStudents()const
{
	return students;
}
int Course::getNumberOfStudents()const
{
	return numberOfStudents;
}
Course::Course(const Course& course)
{
	courseName = course.courseName;
	numberOfStudents = course.numberOfStudents;
	capacity = course.capacity;
	students = new string[capacity];
}
