#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &nums, int k)
{
    vector<int> cnt(31, 0);
    for (int x : nums)
    {
        for (int b = 0; b < 31; ++b)
        {
            if (x & (1 << b))
            {
                cnt[b]++;
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < k; ++i)
    {
        long long cur = 0;
        for (int b = 0; b < 31; ++b)
        {
            if (cnt[b] > 0)
            {
                cur |= (1LL << b);
                cnt[b]--;
            }
        }
        ans += cur * cur;
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 6, 5, 8};
    int k = 2;

    cout << solve(nums, k) << '\n';
    return 0;
}