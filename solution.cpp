class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool>mst(n,false);
        pq.push({0,0}); // dist,index
        int count =0;
        int distance=0;
        while(count<n){
            auto [dist,u] =pq.top();pq.pop();
            if(mst[u]) continue;
            mst[u]=true;
            count++;
            distance+=dist;
            for(int v=0;v<n;v++){
                if(mst[v]==false){
                    int dis = abs(abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]));
                    pq.push({dis,v});
                }
            }
        }
        return distance;
    }
};
