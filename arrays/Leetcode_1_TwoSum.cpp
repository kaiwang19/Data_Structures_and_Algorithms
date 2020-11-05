// https://leetcode.com/problems/two-sum/

// Better Approach - Hash
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> prevMap;
    //     for (int i = 0; i < nums.size(); i++) {
    //         int diff = target - nums[i];
    //         if(prevMap.count(diff)) 
    //             return { prevMap[diff], i };
    //         prevMap[nums[i]] = i;
    //     }
    //     return {};
    // }



#include <vector>
#include <iostream>
 
using namespace std;

class Solution {
public:
    // Brute Force
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
            int sum = nums[i];
            for(int j=i+1; j<nums.size(); j++)
            {
                if(sum+nums[j]==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }

        }
        return res;
    }
};


