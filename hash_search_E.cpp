
#include "hash_table.hpp"

 hash_item* hash_map::search(std::string s){
    int index = hash_func(s);

    int probed = 0;
    while (probed < size)
    {
        if (map[index].key == " "){
            return nullptr;
        }
        if (map[index].key == s){
            return &map[index];
        }
        index = (index + 1)%size;
        probed++;
    }
    return nullptr;



    
}
