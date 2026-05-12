// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem399.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> stringToindex;
        int index = 0;
        for (auto& equation : equations) {
            for (auto& str : equation) {
                if (!stringToindex.contains(str)) {
                    stringToindex[str] = index;
                    ++index;
                }
            }
        }

        vector<vector<double>> graph(stringToindex.size(), vector<char>(stringToindex.size(), -1.0));
        for (int i = 0; i < equations.size(); ++i) {
            graph[stringToindex(equation[0])][stringToindex(equation[1])] = values[i];
            graph[stringToindex(equation[1])][stringToindex(equation[0])] = 1.0 / values[i];
        }

        vector<double> ans;
        for(auto& query : queries) {
            int an = -1;
            string first = query[0];
            string second = query[1];
            if (stringToindex.contains(first) && stringToindex.contains(second)) {
                dfs(stringToindex[first], stringToindex[second], an);
            }
            ans.push_back(an);
        }
        return ans;
    }

    void dfs(int i, int j, int& ans) {
        
    }
    

    
};
// @lc code=end

