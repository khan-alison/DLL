//
// Created by khanh on 04/01/2022.
//

#include "Class.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
using namespace std;
const char separator    = ' ';
fstream dataFile;

Class::Class():className(""), numberOfStu(0) {}
Class::Class(string name, int number) : className(name),
                                        numberOfStu(number) {

}
Class::Class(const Class& c) : className(c.className),
                               numberOfStu(c.numberOfStu) {
}

Class::~Class() {
}
void Class::print() const
{
    cout << "ID: " <<className<< endl;
    cout << "Number of student: " <<endl;
}

void Class::setClassName(string name) {
    className = name;
}
string Class::getClassName() {
    return className;
}

void Class::displayAllStudent(){
    Node* currentNode = head;
    int index = 0;
    if(numberOfStu != 0){
        cout << "Display student information.."<<endl;
        cout << " Number of student:" << numberOfStu<<endl;
        cout << left << setw(6) << setfill(separator) << "STT"
             << left << setw(10) << setfill(separator) << "ID"
             << left << setw(25) << setfill(separator) << "NAME"
             << left << setw(5) << setfill(separator) << "GPA"
             << left << setw(5) << setfill(separator) << "Year"
             << left << setw(10) << setfill(separator) << "Scholarship"
             <<endl;
        while(index < numberOfStu){
            cout << left << setw(6) << setfill(separator) << numberOfStu
                 << left << setw(10) << setfill(separator) << currentNode->getData().getId()
                 << left << setw(25) << setfill(separator) << currentNode->getData().getName()
                 << left << setw(5) << setfill(separator) << currentNode->getData().getGPA()
                 << left << setw(5) << setfill(separator) << currentNode->getData().getYear()
                 << left << setw(10) << setfill(separator) << currentNode->getData().getScholarship() <<endl;
            currentNode=currentNode->getNext();
            index++;
        }
    }else{
        cout << "We dont have any information of any student yet!!!" <<endl;
    }
};


void Class::removeAllStd() {
    Node* currentNode = head;
    Student* stdPrt = NULL;
    while(currentNode != NULL)
    {
        Node* nextNode = currentNode->getNext();
        currentNode->setNext(NULL);
        currentNode->setPrevious(NULL);
        currentNode->setData(*stdPrt);
        currentNode = nextNode;
    }
    head=tail=NULL;
    numberOfStu = 0;
}

int Class::size() {
    return numberOfStu;
}

bool Class::isEmpty() {
    return  size() == 0;
}

void Class::add(Student std) {
    addLast(std);
}

void Class::addFirst(Student std) {
    if(isEmpty())
    {
        head=tail=new Node(std,NULL,NULL);
    }else
    {
        head->setPrevious(new Node(std,NULL,head));
        head=head->getPrevious();
    }
    numberOfStu++;
}

void Class::addLast(Student std) {
    if(isEmpty())
    {
        head=tail=new Node(std,NULL,NULL);

    }else
    {
        tail->setNext(new Node(std,tail,NULL));
        tail=tail->getNext();
    }
    numberOfStu++;
}

Student Class::peekFirst() {
    if(isEmpty()) throw runtime_error("Empty linked list");
    return head->getData();
}
//
//Node Class::getFirst() {
//    if(isEmpty()) throw runtime_error("Empty linked list");
//    return *head;
//}

Student Class::peekLast() {
    if(isEmpty()) cout <<"Empty linked list" <<endl;
    return tail->getData();
}

void Class::removeFirst() {
    if(isEmpty()) {
        cout <<"There are no data to remove" <<endl;
        return;
    };
    Student data = head->getData();
    head=head->getNext();
    numberOfStu--;
    if(isEmpty()) tail=NULL;
    else head->setPrevious(NULL);
}


void Class::removeLast() {
    if(isEmpty()) {
        cout <<"There are no data to remove" <<endl;
        return;
    };
    Student data = tail->getData();
    tail=tail->getPrevious();
    numberOfStu--;
    if(isEmpty()) {
        head = NULL;
    }else
    {
        tail->setPrevious(NULL);
    }
}

void Class::remove(int id ) {
    Student* stdPrt = NULL;
    Node* node = findStudent(id);

    if(numberOfStu > 0 && node){
        if(node->getPrevious() == NULL) {
            removeFirst();
            cout << "Remove student with id " << id << endl;
            return;
        };
        if(node->getNext()==NULL) {
            removeLast();
            cout << "Remove student with id " << id << endl;

            return;
        };
        node->getPrevious()->setNext(node->getNext());

        node->getNext()->setPrevious(node->getPrevious());

        Student data = node->getData();

        numberOfStu--;

        node->setData(*stdPrt);

        node->setPrevious(NULL);

        node->setNext(NULL);

        node=NULL;
    }
}

int Class::indexOf(Student std) {
    int index = 0;
    Node* currentNode = head;
    Student* stdPrt = NULL;

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

bool Class::contain(int id) {
        if(findStudent(id)){
            cout << findStudent(id)->getData().getName() << endl;
            return true;
        }else{
            cout << "The student with that id doesn't existed" << endl;
            return false;
        }
}

Node *Class::findStudent(long id) {
    Node* currentNode = head;
   if(numberOfStu>0)
   {
       while(currentNode != NULL)
       {
           if(currentNode->getData().getId() == id)
           {
               return currentNode;
           }else{
               cout  << "This student doesn't existed on file" <<endl;
               return NULL;
           }

           currentNode=currentNode->getNext();

       }
   }else{
       cout  << "There are no data to to search"  <<endl;

   }
    return NULL;
}

void Class::updateStudent(int oldId, Student newData) {
    Node* node = findStudent(oldId);
    if(node)
    {
        node->setData(newData);
        return;
    }
    return;
}

void sortedInsert(Node*  head_ref, Node*  newNode)
{
    Node* current;

    // if list is empty
    if (head_ref->getData().getGPA() == NULL)
        head_ref = newNode;

        // if the node is to be inserted at the beginning
        // of the doubly linked list
    else if ((head_ref)->getData().getGPA() >= newNode->getData().getGPA()) {
        newNode->setNext(head_ref) ;
        newNode->getNext()->setPrevious(newNode);
        head_ref = newNode;
    }

    else {
        current = head_ref;

        // locate the node after which the new node
        // is to be inserted
        while (current->getNext() != NULL &&
               current->getNext()->getData().getGPA() < newNode->getData().getGPA())
            current = current->getNext();

        /*Make the appropriate links */

        newNode->setNext(current->getNext()) ;

        // if the new node is not inserted
        // at the end of the list
        if (current->getNext() != NULL)
            newNode->getNext()->setPrevious(newNode) ;

        current->setNext(newNode)  ;
        newNode->setPrevious(current)  ;
    }
}

void insertionSort(Node** head_ref)
{
    // Initialize 'sorted' - a sorted doubly linked list
     Node* sorted = NULL;

    // Traverse the given doubly linked list and
    // insert every node to 'sorted'
     Node* current = *head_ref;
    while (current != NULL) {

        // Store next for next iteration
        struct Node* next = current->getNext();

        // removing all the links so as to create 'current'
        // as a new node for insertion
        current->setPrevious(NULL) ;
        current->setNext(NULL)  ;

        // insert current in 'sorted' doubly linked list
        sortedInsert(sorted, current);
        // Update current
        current = next;
    }

    // Update head_ref to point to sorted doubly linked list
    *head_ref = sorted;
}

