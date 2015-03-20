// Carrie Hadley
// March, 2015
// Functions

#include <iostream>
#include "battleship.h"


using std::cout; using std::cin; using std::endl;


bool match(ship myShip, location mySpot){
    // returns true if this location matches
    // the location of the ship
    // returns false otherwise

    if (myShip.loc.x == mySpot.x && myShip.loc.y == mySpot.y)
        return true;
    else
        return false;
 }


int check(ship myFleet[], location mySpot){
    // returns the index of element of the array
    // that matches the location
    // returns -1 if none do
    
    for (int i = 0; i < 6; ++i)
        if (match(myFleet[i], mySpot) == true) {
            return i;
            break;
        }
    return -1;

 }


void initialize(ship myFleet[]) {
    // places all ships in -1 X location to signify
    // that the ship is not deployed
    
    for (int i=0; i<6; ++i) {
        myFleet[i].loc.x = -1;
        myFleet[i].loc.y = -1;
    }

 }


location pick() {
    // generates a random location
    
    location mySpot;
    srand(int(time(0)));
    mySpot.x = rand() % 5 + 1;
    int y = rand() % 5 + 1;

    switch (y) {
        case -1:
            mySpot.y = 'X';
            break;
        case 1:
            mySpot.y = 'a';
            break;
        case 2:
            mySpot.y = 'b';
            break;
        case 3:
            mySpot.y = 'c';
            break;
        case 4:
            mySpot.y = 'd';
            break;
        case 5:
            mySpot.y = 'e';
            break;
    }
    return mySpot;
}


void deploy(ship myFleet[]) {
    // places an array of battleships in
    // random locations in the ocean
    
    int i = 0;
    while (i < 6) {
        location mySpot = pick();
        int tmp = check(&myFleet[FLEET_SIZE], mySpot);
        if (tmp == -1) {
            myFleet[tmp] = {mySpot};
            ++i;
        }
    // !! STILL NEED TO ADD STATUS OF THE SHIP BEING "not sunk" !!
    }
 }

 
 
 
// DISPLAY FUNCTIONS

 
void printShip(ship myShip) {
    // prints the location and status (sunk or not) of a single ship

    cout << "The ship is at: " << myShip.loc.x  << myShip.loc.y << endl;
    cout << "Status of ship: ";
    if (myShip.sunk == 0)
        cout << "The ship is still alive!" << endl;
    else
        cout << "The ship was sunk!" << endl;
        }


void printFleet(ship myFleet[]) {
    // prints the locations of all the ships and whether they are sunk
    
    for (int i = 0; i < 6; ++i) {
        cout << "The ship is at: " << myFleet[i].loc.x  << myFleet[i].loc.y << endl;
        cout << "Status of ship: ";
        if (myFleet[i].sunk == 0) //thissss right here what am I doing
            cout << "The ship is still alive!" << endl;
        else
            cout << "The ship was sunk!" << endl;
    }
}


 

// BATTLE FUNCTIONS

 
bool operational(ship myFleet[]) {
    // returns true if at least one ship in the array is not sunk

    for (int i = 0; i < 6; ++i) {
        if (myFleet[i].loc.x != -1 && myFleet[i].loc.y != -1)
            return true;
    }
    return false;
 }
 

location fire() {
    // asks the user to input the coordinates of the next shot
    
    location mySpot;
    cout << "Where will you take your next shot? (Coordinates 1-5 a-e separated by a space): ";
    cin >> mySpot.x >> mySpot.y;
    return mySpot;
}

 
void sink(ship myShip) {
    // sets "sunk" member variable of the ship to true
    
    myShip.sunk = true;
}