//
// Created by khanh on 04/01/2022.
//

#include "Vehicle.h"

Vehicle::Vehicle() : Object(), producer("Undefined"), speed(0.0){

}
Vehicle::Vehicle(long ID, string type,string name, double speed, string producer): Object(ID, type), speed(speed), producer(producer), name(name)
{

}

Vehicle::Vehicle(const Vehicle& vehicle): Object::Object(vehicle),speed(vehicle.speed), producer(vehicle.producer), name(vehicle.name) {

}

Vehicle::~Vehicle() {
}

void Vehicle::print() const
{
    Object::print();
    cout << "Year: " << producer << endl;
    cout << "GPA: " << speed << endl;
}
void Vehicle::setGPA(double g) {
    speed = g;
}
void Vehicle::setYear(string y) {
    producer = y;
}

string Vehicle::getProducer() {return producer;}
double Vehicle::getSpeed() {return speed;}
//void Vehicle::setScholarship(string scholar){
//    name = scholar;
//}
string Vehicle::getScholarship(){return name;}
void Vehicle::copy(Vehicle &s) {
    Object::copy(s);
    speed = s.getSpeed();
    producer = s.getProducer();
    name = s.getName();
}

string Vehicle::getName() {return name;};
void Vehicle::setType(string n) {
    name = n;
}



