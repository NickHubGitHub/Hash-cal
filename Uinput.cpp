#include "Uinput.hpp"
#include <iostream>
#include <string>
using namespace std;


int UInput(hash_map* map){
    string inp;
        while(cin){
            cout<<">>";
            getline(cin,inp);
            if(inp == "quit"){
                cout<<"Bye!";
                return 0;
            }
        EXP_Parse(decode(inp),map);
    }
    return 0;
    
}