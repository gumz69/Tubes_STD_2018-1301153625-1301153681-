#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include "roomData.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmlistRoom *addressRoom;

struct elmlistRoom{
    Room info;
    addressRoom next;
};

struct ListRoom{
    addressRoom first;
};

void createListRoom(ListRoom &L);
addressRoom allocateRoom(Room x);
void deallocateRoom(addressRoom &P);

// define insert and delete procedure
void insertFirstRoom(ListRoom &L, addressRoom P);
void insertLastRoom(ListRoom &L, addressRoom P);
void insertAfterRoom(ListRoom &L, addressRoom Prec, addressRoom P);
void deleteFirstRoom(ListRoom &L, addressRoom &P);
void deleteLastRoom(ListRoom &L, addressRoom &P);
void deleteAfterRoom(ListRoom &L, addressRoom Prec, addressRoom &P);
void deleteByIDRoom(ListRoom &L, addressRoom &P);

// define search-by-ID function and view procedure
addressRoom findElmRoom(ListRoom L, Room x);
void printInfoRoom(ListRoom L);

#endif // ROOM_H_INCLUDED
