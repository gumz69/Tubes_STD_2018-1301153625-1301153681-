#include "roomData.h"

Room createRoom(){
    Room d;
    cout<<"     No. Room    : ";
    cin>>d.id;
    cout<<"     Large(m^2)  : ";
    cin>>d.large;
    cout<<"     Price       : ";
    cin>>d.price;
    return d;
}

void viewRoom(Room d){
    cout<<"     No. Room    : "<<d.id<<endl;
    cout<<"     Large(m^2)  : "<<d.large<<endl;
    cout<<"     Price       : "<<d.price<<endl;
}

void editRoom(Room &d){
    cout<<"     No. Room    : ";
    cin>>d.id;
    cout<<"     Large(m^2)  : ";
    cin>>d.large;
    cout<<"     Price       : ";
    cin>>d.price;
}
