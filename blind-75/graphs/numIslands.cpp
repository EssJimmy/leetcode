#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        
        numIslands(0, 0, result, grid, visited);
        return result;
    }

private:
    void numIslands(int i, int j, int count, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        if(i == grid.size() || i < 0 || j == grid[0].size() || j < 0) return;
        
        if(visited[i][j]) return;

        for(auto i = 0; i < grid.size(); i++) {
            for(auto j = 0; j < grid[0].size(); j++) {
                visited[i][j] = true;
                
                if(grid[i][j] - '0'){
                    numIslands(i, j+1, count, grid, visited);
                    numIslands(i+1, j, count, grid, visited);
                    numIslands(i, j-1, count, grid, visited);
                    numIslands(i-1, j, count, grid, visited);

                    ++count;
                }
            }
        }
    }

};