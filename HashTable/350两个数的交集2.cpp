#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mp;
        //键传数据，值传出现次数
        for (auto& it : nums1) mp[it]++;
        //{
        //    //1.如果当前数据已经出现过，让值加一
        //    //mp.find(it)-键值对的指针
        //    if (mp.find(it) != mp.end()) (mp.find(it)->second)++;
        //    //2.没找到，新建一个键值对，值为1
        //    else mp.insert({ it,1 });
        //}     
       
        vector<int> ans;        
        for (auto& it : nums2) {
            //下标访问会创建，所以不能下标访问
            if (mp.count(it) && mp[it] > 0) {
                ans.push_back(it);
                mp[it]--;
            }
        }
        return ans;
    }
};