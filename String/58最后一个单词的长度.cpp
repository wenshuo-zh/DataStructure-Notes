#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        //´¦ÀíÄ©Î²¿Õ¸ñ
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') n--;
            else break;
            
        }
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ') return ans;
            ans++;
        }
        return ans;
    }
};