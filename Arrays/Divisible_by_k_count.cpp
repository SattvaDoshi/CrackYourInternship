class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int sum = 0;
        int count = 0;

        unordered_map<int, int> ans;
        ans[0] = 1;

        for (int num : nums)
        {
            sum += num;
            int mod = sum % k;

            if (mod < 0)
                mod += k;
            if (ans.find(mod) != ans.end())
            {
                count += ans[mod];
            }
            ans[mod]++;
        }
        return count;
    }
};