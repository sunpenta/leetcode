// 搜索插入位置  l-35
// 不含重复元素，升序排列； 
// 时间复杂度:O(logn) 空间复杂度:O(1)
#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target);

int main()
{
    vector<int> nums={2,3,5,7,8,9}; int target=6; // input
    cout<<searchInsert(nums,target)<<endl; // output:3
    return 0;
}

int searchInsert(vector<int>& nums, int target)
{
    int left=0, right=nums.size()-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]<target) // [left,mid,target,right]
            left=mid+1;
        else
            right=mid-1; // [left,target,mid,right]
    }
    return left;
}