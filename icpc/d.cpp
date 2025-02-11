#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

struct Cell {
    int row, col, steps;
};

bool isStable(const vector<vector<char>> &matrix, int row, int col, int N) {
    return (row == N - 1 || matrix[row + 1][col] == 'B');
}

bool isValid(const vector<vector<char>> &matrix, int row, int col, int N, int M) {
    return (row >= 0 && row < N && col >= 0 && col < M && matrix[row][col] != 'B');
}

int main() {
    int N, M, K;
    cin >> N >> M;

    vector<vector<char>> matrix(N, vector<char>(M));
    int startRow, startCol;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
        }
    }

    cin >> K;

    queue<Cell> q;
    q.push({startRow, startCol, 0});

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[startRow][startCol] = true;

    vector<pair<int, int>> farthestCells;
    int maxDistance = 0;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.steps > K) continue;

        if (isStable(matrix, current.row, current.col, N)) {
            int distance = abs(current.row - startRow) + abs(current.col - startCol);
            if (distance > maxDistance) {
                maxDistance = distance;
                farthestCells.clear();
                farthestCells.emplace_back(current.row, current.col);
            } else if (distance == maxDistance) {
                farthestCells.emplace_back(current.row, current.col);
            }
        }

        // Gravity
        int nextRow = current.row;
        while (nextRow + 1 < N && matrix[nextRow + 1][current.col] != 'B') {
            nextRow++;
            current.steps++;
            if (current.steps > K) break;
        }

        if (!visited[nextRow][current.col]) {
            visited[nextRow][current.col] = true;
            q.push({nextRow, current.col, current.steps});
        }

        // Explore adjacent cells
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}}; // Left, Right
        for (auto [dr, dc] : directions) {
            int newRow = current.row;
            int newCol = current.col + dc;

            if (isValid(matrix, newRow, newCol, N, M) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol, current.steps + 1});
            }
        }
    }

    sort(farthestCells.begin(), farthestCells.end());
    for (const auto &cell : farthestCells) {
        cout << cell.first << " " << cell.second << endl;
    }

    return 0;
}
