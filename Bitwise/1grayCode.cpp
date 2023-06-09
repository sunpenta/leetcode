// 格雷编码 - 位运算 l-89
// 第1位是0；每相邻两个数的二进制只有1位不同；头尾两个数的二进制只有1位不同
#include <iostream>
#include <vector>
using namespace std;
vector<int> grayCode(int n);

int main()
{
    int n=3; // 输入:二进制表示为n位
    vector<int> res=grayCode(n); // 输出:{0,1,3,2,6,7,5,4}
    for (int num:res)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}

// i 与前1位异或，最高位保持不变
vector<int>grayCode(int n)
{
    vector<int> res(1<<n);
    for (int i=0; i<(1<<n); i++)
        gray[i]=i^(i>>1); 
    return res;
}
