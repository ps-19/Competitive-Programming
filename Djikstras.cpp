class Solution {
public:
    int N = 101;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> p[N];
        for(int i=0;i<times.size();i++){
            p[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        int d[n+1];
        for(int i=0;i<=n;i++){
            d[i]=INT_MAX;
        }
        d[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            for(int i=0;i<p[temp.second].size();i++){
                if((temp.first+p[temp.second][i].second) < d[p[temp.second][i].first]) {
                    d[p[temp.second][i].first] = temp.first+p[temp.second][i].second;
                    pq.push({d[p[temp.second][i].first], p[temp.second][i].first});
                }
            }
        }
        int ans=0;
        for(int  i=1;i<=n;i++){
            ans=max(ans, d[i]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};