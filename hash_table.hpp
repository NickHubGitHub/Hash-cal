#ifndef HASH_TABLE
#define HASH_TABLE
#include <string>
struct hash_item{
    std::string key;
    float val;
    hash_item(){}
    hash_item(std::string c, float f): key(c), val(f){}
};

class hash_map{
private:
    int size;
    hash_item *map;	//hash table
    int hash_func(std::string);	//returns the hash index
public:
    bool insert(hash_item); 
    bool remove(std::string);	//takes key to be removed as argument
    bool update(std::string,float);	//arguments are key to be updated and the new value
    hash_item* search(std::string);	//argument is the key to be found and returns the value associated
    hash_map(int s): size(s) {map = new hash_item[s];for(int i = 0;i<size;i++){map[i].key = " ";}}
};
#endif
