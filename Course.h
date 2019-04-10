#pragma once
#include<iostream>
#include<string>
#include"Student.h"
#include<cstring>
using namespace std;

//respective Course Class 
class Course
{
	friend class Student;
	
	string course_name;
	string course_number;
	Student** student;
	void addStudent (Student* s);
	void removeStudent(Student*s);
	friend ostream& operator<<(ostream & os,Course &c);
	
public:
	int count;
	Course(string,string);
	Course& operator=(Course& a);
	Course(Course&);
	~Course();
	
};