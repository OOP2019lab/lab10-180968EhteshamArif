
#include"Course.h"
#include"Student.h"
using namespace std;
#pragma once
//respective main
int main()
{
	Student S1("1", "Anum", "11-1351");
	Student S2("2", "Sara", "12-6462");
	Student S3("3", "Sana", "11-4531");
	Student S4("4", "Zara", "12-4342");
	Student S5("5", "Hira", "11-5940");
	Course C1("OOP","CS102");
	Course C2("PF", "CS101");
	Course C3("AI","CS365");
	S1.addCourse(&C1);
	S1.addCourse(&C2);
	S1.addCourse(&C3);
	cout<<S1<<endl;
	cout<<C2<<endl;
	cout<<C1<<endl;
	cout<<S5<<endl;
	cout<<C1<<endl;
	cout<<C3<<endl;
	S5.dropcourse(&C1);
	//C3.removeStudent(&S4); //remove S4 from c3 but student cannot do that
	//C1.removeStudent(&S1);
	return 0;
}