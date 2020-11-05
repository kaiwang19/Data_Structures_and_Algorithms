// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <iostream>

using namespace std;

// find the kth smallest element in 2 sorted lists
int findKth(vector<int> nums1, int i, vector<int> nums2, int j, int k)
{
    if (i >= nums1.size())
        return nums2[j + k - 1]; // because nums1 is empty

    if (j >= nums2.size())
        return nums1[i + k - 1]; // because nums2 is empty

    if (k == 1)
    {
        return nums1[i] < nums2[j] ? nums1[i]: nums2[j];
    }

    // in case the length of nums1 or nums2 is not enough
    int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    if (midVal1 < midVal2)
    {
        // remove k/2 elements in nums1
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
    }
    else
    {
        // remove k/2 elements in nums2
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int k = 0;
    if ((m + n) % 2 == 0)
    {
        return ( findKth(nums1,0,nums2,0,(m+n)/2) + findKth(nums1,0,nums2,0,(m+n)/2+1) )/ 2.0;
    }
    else
    {
        return findKth(nums1,0,nums2,0,(m+n+1)/2);
    }

    return (m + n) / 2;
}

int main()
{
    vector<int> nums1;
    vector<int> nums2;
    double res = 0.0;

    nums1 = {1, 3};
    nums2 = {2};
    res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;

    nums1 = {};
    nums2 = {1};
    res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}