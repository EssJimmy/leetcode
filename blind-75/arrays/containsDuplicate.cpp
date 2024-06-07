#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums){
    int prevSize = 0;
    unordered_set<int> set;

    for(int& i : nums){
        set.insert(i);
        if(set.size() == prevSize)
            return true;

        prevSize++;
    }

    return false;
}