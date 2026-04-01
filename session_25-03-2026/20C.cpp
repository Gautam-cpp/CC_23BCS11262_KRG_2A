#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n+1, 1e9);
    vector<int> parent(n+1,-1);
    priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        auto it= pq.top();
        pq.pop();
        
        int node=it.second;
        for(auto it: adj[node]){
            int v= it.first;
            int wt= it.second;
            if(wt+dist[node] < dist[v] ){
                dist[v]= dist[node]+wt;
                pq.push({dist[v],v});
                parent[v]=node;
            }
        }
    }

    vector<int> path;
    for(int i=n;i!=-1; i=parent[i]) path.push_back(i);

    reverse(path.begin(), path.end());
    for(auto it: path) cout<< it<<" ";
    cout<<endl;


}