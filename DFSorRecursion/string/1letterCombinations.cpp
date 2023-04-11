// 电话号码的字母组合-回溯  l-17
#include <bits/stdc++.h>
using namespace std;
vector<string>letterCombinations(string digits);

int main()
{
    string digits = "23"; // 输入
    vector<string> ans=letterCombinations(digits); // 输出所有数字组合
    for (auto num:ans)
        cout << num << " ";
    system("pause");
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
// 回溯法-无需剪枝
void backtrack(vector<string>&ans,string &str,const string &digits, int index)
{   // 终止条件
    if (index == digits.size()) 
    {
        ans.push_back(str);
        return;
    }

    char digit = digits[index];
    // const string &letters = phonemap[digit]; // key不存在，添加key，不抛出异常
    const string &letters = phonemap.at(digit); //取出map中digit对应的值;检查key，key不存在抛出异常
    for (auto &letter : letters) // auto是const char
    {
        str.push_back(letter);
        backtrack(ans,str,digits, index + 1); 
        str.pop_back(); // 恢复原状
    }
}

vector<string>letterCombinations(string digits)
{
    vector<string>ans; string str;
    // 特殊情况：空字符串
    if (digits.size()==0) return ans;
    backtrack(ans,str,digits, 0); // 回溯
    return ans;
}