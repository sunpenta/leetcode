// 搜索旋转升序数组 - Binary Search l-33
// -> 目标元素位置/-1(未找到); 不含重复元素，升序排列
// 时间复杂度：O(logn) 空间复杂度:O(1)
#include<iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target);

int main()
{ 
    vector<int> nums{4,5,6,7,0,1,2}; int target=0; // 输入:{4,5,6,7,|0,1,2}
    int res=search(nums,target); // 输出：4
    cout<<res<<endl;
    return 0;
}

int search(vector<int>& nums, int target) // [0,|,n-1]
{
    int n=nums.size();
    int left=0, right=n-1;
    while (left<=right) // <=
    { 
        int mid=left+(right-left)/2;
        if (nums[mid]==target) 
            return mid; 
        else if (nums[mid]>=nums[0]) // [0,mid,|]
        {   
            if (target>=nums[0] && target<=nums[mid]) // 前半升序段[0,target,mid,|]
                right=mid-1; 
            else 
                left=mid+1;
        }
        else // [|,mid,n-1]
        {         
            if (target>=nums[mid] && target<=nums[n-1]) // 后半升序段[|,mid,target,n-1]
                left=mid+1;
            else 
                right=mid-1; 
        }
    }
    return -1;
}

