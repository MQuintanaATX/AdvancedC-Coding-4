/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 04 - Linked Lists
Purpose: Class - Linked List
Notes: Implementation for the linked list class
************************************************************************ */
#include "linkedlist.h"

LinkedList::LinkedList(){
    nodeCount = 0;
    headptr = nullptr;
    tailptr = nullptr;
};


bool LinkedList::addNode(int id, string data) {
    if (id < 1000 or id > 9999) {return false;}//Checks if the int is outside of the ranges
    //Create a new temp node and load it with the data, and a finder
    Node *temp = new Node;
    temp->id = id;
    temp->data = data;
    temp->forward = nullptr;
    temp->backward = nullptr;

    //Checks for an existing value
    Node* valuecheck = new Node;
    valuecheck = headptr;
    if (valuecheck != nullptr ) {//If headptr isn't null checks for any existing values and declines to add
         while (valuecheck != nullptr) {
            if (valuecheck->id == temp->id) {return false; }
            valuecheck = valuecheck->forward;
        }
    }

    //adds a new header if none exists
    if (headptr == nullptr) {addHeader(temp); return true;}
    else if (temp->id < headptr->id){addHeader(temp); return true;} //Adds a new header if the ID is smaller than header's
    else if (headptr == tailptr) {addTail(temp); return true;} //Add sthe tail/second node. This keeps an item from 'falling off'
    else if (temp->id > tailptr->id) {addTail(temp); return true;}//adds it as a tail if the ID is higher than headerptr's
    else {//Finding the position where it goes if none of the previous cases match
        Node *finder = headptr;
        while (finder->forward != nullptr and finder->forward->id < temp->id) {
            finder = finder->forward;
        }
        addMiddle(finder, temp);
        return true;
    }
}

void LinkedList::addHeader(Node* temp){
    if (headptr == nullptr){
        headptr= temp;
        tailptr = temp;
        nodeCount++;
        return;
    } else {
        temp->forward = headptr;
        temp->forward->backward = temp;
        headptr = temp;
        nodeCount++;
        return;
    }
}

void LinkedList::addTail(Node* temp){
    tailptr->forward = temp;
    temp->forward = nullptr;
    tailptr = temp;
    nodeCount++;
    return;
}

void LinkedList::addMiddle(Node* finder, Node* temp){
    temp->forward = finder->forward;
    finder->forward->backward = temp;
    temp->backward = finder;
    finder->forward = temp;
    nodeCount++;
    return;
}

void LinkedList::printlist() {
    Node *current = headptr;
    cout << "Listing all nodes...\n=================" << endl;
    for (int i = 1; i <= nodeCount && current != nullptr; i++){
        cout << "Node : " << i  << " | ID: " << current->id << " | Data: " << current->data << endl;
        current = current->forward;
    }
    return;
}

int LinkedList::count() {
    return nodeCount;
}
//gets the head ptr iD to allow for deletion
int LinkedList::getHeadId() {
    return headptr->id;
}

//gets the tail ptr iD to allow for deletion
int LinkedList::getTailId() {
    return tailptr->id;
}

//gets the midpoint for deletion
int LinkedList::getMidId() {
    Node *finder = headptr;
    if (nodeCount > 2) {
        for (int i = 0; i < nodeCount / 2; i++){
            finder=finder->forward;
        }
    } else {return 0;}
    return finder->id;
}
bool LinkedList::deleteNode(int id) {
    Node *finder = headptr;
    bool found = false;
    if (count() == 0) {return false;}
    if (finder != nullptr){
        while (finder->forward != nullptr and finder->id != id) {
            finder = finder->forward;
        }
        if (finder->id == id){found = true;}
    }
    if (finder->id == headptr->id){deleteHead(finder); return found;}
    else if (finder->id == tailptr->id){deleteTail(finder); return found;}
    else if (found==true){deleteMiddle(finder); return true;}
    return found;
}

void LinkedList::deleteHead(Node* finder) {
    if (finder->forward != nullptr){headptr = finder->forward;}
    headptr->backward = nullptr;
    nodeCount--;
    return;
}

void LinkedList::deleteTail(Node* finder) {
    finder->backward = nullptr;
    nodeCount--;
    return;
}

void LinkedList::deleteMiddle(Node* finder){
    finder->backward->forward = finder->forward;
    finder->forward->backward = finder->backward;
    nodeCount--;
    return;
}