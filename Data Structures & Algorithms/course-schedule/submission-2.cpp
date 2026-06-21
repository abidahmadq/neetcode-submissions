class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>> &pre_map, vector<int> &visited) {
        if(visited[node] == 1) {
            return false;
        }
        if(pre_map[node].empty()) {
            return true;
        }
        visited[node] = 1;
        for(int pre: pre_map[node]) {
            if(!dfs(pre, pre_map, visited)) {
                return false;
            }
        }
        visited[node] = 0;
        pre_map[node].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre_map;
        for(int i=0; i < prerequisites.size(); i++) {
            pre_map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses, 0);
        for(int c=0; c < numCourses; c++) {
            if(!dfs(c, pre_map, visited)) {
                return false;
            }
        }
        return true;
    }
};
