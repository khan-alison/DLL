//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_VEHICLE_H
#define UNTITLED_VEHICLE_H
#include <iostream>
#include "string"
#include "Object.h"
using namespace std;
class Vehicle: public Object{
private:
    string name;
    double speed;
    string producer;
    string type;
public:
    Vehicle();
    Vehicle(long ID, string name, string type, double spd, string producer);
    Vehicle(const Vehicle& vehicle);
    ~Vehicle();
    void setYear(string year);
    string getProducer();
    void setGPA(double gpa);
    double getSpeed();
    void setScholarship(string scholar);
    string getName();
    void setType(string name);
    string getScholarship();
    bool getStatus();
    virtual void print () const;
    virtual void copy(Vehicle &s);

};


#endif //UNTITLED_VEHICLE_H
