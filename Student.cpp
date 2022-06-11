//
// Created by khanh on 04/01/2022.
//

#include "Student.h"

Student::Student() : Person(), year("Undefined"), gpa(0.0){

}
Student::Student(long ID, string name, double gpa, string year): Person(ID, name), gpa(gpa), year(year),scholarship("")
{

}

Student::Student(const Student& student):Person::Person(student), gpa(student.gpa), year(student.year),scholarship(student.scholarship) {

}

Student::~Student() {
}

void Student::print() const
{
    Person::print();
    cout << "Year: " <<year<< endl;
    cout << "GPA: " <<gpa<<endl;
}
void Student::setGPA(double g) {
    gpa = g;
}
void Student::setYear(string y) {
    year = y;
}
string Student::getYear() {return year;}
double Student::getGPA() {return gpa;}
void Student::setScholarship(string scholar){
    scholarship = scholar;
}
string Student::getScholarship(){return scholarship;}
void Student::copy(Student &s) {
    Person::copy(s);
    gpa = s.getGPA();
    year = s.getYear();
    scholarship = s.getScholarship();
}

