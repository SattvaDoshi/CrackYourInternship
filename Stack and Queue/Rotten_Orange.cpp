int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> dis(rows, vector<int>(cols, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (q.empty() == false)
    {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int step = q.front().second;
        q.pop();
        dis[i][j] = step;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 and ni < rows and nj >= 0 and nj < cols and visited[ni][nj] == false and grid[ni][nj] == 1)
            {
                visited[ni][nj] = true;
                q.push({{ni, nj}, step + 1});
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (visited[i][j] == false and grid[i][j] == 1)
                return -1;
        }
    }
    int maxi = dis[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (dis[i][j] > maxi)
                maxi = dis[i][j];
        }
    }
    return maxi;
}
