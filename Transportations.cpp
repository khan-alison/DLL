//
// Created by khanh on 04/01/2022.
//

#include "Transportations.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const char separator    = ' ';
fstream dataFile;

Transportations::Transportations(): routeName(""), numberOfObj(0) {}
Transportations::Transportations(string name, int number) : routeName(name),
                                                            numberOfObj(number) {

}
Transportations::Transportations(const Transportations& c) : routeName(c.routeName),
                                                             numberOfObj(c.numberOfObj) {
}

Transportations::~Transportations() {
}
void Transportations::print() const
{
    cout << "ID: " << routeName << endl;
    cout << "Number of student: " <<endl;
}

void Transportations::setRouteName(string name) {
    routeName = name;
}
string Transportations::getRouteName() {
    return routeName;
}

void Transportations::displayAllVehicle(){
    Node* currentNode = head;
    int index = 0;
    if(numberOfObj != 0){
        cout << "Display vehicle information.."<<endl;
        cout << " Number of vehicle:" << numberOfObj << endl;
        cout << left << setw(6) << setfill(separator) << "STT"
             << left << setw(10) << setfill(separator) << "ID"
             << left << setw(20) << setfill(separator) << "TYPE"
                << left << setw(25) << setfill(separator) << "Name"
             << left << setw(20) << setfill(separator) << "SPEED"
             << left << setw(25) << setfill(separator) << "PRODUCER"
             << left << setw(10) << setfill(separator) << "Scholarship"
             <<endl;
        while(index < numberOfObj){
            cout << left << setw(6) << setfill(separator) << index+1
                 << left << setw(10) << setfill(separator) << currentNode->getData().getId()
                 << left << setw(20) << setfill(separator) << currentNode->getData().getType()
                    << left << setw(25) << setfill(separator) << currentNode->getData().getName()
                 << left << setw(20) << setfill(separator) << currentNode->getData().getSpeed()
                 << left << setw(25) << setfill(separator) << currentNode->getData().getProducer()
                 << left << setw(10) << setfill(separator) << currentNode->getData().getScholarship() <<endl;
            currentNode=currentNode->getNext();
            index++;
        }
    }else{
        cout << "We dont have any information of any vehicle yet!!!" <<endl;
    }
};


void Transportations::removeAllVehicle() {
    Node* currentNode = head;
    Vehicle* vehiclePt = NULL;
    while(currentNode != NULL)
    {
        Node* nextNode = currentNode->getNext();
        currentNode->setNext(NULL);
        currentNode->setPrevious(NULL);
        currentNode->setData(*vehiclePt);
        currentNode = nextNode;
    }
    head=tail=NULL;
    numberOfObj = 0;
}

int Transportations::size() {
    return numberOfObj;
}

bool Transportations::isEmpty() {
    return  size() == 0;
}

void Transportations::add(Vehicle std) {
    addLast(std);
}

void Transportations::addFirst(Vehicle std) {
    if(isEmpty())
    {
        head=tail=new Node(std,NULL,NULL);
    }else
    {
        head->setPrevious(new Node(std,NULL,head));
        head=head->getPrevious();
    }
    numberOfObj++;
}

void Transportations::addLast(Vehicle std) {
    if(isEmpty())
    {
        head=tail=new Node(std,NULL,NULL);

    }else
    {
        tail->setNext(new Node(std,tail,NULL));
        tail=tail->getNext();
    }
    numberOfObj++;
}

Vehicle Transportations::peekFirst() {
    if(isEmpty()) throw runtime_error("Empty linked list");
    return head->getData();
}
//
Node *Transportations::getFirst() {
    if(isEmpty()) throw runtime_error("Empty linked list");
    cout <<"There are no data to remove"<<head <<endl;
    return head;
}

Vehicle Transportations::peekLast() {
    if(isEmpty()) cout <<"Empty linked list" <<endl;
    return tail->getData();
}

void Transportations::removeFirst() {
    if(isEmpty()) {
        cout <<"There are no data to remove" <<endl;
        return;
    };
    Vehicle data = head->getData();
    head=head->getNext();
    numberOfObj--;
    if(isEmpty()) tail=NULL;
    else head->setPrevious(NULL);
}


void Transportations::removeLast() {
    if(isEmpty()) {
        cout <<"There are no data to remove" <<endl;
        return;
    };
    Vehicle data = tail->getData();
    tail=tail->getPrevious();
    numberOfObj--;
    if(isEmpty()) {
        head = NULL;
    }else
    {
        tail->setPrevious(NULL);
    }
}


void Transportations::remove(int id ) {
    Vehicle* stdPrt = NULL;
    Node* node = findVehicle(id);
    if(numberOfObj > 0 && node){
        if(node->getPrevious() == NULL) {
            removeFirst();
            cout << "Remove first with id " << id << endl;
            return;
        };
        if(node->getNext() ==NULL) {
            removeLast();
            cout << "Remove last with id " << id << endl;
            return;
        };
        cout << "Remove " << id << endl;
        node->getPrevious()->setNext(node->getNext());
        node->getNext()->setPrevious(node->getPrevious());
        numberOfObj--;

        node->setData(*stdPrt);
        node->setPrevious(NULL);
        node->setNext(NULL);
        node=NULL;
    }
}

int Transportations::indexOf(Vehicle std) {
    int index = 0;
    Node* currentNode = head;
    Vehicle* stdPrt = NULL;

    if(std.getId() == NULL)
    {
        while(currentNode != NULL)
        {
            if(currentNode->getData().getId() == NULL)
            {
                return index;
            }
            currentNode=currentNode->getNext();
            index++;
        }
    }else{
        while(currentNode != NULL)
        {
            if(currentNode->getData().getId() == std.getId())
            {
                return index;
            }
            currentNode=currentNode->getNext();
            index++;
        }
    }
    return -1;
}

bool Transportations::contain(int id) {
        if(findVehicle(id)){
            cout << findVehicle(id)->getData().getType() << endl;
            return true;
        }else{
            cout << "The student with that id doesn't existed" << endl;
            return false;
        }
}

Node *Transportations::findVehicle(long id) {
    Node* currentNode = head;
    int index = 0;
//    bool b;
    if(numberOfObj != 0){
        while(index < numberOfObj){
            if(currentNode->getData().getId() == id){
//                istringstream(currentNode->getNext()->getData().getType())>>b;
//                cout << b <<endl;

                return currentNode;
            }else{
               cout << "This vehicle doesn't existed on data" <<endl;
            }
            currentNode=currentNode->getNext();
            index++;
        }
    }else{
        cout << "We dont have any information of any student yet!!!" <<endl;
    }
    return NULL;
}

void Transportations::updateVehicleInfo(int oldId, Vehicle newData) {
    Node* node = findVehicle(oldId);
    if(node)
    {
        node->setData(newData);
        return;
    }
    return;
}



