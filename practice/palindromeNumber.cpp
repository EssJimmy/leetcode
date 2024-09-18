#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x){
        if(x <= 0) return false;        
        if(x < 9) return true;

        int ans = 0;
        int cp = x;
        while(cp) {
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10) return false;

            ans = ans*10 + (cp%10);
            cp /= 10;
        }
        return ans == x;
    }
};