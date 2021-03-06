class Solution 
{
public:
    vector<vector<int>> g;
    vector<int> c;
    vector<int> ans;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for (int i = 0; i < numCourses; ++i)
        {
            c.push_back(0);
            vector<int> t;
            g.push_back(t);
        }
        
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for (int i = 0; i < numCourses; ++i)
        {
            if (!c[i])
            {
                if (!dfs(i))
                {
                    ans.clear();
                    return ans;
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    bool dfs(int v)
    {
        c[v] = 1;
        
        for (int i = 0; i < g[v].size(); ++i)
        {
            int u = g[v][i];
            if (!c[u])
            {
                if (!dfs(u))
                {
                    return false;
                }
            }
            else if (c[u] == 1)
            {
                return false;
            }
        }
        
        c[v] = 2;
        
        ans.push_back(v);
        
        return true;
    }
};