// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem130.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j, vector<pair<int, int>>& zeros, bool& arrivalboard) {
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) {
            return;
        }
        if (board[i][j] == 'O') {
            board[i][j] = 'X';
            zeros.push_back({i, j});
            dfs(board, i-1, j, zeros, arrivalboard);
            dfs(board, i+1, j, zeros, arrivalboard);
            dfs(board, i, j-1, zeros, arrivalboard);
            dfs(board, i, j+1, zeros, arrivalboard);
            if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1) {
                arrivalboard = true;
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>> noteat;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    vector<pair<int, int>> zeros;
                    bool arrivalboard = false;
                    dfs(board, i, j, zeros, arrivalboard);
                    if (arrivalboard) {
                        noteat.insert(noteat.end(), zeros.begin(), zeros.end());
                    }
                }
            }
        }

        for (auto zero : noteat) {
            int i = zero.first;
            int j = zero.second;
            board[i][j] = 'O';
        }
        return;
    }
};
// @lc code=end

