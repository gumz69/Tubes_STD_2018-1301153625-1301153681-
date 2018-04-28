#include "relation.h"
#include "member.h"
#include "room.h"

void createListRelation(ListRelation &L){
    first(L) = NULL;
}

addressRelation allocateRelation(addressMember aP, addressRoom aC){
    addressRelation P = new elmlistRelation;
    member(P) = aP;
    Room(P)  = aC;
    return P;
}

void deallocateRelation(addressRelation &P){
    delete P;
}

void insertRelation(ListRelation &L, addressRelation P){
    if(first(L) == NULL){
        first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

void deleteRelation(ListRelation &L, addressRelation &P){
    if(first(L) != NULL){
        if(P == first(L)){
            first(L) = next(first(L));
        }
        addressRelation Q = first(L);
        while(next(Q) != NULL){
            if(next(Q) == P){
                next(Q) = next(P);
                break;
            }
            Q = next(Q);
        }
    }
}

addressRelation findRelation(ListRelation L, addressMember aP, addressRoom aC){
    if(first(L) != NULL){
        addressRelation P = first(L);
        while(P != NULL){
            if((member(P) == aP) && (Room(P) == aC)){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void printMemberRoom(listMember listmem, ListRelation listRel){
    addressMember pmem = first(listmem);
    bool yess = false;
    if(pmem != NULL){
        addressRelation pRelasi = first(listRel);
        if(pRelasi != NULL){
            if(member(pRelasi) == pmem){
                yess = true;
                cout<<"     Member Name  : "<<info(member(pRelasi)).name<<endl;
                cout<<"     Room ID      : "<<info(Room(pRelasi)).id<<endl;
                cout<<"     Large of Room: "<<info(Room(pRelasi)).large<<endl;
                cout<<"     Price of Room: "<<info(Room(pRelasi)).price<<endl;
            }
            pRelasi = next(pRelasi);
        }
        if(yess == false){
            cout<<"     No one rent a room";
        }
        cout<<endl<<endl;
        pmem = next(pmem);
    }
}
