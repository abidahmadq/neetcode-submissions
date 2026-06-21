class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses, 0); 
        unordered_map<int, vector<int>> mp;
        for(int i=0; i < prerequisites.size(); i++) {
            indegree[prerequisites[i][1]]++;
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i < indegree.size(); i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neigh: mp[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }
        for(int i=0; i < indegree.size(); i++) {
            if(indegree[i] != 0) return false;
        }
        return true;
    }
};
