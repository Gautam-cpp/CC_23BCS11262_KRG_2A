#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;    
    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + b[i];

        vector<long long> cnt(n + 2, 0);     // difference array for full cups
        vector<long long> extra(n + 2, 0);   // partial remainder

        for (int i = 0; i < n; i++) {
            long long total = a[i] + pref[i];

            int j = upper_bound(pref.begin(), pref.end(), total) - pref.begin() - 1;

            cnt[i] += 1;
            cnt[j] -= 1;

            long long used = pref[j] - pref[i];
            long long rem = a[i] - used;

            if (j < n)
                extra[j] += rem;
        }

        long long active = 0;
        for (int i = 0; i < n; i++) {
            active += cnt[i];
            long long ans = active * b[i] + extra[i];
            cout << ans << " ";
        }
        cout<<endl;
    }

    return 0;
}