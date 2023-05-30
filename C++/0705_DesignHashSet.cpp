/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/design-hashset/
 */
#include <iostream>
#include <vector>
using namespace std;
#define prime 104729
// Largest prime number within the given range which is used for hashing
class MyHashSet {
public:
    vector<int> map;
    MyHashSet() {
        map.resize(prime, -1);
    }
    // Modulo Division method is used 
    void add(int key) {
        int index = key % prime;
        if (map[index] == -1) {
            map[index] = key;
        }
    }

    void remove(int key) {
        int index = key % prime;
        if (map[index] == key) {
            map[index] = -1;
        }
    }

    bool contains(int key) {
        int index = key % prime;
        return (map[index] == key);
    }
};
