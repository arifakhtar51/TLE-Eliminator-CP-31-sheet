#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int startX, int startY, vector<vector<char>>& grid, vector<vector<bool>>& visited, bool breakWall) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int points = 0;
    bool wallBroken = false;

    if (grid[startX][startY] == '*') {
        points++;
    }

    while (!q.empty()) {
        // auto [x, y] = q.front();
        auto x=q.front().first;
        auto y=q.front().second;
        q.pop();

        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (grid[nx][ny] == '*' && !visited[nx][ny]) {
                    points++;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (grid[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (grid[nx][ny] == '#' && !wallBroken && breakWall) {
                    wallBroken = true;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    return points;
}

int maxPoints(int n, int m, vector<vector<char>>& grid) {
    int maxPoints = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                fill(visited.begin(), visited.end(), vector<bool>(m, false));
                maxPoints = max(maxPoints, bfs(i, j, grid, visited, false));

                for (const auto& dir : directions) {
                    int nx = i + dir[0];
                    int ny = j + dir[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '#') {
                    
                        grid[nx][ny] = '.';
                        fill(visited.begin(), visited.end(), vector<bool>(m, false));
                        maxPoints = max(maxPoints, bfs(i, j, grid, visited, true));
                
                        grid[nx][ny] = '#';
                    }
                }
            }
        }
    }

    return maxPoints;
}

int main() {
    int n = 4;
    int m = 4;
    vector<vector<char>> grid = {
        {'*', '.', '.', '*','#'},
        {'#', '#','*', '#', '#'},
        {'.', '*', '*', '*','*'},
        {'*', '#', '#', '#','#'}
    };

    cout << "Maximum points collected: " << maxPoints(n, m, grid) << endl; // Output will be the maximum number of points that can be collected

    return 0;
}
