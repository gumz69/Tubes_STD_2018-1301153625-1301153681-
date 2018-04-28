#include "caseFunction.h"

void averageOfAllPrice(ListRoom lR, ListRelation listRel){
    addressRoom pR = first(lR);
    do{
        addressRelation pRelasi = first(listRel);
        float allPrice = 0;
        int allData = 0;

        while(pRelasi != NULL){
            if(Room(pRelasi) == pR){
                allPrice = allPrice + info(Room(pRelasi)).price;
                allData++;
            }
            pRelasi = next(pRelasi);
        }
        viewRoom(info(pR));
        cout<<"  Average of all Price  : "<<allPrice / allData<<endl;
        cout<<endl;
        pR = next(pR);
    }while(pR != first(lR));
}
