// 最长回文串 - hash  l-409
// 给定字符串的字母（包括大小写），组成的最长回文串
#include <iostream>
using namespace std;
int longestPalindrome(string s);

int main()
{
    string s="aaaaAa"; // input
    cout<<longestPalindrome(s)<<endl; // output:5
    return 0;
}

int longestPalindrome(string s)
{
    int dict[256]={0}; // note:initialize
    for (char ch:s)
        dict[ch-'A']++;
    int maxlen=0;
    for (int i=0; i<256; ++i)
    {
        maxlen+=dict[i]/2*2;
    }
    return maxlen==s.length()?maxlen:maxlen+1;
}
