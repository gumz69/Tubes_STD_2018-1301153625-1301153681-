#include "memberData.h"

member createMemberData(){
    member d;
    cout<<"     ID        : ";
    cin>>d.id;
    cout<<"     Name      : ";
    cin>>d.name;
    cout<<"     Username  : ";
    cin>>d.username;
    cout<<"     Password  : ";
    cin>>d.password;
    return d;
}

void viewMemberData(member d){
    cout<<"     ID         : "<<d.id<<endl;
    cout<<"     Name       : "<<d.name<<endl;
    cout<<"     Username   : "<<d.username<<endl;
    cout<<"     Password   : "<<d.password<<endl;
}

void editMemberData(member &d){
    cout<<"     Name      : ";
    cin>>d.name;
    cout<<"     Username  : ";
    cin>>d.username;
    cout<<"     Password  : ";
    cin>>d.password;
}
