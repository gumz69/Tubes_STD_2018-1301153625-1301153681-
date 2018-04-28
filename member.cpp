#include "member.h"
#include "memberData.h"

void createListMember(listMember &L){
    first(L) = NULL;
    last(L)  = NULL;
}
addressMember allocateMember(member x){
    addressMember P;
    P = new elmListMember;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}
void deallocateMember(addressMember &P){
    delete P;
}
void insertFirstMember(listMember &L, addressMember P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastMember(listMember &L, addressMember P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstMember(L,P);
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void insertAfterMember(listMember &L, addressMember Prec, addressMember P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstMember(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}
void deleteFirstMember(listMember &L, addressMember &P){
    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}
void deleteLastMember(listMember &L, addressMember &P){
    if(last(L) != NULL){
        P = last(L);
        if(first(L) == last(L)){
            deleteFirstMember(L,P);
        }
        else{
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}
void deleteAfterMember(listMember &L, addressMember Prec, addressMember &P){
    if((Prec != NULL) && next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteByIDMember(listMember &L, addressMember &P){
    if(P == first(L)){
        deleteFirstMember(L,P);
    }
    else if(P == last(L)){
        deleteLastMember(L,P);
    }
    else{
        addressMember Q = prev(P);
        deleteAfterMember(L,Q,P);
    }
}
addressMember findElmMember(listMember L, member x){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressMember P = first(L);
        while(P != NULL){
            if(info(P).id == x.id){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}
void printInfoMember(listMember L){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressMember P = first(L);
        while(P != NULL){
            viewMemberData(info(P));
            cout<<endl;
            P = next(P);
        }
    }
}
