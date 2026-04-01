#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int maxi= 1e5;
bool visited[maxi];
vector<int> adj[maxi];


void dfs(int u){
    visited[u]= true;
    for(int v: adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y;  cin>>x>>y;
        adj[x].pb(y); adj[y].pb(x);
    }

    vector<int> reps;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            reps.push_back(i);
        }
    }
    cout << reps.size()-1<<endl;
    for (int i=1;i< reps.size(); i++) {
        cout<<reps[i-1]<<" "<<reps[i]<<endl;
    }
}

int main() {
    solve();
    return 0;
}