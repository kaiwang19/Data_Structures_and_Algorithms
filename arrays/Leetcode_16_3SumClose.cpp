// https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }
            if (sum < target)
                l++;
            else
                r--;
        }
    }
    return ans;
}