#include<bits/stdc++.h>
using namespace std;

//计数排序（稳定版）
void countingSort(vector<int>& arr) {
    const int n = arr.size();
    if (n == 0) return;

    // 1. 求最大值
    int max = arr[0];
    for (auto& it : arr)  if (it > max)max = it;

    // 2. 统计每个值出现次数
    vector<int>count(max + 1, 0);
    for (int i = 0; i < n; i++)     count[arr[i]]++;

    // 3. 前缀和 → count[i] 变成每个数最后一次出现的下标
    //count[0]本身就是前缀和，不用再算
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. 倒序遍历原数组，放入 ans
    vector<int>ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 5. 写回原数组
    arr = ans;
}
//时间复杂度：O(n+k)
//空间复杂度：O(k)
//稳定性：稳定
int main() {
	vector<int>arr = { 77,23,11,1,24,91,0,41,6 };
	countingSort(arr);
	for (auto& it : arr)cout << it << " ";
	cout << endl;
	return 0;
}
