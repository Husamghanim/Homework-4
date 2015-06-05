#include <iostream>
#include "Course.h"
using namespace std;

//Note: EX04_01 is in the main function

//EX04_02

int *doubleCapacity( int* list, int size)
{
	int *val;
	
	int newSize = size * 2;
	val = new int[newSize];
	for (int i = 0; i < size; i++)
	{
		val[i] = list[i];
	}
	
	
	
	return val;
		

}

//EX04_03
int *findSmallestNumber(int *list, int size)
{
	int temp;
	int *p = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = list[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (list[j] < list[i])
			{
				temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}
	return p;
}

class Rectangle2D
{
public:
	 double x;
	 double y;
	 double width;
	 double height;
	Rectangle2D()
	{
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}
	Rectangle2D(double a, double b, double c, double d)
	{
		x = a;
		y = b;
		width = c;
		height = c;
	}
	void setX(double a) const
	{
		
	}
	double getX() const
	{
		return x;
	}
	void setY(double b) const
	{
		
	}
	double getY()const
	{
		return y;
	}
	void setWidth(double c)const
	{
		
	}
	double getWidth() const
	{
		return width;
	}
	void setHeight(double d)const
	{
		
	}
	double getHeight()const
	{
		return height;
	}
	double getArea()const
	{
		return width*height;
	}
	double getPerimeter()const
	{
		return (2 * width) + (2 * height);
	}
	bool contains(double i, double j)const
	{
		if ((i > (x - 0.5*width)) && (i<(x + 0.5*width)) && (j>(y - 0.5*height)) && (j < (y + 0.5*height)))
			return true;
		else
			return false;
	}
	bool contains(const Rectangle2D &r) const
	{
		if ((r.x - 0.5*r.width)>(x - 0.5*width) && (r.x + 0.5*r.width) < (x + 0.5*width) && (r.y - 0.5*r.height) > (y - 0.5*height) && (r.y + 0.5*r.height) < (y + 0.5*height))
			return true;
		else
			return false;
	}
	bool overlaps(const Rectangle2D &r)const
	{
		if ((((r.x - 0.5*r.width) > (x - 0.5*width) && (r.x - 0.5*r.width) < (x + 0.5*width)) || ((r.x + 0.5*r.width) > (x - 0.5*width) && (r.x + 0.5*r.width) < (x + 0.5*width))) && (((r.y - 0.5*r.height) > (y - 0.5*height) && (r.y - 0.5*r.height) < (y + 0.5*height)) || ((r.y + 0.5*r.height) > (y - 0.5*height) && (r.y + 0.5*r.height) < (y + 0.5*height))))
			return true;
		else
			return false;
	}
};



int main()
{
	//EX04_01
	int *val;
	int size;
	int sum=0;
	int count=0;
	
	
	cout << "Please enter the size of the array: ";
	cin >> size; 
	val = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Please enter value number " << i + 1<< endl;
		cin >> val[i];
		sum += val[i];
	}

	double average = double(sum) / size;
	for (int i = 0; i < size; i++)
	{
		if (val[i]>average)
			count++;
	}
	cout << "The average is " << average << " and there are " << count << " numbers above average." << endl;
	cout << val[size + 1];
	//EX04_02
	
	val=doubleCapacity(val, size) ;
	

	delete[] val;

	//EX04_03
	int list[] = { 1, 2, 4, 5, 10, 100, 2, -22 };
	int *p = findSmallestNumber(list, 8);
	cout << "Smallest number is " << p[0] << endl;
	delete [] p;
	//EX04_04
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);
	cout << "the area of r1 is " << r1.getArea() << endl;
	cout << r1.contains(3, 3) << endl;
	cout << r1.contains(r2) << endl;
	cout << r1.overlaps(r3) << endl;

	//EX04_05
	Course course1("Data Structures", 2);
	Course course2("Database Systems", 15);
	course1.addStudent("Peter Jones");
	course1.addStudent("Brian Smith");
	course1.addStudent("Anne Kennedy");

	course2.addStudent("Peter Jones");
	course2.addStudent("Steven Smith");

	cout << "Number of students in course1: " << course1.getNumberOfStudents() << endl;
	string* students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << "\nNumber of students in course2: " << course2.getNumberOfStudents() << endl;
	students = course2.getStudents();
	for (int i = 0; i < course2.getNumberOfStudents(); i++)
		cout << students[i] << ", ";
	cout << endl;
	course1.dropStudent("Brian Smith");
	cout << "Number of students in course1: " << course1.getNumberOfStudents() << endl;
	students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		cout << students[i] << ", ";


	return 0;
}