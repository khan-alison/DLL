//
// Created by khanh on 04/01/2022.
//

#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H


#include <iostream>
#include <iomanip>
#include "string"
#include "student.h"
#include <string.h>
#include "node.h"

using namespace std;
class Class{
private:
    string className; //number ID
    int numberOfStu;
    Student stu[100];
    Node* head = NULL;
    Node* tail = NULL;
public:
    Class();
    Class(string className, int numberOfStu);
    Class(const Class& c);
    ~Class();
    void print() const;
    void setClassName(string name);
    string getClassName();
    void displayAllStudent();
    int size();
    bool isEmpty();
    void add(Student std);
    void addLast(Student std);
    void addFirst(Student std);
    Student peekFirst();
//    Node getFirst();
    Student peekLast();
    void removeFirst();
    void removeLast() ;
    void removeAllStd();
    void remove(int id);
    bool remove(Student std);
    Student removeAt(int index);
    int indexOf(Student std);
    bool contain(int id);
    Node *findStudent(long id);
    void updateStudent(int oldId,Student newData);
    void sortedInsert(Node node,Node node2);
    void insertionSort(Node node);
};

#endif //UNTITLED_CLASS_H
