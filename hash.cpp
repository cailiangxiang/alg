#include<iostream>
#include<string>
#include<unordered_map>

#include"windows.h"

using namespace std;

int main(){
    /* Initialize hash table */
    unordered_map<int,string> map;

    /* Add operation */
    // Add key-value pair (key, value) to the hash
    map[1] = "zhang";
    map[2] = "cai";
    map[3] = "sun";

    for(auto kv:map){
        cout << kv.first << "->" << kv.second << endl;
    }

    for(auto iter = map.begin(); iter != map.end();iter++){
        cout << iter->first << "->" << iter->second << endl;
    }

    system("pause");

    return 0;
}