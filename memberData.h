#ifndef MEMBERDATA_H_INCLUDED
#define MEMBERDATA_H_INCLUDED

#include <iostream>
using namespace std;

struct member{
    int id;
    string name;
    string username;
    string password;
};

member createMemberData();
void viewMemberData(member d);
void editMemberData(member &d);

#endif // MEMBERDATA_H_INCLUDED
