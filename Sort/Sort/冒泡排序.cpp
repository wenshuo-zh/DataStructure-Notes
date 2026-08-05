#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int nums[N];

//冒泡排序（从大到小）
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
//时间复杂度：最好O(n) 平均/最坏O(n^2)
//空间复杂度：O(1)
//稳定性：稳定


int main() {
	int arr[] = { 77,23,11,1,24,91,0,41,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	cout << endl;
	return 0;
}
