/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : Design Underground System - LeetCode
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIn_umap; // id mapped with entry time and station
    unordered_map<string, pair<int, int>> checkOut_umap; // route mapped with total time for that route and its count
    UndergroundSystem() {
        
    }
    void checkIn(int id, string stationName, int t) {
        checkIn_umap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto &it = checkIn_umap[id];
        int startTime = it.second;
        int timeTaken = t - startTime;
        string entryStation = it.first;
        string exitStation = stationName;
        string route = entryStation + "_" + exitStation;
        checkOut_umap[route].first  += timeTaken;
        checkOut_umap[route].second += 1;
    }
    double getAverageTime(string startStation, string endStation) {
        string route =  startStation + "_" + endStation;
        auto &it = checkOut_umap[route];
        return (double)it.first/(double)it.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
