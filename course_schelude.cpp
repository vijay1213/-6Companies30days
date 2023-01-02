class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
                
        unordered_map<int, vector<int>> um;
        vector<int> visited(numCourses, 0);
        
        //Make list of prerequisites of all courses and add to a map
        for (auto p: prerequisites)
        {
            um[p[0]].push_back(p[1]);
        }
        
        //Traverse each course, return true if each prerequisite of the course can be traversed
        for (int i=0; i<numCourses; i++)
        {
            if (!traverse(visited, um, i))
                return false;
        }
        
        return true;
    }
    
    bool traverse (vector<int>& visited, unordered_map<int, vector<int>>& um, int i)
    {
        
        if (visited[i]==10) //Already visiting (a cycle exists)
            return false;
        if (visited[i]==1)
            return true;
        visited[i]=10;      //Mark as visiting
        for (auto c: um[i])
        {
            if (!traverse(visited, um, c))
                return false;
        }
        visited[i] = 1;     //Visited
        return true;
    }
    
};
