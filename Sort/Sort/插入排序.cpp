#include<bits/stdc++.h>
using namespace std;

//插入排序（从小到大）：将数组分成有序区和无序区
void insertSort(vector<int>&vec) {
	int n = vec.size();
	for (int i = 1; i < n; i++) {
		int temp = vec[i];
		//将无序区的第一个数拿出来，遍历有序区，小于有序区的数就让有序区的数后移，最后再插入到有序区合适的位置
		int j = i - 1;
		for (; j >= 0; j--) {
			if (vec[j] > temp)vec[j + 1] = vec[j];
			else break;
		}
		//因为循环之后j--了，所以要定位有序区最后一位的下标，需要+1
		vec[j+1] = temp;
	}
}
//时间复杂度：最好O(n) 已经有序 平均/最坏O(n^2)
//空间复杂度：O(1)
//稳定性：稳定

int main() {
	vector<int>vec = { 77,23,11,1,24,91,0,41,6 };
	insertSort(vec);
	for (auto it : vec)cout << it << " ";
	cout << endl;
	return 0;
}