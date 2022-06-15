//
// Created by khanh on 04/01/2022.
//

#include "Object.h"
using namespace std;

Object::Object(): ID(0), type("Undefined") {

}

Object::Object(long id, string n) : ID(id), type(n) {
}

Object::Object(const Object &object) : ID(object.ID), type(object.type) {

}

Object::~Object() {
}
void Object::print() const
{
    cout<<"ID: " << ID<< endl;
    cout << "Type: " << type << endl;
}
void Object::setId(long id){
    ID = id;
}
void Object::setType(string n) {
    type = n;
}
string Object::getType() {return type;}
long Object::getId() {return ID;}
void Object::copy(Object &p) {
    ID = p.getId();
    type = p.getType();
}