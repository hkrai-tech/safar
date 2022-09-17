/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
Return nums after the rearrangement.
*/

/*Solution 1
TC O(n) SC O(n)
*/
class solution
{
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> chota, bara, barabar;
        int n = nums.size();

        for (auto i : nums)
        {
            if (i < pivot)
                chota.push_back(i);
            else if (i == pivot)
                barabar.push_back(i);
            else
                bara.push_back(i);
        }

        vector<int> ans;

        for (auto i : chota)
        {
            ans.push_back(i);
        }

        for (auto i : barabar)
        {
            ans.push_back(i);
        }
        for (auto i : bara)
        {
            ans.push_back(i);
        }

        return ans;
    }

    /*
    Solution 2 Three pointer approach
    same tc and sc but better implementation
    */

    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int low = 0;
        int same = 0;
        int high;
        for (auto n : nums)
        {
            if (n < pivot)
            {
                ++low;
            }
            else if (n == pivot)
            {
                ++same;
            }
        }
        vector<int> res(nums.size());
        high = same + low;
        same = low;
        low = 0;
        for (auto n : nums)
        {
            if (n < pivot)
            {
                res[low++] = n;
            }
            else if (n == pivot)
            {
                res[same++] = n;
            }
            else
            {
                res[high++] = n;
            }
        }
        return res;
    }
};