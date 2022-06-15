//
// Created by Khanh on 04/05/2022.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


#include "Vehicle.h"

using namespace std;

class Node {
private:Vehicle data;
    Node* next;
    Node* previous;

public:
    Node();
    Node(const Node& c);
    Node(Vehicle data, Node* next, Node* previous);
    ~Node();
    Vehicle getData();

    void setData(Vehicle data);

    Node *getNext() const;

    void setNext(Node *next);

    Node *getPrevious() const;

    void setPrevious(Node *previous);

};




#endif //UNTITLED_NODE_H
