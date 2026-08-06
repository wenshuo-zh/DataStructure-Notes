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


void countSort2(vector<int>& vec) {
    if (vec.empty()) return;
    //求取跨度值：
    //1. 节约空间
    //2. 可以排序负数
    int maxx = vec[0], minn = vec[0];
    for (auto& i : vec) {
        if (i > maxx) maxx = i;
        if (i < minn) minn = i;
    }
    //开辟空间的范围
    int numsRange = maxx - minn + 1;
    vector <int> count(numsRange, 0);
    //2.count 记录数据出现的次数
    //下标 + 最小值 = 对应的数组数据
    //下标 = 对应的数组数据 - 最小值
    for (auto& it : vec) count[it - minn]++;
    //3.求取数据的前缀和 - 前缀和记录的是当前数据最后一次出现的位置
    for (int i = 1; i < numsRange; i++) count[i] += count[i - 1];
    //4.开辟数组存放最终结果
    vector<int> ans(vec.size(), 0);
    //5.倒序遍历vec 后面进来的数据先放入靠后位置
    for (int i = vec.size() - 1; i >= 0; i--) {
        int temp = vec[i];
        //temp - 数组中的原始数据
        //temp - minn  count中的下标
        //count[temp - minn] 取出来的是他要放入的位置
        //count[temp - minn] - 1 在ans中对应的下标
        ans[count[temp - minn] - 1] = temp;
        //前缀和里面的数据 - 1 下一次放入位置前移一位
        count[temp - minn]--;
    }
    vec = ans;
}


int main() {
	vector<int>arr = { 77,23,11,1,24,91,0,41,6 };
	countingSort(arr);
	for (auto& it : arr)cout << it << " ";
	cout << endl;
	return 0;
}
