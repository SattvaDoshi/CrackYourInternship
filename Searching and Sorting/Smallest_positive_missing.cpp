class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    {
        bool* present = new bool[n + 1];
        for (int i = 0; i <= n; i++)
            present[i] = false;

        for (int i = 0; i < n; i++)
            if (arr[i] > 0 && arr[i] <= n)
                present[arr[i]] = true;

        int ans = 1;
        while (ans <= n && present[ans])
            ans++;

        delete[] present;
        return ans;
    }
};