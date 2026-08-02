#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       //数组版本：
       // 哈希表为散列表，会更占用空间
       // 此题不需要去重，有准确大小的数据存储，用vector更好
       // 当 key范围已知且很小时，数组下标就是最快的哈希函数。
        if (ransomNote.size() > magazine.size())return false;
        vector<int>vec(26);
        for (auto& it : magazine)vec[(int)(it - 'a')]++;
        for (auto& it : ransomNote) {
            vec[(int)(it - 'a')]--;
            if (vec[(int)it - 'a'] < 0)return false;
        }
        return true;
    }
};