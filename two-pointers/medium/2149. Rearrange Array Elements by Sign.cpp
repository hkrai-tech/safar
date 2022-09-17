/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos, neg;
        int sz = nums.size();
        for (auto n : nums)
        {
            if (n >= 0)
                pos.push_back(n);
            else
                neg.push_back(n);
        }

        nums.clear();

        int i = 0;

        while (i < (sz / 2))
        {
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);
            i++;
        }

        return nums;
    }
};