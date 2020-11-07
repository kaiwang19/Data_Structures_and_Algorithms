// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
#include <iostream>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return n;
    int order = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
            nums[order++] = nums[i];
    }
    return order;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int res = removeDuplicates(nums);

    cout << res << endl;
}
