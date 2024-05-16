#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

/* 键值对 */
struct Pair{
public:
    int key;
    string val;
    Pair(int key, string val):key(key),val(val){}
};

/* 基于数组实现哈希表 */
class ArrHashMap{
private:
    vector<Pair*>buckets;

public:
    /* 初始化数组，包含100个桶 */
    ArrHashMap(){
        buckets = vector<Pair*>(100);

    }

    /* 释放内存 */
    ~ArrHashMap(){
        for(const auto bucket:buckets){
            delete bucket;
        }
        /* 释放完内存 元素仍然指向一个已释放内存的空间 */
        buckets.clear();
    }
    /* hash 函数 */
    int hashFunc(int key){
        return key%100;
    }
    /* 添加操作 */
    void put(int key, string val){
        int index = hashFunc(key);
        Pair* pair = new Pair(key,val);
        buckets[index] = pair;
    }

    /* 查询操作 */
    string get(int key){
        int index = hashFunc(key);
        Pair* pair = buckets[index];
        if(pair == nullptr)
            return "";

        return pair->val;
    }

    /* 删除操作 */
    void remove(int key){
        int index = hashFunc(key);
        if(buckets[index] != nullptr){
            delete buckets[index];
            buckets[index] = nullptr;
        }
    }

    /* 获取所有的键值对 */
    vector<Pair*> PairSet(){
        vector<Pair*> pairSet;
        for(auto bucket:buckets){
            if(bucket != nullptr){
                pairSet.push_back(bucket);
            }
        }

        return pairSet;
    }

    /* 获取所有的键 */
    vector<int> KeySet(){
        vector<int> keyset;
        for(auto bucket:buckets){
            if(bucket != nullptr){
                keyset.push_back(bucket->key);
            }
        }
        return keyset;
    }

    /* 获取所有的值 */
    vector<string> ValSet(){
        vector<string> valset;
        for(auto bucket:buckets){
            if (bucket !=nullptr)
            {
               valset.push_back(bucket->val);
            }
        }
        return valset;
    }

    /* 打印哈希表 */
    void print(){
        for(auto bucket:PairSet()){
            cout << bucket->key << "->" << bucket->val << endl;
        }
    }
};


int main(){
    ArrHashMap _arr_hash_map;
    _arr_hash_map.put(1,"a");
    _arr_hash_map.put(2,"b");
    _arr_hash_map.put(3,"c");
    _arr_hash_map.put(4,"d");

    vector<int>keyset = _arr_hash_map.KeySet();
    for(auto key:keyset){
        cout << key << " ";
    }
    cout << endl;
    vector<string>valset = _arr_hash_map.ValSet();
    for(auto val:valset){
        cout << val << " ";
    }
    cout << endl;
    _arr_hash_map.print();

    cout << "--------------------------" << endl;
    _arr_hash_map.remove(2);
    _arr_hash_map.print();

    cout << _arr_hash_map.get(3) << endl; 

    return 0;
}