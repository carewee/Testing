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
    // uses match()
    for (int i = 0; i < 6; ++i)
        if (match(myFleet[i], location) == true)
            return i;
        else
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
//    // places an array of battleships in
//    // random locations in the ocean
    for (int i = 0; i < 6; ++i){
        tmp = check(pick());
        if (tmp != -1)
            myFleet[i] = tmp;
    }

/*
 The pseudocode for deploy()is as follows:
 declare a variable that stores the number of the deployed ships, initially zero
 this variable is to be used as an index in the array of ships
 loop until all ships are deployed
 invoke pick() to get a new random location in the ocean
 invoke check() to verify whether this location is occupied
 if this location is available then
 deploy the next ship at this location by storing the coordinates
 of this location in the ship's location, change the status of
 the ship to "not sunk"
 increment the number of the deployed ships
 */
 }

 
 
 
// DISPLAY FUNCTIONS

 
void printShip(ship myShip) {
    // prints the location and status (sunk or not)
    // of a single ship
    cout << "The ship is at: " << myShip.loc.x  << myShip.loc.y << endl;
    cout << "Status of ship: ";
    if (myShip.sunk == 0)
        cout << "The ship is still alive!" << endl;
    else
        cout << "The ship was sunk!" << endl;
        }
//ship myFleet[FLEET_SIZE]


void printFleet(ship myFleet[]) {
    // prints the locations of all the ships and
    // whether they are sunk
    for (int i = 0; i < 6; ++i) {
        cout << "The ship is at: " << myFleet[i].loc.x  << myFleet[i].loc.y << endl;
        cout << "Status of ship: ";
        if (myFleet[i].sunk == 0)
            cout << "The ship is still alive!" << endl;
        else
            cout << "The ship was sunk!" << endl;
    }
}

 
 

// BATTLE FUNCTIONS

 
//bool operational(const ship[]) {
    // returns true if at least one ship in the array
    // is not sunk
// }
 
 
// 
location fire() {
    location mySpot;

    cout << "Where will you take your next shot? (Coordinates 1-5 a-e separated by a space): ";
    cin >> mySpot.x >> mySpot.y;
    return mySpot;
    // note that check() is also used in the battle
}

 
 
void sink(ship &myShip) {
    myShip.sunk = true;
}