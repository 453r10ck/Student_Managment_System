
#include <iostream>
#include "Student.h"
#include <vector>
#include <string>
#include "Credit.h"
#include "Model.h"
#include <limits>
#include <memory>
using namespace std;

void get_input_number_of_students(vector<std::unique_ptr<Student>>& v1, int p1) {
	for (int j = 0; j < p1; j++) {
		int ID;
		string NAME;
		int COURSE;
		int CHECK;
		double GPA;
		int CREDIT;
		cout << "*********************************************************************" << endl;
		cout << "Enter the information of student " << j + 1 << " :" << endl;
		cout << "Enter name of student " << endl;
		cin.ignore();
		getline(cin, NAME);
		cout << "\nEnter the ID: " << endl;
		cin >> ID;
		while (ID<= 0) {
			cout << "Please input a positive numeric data! \n";
			cin.clear(); // reset failed bit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cin >> ID;
		}
		cout << "\nEnter the Course: " << endl;
		cin >> COURSE;
		while (COURSE <= 0) {
			cout << "Please input a positive numeric data! \n";
			cin.clear(); // reset failed bit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cin >> COURSE;
		}
		cout << "\nEnter 1:Study credit program . Enter 2: Study model program" << endl;
		cin >> CHECK;
		while (CHECK <= 0||CHECK>2) {
			cout << "Require input is 1 or 2\n";
			cin.clear(); // reset failed bit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cin >> CHECK;
		}
		if (CHECK == 1) {
			cout << "\nHow many credit ?" << endl;
			cin >> CREDIT;
			while (CREDIT <= 0||CREDIT>128) {
				cout << "Please input a positive numeric data and <= 128\n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> CREDIT;
			}
			v1.push_back(std::unique_ptr<Student>(new Credit_program(NAME, ID, COURSE, CHECK, CREDIT)));
		}
		else if (CHECK == 2) {
			cout << "\nGPA ?" << endl;
			cin >> GPA;
			while (GPA <= 0||GPA>10) {
				cout << "Please input a positive numeric data and <= 10 \n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> GPA;
			}
			v1.push_back(std::unique_ptr<Student>(new Model_program(NAME, ID, COURSE, CHECK, GPA)));
		}

	}
}

void input() {
	cout << "\nEnter request" << endl;
	cout << "1: Add student information" << endl;
	cout << "2: Fix student information" << endl;
	cout << "3: Delete student information" << endl;
	cout << "4: Search student information by ID" << endl;
	cout << "5: Search student information by Name" << endl;
	cout << "6: Search student information by course" << endl;
	cout << "7: Statistics of students studying according to the type of credit" << endl;
	cout << "8: Statistics of students studying according to the model program " << endl;
	cout << "9:Statistics of the list of students allowed to graduate " << endl;
	cout << "10: Exit" << endl;
	cout << "====================================================================" << endl;	
}

void fixing() {
	cout << "\nWhat information do you want to edit ?" << endl;
	cout << "1: Name" << endl;
	cout << "2: ID" << endl;
	cout << "3: Course" << endl;
	cout << "4: GPA/Credit"<<endl;
}

int main() {
	int choose;
	int fix;
	int n; // number of student
	int k; // sinh viên thứ k
	string newname;
	int newid;
	int newcourse;
	int newcheck;
	int newcredit;
	int newgpa;
	int x;; // bien trung gian check co thong tin hay ko
	//std::unique_ptr<Student> v = std::unique_ptr<Student>(new Student());
	vector< std::unique_ptr<Student> > v;
	input();
	while (true) {
		cin >> choose;
		while (choose <= 0 || choose > 10) {
			cout << "Please re-enter the correct format \n";
			cin.clear(); // reset failed bit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			cin >> choose;
		}
		switch (choose) {
		case 1:
		{
			cout << "Please input number of students (n>=1): \t";;
			cin >> n;
			while (n <= 0) {
				cout << "Please input a positive numeric data! \n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> n;
			}
			get_input_number_of_students(v, n);
			input();
			break;
		}
		case 4:
		{
			x = 0;
			cout << "Search student information by ID : ";
			int id1;
			cin >> id1;
			while (id1 <= 0) {
				cout << "Please re-enter the correct format \n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> id1;
			}
			for (int i = 0; i < v.size(); i++) {
				if (id1 == v.at(i)->getId()) {
					cout << "\nThe information student " << (i + 1) << " by ID " << endl;
					v.at(i)->display();
					x++;
				}
			}
			if (x == 0) {
				cout << "Not found";
			}
			input();
			break;
		}
		case 5:
		{
			x = 0;
			cout << "5: Search student information by Name : ";
			cin.ignore();
			string name1;
			getline(cin, name1);
			for (int i = 0; i < v.size(); i++) {
				if (name1 == v.at(i)->getName()) {
					cout << "\nThe information student " << (i + 1) << " by NAME " << endl;
					v.at(i)->display();
					x++;
				}
			}
			if (x == 0) {
				cout << "Not found";
			}
			input();
			break;
		}
		case 6:
		{
			x = 0;
			cout << "6: Search student information by course";
			int course1;
			cin >> course1;
			while (course1 <= 0) {
				cout << "Please re-enter the correct format \n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> course1;
			}
			for (int i = 0; i < v.size(); i++) {
				if (course1 == v.at(i)->getCourse()) {
					cout << "\nThe information " << (i + 1) << " by Course" << endl;
					v.at(i)->display();
					x++;
				}
			}
			if (x == 0) {
				cout << "Not found";
			}
			input();
			break;
		}
		case 3: {
			cout << "3: Delete student information " << endl;
			cout << "List of student information before deleting " << endl;
			cout << "====================================================================" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << "\nThe information of student " << (i + 1) << " :" << endl;
				v.at(i)->display();
			}
			int del;
			cout << "\nSelect the  student you want to delete : ";
			cin >> del;
			while (del <= 0 || del > v.size()) {
				cout << "Please input a positive numeric data and <= " << v.size() << endl;
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> del;
			}
			v.erase(v.begin() + del - 1);
			cout << "\nList of student information after deleting ";
			for (int i = 0; i < v.size(); i++) {
				cout << "\nThe information of student " << (i + 1) << " :" << endl;
				v.at(i)->display();
			}
			input();
			break;
		}
		case 2:
		{
			cout << "2: Fix student information " << endl;
			cout << "====================================================================" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << "\nThe information of student " << (i + 1) << " :" << endl;
				v.at(i)->display();
			}
			fixing();
			cout << "\nSelect the information of student you want to edit " << endl;
			cin >> fix;
			while (fix <= 0 || fix > 4) {
				cout << "Please re-enter the correct format \n";
				cin.clear(); // reset failed bit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> fix;
			}
			if (fix == 1) {
				cout << "Select the student you want to change the name ";
				cin >> k;
				while (k <= 0 || k > v.size()) {
					cout << "Please input a positive numeric data and <= " << v.size() << endl;
					cin.clear(); // reset failed bit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					cin >> k;
				}
				cout << "\nEnter new name for student ";
				cin.ignore();
				getline(cin, newname);
				v.at(k - 1)->setName(newname);
				cout << "New information of student : " << endl;
				v.at(k - 1)->display();
				input();
			}
			if (fix == 2) {
				cout << "Select the student you want to change the ID ";
				cin >> k;
				while (k <= 0 || k > v.size()) {
					cout << "Please input a positive numeric data and <= " << v.size() << endl;
					cin.clear(); // reset failed bit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					cin >> k;
				}
				cout << "\nEnter new ID for student ";
				cin.ignore();
				cin >> newid;
				v.at(k - 1)->setId(newid);
				cout << "New information of student : " << endl;
				v.at(k - 1)->display();
				input();
			}
			if (fix == 3) {
				cout << "Select the student you want to change the COURSE ";
				cin >> k;
				while (k <= 0 || k > v.size()) {
					cout << "Please input a positive numeric data and <= " << v.size() << endl;
					cin.clear(); // reset failed bit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					cin >> k;
				}
				cout << "\nEnter new COURSE for student ";
				cin.ignore();
				cin >> newcourse;
				v.at(k - 1)->setCourse(newcourse);
				cout << "New information of student : " << endl;
				v.at(k - 1)->display();
				input();
			}
			if (fix == 4) {
				cout << "Select the student you want to change the GPA/Credit ";
				cin >> k;
				while (k <= 0 || k > v.size()) {
					cout << "Please input a positive numeric data and <= " << v.size() << endl;
					cin.clear(); // reset failed bit
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
					cin >> k;
				}
				if (v.at(k - 1)->getCheck() == 1)
				{
					int Credit;
					cout << "\n Enter new Credit : ";
					cin >> Credit;
					while (Credit <= 0||Credit>128) {
						cout << "Please input a positive numeric data and <=128 \n";
						cin.clear(); // reset failed bit
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
						cin >> Credit;
					}
					v.at(k - 1)->setNumber_of_credit(Credit);
				}
				else
				{
					double Gpa;
					cout << "\n Enter new GPA : ";
					cin >> Gpa;
					while (Gpa <= 0||Gpa>10.0) {
						cout << "Please input a positive numeric data and <=10 \n";
						cin.clear(); // reset failed bit
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
						cin >> Gpa;
					}
					v.at(k - 1)->setGpa(Gpa);
				}
				cin.ignore();
				cout << "New information of student : " << endl;
				v.at(k - 1)->display();
				input();
			}

			break;

		case 7:
		{
			cout << "Statistics of students studying according to the type of credit " << endl;
			int cnt = 0;
			// the number of student to studying credit program
			for (int i = 0; i < v.size(); i++) {
				if (v.at(i)->getCheck() == 1) {
					cnt++;
				}
			}
			cout << cnt <<" students"<< endl;
			input();
			break;
		}
		case 8:
		{
			cout << "Statistics of students studying according to the type of model" << endl;
			int cnt1 = 0;
			// the number of student to studying model program
			for (int i = 0; i < v.size(); i++) {
				if (v.at(i)->getCheck() == 2) {
					cnt1++;
				}
			}
			cout << cnt1 <<" students"<<endl;
			input();
			break;
		}
		case 9: {
			int creditCount = 0, modelCount = 0;
			int cnt = 0;
			cout << "Statistics of the list of students allowed to graduate " << endl;
			/*cout << "Credit Program" << endl;*/
			for (int i = 0; i < v.size(); i++)
			{ 
				if (v.at(i)->getCheck() == 1) {
					if (v.at(i)->getNumber_of_credit() == 128) {
						v.at(i)->display();
						creditCount++;
					}
				}
			}
		/*	cout << "Model Program" << endl;*/
			for (int i = 0; i < v.size(); i++)
			{
				if (v.at(i)->getCheck() == 2) {
					if (v.at(i)->getGpa() >= 5.0) {
						v.at(i)->display();
						modelCount++;
					}
				}
			}
			cnt = modelCount + creditCount;
			cout << "Graduation Condition Satisfied: " << endl;
			cout << "Model Program: " << modelCount << endl;
			cout << "Credit Program: " << creditCount << endl;
			cout << "So " << cnt << " students are allowed to graduate " << endl;

			input();
			break;
		}

		case 10:
		{
			cout << "\nEnd program";
			return 0;
		}
		}
		}
	}
}



