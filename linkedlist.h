/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 04 - Linked Lists
Purpose: Header - main
Notes: This header file defines functions used by main and implemented in linkedlist.cpp
************************************************************************ */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
using namespace std;

/*
 * Structure Definition
 */
struct Node {
    int id;
    string data;
    Node *forward;
    Node *backward;
};

/*
 * Class Definition
 */
class LinkedList {
    private:
        //variables
        int nodeCount;
        Node *headptr, *tailptr;
        //methods
        void addHeader(Node*);
        void addMiddle(Node*, Node*);
        void addTail(Node*);
        void deleteHead(Node*);
        void deleteTail(Node*);
        void deleteMiddle(Node*);
public:
        LinkedList();
        bool addNode(int, string);
        void printlist();
        int count();
        bool deleteNode(int);
        int getHeadId();
        int getTailId();
        int getMidId();
};

#endif