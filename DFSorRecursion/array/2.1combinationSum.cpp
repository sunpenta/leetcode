// 组合之和 - 回溯  l-39
// 元素可重复使用；组合无重复
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>combinationSum(vector<int>& candidates, int target);

int main()
{
    vector<int> candidates{2,3,6,7}; int target=7; // 输入
    vector<vector<int>>ans=combinationSum(candidates,target); // 输出:
    for (int i=0;i<ans.size();i++) // {{2,2,3},{7}}
    {
        for (auto num:ans[i])
            cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

// target-子数组和=0; ans:所有子数组; index:搜索起点candidates[index]
void dfs(vector<vector<int>>& ans, vector<int>& combine, vector<int>& candidates, int target, int index)
{
    if (target==0) // 终止条件
    { 
        ans.emplace_back(combine);
        return;
    }
    for (int i=index; i<candidates.size(); i++) // 循环
    {
        if (target<candidates[i]) // 剪枝
            break;
        combine.emplace_back(candidates[i]);                  // dfs(...,i)保证可重复使用元素
        dfs(ans,combine,candidates,target-candidates[i],i); // 目标值变为：target-candidates[i]
        combine.pop_back();
    }
}

vector<vector<int>>combinationSum(vector<int>&candidates,int target)
{
    sort(candidates.begin(),candidates.end()); // *排序*
    vector<vector<int>> ans; vector<int> combine; // 子数组集；子数组
    int n=candidates.size();
    dfs(ans,combine,candidates,target,0);
    return ans;  
}