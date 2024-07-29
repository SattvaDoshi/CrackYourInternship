class Solution
{
public:
    int SubArrayCombSum(vector<int> nums, int maxSum)
    {

        int totalSum = 0, partitions = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (totalSum + nums[i] > maxSum)
            {
                partitions++;
                totalSum = nums[i];
            }
            else
            {
                totalSum += nums[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high)
        {
            int mid = (low + high) / 2;
            int partitions = SubArrayCombSum(nums, mid);
            if (partitions > k)
            {

                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};