/* ************************************************************************
Name: Michael Quintana
Assignment: Coding 04 - Linked Lists
Purpose: Implementation - main
Notes: Implemenation file serving as the main driver for the program
************************************************************************ */
#include <iostream>
#include "./main.h"
using namespace std;


int main (int argc,char** argv){
    srand (time(NULL));
    cout << boolalpha;
    /*
     * Variable Declaration
     */
    int n; //user input
    int id;
    int deletion = 1;//loop display for deletion tests
    string data[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
                     "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"}; //Data value
    if (argc != 2) {cout <<  "You have specified too many or too few arguments. Please try again."; return 3;}
    try {
        string userInput(argv[1]);
        n = stoi(userInput);
    } catch (...){cout << "You have enter a non-numeric value. Please re-run the program with a numeric value." << endl;}
    LinkedList list;
    for (int counter = 0; counter < n; counter++){
        //Sets up the random int.  Seeds in the first six values to allow for testing of deletion / dupe later
        switch (counter){
            case 0: id = 8999; break;
            case 1: id = 3492; break;
            case 2: id = 4063; break;
            case 3: id = 1; break;
            case 4: id = 99999; break;
            case 5: id = 8999; break;
            default: id = randomInt();
        }
        cout << "Sucessfully Added?: " << list.addNode(id, data[counter]);
        cout << " ID: " << id << ", " << data[counter] << " | Current Count: " << list.count() << endl;
    }
    list.printlist();
    cout << endl << endl << "Node Deletion " << endl << "=================" << endl;

    while (list.count()  != 0){
        cout << "Pass: " << deletion << endl;
        cout << "Header | Deleted Node w/ ID "<< list.getHeadId() <<"| Sucessful? "
             << list.deleteNode(list.getHeadId()) << endl;
        list.printlist();
        cout << endl << endl;
        cout << endl <<"Tail | Deleted Node w/ ID "<< list.getTailId() <<"| Sucessful? "
            << list.deleteNode(list.getHeadId()) << endl;
        list.printlist();
        cout << endl << "Mid | Deleted Node w/ ID "<< list.getMidId() << "| Sucessful? "
           << list.deleteNode(list.getMidId()) << endl;
        list.printlist();
    }
    return 0;
}