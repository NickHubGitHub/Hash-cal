#include <iostream>
#include <string>
#include "Uinput.hpp"
#include "hash_table.hpp"
#include <queue>
using namespace std;

int main(){
    hash_map *map;
    map = new hash_map(501);
    //string inp;
    cout<<"Starting Calculator Terminal...\nTerminal Ready\n";
    UInput(map);
    return 0;
}
