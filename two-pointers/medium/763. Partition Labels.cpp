/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.
*/
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> ans;

        int hash[26] = {0};

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }

        int anchor = 0;
        int max_last = 0;
        for (int i = 0; i < s.size(); i++)
        {
            max_last = max(max_last, hash[s[i] - 'a']);

            if (max_last == i)
            {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }

        return ans;
    }
};