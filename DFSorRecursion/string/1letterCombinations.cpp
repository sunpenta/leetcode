// 电话号码的字母组合 - hash+回溯  l-17
#include <bits/stdc++.h>
using namespace std;
vector<string>letterCombinations(string digits);

int main()
{
    string digits = "23"; // 输入
    vector<string> ans=letterCombinations(digits); // output: ad ae af bd be bf cd ce cf
    for (string nums:ans)
        cout << nums << " ";
    return 0;
}
// 建立哈希表，存储电话表
const unordered_map<char, string> phonemap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void backtrack(vector<string>& ans,string& s,const string& digits, int index)
{   
    if (index == digits.size()) // 终止条件 
    {
        ans.push_back(s);
        return;
    }

    char digit = digits[index];
    // 同const string &letters = phonemap[digit]; // [], 若key不存在，则添加key，不抛出异常
    const string& letters = phonemap.at(digit); // .at 检查key，若key不存在，抛出异常
    for (const char& letter : letters) // auto是const char
    {
        s+=letter;
        backtrack(ans,s,digits, index + 1); 
        s.pop_back(); // 恢复原状
    }
}

vector<string>letterCombinations(string digits)
{
    vector<string> ans; string s;
    // 特殊情况：空字符串
    if (digits.size()==0) return ans;
    backtrack(ans,s,digits, 0); // 回溯
    return ans;
}