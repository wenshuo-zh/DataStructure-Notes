#include<bits/stdc++.h>
using namespace std;

//递归调用，每递归一次确定基准值的位置（把比基准值小的都放到基准值左边，大的放右边，基准值自然就是正确位置）
int partition(vector<int>vec, int l, int r) {
	int i = l;//下一个小于基准值的元素要放的下标
	for (int j = l; j < r; j++) {
		if (vec[j] < vec[r]) {
			swap(vec[i], vec[j]);
			i++;                   //只有第i项放了正确的，比基准值小的元素，i才走到下一项
		}
	}
	swap(vec[i], vec[r]);          //都走完第i项自然就是基准值要放的下标
	return i;
}
void quickSort(vector<int>vec, int l, int r) {
	if (l >= r)return;
	int pos = partition(vec, l, r);
	quickSort(vec, l, pos - 1);
	quickSort(vec, pos + 1, r);
}

int main() {

	return 0;
}