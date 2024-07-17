class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int start = 0, end = n - 1;
        int maxi = 0;
        while (start <= end)
        {
            int area = (end - start) * min(height[start], height[end]);
            maxi = max(maxi, area);
            if (height[start] > height[end])
                end--;
            else
                start++;
        }
        return maxi;
    }
};