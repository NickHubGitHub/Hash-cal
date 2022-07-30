#include "hash_table.hpp"
int hash_map::hash_func(std::string key) {
    return (key[0]*key[1] + key[1])%size;
}
bool hash_map::insert(hash_item item) {
    int ind = hash_func(item.key);
    while(map[ind].key != " "&& map[ind].key != "empty"){
        ind = ++ind%size;
        if(ind == hash_func(item.key))
            return false;   //map is full
    }
    map[ind] = item;
    return true;
}
