/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/design-hashmap/
 */
#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;
class MyHashMap {
public:
    vector<list<pair<int, int>>> bucket;
    MyHashMap() {
        bucket.resize(1009);
    }
    void put(int key, int value) {
        int bucket_no = key%1009;
        auto& chain = bucket[bucket_no];
        for(auto& it:chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    int get(int key) {
        int bucket_no = key%1009;
        auto& chain = bucket[bucket_no];
        if(chain.empty())
            return -1;
        for(auto& it:chain) {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    void remove(int key) {
        int bucket_no = key%1009;
        auto& chain = bucket[bucket_no];
        for (auto it=chain.begin(); it!=chain.end(); ) {
            if(it->first == key) {
                chain.erase(it);
                return;
            }
            it++;
        }
    }
};
