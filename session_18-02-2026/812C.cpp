#include <bits/stdc++.h>
using namespace std;

void solve() {
   int n;
    long long S;
    cin >> n >> S;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)  cin>>a[i];

    int low = 0, high = n;
    int bestK = 0;
    long long bestCost = 0;

    while(low <= high) {
        int mid = (low + high) / 2;  

        vector<long long> b(n);

      
        for(int i = 0; i < n; i++) {
            b[i] = a[i] + 1LL * (i + 1) * mid;
        }

        sort(b.begin(),b.end());

        long long sum = 0;
        for(int i = 0; i < mid; i++) {
            sum += b[i];
        }

        if(sum <= S) {
            bestK = mid;
            bestCost = sum;
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    cout<<bestK << " " << bestCost <<endl;
}

int main() {
    solve();
    return 0;
}

