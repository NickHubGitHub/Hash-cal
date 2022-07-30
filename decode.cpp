#include "decode.h"
using namespace std;
deque<string>* decode(string exp){
    regex c_reg("(Create|Print|Delete)\\s([A-Z][0-9][0-9]?)");
    regex e_reg("([A-Z][0-9])(?:\\s*)=(((?:\\s*)(~)?(\\d+|[A-Z][0-9])(?:\\s*)(\\+|-|\\*|/))*)(?:\\s*)(~)?(\\d+|[A-Z][0-9])(?:\\s*)");
    regex e_reg1("((?:\\s*)~?([A-Z][0-9]|\\d+)(?:\\s*)([+\\-*/])(?:\\s*))+");
    smatch match;
    deque<string> *ret = new deque<string>;
    if(regex_match(exp,match,c_reg)){
        ret->push_back(match.str(1));
        ret->push_back(match.str(2));
    }
    else if(regex_match(exp,match,e_reg)){
        string var = match.str(1);
        ret->push_front(match.str(8));
        string sub_exp = match.str(2);
        if(match.str(7)=="~")
            ret->push_front("~");
        if(sub_exp == ""){
            ret->push_front(var);
            return ret;
        }
        while(regex_match(sub_exp,match,e_reg1)){
            int count = 2;
            ret->push_front(match.str(3));
            ret->push_front(match.str(2));
            for(count;count>0;count--){
                if(sub_exp.back() == ' ')
                    count++;
                sub_exp.pop_back();
            }
            while(sub_exp.size()&&sub_exp.back()!='+'&&sub_exp.back()!='-'&&sub_exp.back()!='*'&&sub_exp.back()!='~'&&sub_exp.back()!='/')
                sub_exp.pop_back();
            if(sub_exp.back()=='~'){
                ret->push_front("~");
                sub_exp.pop_back();
            }
        }
        ret->push_front(var);
    }
    else{return NULL;}
    return ret;
}
