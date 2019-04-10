#include"Course.h"
using namespace std;
//Overloaded Constructor
Course::Course(string nam,string number)
{
	course_name=nam;
	course_number=number;
	count=0;
	student=new Student*[4];
}
//Function to add student
void Course::addStudent (Student* s)
{
	bool flag =false;
	for(int i=0;i<count;i++)
	{
		if(student[i]==s)
		{
			flag=true;
			
		}
	}
	if(flag==true)
	{
		cout<<"Element already present "<<endl;
	}
	if(flag==false)
	{
		if(count>=4)
	    {
		    cout<<"More than four Students can't be added, Sorry!"<<endl;
	    }
	    else
	    {
		    if(s!=nullptr)
	        {
		       student[count]=s;
		       count++;
	        }
	    }
	}
}
//overloaded assignment operator
Course& Course::operator=(Course& a)
{
	course_name=a.course_name;
	course_number=a.course_number;
	count=a.count;
	if(student!=nullptr)
	{
		for(int i=0;i<count;i++)
		{
			delete student[i];
		}
		delete [] student;
	}
	else
	{
		student=new  Student*[4];
	   for(int i=0;i<count;i++)
	   {
		   student[i]=a.student[i];
	   }
	}
	return *this;
}
//copy constructor
Course::Course(Course& a)
{
	course_name=a.course_name;
	course_number=a.course_number;
	count=a.count;
	student=new  Student*[4];
	for(int i=0;i<count;i++)
	{
		student[i]=a.student[i];
	}
}
//oerloaded instream operator
ostream& operator<<(ostream & os,Course &c)
{
		os<<"Course name :"<<c.course_name<<endl;
		os<<"Course number :"<<c.course_number<<endl;
		if(c.student!=nullptr)
		{
			for(int i=0;i<c.count;i++)
			{
				os<<"Student name :"<<*(c.student[i])<<endl;
			}
		}
		return os;
}
//default destructor
Course::~Course()
{
	if(student!=nullptr)
	{
		for(int i=0;i<count;i++)
		{
			delete student[i];
		}
		delete [] student;
	}
}
//Function to remove a student from course
void Course::removeStudent(Student* s)
{
	bool check=false;
	for(int i=0;i<count;i++)
	{
		if(student[i]!=s)
		{
			check=true;
		}
	}
	for(int i=0;i<count-1;i++)
	{
		if(student[i]==s)
		{
			delete student[i];
			student[i]=nullptr;
			student[i]=student[i+1];
		}
	}
	if(check==true)
	{
		cout<<"Element not found ."<<endl;
	}
}


