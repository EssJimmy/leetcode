#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool isValidSudoku(vector<vector<char>>& board){
        vector<bool> rows(9, false);
        vector<bool> cols(9, false);
        vector<vector<bool>> square(9, {vector<bool>(9, false)});

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if(rows[i] || cols[j] || square[i/3][j/3]) return false;
                
                rows[i] = true; cols[j] = true; square[i/3][j/3] = true;
            }
        }

        return true;
    }
};