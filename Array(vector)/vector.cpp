#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int>vec1;
	//使用列表初始化
	vector<int>vec2 = { 1,2,3,4,5 };
	//memst(首地址,初始值,字节数)
	//开辟100块空间，初始化为10
	vector<int>vec3(100, 10);
	//拷贝构造
	vector<int>vec4(vec3);

	//添加数据
	//1.尾部添加
	vec1.push_back(1);
	vec1.push_back(9);
	vec1.push_back(8);
	vec1.push_back(7);
	vec1.push_back(6);
	vec1.push_back(22);
	//2.insert
	//迭代器：
	//vec.begin()容器第一项
	//vec.back()容器最后一项的下一项
	//vec.insert(vec.begin()+偏移量 , 插入的数据)
	vec1.insert(vec1.begin() + 1, 5);
	cout << vec1[3] << endl;
	//at防止越界直接报错终止
    //抛出异常，让程序正常正常执行
    //vec1.at (100);

	//删除数据
	//1.尾部删除
	vec1.pop_back();
	//2.指定位置删除
	//erase(需要被删除的位置)-使用迭代器
	//vec1.erase(vec1.begin() + 1);
	for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
	cout << endl;
	//erase(被删除的起始位置 , 被删除的终止位置)
	//左闭右开区间
	vec1.erase(vec1.begin() + 1, vec1.begin() + 3);
	for (int i = 0; i < vec1.size(); i++) cout << vec1[i] << " ";
	cout << endl;

	vec1.back();
	vec1.front();
	vec1.empty();
}