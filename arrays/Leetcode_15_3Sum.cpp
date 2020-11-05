// https://leetcode.com/problems/3sum/

#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int>& unsorted, int p, int r)
{
    int x = unsorted[r];
    int i = p-1;
    for(int j=p; j<r; j++)
    {
        if(unsorted[j] <= x)
        {
            i++;
            swap(unsorted[i], unsorted[j]);
        }
    }
    swap(unsorted[i+1], unsorted[r]);
    return i+1;
}

vector<int> quick_sort(vector<int>& unsorted, int p, int r)
{
    if(p < r)
    {
        int q = partition(unsorted, p, r);
        quick_sort(unsorted, p, q-1);
        quick_sort(unsorted, q+1, r);
    }

    return unsorted;
}

int main()
{
    vector<int> nums={-1,0,1,2,0,-1,-4};
    vector<vector<int>> res;
    int size = nums.size();

    vector<int> sorted = quick_sort(nums, 0, size-1);

    // for(int i=0; i<size; i++)
    // {
    //     cout << sorted[i] << endl;
    // }

    if(size<3)
    {
        return 0;
    } 
    
    for(int i=1; i<size-1; i++)
    {
        int left = 0;
        int right = size-1;
        
        while(left<i && right>i)
        {
            int sum = sorted[left] + sorted[i] + sorted[right]; 
            
            if(sum == 0)
            {
                vector<int> success={sorted[left], sorted[i], sorted[right]};
                res.push_back(success);

                while(sorted[left] == sorted[left+1]) { left++; }
                left++;
                
                while(sorted[right] == sorted[right-1]) { right--; }
                right--;
            }
            else if(sum < 0)
            {
                while(sorted[left] == sorted[left+1]) { left++; }
                left++;
            }
            else
            {
                while(sorted[right] == sorted[right-1]) { right--; }
                right--;
            }
        }
    }


}
