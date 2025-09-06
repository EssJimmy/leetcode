#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n){
        if(n == 1) return vector<string>(1, "1");

        vector<string> ans = {"1", "2"};
        if(n == 2) return ans;

        for(int i = 3; i <= n; i++) {
            if(!(i % 5) && !(i % 3)) ans.push_back("FizzBuzz");
            else if (!(i%3)) ans.push_back("Fizz");
            else if (!(i%5)) ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }

        return ans;
    }
};
