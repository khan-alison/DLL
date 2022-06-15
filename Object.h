//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H
#include <iostream>
#include <string>

using namespace std;
class Object {
protected:
    long ID;
    string type;
public:
    Object();
    Object(long id, string name);
    Object(const Object& object);
    ~Object();
    void setId(long id);
    void setType(string n);
    long getId();
    string getType();
    virtual void copy(Object &p);
    virtual void print() const;
};

#endif //UNTITLED_OBJECT_H
