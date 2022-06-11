//
// Created by khanh on 04/01/2022.
//

#include "Person.h"
using namespace std;

Person::Person():ID(0), name("Undefined") {

}

Person::Person(long id, string n) : ID(id), name(n) {
}

Person::Person(const Person &person) : ID(person.ID), name(person.name) {

}

Person::~Person() {
}
void Person::print() const
{
    cout<<"ID: " << ID<< endl;
    cout<<"Name: " <<name <<endl;
}
void Person::setId(long id){
    ID = id;
}
void Person::setName(string n) {
    name = n;
}
string Person::getName() {return name;}
long Person::getId() {return ID;}
void Person::copy(Person &p) {
    ID = p.getId();
    name = p.getName();
}