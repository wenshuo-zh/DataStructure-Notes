#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, n = nums.size();
        for (int fast = 0; fast < n; fast++) {
            if (nums[fast])
                nums[slow++] = nums[fast];
        }
        // 把slow往后的位置全部置0
        //memset()函数的用法 
        //参数：要初始化的内存起始位置，按字节赋值的数值，需要填充的字节数量
        memset(&nums[slow], 0, (n - slow) * sizeof(int));
    }
};