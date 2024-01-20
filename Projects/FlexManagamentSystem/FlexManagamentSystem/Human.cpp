#include "Human.h"


Human::Human()
{
	Password = Id = "";
	user = '\0';
}
void Human::viewAllStudents()
{

	ifstream fin;
	fin.open((PATH + "Student/student.txt"));
	if (!fin.is_open())
	{
		cout << "-----File not found----" << endl;
		return;
	}
	int n;
	string id;
	student s;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> id;
		cout << i + 1 << ")" << endl;
		cout << "Id : " << id << '\t' << endl;
		s.Id = id;
		s.getData();
		cout << "Name : " << s.FirstName << ' ' << s.LastName << endl;
		cout << "Password : " << s.Password << endl;
		cout << "Department : " << s.DepartmentName << endl << endl;

	}
	fin.close();
	system("pause");
}
void Human::viewAllTeachers()
{
	ifstream fin;
	fin.open((PATH + "Teacher/teacher.txt"));
	if (!fin.is_open())
	{
		cout << "-----File not found----" << endl;
		return;
	}
	int n;
	string id;
	teacher t;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> id;
		cout << i + 1 << ")" << endl;
		cout << "Id : " << id << '\t' << endl;
		t.Id = id;
		t.getData();
		cout << "Name : " << t.FirstName << ' ' << t.LastName << endl;
		cout << "Password : " << t.Password << endl;
		cout << "Department : " << t.DepartmentName << endl;
		cout << "Subject : " << t.subject << endl << endl;
		fin >> id;
	}
	fin.close();
	system("pause");
}


bool Admin::getData()
{
	return 0;
}
void Admin::displayMenu()
{
	while (1)
	{
		system("cls");
		cout << "-----Welcome Admin----" << endl;
		cout << "\n\n\t\t1)Add a new student\n\t\t2)Add new Teacher\n\t\t3)Edit Student details\n\t\t4)Edit Teacher details\n\t\t5)View all Students\n\t\t6)View all Teacher\n\t\t7)log out" << endl << endl;
		switch (_getch())
		{
		case '1':
		{
			student s;
			s.addStudent();
			s.~student();
			break;
		}
		case '2':
		{
			teacher t;
			t.addTeacher();
			t.~teacher();
			break;
		}
		case '3':
		{
			editStudentDetails();
			break;
		}
		case '4':
		{
			editTeacherDetails();
			break;
		}
		case '5':
		{
			viewAllStudents();
			break;
		}
		case '6':
		{
			viewAllTeachers();
			break;
		}
		case '7':
		{
			return;
			break;
		}
		}
	}

}
void Admin::editStudentDetails()
{
	string id;
	viewAllStudents();
	cout << "\n\nEnter Id of student you want to change : ";
	cin >> id;
	student st;
	st.Id = id;
	if (!(st.getData()))
	{
		return;
	}
	try {

		cout << "Enter first name: ";
		cin > st.FirstName;
		cout << "Enter last name: ";
		cin > st.LastName;
		cout << "Enter gender (M/F): ";
		cin >> st.Gender;
		cout << "Enter contact number: ";
		cin >> st.ContactNo;
		cout << "Enter address: ";
		cin > st.Address;
		cout << "\nEnter registration date (DD MM YYYY): ";
		cin >> st.RegistrationDate;
		cout << "Enter blood group: ";
		cin >> st.Blood_Group;
		cout << "Enter qualification: ";
		cin > st.Qualification;
		cout << "Enter password: ";
		cin >> st.Password;
		cout << "Enter fee status: ";
		cin >> st.FeeStatus;



	}
	catch (const exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}
	int n;
	string* dat;

	string s = PATH + "Student/";
	//2) password file;
	ifstream fin;
	fin.open((PATH + (PATH + "password.txt")));
	fin >> n;
	dat = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > dat[i];
	}
	fin.close();


	ofstream fout;
	fout.open((PATH + "password.txt"));
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		if (st.Id == dat[i].substr(0, 8))
		{
			fout << st.Id << '\t' << user << '\t' << st.Password << endl;
			continue;
		}
		fout << dat[i] << endl;
	}
	fout << endl;
	fout.close();
	delete[]dat;



	//  3) make data file
	fout.open(s + st.Id + ".txt");
	fout << st.FirstName << endl
		<< st.LastName << endl
		<< st.ContactNo << endl
		<< st.Address << endl
		<< st.Blood_Group << endl
		<< st.Qualification << endl
		<< st.DepartmentName << endl
		<< st.FeeStatus << endl
		<< st.Gender << endl
		<< st.RegistrationDate.day << "\t" << st.RegistrationDate.month << "\t" << st.RegistrationDate.year << "\t" << endl << endl;

	fout.close();



}
void Admin::editTeacherDetails()

{
	string id;
	viewAllTeachers();
	cout << "\n\nEnter Id of teacher you want to change : ";
	cin >> id;
	teacher st;
	st.Id = id;
	if (!(st.getData()))
	{
		return;
	}
	try {

		cout << "Enter first name: ";
		cin > st.FirstName;
		cout << "Enter last name: ";
		cin > st.LastName;
		cout << "Enter gender (M/F): ";
		cin >> st.Gender;
		cout << "Enter contact number: ";
		cin >> st.ContactNo;
		cout << "Enter address: ";
		cin > st.Address;
		cout << "\nEnter registration date (DD MM YYYY): ";
		cin >> st.RegistrationDate;
		cout << "Enter blood group: ";
		cin >> st.Blood_Group;
		cout << "Enter qualification: ";
		cin > st.Qualification;
		cout << "Enter password: ";
		cin >> st.Password;
		ifstream fin;
		fin.open(PATH + "Teacher/subjects.txt");
		int n, n2;
		fin >> n;
		string* sub = new string[n];

		cout << endl << endl;
		for (int i = 0; i < n; i++)
		{
			fin >> sub[i];
			cout << i + 1 << ") " << sub[i] << endl;
		}
		do
		{
			cout << "Enter the Subject :";
			cin >> n2;
			if (!(n2 > 0 && n2 <= n))
			{
				cout << "Enter corectly!" << endl;
			}
		} while (!(n2 > 0 && n2 <= n));
		st.subject = sub[n2 - 1];
		delete[]sub;



	}
	catch (const exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}





	int n;
	string* dat;

	string s = PATH + "Teacher/";
	//2) password file;
	ifstream fin;
	fin.open((PATH + "password.txt"));
	fin >> n;
	dat = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > dat[i];
	}
	fin.close();


	ofstream fout;
	fout.open((PATH + "password.txt"));
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		if (st.Id == dat[i].substr(0, 7))
		{
			fout << st.Id << '\t' << st.user << '\t' << st.Password << endl;
			continue;
		}
		fout << dat[i] << endl;
	}
	fout << endl;
	fout.close();
	delete[]dat;
	dat = nullptr;



	fin.open(s + "teacher.txt");
	if (!fin.is_open())
	{
		cout << "teacher file not found!" << endl;
		return;
	}
	fin >> n;
	dat = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > dat[i];
	}
	fin.close();

	fout.open(s + "teacher.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		if (st.Id == dat[i].substr(0, 7))
		{
			fout << st.Id << '\t' << st.subject << endl;
			continue;
		}
		fout << dat[i] << endl;
	}
	fout.close();
	delete[]dat;
	dat = nullptr;





	//  3) make data file
	fout.open(s + st.Id + ".txt");
	fout << st.FirstName << endl
		<< st.LastName << endl
		<< st.ContactNo << endl
		<< st.Address << endl
		<< st.Blood_Group << endl
		<< st.Qualification << endl
		<< st.DepartmentName << endl
		<< st.subject << endl
		<< st.Gender << endl
		<< st.RegistrationDate.day << "\t" << st.RegistrationDate.month << "\t" << st.RegistrationDate.year << "\t" << endl << endl;

	fout.close();
	system("pause");


}


bool teacher::getData()
{
	string path = PATH + "Teacher/" + Id + ".txt";
	//cout << path << endl;
	ifstream fin;
	fin.open(path);
	if (!(fin.is_open()))
	{
		cout << "data not found" << endl;
		return 0;
	}
	fin > FirstName > LastName > ContactNo > Address > Blood_Group > Qualification > DepartmentName > subject;
	fin >> Gender >> RegistrationDate.day >> RegistrationDate.month >> RegistrationDate.year;
	//	cout << FirstName << '\t' << LastName << '\t' << '\t' << ContactNo << '\t' << Address << '\t' << Blood_Group << '\t' << Qualification << '\t' << DepartmentName << '\t' << Gender << '\t' << RegistrationDate.day << '\t' << RegistrationDate.month << '\t' << RegistrationDate.year;

	fin.close();


	fin.open((PATH + "password.txt"));
	if (fin.is_open())
	{
		int n;
		fin >> n;
		string id;
		for (int i = 0; i < n; i++)
		{
			fin >> id >> user >> Password;
			if (id == Id)
			{
				break;
			}
		}
	}
	return 1;
}
void teacher::addTeacher()
{
	int n;
	string* st;
	string dp = "FF";

	string s = PATH + "Teacher/";


	// input all data members name last name etc;
	//

	cout << "----Adding new teacher-----" << endl;
	try {


		cout << "Enter first name: ";
		cin > FirstName;
		cout << "Enter last name: ";
		cin > LastName;
		cout << "Enter gender (M/F): ";
		cin >> Gender;
		cout << "Enter contact number: ";
		cin >> ContactNo;
		cout << "Enter address: ";
		cin > Address;

		do
		{
			cout << "\nEnter department \n\n1)Computer Science\n2) Electric Engineering\n3) Software Engineering\n4) Business Management\n5) Social Sciences\n Enter your choice (1-5) :  ";
			cin >> n;
			if (!(n > 0 && n < 6))
			{
				cout << "Enter corectly  " << endl;
			}
		} while (!(n > 0 && n < 6));
		switch (n)
		{
		case 1:
			DepartmentName = "Computer Science";
			dp = "CS";
			break;
		case 2:
			DepartmentName = "Electric Engineering";
			dp = "EE";
			break;
		case 3:
			DepartmentName = "Software Engineering";
			dp = "SE";
			break;
		case 4:
			DepartmentName = "Business Management";
			dp = "BM";
			break;
		case 5:
			DepartmentName = "Social Sciences";
			dp = "SC";
			break;
		}

		cout << "\nEnter registration date (DD MM YYYY): ";
		cin >> RegistrationDate;
		cout << "Enter blood group: ";
		cin >> Blood_Group;
		cout << "Enter qualification: ";
		cin > Qualification;
		cout << "Enter password: ";
		cin >> Password;
		ifstream fin;
		fin.open(PATH + "Teacher/subjects.txt");
		int n, n2;
		fin >> n;
		string* sub = new string[n];

		cout << endl << endl;
		for (int i = 0; i < n; i++)
		{
			fin >> sub[i];
			cout << i + 1 << ") " << sub[i] << endl;
		}
		do
		{
			cout << "Enter the Subject :";
			cin >> n2;
			if (!(n2 > 0 && n2 <= n))
			{
				cout << "Enter corectly!" << endl;
			}
		} while (!(n2 > 0 && n2 <= n));
		subject = sub[n2 - 1];
		delete[]sub;

		user = 't';



	}
	catch (const exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}





	// getting teacher data
	ifstream fin;
	fin.open(s + "teacher.txt");
	if (!fin.is_open())
	{
		cerr << "teacher file not found!" << endl;
		return;
	}
	fin >> n;
	st = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > st[i];
	}
	fin.close();



	// generating  ID
	int num = 0;

	for (int i = 0; i < n; i++)
	{
		if (dp == st->substr(0, 2))
		{
			if (num < stoi((st->substr(3, 4))))
			{
				num = stoi((st->substr(3, 4)));
			}
		}
	}

	num++;
	n++;
	string id = to_string(num);
	for (; id.length() < 4;)
	{
		id.insert(id.begin(), '0');
	}
	Id = dp + "-" + id;



	//1) teacher file
	ofstream fout;
	fout.open(s + "teacher.txt");
	fout << n << endl;
	for (int i = 0; i < n - 1; i++)
	{
		fout << st[i] << endl;
	}
	fout << Id << '\t' << subject << endl;
	fout.close();
	delete[]st;
	st = nullptr;

	//2) password file;
	fin.open((PATH + "password.txt"));
	fin >> n;
	st = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > st[i];
	}
	fin.close();

	fout.open((PATH + "password.txt"));
	fout << (n + 1);
	fout << endl;
	for (int i = 0; i < n; i++)
	{
		fout << st[i] << endl;
	}
	fout << Id << '\t' << user << '\t' << Password << endl;
	fout << endl;
	fout.close();
	delete[]st;
	st = nullptr;


	//  3) make data file
	fout.open(s + Id + ".txt");
	fout << FirstName << endl
		<< LastName << endl
		<< ContactNo << endl
		<< Address << endl
		<< Blood_Group << endl
		<< Qualification << endl
		<< DepartmentName << endl
		<< subject << endl
		<< Gender << endl
		<< RegistrationDate.day << '\t' << RegistrationDate.month << '\t' << RegistrationDate.year << '\t' << endl << endl;

	fout.close();





	// Print the entered values
	cout << "\nEntered values:\n";
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Contact Number: " << ContactNo << endl;
	cout << "Address: " << Address << endl;
	cout << "Department Name: " << DepartmentName << endl;
	cout << "Registration Date: " << RegistrationDate.day << " "
		<< RegistrationDate.month << " " << RegistrationDate.year << endl;
	cout << "Blood Group: " << Blood_Group << endl;
	cout << "Qualification: " << Qualification << endl;
	cout << "Subject : " << subject << endl;
	cout << "ID: " << Id << endl;
	cout << "Password: " << Password << endl;


	fout.open(s + Id + "_marks.txt");
	fout.close();
	fout.open(s + Id + "_attendence.txt");
	fout.close();

		system("pause");



}
void teacher::AssignMarks()
{
	string s,s2;
	ofstream fout;
	ifstream fin;
	fout.open(PATH + "Teacher/" + Id + "_marks.txt");
	fin.open(PATH + "Student/subjects.txt");
	while (!fin.eof())
	{
		fin > s > s2;
		remove(s2.begin(), s2.end(), ' ');
		remove(s2.begin(), s2.end(), '\t');

		if (s2.find((Id + subject))!=-1)
		{
			int n;
			cout << "Marks of " << s << " : ";
			cin >> n;
			fout << s << '\t' << n << '\t' << 'I' << endl;

		}
		

		if (fin.peek() == '\n')
			fin.ignore();
	}
	fin.close();
	fout.close();
}
void teacher::AssignGrades()
{
	vector<string> id, grade;
	vector<int> marks;
	ifstream fin;
	string s1, s2;
	int n;

	fin.open(PATH + "Teacher/" + Id + "_marks.txt");
	while (!fin.eof())
	{
		fin >> s1 >>n >> s2;
		id.push_back(s1);
		grade.push_back(s2);
		marks.push_back(n);
		for(;fin.peek() == '\n';)
			fin.ignore();
	}
	fin.close();
	for (int i = 0; i < id.size(); i++)
	{
		switch (marks[i] / 10)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			grade[i] = "F";
		case 4:
			grade[i] = "C";
			break;
		case 5:
			grade[i] = "C+";
			break;
		case 6:
			grade[i] = "B";
			break;
		case 7:
			grade[i] = "B+";
			break;
		case 8:
			grade[i] = "A";
			break;
		case 9:
		case 10:
			grade[i] = "A+";
			break;
		default:
			grade[i] = "I";
		}
	}
	ofstream fout;
	fout.open(PATH + "Teacher/" + Id + "_marks.txt");
	for (int i = 0; i < id.size(); i++)
	{
		fout << id[i] << "\t" << marks[i] << '\t' << grade[i] << endl;
		cout << id[i] << "\t" << marks[i] << '\t' << grade[i] << endl;
	}
	fout.close();
}
void teacher::AddAtendence()
{
	string s, s2;
	ofstream fout;
	ifstream fin;
	fout.open(PATH + "Teacher/" + Id + "_attendence.txt", ios::app);
	fin.open(PATH + "Student/subjects.txt");
	Date d;
	cout << "Enter attendence date (DD MM YYYY) : ";
	cin >> d;
	fout << d.day << '-' << d.month << '-' << d.year << endl;
	while (!fin.eof())
	{
		fin > s > s2;
		remove(s2.begin(), s2.end(), ' ');
		remove(s2.begin(), s2.end(), '\t');

		if (s2.find((Id + subject)) != -1)
		{
			char c;
			cout << "Attendence  of " << s << "  ( p/a/l ) : ";
			cin >> c;
			fout << s << c << '\t';

		}


		if (fin.peek() == '\n')
			fin.ignore();
	}
	fout << endl;
	fin.close();
	fout.close();
}
void teacher::TimeTable()
{
	const int rooms = 10;
	const int days = 6;
	const int slots = 5;

	string s = Id + "_" + subject;


	string*** timetable = new string * *[days];
	for (int i = 0; i < days; i++)
	{
		timetable[i] = new string * [slots];
		for (int j = 0; j < slots; j++)
		{
			timetable[i][j] = new string[rooms];
		}
	}

	ifstream fin;
	fin.open(PATH + "TimeTable.txt");
	for (int i = 0; i < days; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			for (int k = 0; k < rooms; k++)
			{
				fin >> timetable[i][j][k];
			}
		}
	}
	fin.close();


	for (int i = 0; i < days; i++)
	{
		cout <<"\t" << weekdays(i + 1) << endl;
		for (int j = 0; j < slots; j++)
		{
			for (int k = 0; k < rooms; k++)
			{
				if (timetable[i][j][k] == s)
					cout << SlotsTime(j + 1) << " : " << s << ":in room " << k + 1 << endl;

			}
		}
		cout << endl << endl;
	}

	char op;
	cout << "\n\n1) Add lecture\n2) Remove a lecture\n3)back\n";
	op = _getch();
	if (op == '1')
	{
		system("cls");
		int n1, n2, n3;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ") " << weekdays(i + 1) << endl;
		}
		do
		{
			cout << "\nEnter the day in which you want to add lecture : ";
			cin >> n1;
			if (!(n1 > 0 && n1 <= 6))
			{
				cout << "Enter corectly" << endl;
			}
		} while (!(n1 > 0 && n1 <= 6));
		n1--;

		do
		{
			cout << "\nEnter the slot nunmber from (1-5) in which you want to add lecture : ";
			cin >> n2;
			if (!(n2 > 0 && n2 <= 5))
			{
				cout << "Enter corectly" << endl;
			}
		} while (!(n2 > 0 && n2 <= 5));
		n2--;

		cout << "Free Rooms  are : ";
		for (int k = 0; k < rooms; k++)
		{
			if (timetable[n1][n2][k] == "NA")
				cout << k + 1 << ',';
		}
		do
		{
			cout << "Enter the Room  no : ";
			cin >> n3;
			if (!(n3 > 0 && n3 < 10))
			{
				cout << "Enter correctly " << endl;
				continue;
			}
			if (timetable[n1][n2][n3] != "NA")
			{
				cout << "Enter correctly " << endl;
				continue;
			}
			break;
		} while (1);
		n3--;
		timetable[n1][n2][n3] = s;
		cout << "Lecture added successfully" << endl;

	}
	else if (op == '2')
	{
		system("cls");
		int count = 1;
		for (int i = 0; i < days; i++)
		{
			for (int j = 0; j < slots; j++)
			{
				for (int k = 0; k < rooms; k++)
				{
					if (timetable[i][j][k] == s)
					{
						cout << count << ") " << weekdays(i + 1) << "\t" << SlotsTime(j + 1) << " : " << s << ":in room " << k + 1 << endl;
						count++;
					}

				}
			}
		}
		int n;
		do
		{
			cout << "Enter the lecture no to remove : ";
			cin >> n;
			if (!(n > 0 && n <= count))
			{
				cout << "Enter corectly" << endl;
			}
		} while (!(n > 0 && n <= count));


		for (int i = 0; i < days && n != 0; i++)
		{
			for (int j = 0; j < slots && n != 0; j++)
			{
				for (int k = 0; k < rooms && n != 0; k++)
				{
					if (timetable[i][j][k] == s)
					{
						if (n == 1)
						{
							timetable[i][j][k] = "NA";
							cout << "Lecture removed successfully" << endl;
						}
						n--;
					}

				}
			}
		}

	}

	ofstream fout;
	fout.open(PATH + "TimeTable.txt");
	for (int i = 0; i < days; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			for (int k = 0; k < rooms; k++)
			{
				fout << timetable[i][j][k] << '\t';
			}
			fout << endl;
		}
		fout << endl << endl;
	}
	fout.close();



	for (int i = 0; i < days; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			delete[]timetable[i][j];
		}
		delete[]timetable[i];
	}
	delete[]timetable;


}
void teacher::displayMenu()
{
	while (1)
	{
		system("cls");
		cout << "-----Welcome  " << FirstName << " " << LastName << "----" << endl;
		cout << "\n\n\t\t1)Teacher Time Table\n\t\t2)Assign Marks\n\t\t3)Marking Attendance\n\t\t4)Assign Grades\n\t\t5)log out" << endl << endl;
		switch (_getch())
		{
		case '1':
		{
			TimeTable();
			system("pause");
			break;
		}
		case '2':
		{
			AssignMarks();
			system("pause");
			break;
		}
		case '3':
		{
			AddAtendence();
			break;
		}
		case '4':
		{
			AssignGrades();
			system("pause");
			break;
		}
		case '5':
		{
			return;
			break;
		}
		}
	}

}



student::student() 
{
}
student::~student()
{
	courses.clear();

}
bool student::getData()
{
	string path = PATH + "Student/" + Id + ".txt";
	//cout << path<<endl;
	ifstream fin;
	fin.open(path);
	if (!(fin.is_open()))
	{
		cout << "data not found" << endl;
		return 0;
	}
	fin > FirstName > LastName > ContactNo > Address > Blood_Group > Qualification > DepartmentName > FeeStatus;
	fin >> Gender >> RegistrationDate.day >> RegistrationDate.month >> RegistrationDate.year;
	//cout << FirstName << '\t' << LastName << '\t' << '\t' << ContactNo << '\t' << Address << '\t' << Blood_Group << '\t' << Qualification << '\t' << DepartmentName << '\t' << FeeStatus << '\t' << Gender << '\t' << RegistrationDate.day << '\t' << RegistrationDate.month << '\t' << RegistrationDate.year;

	fin.close();


	fin.open((PATH + "password.txt"));
	if (fin.is_open())
	{
		int n;
		fin >> n;
		string id;
		for (int i = 0; i < n; i++)
		{
			fin >> id >> user >> Password;
			if (id == Id)
			{
				break;
			}
		}
	}
	fin.close();


	string id;
	fin.open(PATH + "Student/subjects.txt");
	while (!fin.eof())
	{
		fin > id;
		if (id == Id)
		{
			Subject temp;
			while (fin.peek() != '\n' && !(fin.eof()))
			{
				fin >> temp;
				courses.push_back(temp);
			}
			break;
		}
		fin > id;
	}
	fin.close();

	

	return 1;
}
void student::viewAttendence()
{
	system("cls");
	cout << "-----Viewing attendence-----" << endl << endl << endl;
	int op;
	for (int i = 0; i < courses.size(); i++)
	{
		cout << i + 1 << ") " << courses[i].subject << endl;
	}
	do
	{
		cout << "Enter the course no : ";
		cin >> op;
		if (!(op > 0 && op <= courses.size()))
		{
			cout << "Enter correctly " << endl;
		}
	} while (!(op > 0 && op <= courses.size()));
	op--;


	ifstream fin;
	string s1, s2;
	fin.open(PATH + "Teacher/" + courses[op].T_id + "_attendence.txt");
	while (!fin.eof())
	{
		s1 = s2 = "";
		fin > s1 > s2;
		cout << s1 << " : ";
		if (s2.find(Id) != -1)
		{
			cout << s2[s2.find(Id) + 8] << endl;
		}
		else
		{
			cout << " Attendence not found (can be due to late registration)" << endl;
		}
		for (; fin.peek() == '\n';)
			fin.ignore();

	}
	fin.close();

}
void student::addStudent()
{


	// input all data members name last name etc;


	try {


		cout << "Enter first name: ";
		cin > FirstName;
		cout << "Enter last name: ";
		cin > LastName;
		cout << "Enter gender (M/F): ";
		cin >> Gender;
		cout << "Enter contact number: ";
		cin >> ContactNo;
		cout << "Enter address: ";
		cin > Address;
		{
			int n;
			do
			{
				cout << "Enter department \n1)Computer Science\n2) Electric Engineering\n3) Software Engineering\n4) Business Management\n5) Social Sciences\n Enter your choice (1-5) :  ";
				cin >> n;
				if (!(n > 0 && n < 6))
				{
					cout << "Enter corectly  " << endl;
				}
			} while (!(n > 0 && n < 6));
			switch (n)
			{
			case 1:
				DepartmentName = "Computer Science";
				break;
			case 2:
				DepartmentName = "Electric Engineering";
				break;
			case 3:
				DepartmentName = "Software Engineering";
				break;
			case 4:
				DepartmentName = "Business Management";
				break;
			case 5:
				DepartmentName = "Social Sciences";
				break;
			}
		}

		cout << "\nEnter registration date (DD MM YYYY): ";
		cin >> RegistrationDate;
		cout << "Enter blood group: ";
		cin >> Blood_Group;
		cout << "Enter qualification: ";
		cin > Qualification;
		cout << "Enter password: ";
		cin >> Password;
		cout << "Enter fee status: ";
		cin >> FeeStatus;

		user = 's';



	}
	catch (const exception& e)
	{
		cerr << "Exception: " << e.what() << endl;
	}


	int n;
	int year = 22;
	string* st;

	string s = PATH + "Student/";



	// getting student data
	ifstream fin;
	fin.open(s + "student.txt");
	if (!fin.is_open())
	{
		cout << "Student file not found!" << endl;
		return;
	}
	fin >> n;
	st = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin >> st[i];
	}
	fin.close();




	// generating  ID
	n++;
	for (; n > 9999;)
	{
		year++;
		n -= 9999;
	}
	string id = to_string(n);
	for (; id.length() < 4;)
	{
		id.insert(id.begin(), '0');
	}
	Id = to_string(year) + "F-" + id;





	//making data file and saving data

	//1) student file
	ofstream fout;
	fout.open(s + "student.txt");
	fout << n << endl;
	for (int i = 0; i < n - 1; i++)
	{
		fout << st[i] << endl;
	}
	fout << Id << endl;
	fout.close();
	delete[]st;
	st = nullptr;



	//2) password file;
	fin.open((PATH + "password.txt"));
	fin >> n;
	st = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin > st[i];
	}
	fin.close();



	fout.open((PATH + "password.txt"));
	fout << (n + 1) << endl;
	for (int i = 0; i < n; i++)
	{
		fout << st[i] << endl;
	}
	fout << Id << '\t' << user << '\t' << Password;
	fout << endl;
	fout.close();
	delete[]st;



	//  3) make data file
	fout.open(s + Id + ".txt");
	fout << FirstName << endl
		<< LastName << endl
		<< ContactNo << endl
		<< Address << endl
		<< Blood_Group << endl
		<< Qualification << endl
		<< DepartmentName << endl
		<< FeeStatus << endl
		<< Gender << endl
		<< RegistrationDate.day << "\t" << RegistrationDate.month << "\t" << RegistrationDate.year << "\t" << endl << endl;
	fout << 0 << endl;
	fout.close();


	// Print the entered values
	cout << "\nEntered values:\n";
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Gender: " << Gender << endl;
	cout << "Contact Number: " << ContactNo << endl;
	cout << "Address: " << Address << endl;
	cout << "Department Name: " << DepartmentName << endl;
	cout << "Registration Date: " << RegistrationDate.day << " "
		<< RegistrationDate.month << " " << RegistrationDate.year << endl;
	cout << "Blood Group: " << Blood_Group << endl;
	cout << "Qualification: " << Qualification << endl;
	cout << "ID: " << Id << endl;
	cout << "Password: " << Password << endl;
	cout << "Fee Status: " << FeeStatus << endl;
	system("pause");

}
void student::viewMarks()
{
	 ifstream fin;
	 string s1, s2;
	 int n;
	 bool find;
	 for (int i = 0; i < courses.size(); i++)
	 {
		 s1 = s2 = "";
		 n = 0;
		 find = false;
		 fin.open(PATH + "Teacher/" + courses[i].T_id + "_marks.txt");
		 while (!fin.eof())
		 {
			 fin >> s1 >> n >> s2;
			 if (s1 == Id)
			 {
				 cout << courses[i].subject << " marks are : " << n << endl;
				 find = true;
				 break;
			 }
		 }
		 fin.close();
		 if (!find)
		 {
			 cout << courses[i].subject << "  Marks are not uploaded yet " << endl;
		 }
	 }

}
void student::viewGrades()
{
	ifstream fin;
	string s1, s2;
	int n;
	bool find;
	for (int i = 0; i < courses.size(); i++)
	{
		s1 = s2 = "";
		n = 0;
		find = false;
		fin.open(PATH + "Teacher/" + courses[i].T_id + "_marks.txt");
		while (!fin.eof())
		{
			fin >> s1 >> n >> s2;
			if (s1 == Id && s2!="I")
			{
				cout << courses[i].subject << "\tMarks : " << n << "\tGrade : " << s2 << endl;
				find = true;
				break;
			}
		}
		fin.close();
		if (!find)
		{
			cout << courses[i].subject << "  Grades are not uploaded yet " << endl;
		}
	}

}
void student::viewRegiteredCourses()
{
	cout << "You have registered following courses : " << endl;
	for (int i = 0; i < courses.size(); i++)
	{
		cout << i + 1 << ") " << courses[i].subject << "   by teacher  " << courses[i].T_id << endl;
	}

	
	cout << "\n\nIf you want to register another course then press y otherwise n : ";
	//getting available courses with teacher id  
	if (_getch() != 'y')
	{
		return;
	}
	system("cls");
	cout << "Courses available to register : " << endl;
	ifstream fin;
	fin.open(PATH + "Teacher/teacher.txt");
	int n, n2;
	fin >> n;
	Subject* sub = new Subject[n];
	for (int i = 0; i < n; i++)
	{
		fin >> sub[i];
		cout << i + 1 << ") " << sub[i].subject << " By teacher " << sub[i].T_id << endl;
	}
	fin.close();
	do
	{
		cout << "Enter the Subject :";
		cin >> n2;
		if (!(n2 > 0 && n2 <= n))
		{
			cout << "Enter corectly!" << endl;
			continue;
		}
	
	} while (!(n2 > 0 && n2 <= n));

	n2--;

	for (int i = 0; i < courses.size(); i++)
	{
		if (sub[n2].T_id == courses[i].T_id && sub[n2].subject == courses[i].subject)
		{
			cout << "Course already registered " << endl;
			delete[]sub;
			system("pause");
			return;
		}
	}



	//adding coure to student file

	vector<string> dat;
	string temp;
	fin.open(PATH + "Student/subjects.txt");
	while (!fin.eof())
	{
		fin > temp;
		dat.push_back(temp);
		if (fin.peek() == '\n')
			fin.ignore();
	}
	fin.close();
	ofstream fout;
	fout.open(PATH + "Student/subjects.txt");
	bool ok = true;
	for (int i = 0; i < dat.size(); i++)
	{
		fout << dat[i] << endl;
		if (dat[i] == Id) 
		{
			ok = false;
			fout << sub[n2].T_id << ' ' << sub[n2].subject << '\t';
		}
	}
	if (ok)
		fout << Id << endl << sub[n2].T_id << ' ' << sub[n2].subject;

	fout.close();
	delete[]sub;


	// updating student data course
	courses.clear();
	string id;
	fin.open(PATH + "Student/subjects.txt");
	while (!fin.eof())
	{
		fin > id;
		if (id == Id)
		{
			Subject temp;
			while (fin.peek() != '\n' && !(fin.eof()))
			{
				fin >> temp;
				courses.push_back(temp);
			}
			break;
		}
		fin > id;
	}
	fin.close();



}
void student::TimeTable()

{
	const int rooms = 10;
	const int days = 6;
	const int slots = 5;

	string s = "";

	string*** timetable = new string * *[days];
	for (int i = 0; i < days; i++)
	{
		timetable[i] = new string * [slots];
		for (int j = 0; j < slots; j++)
		{
			timetable[i][j] = new string[rooms];
		}
	}

	ifstream fin;
	fin.open(PATH + "TimeTable.txt");
	for (int i = 0; i < days; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			for (int k = 0; k < rooms; k++)
			{
				fin >> timetable[i][j][k];
			}
		}
	}
	fin.close();


	for (int i = 0; i < days; i++)
	{
		cout << "\t" << weekdays(i + 1) << endl;
		for (int j = 0; j < slots; j++)
		{
			for (int k = 0; k < rooms; k++)
			{
				for (int l = 0; l < courses.size(); l++)
				{
					s = courses[l].T_id + "_" + courses[l].subject;

					if (timetable[i][j][k] == s)
						cout << SlotsTime(j + 1) << " : " << s << ":in room " << k + 1 << endl;
				}
			}
		}
		cout << endl << endl;
	}

	for (int i = 0; i < days; i++)
	{
		for (int j = 0; j < slots; j++)
		{
			delete[]timetable[i][j];
		}
		delete[]timetable[i];
	}
	delete[]timetable;


}
void student::displayMenu()
{
	while (1)
	{
		system("cls");
		cout << "-----Welcome " << FirstName << " " << LastName << "----" << endl;
		cout << "\n\n\t\t1)View Attendance\n\t\t2)View Marks\n\t\t3)View Grades\n\t\t4)View Registered Courses\n\t\t5)View fee status\n\t\t6)View Time table\n\t\t7)log out" << endl << endl;
		switch (_getch())
		{
		case '1':
		{
			viewAttendence();
			system("pause");
			break;
		}
		case '2':
		{
			viewMarks();
			system("pause");
			break;
		}
		case '3':
		{
			viewGrades();
			system("pause");
			break;
		}
		case '4':
		{
			viewRegiteredCourses();
			system("pause");
			break;
		}
		case '5':
		{
			cout << "\nFee status : " << FeeStatus << endl << endl;
			system("pause");
			break;
		}
		case '6':
		{
			TimeTable();
			system("pause");
			break;
		}
		case '7':
		{
			return;
			break;
		}
		}
	}

}




void HOD::displayMenu()
{


	while (1)
	{
		system("cls");
		cout << "-----Welcome HOD----" << endl;
		cout << "\n\n\t\t1)HoD as teacher\n\t\t2)View all students\n\t\t3)View all teachers\n\t\t4)log out" << endl << endl;
		switch (_getch())
		{
		case '1':
		{
			teacher::displayMenu();
			break;
		}
		case '2':
		{
			viewAllStudents();
			break;
		}
		case '3':
		{
			viewAllTeachers();
			break;
		}
		case '4':
		{
			return;
			break;
		}
		}
	}


}






ifstream& operator>(ifstream& in, string& s)
{
	if (in.peek() == '\n')
		in.ignore();
	getline(in >> ws, s);
	return in;
}
istream& operator>(istream& in, string& s)
{
	if (in.peek() == '\n')
		in.ignore();
	getline(in >> ws, s);
	return in;
}
istream& operator>>(istream& in, Date& s)
{
	bool ok;
	do
	{
		ok = false;
		in >> s.day >> s.month >> s.year;
		if (!(s.day > 0 && s.day < 32))
		{
			cout << "Invalid day. Please Enter again :" << endl;
			ok = true;
		}
		if (!(s.month > 0 && s.month < 13))
		{
			cout << "Invalid month. Please Enter again :" << endl;
			ok = true;
		}
		if (!(s.year > 1990))
		{
			cout << "Invalid year. Please Enter again :" << endl;
			ok = true;
		}

	} while (ok);
	return in;
}
ifstream& operator>>(ifstream& in, Subject& s)
{
	in >> s.T_id >> s.subject;
	return in;
}


char sign_in(string& id, string& pass)
{
	string temp1, temp2;

	cout << "Enter Username/Id: ";
	cin >> temp1;
	cout << "Enter Password: ";
	cin >> temp2;

	ifstream fin;
	fin.open(( (PATH + "password.txt")));
	if (!(fin.is_open()))
	{
		cout << "Password file not found" << endl;
		exit(0);
	}
	int num;
	fin >> num;
	char ch;
	//cout << num;

	for (int i = 0; i < num; i++)
	{
		fin >> id >> ch >> pass;
		//cout << id << ch << pass;
		if (temp1 == id && temp2 == pass)
		{
			fin.close();
			return ch;
		}

	}
	fin.close();
	return '\0';

}
Human* sign_in()
{
	Human* user = nullptr;
	char us;
	string id, pass;
	us = sign_in(id, pass);
	//cout << us;
	switch (us)
	{
	case '\0':
		cout << "Incorrect id/Password" << endl;
		exit(0);
	case 'a':
		user = new Admin;
		break;
	case 'h':
		user = new HOD;
		break;
	case 't':
		user = new teacher;
		break;
	case 's':
		user = new student;
		break;
	}
	user->Id = id;
	user->Password = pass;
	user->user = us;
	return user;
}





string weekdays(int i)
{
	switch (i)
	{
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thrusday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	case 7:
		return "Sunday";
	default:
		return "";
	}
}


string SlotsTime(int i)
{
	switch (i)
	{
	case 1:
		return "8:30 to 10:00";
	case 2:
		return "10:00 to 11:30";
	case 3:
		return "11:30 to 1:00";
	case 4:
		return "1:30 to 3:00";
	case 5:
		return "3:00 to 4:30";
	default:
		return "";
	}
}

