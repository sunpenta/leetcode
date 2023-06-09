// 移除'*' - newstr  l-2390
// 移除'*'和它相邻左边的非'*'字母，每个输入都make operation possible；时间复杂度:O(n) 空间复杂度:O(1); 原地TLE
#include <iostream>
using namespace std;
string removeStars(string s);

int main()
{
    string s="erase*****"; // input
    cout<<removeStars(s)<<endl; // output: ""
}

string removeStars(string s)
{
    int n=s.length();
    string res="";
    for (int i=0; i<n; i++)
    {
        if (s[i]!='*')
            res+=s[i];
        else
            s.pop_back();
    }
    return res;
}