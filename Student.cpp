#include"Student.h"
using namespace std;
//Overloaded Constructor
Student::Student(string user,string nam, string roll)
{
	username=user;
	roll_number=roll;
	name=nam;
	count=0;
	course=new Course*[2];
}
//Function to  add Course
void Student::addCourse(Course* c)
{
	bool flag=false;
	for(int i=0;i<count;i++)
	{
		if(course[count-1]==c)
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
		if(count>=2)
	   {
		   cout<<"Not more than Two Courses can be taken, Sorry :("<<endl;
	   }
	   else
	   {
		
		   if(c!=nullptr)
		   {
			   c[count].addStudent(this);
			   course[count]=c;
			   count++;
		   }
	   }
	}
}
//overloaded Instream operator
ostream& operator<<(ostream & os,Student &s)
{
		os<<"Student Username :"<<s.username<<endl;
		os<<"Student name :"<<s.name<<endl;
		os<<"Roll Number :"<<s.roll_number<<endl;
		if(s.course!=nullptr)
		{
			for(int i=0;i<s.count;i++)
			{
				os<<*(s.course[i]);
			}
		}
		return os;
}
//copy constructor
Student::Student(Student & a)
{
	count=a.count;
	course=a.course;
	username=a.username;
	roll_number=a.roll_number;
	name=a.name;
	course=new Course*[2];
	for(int i=0;i<count;i++)
	{
		course[i]=a.course[i];
	}
}
// overloaded assignment operator
Student& Student::operator=(Student& a)
{
	count=a.count;
	course=a.course;
	username=a.username;
	roll_number=a.roll_number;
	name=a.name;
	if(course!=nullptr)
	{
		for(int i=0;i<count;i++)
		{
			delete course[i];
		}
		delete [] course;
	}
	else
	{
		course=new  Course*[4];
	   for(int i=0;i<count;i++)
	   {
		   course[i]=a.course[i];
	   }
	}
	return *this;
}
//default destructor 
Student::~Student()
{
	if(course!=nullptr)
	{
		for(int i=0;i<count;i++)
		{
			delete course[i];
		}
		delete [] course;
	}
}
//Function to frop course
void Student::dropcourse(Course* c)
{
	bool check=false;
	for(int i=0;i<count;i++)
	{
		if(course[i]!=c)
		{
			check=true;
		}
	}
	for(int i=0;i<count-1;i++)
	{
		if(course[i]==c)
		{
			course[i]->removeStudent(this);
			delete course[i];
			course[i]=nullptr;
			course[i]=course[i+1];
		}
	}
	if(check==true)
	{
		cout<<"Element not found ."<<endl;
	}
}