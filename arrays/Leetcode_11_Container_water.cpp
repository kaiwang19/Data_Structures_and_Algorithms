// https://leetcode.com/problems/container-with-most-water/

#include <vector>
#include <iostream>

using namespace std;

// int findMax(vector<int> &unsorted)
// {
//     int max = 0;
//     for(int i = 1; i < unsorted.size(); i++)
//     {
//         if (unsorted[i] > unsorted[max])
//         {
//             max = i;
//         }
//     }
//     return max;
// }

int main()
{
    vector<int> height={1,8,6,2,5,4,8,3,7};
    int max_area = 0;
    int left = 0;
    int right = height.size()-1;

    while(left<right)
    {
        int min_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = (right-left) * min_height;
        
        // cout << "left " << left << " - "<< height[left] << endl;
        // cout << "right " << right << " - "<< height[right] << endl;
        // cout << "current_area " << current_area << endl;
        // cout << "max_area " << max_area << endl;
        if(current_area > max_area)
            max_area = current_area;

        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return max_area;
}