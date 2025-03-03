#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_set<string> st;
        stringstream ss(s);
        vector<string> v;
        string temp;

        while(getline(ss, temp, ' ')){
            v.push_back(temp);
        }

        if(pattern.size() != v.size()) return false;

        for(auto i = 0; i < pattern.size(); i++){
            if(mpp.find(pattern[i]) == mpp.cend() && st.find(v[i]) == st.cend()) {
                mpp[pattern[i]] = v[i];
                st.emplace(v[i]);
            }
            else {
                if(mpp[pattern[i]] != v[i])
                    return false;
            }
        }

        return true;
    }
};