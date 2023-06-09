// 二分查找 - 双指针  l-704
// -> 目标元素在数组的位置/-1(未在数组内)，即binary_search(); 原数组升序排列
// 时间复杂度:O(logn) 空间复杂度：O(n)
// 也可用3中search()子函数
# include<iostream>
# include<vector>
using namespace std;
int search(vector<int>& nums, int target);

int main()
{
    vector<int> nums={-1,0,3,5,9,12}; int target=9; // input
    int res=search(nums,target); // output:4
    cout<<res<<endl;
    return 0;
}

int search(vector<int>& nums, int target)
{
    int left=0, right=nums.size()-1;
    while (left<=right) // 统一left,right,不要i和left混杂
    {
        int mid=(left+right)/2;
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}