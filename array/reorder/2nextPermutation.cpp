// nextPermutation l-31
// 
// 时间复杂度:O(n) 空间复杂度：O(1)
# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums);

int main()
{
    vector<int> nums{2,3,5,4,1}; // input
    nextPermutation(nums); // output
    for (int num:nums)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}

void nextPermutation(vector<int>& nums)
{
    int n=nums.size(), i=n-2, j=n-1;
    for (; i>=0 && nums[i]>=nums[i+1]; i--) {} // 从后往前找第1个较小数位置i
    if (i>=0) // 若[3,2,1],i=-1
    {
        for (; j>=0 && nums[j]<=nums[i]; j--) {} // 从后往前找第1个比nums[i]大的位置j,交换
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end()); // 反转[i+1,n-1]
}