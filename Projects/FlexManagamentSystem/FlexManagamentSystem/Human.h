#pragma once
#ifndef Human_H
#define Human_H

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

struct Subject
{
	string subject;
	string T_id;
};

static string PATH = "C:/Users/DELL/OneDrive/Desktop/pf_lab_project/FlexManagamentSystem/FlexManagamentSystem/dataCenter/";

struct Date
{
	int month;
	int year;
	int day;
};

class Human//abstract class
{
protected:
	string Id, Password;
	char user;
public:
	Human();

	virtual ~Human(){}
	friend Human* sign_in();



	//for getting data of student or teacher from file
	virtual bool getData() = 0;
	virtual void displayMenu() = 0;
	void viewAllStudents();
	void viewAllTeachers();

	// for admin
	virtual void addStudent() {}
	virtual void addTeacher() {}
	virtual void editTeacherDetails() {}
	virtual void editStudentDetails() {}

	//for teacher module 
	virtual void TimeTable() {}
	virtual void AssignMarks() {}
	virtual void AddAtendence() {}
	virtual void AssignGrades() {}

	// for student module
	virtual void viewAttendence(){}
	virtual void viewMarks() {}
	virtual void viewGrades() {}
	virtual void viewRegiteredCourses() {}

	// for HOD 
	virtual void AsTeacher() {}
	virtual void activitiesOfTeacher() {}


};


class Admin :public Human
{
public:
	Admin() {}
	~Admin() {}

	bool getData()override;
	void displayMenu() override;
	void editStudentDetails() override;
	void editTeacherDetails() override;



};



class person :public Human
{
protected:
	string FirstName, LastName;
	char Gender;
	string ContactNo;
	string Address;
	string DepartmentName;
	Date RegistrationDate;
	string Blood_Group;
	string Qualification;
public:
	person()
	{
		FirstName = LastName = ContactNo = Address = Blood_Group = Qualification = "";
		DepartmentName = "";
		Gender = '\0';
		RegistrationDate.day = RegistrationDate.month = RegistrationDate.year = 0;
	}
	~person(){}

};



class teacher :public person
{
	string subject;
public:
	teacher(){}
	~teacher(){}
	void TimeTable()override;
	void AssignMarks()override;
	void AddAtendence()override;
	void AssignGrades()override;
	bool getData()override;
	void addTeacher()override;
	void displayMenu() override;
	friend class Human;
	friend class Admin;


};


class HOD : public teacher
{
public:
	HOD(){}
	~HOD(){}
	void displayMenu() override;
	void AsTeacher(){}
	void activitiesOfTeacher(){}

};


class student : public person
{
	vector<Subject> courses;
	string FeeStatus;
public:
	student();
	~student();
	void viewAttendence()override;
	void viewMarks()override;
	void viewGrades()override;
	void TimeTable()override;
	void viewRegiteredCourses() override;
	bool getData() override;
	void addStudent() override;
	void displayMenu() override;
	friend class Human;
	friend class Admin;
	friend class HOD;


};







ifstream& operator>(ifstream& in, string& s);
istream& operator>(istream& in, string& s);
istream& operator>>(istream& in, Date& s);
ifstream& operator>>(ifstream& in, Subject& s);


char sign_in(string& id, string& pass);
Human* sign_in();

string weekdays(int i);
string SlotsTime(int i);




#endif // !Human_H