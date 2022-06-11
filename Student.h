//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <iostream>
#include "string"
#include "Person.h"
using namespace std;
class Student:public Person{
private:
    double gpa;
    string year;
    string scholarship;
public:
    Student();
    Student(long ID, string name, double gpa, string year);
    Student(const Student& student);
    ~Student();
    void setYear(string year);
    string getYear();
    void setGPA(double gpa);
    double getGPA();
    void setScholarship(string scholar);
    string getScholarship();
    bool getStatus();
    virtual void print () const;
    virtual void copy(Student &s);

};


#endif //UNTITLED_STUDENT_H
