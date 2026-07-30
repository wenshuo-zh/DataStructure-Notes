#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) ans[i].push_back(1);
                else ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
        }
        return ans;
    }*/
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);//第i行创建i+1个空间
            ans[i][0] = 1;
            ans[i][i] = 1;
            for (int j = 1; j < i; j++) {//第二位到倒数第二位复制
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};