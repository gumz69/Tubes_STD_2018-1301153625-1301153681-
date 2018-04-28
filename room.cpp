#include "room.h"
#include "roomData.h"

void createListRoom(ListRoom &L){
    first(L) = NULL;
}
addressRoom allocateRoom(Room x){
    addressRoom P;
    P = new elmlistRoom;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void deallocateRoom(addressRoom &P){
    delete P;
}
void insertFirstRoom(ListRoom &L, addressRoom P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else{
        addressRoom Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}
void insertLastRoom(ListRoom &L, addressRoom P){
    if(first(L) == NULL){
        insertFirstRoom(L,P);
    }
    else{
        addressRoom Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}
void insertAfterRoom(ListRoom &L, addressRoom Prec, addressRoom P){
    if((Prec != NULL) && (first(L) != NULL)){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}
void deleteFirstRoom(ListRoom &L, addressRoom &P){
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            first(L) = NULL;
        }
        else{
            addressRoom Q = first(L);
            while(next(Q) != first(L)){
                Q = next(Q);
            }
            first(L) = next(P);
            next(Q) = first(L);
        }
    }
}
void deleteLastRoom(ListRoom &L, addressRoom &P){
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            deleteFirstRoom(L,P);
        }
        else{
            addressRoom Q = first(L);
            while(next(next(Q)) != first(L)){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
        }
    }
}
void deleteAfterRoom(ListRoom &L, addressRoom Prec, addressRoom &P){
    if((Prec != NULL) && (first(L) != NULL)){
        P = next(Prec);
        next(Prec) = next(P);
    }
}
void deleteByIDRoom(ListRoom &L, addressRoom &P){
    if(P == first(L)){
        deleteFirstRoom(L,P);
    }
    else if(next(P) == first(L)){
        deleteLastRoom(L,P);
    }
    else{
        addressRoom Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        deleteAfterRoom(L,Q,P);
    }
}
addressRoom findElmRoom(ListRoom L, Room x){
    if(first(L) != NULL){
        addressRoom P = first(L);
        do{
            if(info(P).id == x.id){
                return P;
            }
            P = next(P);
        }while(P != first(L));
    }
    return NULL;
}
void printInfoRoom(ListRoom L){
    if(first(L) != NULL){
        addressRoom P = first(L);
        do{
            viewRoom(info(P));
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    }
}
