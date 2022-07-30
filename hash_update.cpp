#include "hash_table.hpp"
bool hash_map::update(std::string key, float val){
    //key search
    hash_item* ptr = search(key);
    if(!ptr){
        return false;
    }
    else{
        ptr->val = val;
}
return true;
}
