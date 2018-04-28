#include <iostream>
#include <cstdlib>
#include "member.h"
#include "room.h"
#include "relation.h"

using namespace std;

int main()
{
    listMember listmem;
    ListRoom lR;
    ListRelation listRel;

    member p;
    Room c;

    addressMember aP;
    addressRoom aC;
    addressRelation aR;


    int menu;

    createListMember(listmem);
    createListRoom(lR);
    createListRelation(listRel);

    p.id = 1;
    p.name = "Gumilar";
    p.username = "gumi";
    p.password = "heuheuheu";
    aP = allocateMember(p);
    insertLastMember(listmem, aP);

    p.id = 2;
    p.name = "Haqita";
    p.username = "Haqi";
    p.password = "adouch";
    aP = allocateMember(p);
    insertLastMember(listmem, aP);

    p.id = 3;
    p.name = "BOBOBOI";
    p.username = "boi";
    p.password = "heuheuheu";
    aP = allocateMember(p);
    insertLastMember(listmem, aP);


    c.id = 1;
    c.large = 25;
    c.price = 750000;
    aC = allocateRoom(c);
    insertLastRoom(lR, aC);

    c.id = 2;
    c.large = 30;
    c.price = 900000;
    aC = allocateRoom(c);
    insertLastRoom(lR, aC);


    while(true){
        cout<<endl;
        cout<<" =---------- Welcome to Our Project ---------="<<endl;
        cout<<" ==------------ TUBES STD(2018) -------------="<<endl;
        cout<<"+                                             +"<<endl;
        cout<<"+        Gumilar Sulistian - 1301153625       +"<<endl;
        cout<<"+        Haqita Anjar Alam - 1301153681       +"<<endl;
        cout<<"+                                             +"<<endl;
        cout<<" ==--------------  IF-40-INT  --------------=="<<endl;
        cout<<" =--------------- Room Rental ---------------="<<endl;
        cout<<" "<<endl;
        cout<<"     1.   List of Member"<<endl;
        cout<<"     2.   List of Room"<<endl;
        cout<<"     3.   Input new Member"<<endl;
        cout<<"     4.   Input new Room"<<endl;
        cout<<"     5.   Edit Member data by ID"<<endl;
        cout<<"     6.   Edit Room data by ID"<<endl;
        cout<<"     7.   Delete Member by ID"<<endl;
        cout<<"     8.   Delete Room by ID"<<endl;
        cout<<"     9.   Choose room for member by ID"<<endl;
        cout<<"     10.  List of Member & Room"<<endl;
        cout<<"     11.  Average of ALL price"<<endl;
        cout<<" "<<endl;
        cout<<"     0.  Keluar Program"<<endl;
        cout<<" "<<endl;
        cout<<" ---------------------------------------------"<<endl;
        cout<<" "<<endl;

        cout<<endl;
        cout<<"     Choose with NUMBER: ";
        cin>>menu;
        if(cin.fail()){
            cin.clear();
            cout<<"     Please input with NUMBER!, press 'enter' to continue...";
            cin.sync();
            cin.get();
        }else{
            switch(menu){
                case 0:
                    return 0;
                break;
                case 1:
                    cout<<endl;
                    printInfoMember(listmem);
                    cout<<"     press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 2:
                    cout<<endl;
                    printInfoRoom(lR);
                    cout<<"     press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 3:
                    p = createMemberData();
                    if(findElmMember(listmem,p) == NULL){
                        aP = allocateMember(p);
                        insertLastMember(listmem, aP);
                    }
                    else{
                        cout<<"     Sorry that ID is already exist, press 'enter' to continue...";
                    }
                    cin.sync();
                    system("cls");
                break;
                case 4:
                    c = createRoom();
                    if(findElmRoom(lR,c) == NULL){
                        aC = allocateRoom(c);
                        insertLastRoom(lR, aC);
                    }
                    else{
                        cout<<"     Sorry that ID is already exist, press 'enter' to continue...";
                    }
                    cin.sync();
                    system("cls");
                break;
                case 5:
                    cout<<"  Input Member ID  : ";
                    cin>>p.id;
                    aP = findElmMember(listmem,p);
                    if(aP == NULL){
                        cout<<"     ID not found! press 'enter' to continue...";
                    }
                    else{
                        p = info(aP);
                        editMemberData(info(aP));
                    }
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 6:
                    cout<<"     Input Room ID  : ";
                    cin>>c.id;
                    aC = findElmRoom(lR,c);
                    if(aC == NULL){
                        cout<<"     ID not found! press 'enter' to continue...";

                    }
                    else{
                        editRoom(info(aC));
                    }
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 7:
                    cout<<"     Input Member ID: ";
                    cin>>p.id;
                    aP = findElmMember(listmem,p);
                    if(aP == NULL){
                        cout<<"     ID not found! press 'enter' to continue...";
                    }
                    else{
                        deleteByIDMember(listmem,aP);
                        cout<<info(aP).name<<"      Deleted from list press 'enter' to continue...";
                        aR = first(listRel);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(member(aR) == aP){
                                deleteRelation(listRel,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        deallocateMember(aP);
                    }
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 8:
                    cout<<"     Input Room ID: ";
                    cin>>c.id;
                    aC = findElmRoom(lR,c);
                    if(aC == NULL){
                        cout<<"     ID not found! press 'enter' to continue...";
                    }
                    else{
                        deleteByIDRoom(lR,aC);
                        cout<<info(aC).id<<"    Deleted from list press 'enter' to continue...";
                        aR = first(listRel);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(Room(aR) == aC){
                                deleteRelation(listRel,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        deallocateRoom(aC);
                    }
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 9:
                    cout<<"     Input ID Member  : ";
                    cin>>p.id;
                    cout<<"     Input ID Room : ";
                    cin>>c.id;
                    aP = findElmMember(listmem, p);
                    aC = findElmRoom(lR, c);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(listRel,aP,aC);
                        if(aR == NULL){
                            aR = allocateRelation(aP,aC);
                            insertRelation(listRel, aR);
                        }
                        cout<<"     Member "<<info(aP).name<<" rent room with id "<<info(aC).id<<endl;
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"     ID member & ID room not found";
                    }
                    else if(aC == NULL){
                        cout<<"     ID room not found!";
                    }
                    else if(aP == NULL){
                        cout<<"         ID member not found!";
                    }
                    cout<<"     press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 10:
                    cout<<endl;
                    printMemberRoom(listmem, listRel);
                    cout<<"     press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                    system("cls");
                break;
                case 11:
                    cout<<endl;
                    void averageOfAllPrice(ListRoom, ListRelation );
                    cout<<"     press 'enter' to continue...";
                    cin.sync();
                    cin.get();
                break;
            }

        }

    }
}

