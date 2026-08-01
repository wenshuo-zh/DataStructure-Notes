#include<bits/stdc++.h>
using namespace std;

int main() {
	//map存一组键值对
	//键 - 存储数据具有唯一性
	//值 - 没有限制
	//1.键值去重
	//2.键值默认升序

	//初始化空的map
	map<int, int>mp1;

	//直接赋值
	map<int, int>mp2 = { {3,6},{4,9} };
	//拷贝构造
	map<int, int>mp3(mp2);

	//insert()插入数据
	mp3.insert({ 9,3 });
	//map - 允许通过下标进行访问
	//如果访问的值不存在，直接创建键值对，里面的值初始化为0
	mp3[6];
	//不存在可以直接创建并赋值
	mp3[5] = 77;
	///存在则直接修改里面的值
	mp3[4] = 7;

	//安全访问
	int ans = mp3.at(4);
	cout << ans << endl;

	//find() 返回迭代器：找到返回位置，没找到返回end()
	//count()返回int：找到返回1，没找到返回0

	auto it = mp3.find(1);
	//此时it是指针，访问要用->
	if (it != mp3.end())cout << it->first << " " << it->second << endl;
	//输出数据，先查找是否存在
	if (mp3.count(1)) cout << "1," << mp3[1] << endl;
	
	//erase()删除数据
	if (mp3.count(1))mp3.erase(1);

	//遍历输出
	//auto it : mp3  创建副本在遍历，遍历副本后再释放空间
	//const auto &it 用引用，此时it是map类型存键值对
	cout << "输出mp3中的全部键值对：" << endl;
	for (const auto& it : mp3) cout <<"<"<< it.first << "," << it.second << "> ";

}
