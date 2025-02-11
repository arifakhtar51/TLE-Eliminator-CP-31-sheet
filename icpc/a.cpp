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

    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    });

    vector<vector<int>> lowerHull;
    for (const auto& point : points) {
        while (lowerHull.size() >= 2 &&
               (lowerHull[lowerHull.size() - 2][0] - lowerHull[lowerHull.size() - 1][0]) *
                   (point[1] - lowerHull[lowerHull.size() - 1][1]) -
               (lowerHull[lowerHull.size() - 2][1] - lowerHull[lowerHull.size() - 1][1]) *
                   (point[0] - lowerHull[lowerHull.size() - 1][0]) <= 0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(point);
    }

    double perimeter = 0.0;
    for (size_t i = 0; i < lowerHull.size() - 1; ++i) {
        perimeter += sqrt(pow(lowerHull[i + 1][0] - lowerHull[i][0], 2) +
                          pow(lowerHull[i + 1][1] - lowerHull[i][1], 2));
    }

    cout << static_cast<int>(round(perimeter)) << endl;

    return 0;
}
