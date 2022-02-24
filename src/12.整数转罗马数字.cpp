/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    map<string, int> mapRoman = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
    string intToRoman(int num)
    {
        string str = "";
        run (num, str);
        return str;
    }
    void run(int num, string &s) {
        if (num==0) {
            return;
        }
        if (num>=1000) {
            num-=1000;
            s.append("M");
        } else if (num>=900) {
            num-=900;
            s.append("CM");
        } else if (num>=500) {
            num-=500;
            s.append("D");
        } else if (num>=400) {
            num-=400;
            s.append("CD");
        }
         else if (num>=100) {
            num-=100;
            s.append("C");
        } else if (num>=90) {
            num-=90;
            s.append("XC");
        } else if (num>=50) {
            num-=50;
            s.append("L");
        } else if (num>=40) {
            num-=40;
            s.append("XL");
        } else if (num>=10) {
            num-=10;
            s.append("X");
        } else if (num>=9) {
            num-=9;
            s.append("IX");
        } else if (num>=5) {
            num-=5;
            s.append("V");
        } else if (num>=4) {
            num-=4;
            s.append("IV");
        } else if (num>=1) {
            num-=1;
            s.append("I");
        }
        run(num, s);
    }
};
// @lc code=end
