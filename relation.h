#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include "member.h"
#include "room.h"

#define first(L) L.first
#define member(P) P->member
#define Room(P) P->Room
#define next(P) P->next


using namespace std;

typedef struct elmListMember *addressMember;
typedef struct elmlistRoom *addressRoom;
typedef struct elmlistRelation *addressRelation;


struct elmlistRelation{
    addressMember member;
    addressRoom Room;
    addressRelation next;
};

struct ListRelation{
    addressRelation first;
};

void createListRelation(ListRelation &L);
addressRelation allocateRelation(addressMember aP, addressRoom aC);
void deallocateRelation(addressRelation &P);

void insertRelation(ListRelation &L, addressRelation P);
void deleteRelation(ListRelation &L, addressRelation &P);
addressRelation findRelation(ListRelation L, addressMember aP, addressRoom aC);

void printMemberRoom(listMember listmem, ListRelation listRel);


#endif // RELATION_H_INCLUDED
