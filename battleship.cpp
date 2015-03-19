// Carrie Hadley
// March, 2015

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



//int check(const ship[], location){

//    // returns the index of element of the array
//    // that matches the location
//    // returns -1 if none do
//    // uses match()

//if (match(ship, location) == true)

// }



//void initialize(ship[]) {
//    // places all ships in -1 X location to signify
//    // that the ship is not deployed
// }



location pick() {
    location mySpot;
    srand(int(time(0)));
    mySpot.x = rand() % 5 + 1;
    int y = rand() % 5 + 1;

    switch (y) {
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


//void deploy(ship[]) {
//    // places an array of battleships in
//    // random locations in the ocean

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
// }

 
 
 
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



//void printFleet(const ship[]);
//    // prints the locations of all the ships and
//    // whether they are sunk

 
 

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