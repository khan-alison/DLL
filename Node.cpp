//
// Created by Khanh on 04/05/2022.
//

#include "Node.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include "Vehicle.h"


using namespace std;
Node::Node():data(),next(NULL),previous(NULL) {}
Node::Node(Vehicle data, Node* next, Node* previous): data(data), next(next), previous(previous) {

}

Node::~Node() {

}

Vehicle Node::getData() {
    return data;
}

void Node::setData(Vehicle data) {
    Node::data = data;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

Node *Node::getPrevious() const {
    return previous;
}

void Node::setPrevious(Node *previous) {
    Node::previous = previous;
}



