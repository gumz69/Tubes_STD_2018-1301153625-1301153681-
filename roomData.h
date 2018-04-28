#ifndef ROOMDATA_H_INCLUDED
#define ROOMDATA_H_INCLUDED

#include <iostream>
using namespace std;

struct Room{
    int id;
    int large;
    int price;
};

Room createRoom();
void viewRoom(Room d);
void editRoom(Room &d);

#endif // ROOMDATA_H_INCLUDED
