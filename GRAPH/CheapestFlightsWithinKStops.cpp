class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& cost, int src, int dst, int k, int& min_fare, int dist){
        if(k<0)
            return;
        if(src == dst)
        {
            min_fare = min(min_fare, dist);
            return;
        }
        for(auto i:graph[src])
        {
            if(dist + cost[src][i] < min_fare)
            {
                dfs(graph, cost, i, dst, k-1, min_fare, dist+cost[src][i]);
            }
        }
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> graph(n), cost(n, vector<int> (n));
        for(auto i: flights)
        {
            graph[i[0]].push_back(i[1]);
            cost[i[0]][i[1]] = i[2];
        }
        int min_fare = INT_MAX;
        dfs(graph, cost, src, dst, k+1, min_fare, 0);
        
        if(min_fare==INT_MAX)
            return -1;
        else
            return min_fare;
        
    }
};
