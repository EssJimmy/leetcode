#include <bits/stdc++.h>

using namespace std;

class SummaryRanges{
public:
    SummaryRanges(){}

    void addNum(int val) {
        // if value is in interval no point in doing anything
        if(intervals.find(val) != intervals.cend()) return; // should be intervals.contains but compiler is being annoying

        const int lo = lowerKey(val);
        const int hi = higherKey(val);

        // check if two intervals should be merged
        if (lo >= 0 && hi >= 0 && intervals[lo][1] + 1 == val && val + 1 == hi) {
            intervals[lo][1] = intervals[hi][1];
            intervals.erase(hi);
        } else if (lo >= 0 && intervals[lo][1] + 1 >= val) { //if they dont need to be merged check if you need to append to smaller interval
            intervals[lo][1] = max(intervals[lo][1], val);
        } else if (hi >= 0 && val + 1 == hi) { // or to higher interval
            intervals[val] = {val, intervals[hi][1]};
            intervals.erase(hi);
        } else {
            intervals[val] = {val, val}; //if not then its a sole value and its not needed to append
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(const auto& [_, interval] : intervals) {
            res.push_back(interval);
        }

        return res;
    }

private:
    map<int, vector<int>> intervals;

    // returns max of the smaller interval
    int lowerKey(int key) {
        auto it = intervals.lower_bound(key);
        if (it == intervals.begin())
            return -1;
        
        return (--it)->first;
    }

    // returns min of the higher interval
    int higherKey(int key) {
        auto it = intervals.upper_bound(key);
        if (it == intervals.cend())
            return -1;

        return it->first;
    }
};