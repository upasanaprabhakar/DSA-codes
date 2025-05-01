class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph(numCourses);  //adjency list
            vector<int> indegree(numCourses,0);
    
            for(auto&p : prerequisites){
                graph[p[1]].push_back(p[0]);    //p[1] --> p[0]
                indegree[p[0]]++;
            }
            queue<int> q;
    
            for(int i=0;i<numCourses;i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            int count=0;
            while(!q.empty()){
                int course= q.front();
                q.pop();
                count++;
    
                for(auto neighbour : graph[course]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
            return count == numCourses;
        }
    };