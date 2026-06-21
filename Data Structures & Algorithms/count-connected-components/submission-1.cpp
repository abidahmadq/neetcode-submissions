class Solution {
    vector<int> parents;
    int find(int x) {
        if(x == parents[x]) {
            return x;
        }
        parents[x] = find(parents[x]);
        return parents[x];
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parents.resize(n, 0);
        for(int i=0; i < parents.size(); i++) {
            parents[i] = i;
        }
        for(int i=0; i < edges.size(); i++) {
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x != y) {
                parents[x] = y;
            }
        }
        int c=0;
        for(int i=0; i < parents.size(); i++) {
            if(parents[i] == i) {
                c++;
            }
        }
        return c;
    }
};
