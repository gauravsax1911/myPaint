class Solution
{
public:
    int findpar(int p, vector<int> &par)
    {
        return par[p] == p ? p : (par[p] = findpar(par[p], par));
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> parent(n * m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                parent[i * m + j] = i * m + j;
            }
        }

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int fans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    int p1 = findpar(i * m + j, parent);
                    int area = 0;
                    for (int d = 0; d < dir.size(); d++)
                    {
                        int r = i + dir[d][0];
                        int c = j + dir[d][1];

                        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)

                        {
                            int p2 = findpar(r * m + c, parent);
                            if (p1 != p2)
                            {
                                parent[p1] = p2;
                                area++;
                            }
                        }
                    }
                    fans = max(fans, area);
                }
            }
        }
        return fans;
    }
};