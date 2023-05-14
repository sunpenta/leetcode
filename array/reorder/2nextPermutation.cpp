// nextPermutation l-31
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
    for (; i>=0 && nums[i]>=nums[i+1]; i--) {} // 找第1个较小数位置
    if (i>=) // 
    {
        for (; j>=0 && nums[j]<=nums[i]; j--) {}
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
}