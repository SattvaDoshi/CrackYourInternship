class Solution
{
public
    int minSwaps(int nums[])
    {
        // Code here
        int n = nums.length;
        int swapsmin = 0;
        HashMap<Integer, Integer> orignali = new HashMap<>();

        for (int i = 0; i < n; i++)
        {
            orignali.put(nums[i], i);
        }
        Arrays.sort(nums);
        for (int i = 0; i < n; i++)
        {
            while (orignali.get(nums[i]) != i)
            {
                swapsmin++;
                int swapvar = nums[i];
                int timepasss = orignali.get(nums[i]);
                nums[i] = nums[timepasss];
                nums[timepasss] = swapvar;
                orignali.put(swapvar, timepasss);
            }
        }

        return swapsmin;
    }
}