#pragma once
#include <string>
#include <deque>
#include <regex>
#include <iostream>
#include "hash_table.hpp"
using namespace std;
bool EXP_Parse(deque<string>* _exp, hash_map* map);
void p_Queue(deque<string>* _exp, hash_map* map);
bool Create_V(string _key, hash_map* map);
bool Print_V(string _key, hash_map* map);
bool Delete_V(string key, hash_map* map);

