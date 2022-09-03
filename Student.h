#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	string name;
	int id;
	int course;
	int check; //1:credit 2: model
public:
	Student();
	Student(string name, int id, int course, int check);
	string getName();
	virtual void setName(string name);
	int getId();
	virtual void setId(int id);
	int getCourse();
	virtual void setCourse(int course);
	int getCheck();
	virtual void setCheck(int check);
	virtual int getGpa();
	virtual int getNumber_of_credit();
	virtual void setGpa(double gpa);
	virtual void setNumber_of_credit(int credit);
	virtual void display();
};

Student::Student() {
	name = "";
	id = course = check = 0;
}
Student::Student(string name, int id, int course, int check) {
	this->name = name;
	this->id = id;
	this->course = course;
	this->check = check;

}
string Student::getName() {
	return name;
}

void Student::setName(string name) {
	this->name = name;
}
int Student::getId() {
	return id;
}
void Student::setId(int id) {
	this->id = id;
}
int Student::getCourse() {
	return course;
}
void Student::setCourse(int course) {
	this->course = course;
}
int Student::getCheck() {
	return check;
}
void Student::setCheck(int check) {
	this->check = check;
}
int Student::getGpa() {
	return -1;
}
int Student::getNumber_of_credit() {
	return -1;
}
void Student::setGpa(double GPA) {}
void Student::setNumber_of_credit(int credit){}
void Student::display() {
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getId() << endl;
	cout << "Course: " << getCourse() << endl;
}
