#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> points(N, vector<int>(2));

    for (int i = 0; i < N; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    // Sort points by x-coordinate, and by y-coordinate if x-coordinates are equal
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    });

    vector<vector<int>> lowerHull;
    for (const auto& point : points) {
        while (lowerHull.size() >= 2) {
            // Calculate cross product in place
            auto& a = lowerHull[lowerHull.size() - 2];
            auto& b = lowerHull[lowerHull.size() - 1];
            int cross = (b[0] - a[0]) * (point[1] - a[1]) - (b[1] - a[1]) * (point[0] - a[0]);
            if (cross <= 0) {
                lowerHull.pop_back();
            } else {
                break;
            }
        }
        lowerHull.push_back(point);
    }

    double perimeter = 0.0;
    for (size_t i = 0; i < lowerHull.size() - 1; ++i) {
        // Calculate Euclidean distance in place
        int dx = lowerHull[i + 1][0] - lowerHull[i][0];
        int dy = lowerHull[i + 1][1] - lowerHull[i][1];
        perimeter += sqrt(dx * dx + dy * dy);
    }

    cout << static_cast<int>(round(perimeter)) << endl;

    return 0;
}
