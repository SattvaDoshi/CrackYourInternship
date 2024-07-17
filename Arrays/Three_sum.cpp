class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int start = i + 1, end = n - 1;
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == 0)
            {
                vector<int> temp = {i, start, end};
                ans.push_back(temp);
            }
            else if (sum > 0)
                end--;
            else
                start++;

            while (start < end && nums[start] == nums[start - 1])
                start++;
            while (start < end && nums[end] == nums[end + 1])
                end--;
        }
        return ans;
    }
};