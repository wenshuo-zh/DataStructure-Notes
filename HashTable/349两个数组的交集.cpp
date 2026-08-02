#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for (auto& it : nums1)s1.insert(it);
        for (auto& it : nums2)s2.insert(it);

        vector<int>ans;
        
        for (auto& it : s2) {
            if (s1.count(it))ans.push_back(it);
        }
        return ans;
    }
};