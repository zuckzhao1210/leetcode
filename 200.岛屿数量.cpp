// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int ans = 0;
//         vector<vector<bool>> flags(grid.size(), vector<bool>(grid[0].size(), false));
//         for (int i = 0; i < grid.size(); ++i) {
//             for (int j = 0; j < grid[0].size(); ++j) {
//                 if (!flags[i][j] && grid[i][j] == '1') {
//                     ++ans;
//                     island(grid, i, j, flags);
//                 }
//             }
//         }
//         return ans;
//     }

//     void island(vector<vector<char>>& grid, int i , int j, vector<vector<bool>>& flags) {
//         if (i >= grid.size() || j >= grid[0].size()) return;
        
//         if (grid[i][j] == '1') {
//             flags[i][j] = true;
//             island(grid, i-1, j, flags);
//             island(grid, i+1, j, flags);
//             island(grid, i, j-1, flags);
//             island(grid, i, j+1, flags);
//         }
//         return;
//     }
// };

class Solution {
public:
    const vector<int> dir_y = {1,0,-1,0};
    const vector<int> dir_x = {0,1,0,-1};
    void dfs(vector<vector<char>>& grid, int x, int y){
        if(!(x>=0  && x <grid.size()&& y >= 0 && y < grid[0].size())){
            return;
        }
        if(grid[x][y] != '1') return;
        grid[x][y] = '2';
        for(int i = 0; i < 4; i++){

            dfs(grid, x+dir_x[i], y+dir_y[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ret = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

