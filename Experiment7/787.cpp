class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int>price(n, 1e9);
        price[src]= 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();
            if(stop > k) {
                if(price[dst]==1e9) return -1;
                return price[dst];
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjCost = it.second;

                if(cost+adjCost<price[adjNode] && stop<=k){
                    price[adjNode] = cost+adjCost;
                    q.push({stop+1, {adjNode, cost+adjCost}});

                }
            }
        }

        if(price[dst] == 1e9) return -1;
        return price[dst];

    }
};
