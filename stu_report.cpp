#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>

using namespace std;


//***************************************************************
//                   CLASS USED IN PROJECT
//***************************************************************

class student
{
	double avg_per;
	int rollno;
	char name[50];
	int p_marks, c_marks, m_marks, e_marks, cs_marks, data_marks, os_marks, obo_marks;
	double per;
	char grade;
	void calculate(); //function to calculate grade

public:
	void getdata();		//function to accept data from user
	void showdata() const;	//function to show data on screen
	void show_tabular() const;
	int retrollno() const;
	double average();
	void getdataFromTxt();

}; //class ends here

void student::calculate()
{
	per = (p_marks + c_marks + m_marks + e_marks + cs_marks + data_marks + os_marks + obo_marks) / 8.00;

	if (per >= 90)
		grade = 'A';
	else if (per >= 80)
		grade = 'B';
	else if (per >= 70)
		grade = 'C';
	else if (per >= 60)
		grade = 'D';
	else
		grade = 'F';
}


void student::getdata()
{
	cout << "\nEnter The roll number of student ";
	cin >> rollno;
	cout << "\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "\nEnter The marks in physics out of 100 : ";
	cin >> p_marks;
	cout << "\nEnter The marks in chemistry out of 100 : ";
	cin >> c_marks;
	cout << "\nEnter The marks in maths out of 100 : ";
	cin >> m_marks;
	cout << "\nEnter The marks in english out of 100 : ";
	cin >> e_marks;
	cout << "\nEnter The marks in computer science out of 100 : ";
	cin >> cs_marks;
	cout << "\nEnter The marks in Database Design out of 100 : ";
	cin >> data_marks;
	cout << "\nEnter The marks in Operating System out of 100 : ";
	cin >> os_marks;
	cout << "\nEnter The marks in Object Oriented Programming out of 100 : ";
	cin >> obo_marks;
	calculate();
}

void student::showdata() const
{
	cout << "\nRoll number of student : " << rollno;
	cout << "\nName of student : " << name;
	cout << "\nMarks in Physics : " << p_marks;
	cout << "\nMarks in Chemistry : " << c_marks;
	cout << "\nMarks in Maths : " << m_marks;
	cout << "\nMarks in English : " << e_marks;
	cout << "\nMarks in Computer Science :" << cs_marks;
	cout << "\nPercentage of student is  :" << per;
	cout << "\nGrade of student is :" << grade;
}

void student::show_tabular() const
{
	cout << rollno << setw(6) << " " << name << setw(8) << p_marks << setw(4) << c_marks << setw(4) << m_marks << setw(4)
		<< e_marks << setw(4) << cs_marks << setw(4) << data_marks << setw(4) << os_marks << setw(4) << obo_marks << setw(8) << per << setw(6) << grade << endl;
}

double student::average()
{
	return per;
}


int  student::retrollno() const
{
	return rollno;
}



void write_student();	//write the record in binary file
void display_all();	//read all records from binary file
void display_all2();
void display_sp2(int);
void display_sp(int);	//accept rollno and read record from binary file
void modify_student(int);	//accept rollno and update record of binary file
void delete_student(int);	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void class_result2();
void intro();		//display welcome screen

void AdminLogin();
void adminLoginData();
void stu_login();
void stu_loginData();
void AdminMenu();
void StudentMenu();

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	cout.setf(ios::fixed | ios::showpoint);
	cout << setprecision(2); // program outputs decimal number to two decimal places
	intro();
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. Admin Login";
		cout << "\n\n\t02. Student Login";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> ch;
		switch (ch)
		{
		case '1': AdminLogin();
			break;
		case '2': stu_login();
			break;
		case '3':
			break;
		default:cout << "\a";
		}
	} while (ch != '4');
	return 0;
}


//***************************************************************
//    	function to write in file
//****************************************************************

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat", ios::binary | ios::app);
	st.getdata();
	outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
	outFile.close();
	cout << "\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();

	return AdminMenu();
}

//***************************************************************
//    	function to read all records from file
//****************************************************************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return AdminMenu();
	}
	cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.showdata();
		cout << "\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
	return AdminMenu();
}

void display_all2()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return StudentMenu();
	}
	cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.showdata();
		cout << "\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
	return StudentMenu();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return AdminMenu();
	}
	bool flag = false;
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		if (st.retrollno() == n)
		{
			st.showdata();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nrecord not exist";
	cin.ignore();
	cin.get();
	return AdminMenu();
}

void display_sp2(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return StudentMenu();
	}
	bool flag = false;
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		if (st.retrollno() == n)
		{
			st.showdata();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nrecord not exist";
	cin.ignore();
	cin.get();
	return StudentMenu();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_student(int n)
{
	bool found = false;
	student st;
	fstream File;
	File.open("student.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return AdminMenu();
	}
	while (!File.eof() && found == false)
	{

		File.read(reinterpret_cast<char*> (&st), sizeof(student));
		if (st.retrollno() == n)
		{
			st.showdata();
			cout << "\n\nPlease Enter The New Details of student" << endl;
			st.getdata();
			int pos = (-1) * static_cast<int>(sizeof(st));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&st), sizeof(student));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
	cin.ignore();
	cin.get();
	return AdminMenu();
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_student(int n)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return AdminMenu();
	}
	ofstream outFile;
	outFile.open("Temp.dat", ios::out);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		if (st.retrollno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat", "student.dat");
	cout << "\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
	return AdminMenu();
}

//***************************************************************
//    	function to display all students grade report
//****************************************************************

void class_result()
{
	student st;
	double avg = 0, tmp;
	int count = 0;

	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return AdminMenu();
	}
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "================================================================\n";
	cout << "R.No   Name       P   C   M   E   CS   DS   OS  OBP  per  grade" << endl;
	cout << "================================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.show_tabular();

		tmp = st.average();  //to get average score of each students
		avg = avg + tmp;

		count++;
	}
	cout << "\n\nAverage percentage of students: " << avg / count;   //divides sum of students score and gets average
	inFile.close();
	cin.ignore();
	cin.get();
	return AdminMenu();
}

void class_result2()
{
	student st;
	double avg = 0, tmp;
	int count = 0;

	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return StudentMenu();
	}
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "================================================================\n";
	cout << "R.No   Name       P   C   M   E   CS   DS   OS  OBP  per  grade" << endl;
	cout << "================================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&st), sizeof(student)))
	{
		st.show_tabular();

		tmp = st.average();  //to get average score of each students
		avg = avg + tmp;

		count++;
	}
	cout << "\n\nAverage percentage of students: " << avg / count;   //divides sum of students score and gets average
	inFile.close();
	cin.ignore();
	cin.get();
	return StudentMenu();
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	cout << "\n\n\n\t\t  STUDENT";
	cout << "\n\n\t\tREPORT CARD";
	cout << "\n\n\t\t  PROJECT";
	cin.get();
}


void stu_loginData()
{
	string name, pass;
	ofstream file("stData.dat", ios::binary | ios::app);

	cout << "---Create a Student Account---" << endl;
	cout << "==============================" << endl;
	cout << "Please Enter a Username: ";
	cin >> name;
	cout << "Please Enter a Password: ";
	cin >> pass;
	file << name << " " << pass << endl;;

	file.close();
	cin.ignore();
	cin.get();
	return;
}

void stu_login()
{
	string stu_name, stu_pass, u, p;
	system("cls");

	ifstream input("stData.dat");
	if (!input)
	{
		cout << "No Student User was Created!";
	}
	else
	{
		cout << "\n\n\t\tSTUDENT LOGIN:";
		cout << "\n\nPlease Enter Your User Name and Password: " << endl;
		cout << "===========================================\n\n";
		cout << "Enter User Name: ";
		cin >> stu_name;
		cout << "Enter Password: ";
		cin >> stu_pass;

		while (input >> u >> p)
		{
			if (u == stu_name && p == stu_pass)
            {
                cout <<"Login Successful." << endl;
                system("pause");
				StudentMenu();
			}

		}
	}
}

void adminLoginData()
{
	string name, pass;
	ofstream file("data.dat", ios::binary | ios::app);

	cout << "---Create an Admin Account---" << endl;
	cout << "==============================" << endl;
	cout << "Please Enter a Username: ";
	cin >> name;
	cout << "Please Enter a Password: ";
	cin >> pass;
	file << name << " " << pass << endl;

	cout << "\n\nDon't forget your name and password!!!";
	cout << "\nif do forget, just delete 'data.dat' file :P";

	file.close();
	cin.ignore();
	cin.get();

	return;
}

void AdminLogin()
{
	string Admin_name, Admin_pass, u, p;
	system("cls");

	ifstream input("data.dat", ios::binary);
	if (!input)
	{
		adminLoginData();
	}
	else
	{
		cout << "\n\n\t\tADMIN LOGIN:";
		cout << "\n\nPlease Enter Your User Name and Password: " << endl;
		cout << "===========================================\n\n";
		cout << "Enter User Name: ";
		cin >> Admin_name;
		cout << "Enter Password: ";
		cin >> Admin_pass;

		while (input >> u >> p)
		{
			if (u == Admin_name && p == Admin_pass)
			{

				cout << "\nLogin Successful \n";
				system("pause");
				AdminMenu();
			}
		}
	}
}

void StudentMenu()
{
	char ch;
	int num;
	system("cls");
	cout << "\n\n\n\tSTUDENT MENU";

	cout << "\n\n\t1.Class Result";
	cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout << "\n\n\t3.SEARCH STUDENT RECORD\n";

	cout << "\n\n\t4.BACK LOGIN PAGE";
	cout << "\n\n\tPlease Enter Your Choice (1-4) ";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':   class_result2(); break;
	case '2':	display_all2(); break;
	case '3':	cout << "\n\n\tPlease Enter The roll number "; cin >> num;
		display_sp2(num); break;
	case '4':	break;
	default:	cout << "\a"; StudentMenu();
	}

}

void AdminMenu()
{
	char ch;
	int num;
	system("cls");
	cout << "\n\n\n\tADMIN MENU";
	cout << "\n\n\t1.Create New Student User.";
	cout << "\n\n\t2.Create New Admin Account.\n";
	cout << "\n\n\t3.CLASS RESULT";
	cout << "\n\n\t4.DISPLAY ALL STUDENTS RECORDS";
	cout << "\n\n\t5.SEARCH STUDENT RECORD\n";
	cout << "\n\n\t6.CREATE STUDENT RECORD";
	cout << "\n\n\t7.MODIFY STUDENT RECORD";
	cout << "\n\n\t8.DELETE STUDENT RECORD\n";
	cout << "\n\n\t9.BACK LOGIN PAGE";
	cout << "\n\n\tPlease Enter Your Choice (1-9) ";
	cin >> ch;
	system("cls");
	switch (ch)
	{
	case '1':	stu_loginData(); break;
	case '2':   adminLoginData(); break;
	case '3':   class_result(); break;
	case '4':	display_all(); break;
	case '5':	cout << "\n\n\tPlease Enter The roll number "; cin >> num;
		display_sp(num); break;
	case '6':	write_student(); break;
	case '7':	cout << "\n\n\tPlease Enter The roll number "; cin >> num;
		modify_student(num); break;
	case '8':	cout << "\n\n\tPlease Enter The roll number "; cin >> num;
		delete_student(num); break;
	case '9':	break;
	default:	cout << "\a"; AdminMenu();
	}

}


//***************************************************************
//    			END OF PROJECT
//***************************************************************

