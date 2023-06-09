// 在升序数组中查找元素的第一个和最后一个位置 - Binary Search  l-34
// -> 返回{第1个位置，第二个位置}/{-1,-1}(未找到); 含重复元素, 非降序排列
// 时间复杂度：O(logn) 空间复杂度:O(1)
#include<iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);

int main()
{
    vector<int> nums{1}; int target=1; // 输入
    vector<int> ans=searchRange(nums,target); // 输出:{0,0}
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;;
}

// 大于等于target的第一个元素下标(nums包含重复元素),即lower_bound()
int search(vector<int>& nums, int target)
{
    int left=0, right=nums.size(); // right≠n-1,[0,n]
    while (left<right) // [left,right）
    {
        int mid=(left+right)/2;
        if (nums[mid]>=target)
            right=mid;
        else 
            left=mid+1;
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target)
{  
    int n=nums.size();
    if (n==1 && nums[0]==target) // 仅为提速
        return {0,0};

    vector<int> ans(2);
    ans[0]=search(nums,target);
    ans[1]=search(nums,target+1)-1;
    if (ans[0]<n && nums[ans[0]]==target) 
        return ans;
    return {-1,-1};
}