#pragma once

#include<iostream>
#include<string>
#include"Course.h"

using namespace std;
//respective student class
class Student
{
	string username;
	string name;
	string roll_number;
	Course** course;
	int count;
	friend ostream& operator<<(ostream & os,Student &s);
	
public:
	Student(Student &);
	Student(string ,string, string);
	void addCourse(Course* c);
	void printstudent();
	Student& operator=(Student&);
	~Student();
	void dropcourse(Course*c);
};