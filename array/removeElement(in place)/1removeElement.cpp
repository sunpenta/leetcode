// 移除元素 - 快慢指针  l-27
// ->移除val后的元素数k；原数组前k个是非val元素(相对顺序不变)
// 时间复杂度：O(n) 空间复杂度:O(1)
# include<iostream>
# include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val);

int main()
{
    vector<int> nums={0,1,2,3,3,0,4,2}; int val=2; // input;
    int res=removeElement(nums,val); // output:6 {0,1,3,3,0,4,4,2}
    cout<<res<<endl;
    return 0; 
}

int removeElement(vector<int>& nums, int val)
{
    int i=0, j=0;
    for (; j<nums.size(); j++)
    {
        if (nums[j]!=val)
            nums[i++]=nums[j];
        
    }
    return i;
}