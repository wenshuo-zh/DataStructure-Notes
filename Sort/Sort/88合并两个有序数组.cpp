#include<bits/stdc++.h>
using namespace std;
//法一：直接排序
void insertSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int temp = vec[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (temp < vec[j])vec[j + 1] = vec[j];
            else break;
        }
        vec[j + 1] = temp;
    }
}
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
        insertSort(nums1);
    }
};

//法二：找两个数组中最大值倒序依次放入
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 || j >= 0) {
            int temp;
            if (j == -1)temp = nums1[i--];
            else if (i == -1)temp = nums2[j--];
            else if (nums1[i] >= nums2[j])temp = nums1[i--];
            else temp = nums2[j--];
            nums1[k--] = temp;
        }
    }
};