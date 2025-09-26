class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int count1 = 0;
        int count2 = 0;
        map<int, int> mpp;
        int l = 0;
        int r = 0;
        while (r < nums.size())
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }

                l++;
            }
            count1 += (r - l + 1);
            r++;
        }
        // cout << count1 << endl;
        mpp.clear();
        l = 0;
        r = 0;
        while (r < nums.size())
        {
            mpp[nums[r]]++;
            while (mpp.size() > k - 1)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }

                l++;
            }
            // if (l <= r)
            // {
                count2 += (r - l + 1);
            // }
            r++;
        }
        cout << count2 << endl;
        return count1 - count2;
    }
};