// 法术和药水对 - lowerbound(binary search)  l-2300
// n,m⋿[1,1e5], spell,potion⋿[1,1e5], success⋿[1,1e10]; 容易TLE，注意精度
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, int success);

int main()
{
    vector<int> spells={3,1,2}; vector<int> potions={8,5,8}; int success=16; // input
    vector<int> res=successfulPairs(spells,potions,success); // output
    for (int i:res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, int success)
{
    sort(potions.begin(),potions.end());
    int n=spells.size();
    vector<int> res(n);
    for (int i=0; i<n; ++i)
    {
        int potion=(success+1)/spells[i]-1; // floor
        auto it=lower_bound(potions.begin(),potions.end(),potion); // first spell*potions[j]<success, 即 potions[i]<success/spell
        res[i]=potions.end()-it;
    }
    return res;
}