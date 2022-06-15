//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_TRANSPORTATIONS_H
#define UNTITLED_TRANSPORTATIONS_H


#include <iostream>
#include <iomanip>
#include "string"
#include "Vehicle.h"
#include <string.h>
#include "node.h"

using namespace std;
class Transportations{
private:
    string routeName; //number ID
    int numberOfObj;
    Vehicle stu[100];
    Node* head = NULL;
    Node* tail = NULL;
public:
    Transportations();
    Transportations(string className, int numberOfStu);
    Transportations(const Transportations& c);
    ~Transportations();
    void print() const;
    void setRouteName(string name);
    string getRouteName();
    void displayAllVehicle();
    int size();
    bool isEmpty();
    void add(Vehicle std);
    void addLast(Vehicle std);
    void addFirst(Vehicle std);
    Vehicle peekFirst();
    Node *getFirst();
    Vehicle peekLast();
    void removeFirst();
    void removeLast() ;
    void removeAllVehicle();
    void remove(int id);
    bool remove(Vehicle std);
    Vehicle removeAt(int index);
    int indexOf(Vehicle std);
    bool contain(int id);
    Node *findVehicle(long id);
    void updateVehicleInfo(int oldId, Vehicle newData);
};

#endif //UNTITLED_TRANSPORTATIONS_H
