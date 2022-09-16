/*
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
 */

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        string s1 = "", t1 = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '#')
                s1.push_back(s[i]);
            else if (s[i] == '#' && s1.size() > 0)
                s1.pop_back();
        }

        for (int i = 0; i < m; i++)
        {
            if (t[i] != '#')
                t1.push_back(t[i]);
            else if (t[i] == '#' && t1.size() > 0)
                t1.pop_back();
        }

        cout << s1 << " " << t1 << endl;

        n = s1.size();
        m = t1.size();

        if (n != m)
            return false;

        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (s1[i] != t1[j])
                return false;
            i++;
            j++;
        }

        return true;
    }
};