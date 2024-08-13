#include <bits/stdc++.h>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    unordered_map<int, unordered_set<int>> mpp;

    for(auto it : prerequisites){
        if(mpp.find(it[0]) != mpp.end()) {
            if(mpp[it[0]].find(it[1]) != mpp[it[0]].end()) return false;

            mpp[it[0]].insert(it[1]);
        }
    }
}