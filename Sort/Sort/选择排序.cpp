#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int nums[N];

/*
 * 选择排序（从大到小）
 * 每轮在未排序部分找最大值，放到已排序部分的末尾
 * 1-indexed：nums[1] ~ nums[n] 为有效数据，nums[0] 不使用
 */

void selectSort(int nums[], int n) {
    for (int i = 1; i < n; i++) {
        int maxIndex = i;                    // 从未排序部分的第一个开始
        for (int j = i; j <= n; j++) {       // 在 [i, n] 中找最大值
            if (nums[j] > nums[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(nums[maxIndex], nums[i]);
    }
}

int main() {
    int n = 8;
    // 随机填充 nums[1] ~ nums[n]
    srand(time(0));
    cout << "排序前：";
    for (int i = 1; i <= n; i++) {
        nums[i] = rand() % 100;
        cout << nums[i] << " ";
    }
    cout << endl;

    selectSort(nums, n);

    cout << "排序后（从大到小）：";
    for (int i = 1; i <= n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
