#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int nums[N];

//选择排序（从大到小）：分有序序列和无序序列
void selectSort(int nums[], int n) {
	//默认nums[0]为有序，从i=1开始遍历无序区
	for (int i = 1; i < n; i++) {
		int maxIndex = i;
		//遍历无序区，找到未排序数列的最大值，将最值和无序区第一项交换，归并到有序区
		for (int j = i; j < n; j++) {
			if (nums[j] > nums[maxIndex]) {
				maxIndex = j;
			}
		}
		swap(nums[maxIndex], nums[i]);
	}
}
//时间复杂度：最好/平均/最坏：O(n^2)
//空间复杂度：O(1)
//稳定性：不稳定
int main() {
	int arr[] = { 77,23,11,1,24,91,0,41,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectSort(arr, n);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	cout << endl;
	return 0;
}