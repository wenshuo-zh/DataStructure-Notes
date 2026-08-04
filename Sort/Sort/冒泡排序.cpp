#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int nums[N];

//从大到小排序
void bubbleSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;      
        for (int j = 0; j < n - 1 - i; j++)
        {            
            if (nums[j] < nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag) break; // 无交换说明已有序，提前退出
    }
}

