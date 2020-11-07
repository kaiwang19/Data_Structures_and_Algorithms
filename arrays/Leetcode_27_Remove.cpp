// https://leetcode.com/problems/remove-element/

#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    int order=0;
    for(int i=0; i<n-1; i++)
    {
        if(nums[i]!=val) 
        { 
            nums[order++] = nums[i];
        }
    }

    if(nums[n-1]!=val) nums[order++] = nums[n-1];

    return order;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val =2;

    int res = removeElement(nums, val);

    cout << res << endl;
}
