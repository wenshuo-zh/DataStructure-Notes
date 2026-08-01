#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mp;
        vector<int>ans;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it == mp.end()) mp[nums[i]] = i;
            else {
                //尾部添加两个下标
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};