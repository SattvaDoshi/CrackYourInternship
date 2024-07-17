class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mpp.count(nums[i]) == 0)
                mpp[nums[i]]++;
            else
                ans.push_back(nums[i]);
        }
        return ans;
    }
};