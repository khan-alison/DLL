//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <iostream>

#include <string>

using namespace std;
class Person {
protected:
    long ID;
    string name;
public:
    Person();
    Person(long id,string name);
    Person(const Person& person);
    ~Person();
    void setId(long id);
    void setName(string n);
    long getId();
    string getName();
    virtual void copy(Person &p);
    virtual void print() const;
};

#endif //UNTITLED_PERSON_H
