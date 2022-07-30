#include "hash_table.hpp"
//search for key value
#include <iostream>
bool hash_map::remove(std::string key){
    hash_item* item = search(key);
    if(!item){
        return false;
    }
    else{
        std::cout <<key <<" Cleared\n";
        item->val = 0;
        return true;
    }
}