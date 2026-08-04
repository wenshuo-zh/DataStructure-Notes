#include<bits/stdc++.h>
using namespace std;

/*
 * LeetCode 205 - 同构字符串 (Isomorphic Strings)
 *
 * 【核心思路】
 *   用两个 map 分别记录 s 和 t 中每个字符的"最后出现位置"。
 *   同一位置 i 上，s[i] 和 t[i] 各自的最后出现位置如果不同，
 *   说明当前这对 (s[i], t[i]) 的映射关系与之前的不一致 → 不是同构。
 *
 *   s = "egg", t = "add"
 *   i=0: mps['e']=0, mpt['a']=0  ✓（都是新字符，位置相同）
 *   i=1: mps['g']=1, mpt['d']=1  ✓
 *   i=2: mps['g']=2, mpt['d']=2  ✓
 *   → true
 *
 *   s = "badc", t = "baba"
 *   i=0: mps['b']=0, mpt['b']=0  ✓
 *   i=1: mps['a']=1, mpt['a']=1  ✓
 *   i=2: mps['d']=2, mpt['b']=0  → 2!=0 ✗（s 的 d 首次出现，但 t 的 b 已出现过）
 *   → false
 *
 * 【踩坑记录】
 *   1. map 类型写反：开始写成 unordered_map<int,char>，把位置当 key、字符当 value，
 *      虽然能编译但语义颠倒，且后续按 value 比较时会混入无意义数据。
 *   2. 两个 map 写成一个：mps[...] = i; mps[...] = i; → mpt 始终为空，比较全返回 0。
 *   3. 遍历 map 比较 instead of 遍历字符串：遍历 mps 拿到的是 (字符, 位置)，
 *      用 mps 的字符去查 mpt，隐含假设了"同位置字符相同"（即恒等映射），
 *      但同构允许 f(s[i])=t[i] 中字符名不同（如 e→a, g→d）。
 *      正确做法是遍历字符串，用 s[i] 和 t[i] 各自查各自的 map。
 *   4. 只比 value 集合：两个 map 的 value 集合相同 ≠ 同构，因为丢了"哪个字符配哪个"的对应信息。
 *      {2,3} 和 {2,3} 对应关系可以完全不同（abba vs abab）。
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> mps, mpt;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            mps[s[i]] = i;
            mpt[t[i]] = i;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mps[s[i]] != mpt[t[i]]) return false;
        }
        return true;
    }
};