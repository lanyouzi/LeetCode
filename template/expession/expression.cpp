/*** 
 * @Author: Ruokai Ma mrk_lanyouzi@yeah.net
 * @Date: 2023-03-07 13:46:45
 * @LastEditors: Ruokai Ma mrk_lanyouzi@yeah.net
 * @LastEditTime: 2023-03-07 14:47:16
 * @FilePath: \LeetCode\template\expession\expression.cpp
 * @Description: 
 * @
 * @Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
# include <bits/stdc++.h>
using namespace std;

map<char, int> opt_order = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0}};
string infix2postfix(const string &exp) {
    string ans = "";
    stack<char> opts;           // 栈内元素优先级严格升序
    for (auto& cur:exp) {
        if (isdigit(cur)) {
            ans += cur;
        } else if (cur=='(') {  // 无理由入栈
            opts.push(cur);
        } else if (cur==')') {  // 匹配到左括号出栈
            while (!opts.empty() && opts.top()!='(') {
                ans += opts.top();
                opts.pop();
            }
            opts.pop();
        } else {                // 不断出栈，直至栈为空或者当前运算符优先级大于栈顶元素优先级
            while (!opts.empty() && opt_order[cur]<=opt_order[opts.top()]) {
                ans += opts.top();
                opts.pop();
            }
            opts.push(cur);
        }
    }
    while (!opts.empty()) {
        ans += opts.top();
        opts.pop();
    }
    return ans;

}

int cal_postfix(const string &exp) {
    stack<int> nums;
    for (auto &ch:exp) {
        if (isdigit(ch)) {
            nums.push(ch-'0');
        } else  {
            int y = nums.top();
            nums.pop();
            int x = nums.top();
            nums.pop();
            switch (ch)
            {
            case '+':
                nums.push(x+y);
                break;
            case '-':
                nums.push(x-y);
                break;
            case '*':
                nums.push(x*y);
                break;
            case '/':
                nums.push(x/y);
                break;
            }   
        }
    }
    return nums.top();
}

int cal_infix(const string &exp) {
    return cal_postfix(infix2postfix(exp));
}

int main() {
    string in_exp = "9+(6+5)*2-7";
    cout << cal_infix(in_exp) << endl;
    string post_exp = "965+2*+7-";
    cout << cal_postfix(post_exp);
    return 0;

}