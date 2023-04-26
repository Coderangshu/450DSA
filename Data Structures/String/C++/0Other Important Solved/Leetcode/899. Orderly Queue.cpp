class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        // when k > 1 then there is enough space for every
        // character to group with itself, and arrange in lexicographical
        // order, thus return sorted string
        // when k == 1 find the breakpoint from where the smallest
        // lexicographical string is formed
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        string ans = s;
        for (int i = 1; i < s.length(); i++)
        {
            ans = min(ans, s.substr(i) + s.substr(0, i));
        }
        return ans;
    }
};