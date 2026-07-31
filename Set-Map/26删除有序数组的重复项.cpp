#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        //n = s.size();
        //for (int i = 0; i < n; i++) {
        //    //next()迭代器工具函数，返回迭代器向后偏移i位后的新迭代器
        //    auto it = next(s.begin(), i);
        //    nums[i] = *it;
        //}
        //增强for循环 ;依次取出的元素:要遍历的容器
        int i = 0;
        for (auto it : s) {
            nums[i++] = it;
        }
        return i;
    }
};