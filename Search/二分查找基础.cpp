#include<bits/stdc++.h>
using namespace std;
int main() {
	//查找效率 log n
	srand(time(0));
	int ans = rand() % 1000 + 1;
	int left = 1, right = 1000;
	while (left <= right) {
		//找到中间值
		int middle = (left + right) / 2;
		if (middle == ans) {
			cout << "找到数" << ans << endl;
			return 0;
		}
		else if (middle < ans)left = middle + 1;
		else right = middle - 1;
	}
	cout << "未找到数据" << endl;
	return 0;
}