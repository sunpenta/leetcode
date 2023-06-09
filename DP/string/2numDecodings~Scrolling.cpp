// 解码方法 - 动态规划+分类+滚动数组  l-91
#include <iostream>
#include <vector>
using namespace std;
int numDecodings(string s);

int main()
{
    string s="120303113"; // 输入
    cout<<numDecodings(s)<<endl; // 输出：0
    return 0;
}

int numDecodings(string s)
{
    int n=s.length();
    int pre=1, cur=1; // dp[-1]=dp[0]=1
    for (int i=1; i<n; i++)
    {
        int tmp=cur;
        if (s[i]=='0') // 当前值'0'
        {
            if (s[i-1]=='1' || s[i-1]=='2')
                cur=pre;
            else
                return 0;
        }
        else if (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6'))
            cur+=pre;
        pre=tmp;
    }
    return cur;
}