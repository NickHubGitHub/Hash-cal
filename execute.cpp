#include "execute.h"
bool EXP_Parse(deque<string>* exp, hash_map* map){
    if(!exp){
        cout<<"Invalid expression!"<<endl;
        return 0;
    }
    if(exp->front() == "Create")
        return Create_V(exp->back(), map);
    else if(exp->front() == "Print")
        return Print_V(exp->back(),map);
    else if(exp->front() == "Delete")
        return Delete_V(exp->back(),map);
    else{
        string per_var = exp->front();
        string var;
        exp->pop_front();
        float new_val;
        int neg = 1;
        if(exp->front() == "~") {
            neg = -1;
            exp->pop_front();
        }
        if(regex_match(exp->front(),regex("[A-Z][0-9]"))){
            var = exp->front();
            new_val = (map->search(var))? map->search(var)->val*neg: 0;
            exp->pop_front();
        }
        else if(regex_match(exp->front(),regex("\\d+"))){
            new_val = (float)stoi(exp->front())*neg;
            exp->pop_front();
        }
        while(exp->size()){
            neg = 1;
            switch((char)exp->front()[0]){
                case '+':{
                    exp->pop_front();
                    if(exp->front() == "~"){
                        neg = -1;
                        exp->pop_front();
                    }
                    if(regex_match(exp->front(),regex("[A-Z][0-9]"))){
                        var = exp->front();
                        new_val += (map->search(var))? map->search(var)->val*neg: 0;
                        exp->pop_front();
                    }
                    else if(regex_match(exp->front(),regex("\\d+"))){
                        new_val += (float)stoi(exp->front())*neg;
                        exp->pop_front();
                    }
                    break;
                }
                case '-':{
                    exp->pop_front();
                    if(exp->front() == "~"){
                        neg = -1;
                        exp->pop_front();
                    }
                    if(regex_match(exp->front(),regex("[A-Z][0-9]"))){
                        var = exp->front();
                        new_val -= (map->search(var))? map->search(var)->val*neg: 0;
                        exp->pop_front();
                    }
                    else if(regex_match(exp->front(),regex("\\d+"))){
                        new_val -= (float)stoi(exp->front())*neg;
                        exp->pop_front();
                    }
                    break;
                }
                case '*':{
                    exp->pop_front();
                    if(exp->front() == "~"){
                        neg = -1;
                        exp->pop_front();
                    }
                    if(regex_match(exp->front(),regex("[A-Z][0-9]"))){
                        var = exp->front();
                        new_val *= (map->search(var))? map->search(var)->val*neg: 0;
                        exp->pop_front();
                    }
                    else if(regex_match(exp->front(),regex("\\d+"))){
                        new_val *= (float)stoi(exp->front())*neg;
                        exp->pop_front();
                    }
                    break;
                }
                case '/':{
                    exp->pop_front();
                    if(exp->front() == "~"){
                        neg = -1;
                        exp->pop_front();
                    }
                    if(regex_match(exp->front(),regex("[A-Z][0-9]"))){
                        var = exp->front();
                        new_val /= (map->search(var))? map->search(var)->val*neg: 0;
                        exp->pop_front();
                    }
                    else if(regex_match(exp->front(),regex("\\d+"))){
                        new_val /= (float)stoi(exp->front())*neg;
                        exp->pop_front();
                    }
                    break;
                }
                default:
                    break;
            }
        }
        if(!map->update(per_var,new_val))
            cout<<"Error 5498. Variable space not allocated. Create Variable to assign value"<<endl;
        return map->update(per_var,new_val);
    }
}
bool Create_V(string key, hash_map* map){
    cout <<"Creating Variable:" << key <<endl;
    return map->insert(hash_item(key,0));
}
bool Print_V(string key, hash_map* map){
    hash_item* item = map->search(key);
    if(item){
        cout<<key << "=" <<item->val<<endl;
        return true;
    }
    cout<<"Variable not found"<<endl;
    return false;
}
bool Delete_V(string key, hash_map *map){
    
    return map->remove(key);
}
