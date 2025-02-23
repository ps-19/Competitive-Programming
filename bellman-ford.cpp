// Problem: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, 1000 * 100);
        d[k-1] = 0;
        for (int i = 0; i < (n-1); i++){
            for (int j = 0; j < times.size(); j++){
                int u = times[j][0] - 1;
                int v = times[j][1] - 1;
                int w = times[j][2];
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                }
            }
        }
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1, v = times[i][1] - 1, w = times[i][2];
            if ((d[v] > d[u] + w)) return -1;
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i != (k-1)) ans = max(ans, d[i]);
        }
        return ans == 1000 * 100 ? -1 : ans;
    }
};
