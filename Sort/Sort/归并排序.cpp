#include<bits/stdc++.h>
using namespace std;

void marge(vector<int>& vec, int left, int mid, int right) {
	int i = left, j = mid + 1;
	vector<int>temp;
	while (i <= mid || j <= right) {
		int tempNum;
		if (i == mid + 1)tempNum = vec[j++];
		else if (j == right + 1)tempNum = vec[i++];
		else if (vec[i] <= vec[j])tempNum = vec[i++];
		else tempNum = vec[j++];
		temp.push_back(tempNum);
	}
	for (int i = left; i <= right; i++) {
		vec[i] = temp[i - left];
	}
}

void margeSort(vector<int>&vec, int left, int right) {
	//终止
	if (left == right) return;
	//先拆分数据
	int mid = (left + right) / 2;
	margeSort(vec, left, mid);
	margeSort(vec, mid + 1, right);

	//调用marge(),排序
	marge(vec, left, mid, right);
}

void sortArray(vector<int>&vec) {
	margeSort(vec, 0, vec.size() - 1);
}

int main() {
	vector<int>arr = { 77,23,11,1,24,91,0,41,6 };
	int n = arr.size();
	sortArray(arr);
	for (int i = 0; i < n; i++)cout << arr[i] << " ";
	cout << endl;
	return 0;
}
