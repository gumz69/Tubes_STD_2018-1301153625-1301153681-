#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <iostream>
#include "memberData.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmListMember *addressMember;

struct elmListMember{
    member info;
    addressMember next;
    addressMember prev;
};

struct listMember{
    addressMember first;
    addressMember last;
};

void createListMember(listMember &L);
addressMember allocateMember(member x);
void deallocateMember(addressMember &P);

// define insert and delete procedure
void insertFirstMember(listMember &L, addressMember P);
void insertLastMember(listMember &L, addressMember P);
void insertAfterMember(listMember &L, addressMember Prec, addressMember P);
void deleteFirstMember(listMember &L, addressMember &P);
void deleteLastMember(listMember &L, addressMember &P);
void deleteAfterMember(listMember &L, addressMember Prec, addressMember &P);
void deleteByIDMember(listMember &L, addressMember &P);
// define search-by-ID function and view procedure
addressMember findElmMember(listMember L, member x);
void printInfoMember(listMember L);


#endif // MEMBER_H_INCLUDED
