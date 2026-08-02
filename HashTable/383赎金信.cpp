#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp;
        for (auto& it : magazine)     mp[it]++;//将杂志存到mp里，键为字符，值为出现次数
        for (auto& it : ransomNote) {
            //如果在杂志中未找到赎金信里的字符，或字符数小于赎金信中的
            if (mp.count(it) == 0 || mp[it] <= 0) {
                return false;
            }
            mp[it]--;
        }
        return true;
    }
};