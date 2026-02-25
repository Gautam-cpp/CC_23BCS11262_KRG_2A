#include <bits/stdc++.h>
using namespace std;

struct jobs{
    int id; int deadline; int profit;
};

void jobScheduling(vector<jobs> &v){
    int countJobs= 0; int totalProfit=0;
    int n=v.size();
    priority_queue<pair<int, int>> pq;
    for(int i=0;i<n;i++) pq.push(make_pair(v[i].profit, v[i].deadline));

    vector<int> hash(n,0);
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        for(int i=it.second -1; i>=0;i--){
            if(hash[i]==0){
                hash[i]=1;
                countJobs++;
                totalProfit+= it.first;
                break;
            }
        }
    }
    cout<< countJobs <<" "<< totalProfit <<endl;
}

int main() {
    vector<jobs> v={{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    jobScheduling(v);

    return 0;
} 