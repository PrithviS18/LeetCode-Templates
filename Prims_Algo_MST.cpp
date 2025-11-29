class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> vis(n,0);

        int sum=0;
        priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,0,-1});

        while (!pq.empty()){
            auto it = pq.top();
            int node = it[1], parent = it[2];
            pq.pop();
            if (vis[node]==1)continue;
            sum+=it[0];
            vis[it[1]]=1;

            cout<<node<<" "<<parent<<endl;
            for (int i=0;i<n;i++){
                if (i!=node && i!=parent && vis[i]==0){
                    int dis = abs(points[node][0]-points[i][0]) + abs(points[node][1]-points[i][1]);
                    pq.push({dis,i,node});
                }
            }
        } 
        return sum;
    }
};
