
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    int id;
    double x, y, z;
};

double distance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

double bruteForceTSP(const vector<Point>& points, vector<int>& bestPath) {
    vector<int> perm(points.size());
    for (int i = 0; i < perm.size(); i++) perm[i] = i;

    double minDistance = numeric_limits<double>::max();

    do {
        double currentDistance = 0.0;
        for (size_t i = 0; i < perm.size() - 1; i++) {
            currentDistance += distance(points[perm[i]], points[perm[i + 1]]);
        }
        currentDistance += distance(points[perm.back()], points[perm[0]]);

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            bestPath = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    return minDistance;
}

double dpTSP(const vector<Point>& points, vector<int>& bestPath) {
    int n = points.size();
    vector<vector<double>> dp(1 << n, vector<double>(n, numeric_limits<double>::max()));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                double newDistance = dp[mask][u] + distance(points[u], points[v]);
                if (newDistance < dp[mask | (1 << v)][v]) {
                    dp[mask | (1 << v)][v] = newDistance;
                    parent[mask | (1 << v)][v] = u;
                }
            }
        }
    }

    double minDistance = numeric_limits<double>::max();
    int lastNode = -1;
    for (int i = 1; i < n; i++) {
        double currentDistance = dp[(1 << n) - 1][i] + distance(points[i], points[0]);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            lastNode = i;
        }
    }

    bestPath.clear();
    int mask = (1 << n) - 1;
    while (lastNode != -1) {
        bestPath.push_back(lastNode);
        int temp = lastNode;
        lastNode = parent[mask][lastNode];
        mask ^= (1 << temp);
    }
    reverse(bestPath.begin(), bestPath.end());

    return minDistance;
}

double nearestNeighborTSP(const vector<Point>& points, vector<int>& bestPath) {
    int n = points.size();
    vector<bool> visited(n, false);
    bestPath.clear();

    int current = 0;
    visited[current] = true;
    bestPath.push_back(current);

    double totalDistance = 0.0;

    for (int i = 1; i < n; i++) {
        double minDistance = numeric_limits<double>::max();
        int next = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance(points[current], points[j]) < minDistance) {
                minDistance = distance(points[current], points[j]);
                next = j;
            }
        }

        totalDistance += minDistance;
        current = next;
        visited[current] = true;
        bestPath.push_back(current);
    }

    totalDistance += distance(points[current], points[bestPath[0]]);
    return totalDistance;
}

int main() {
    ifstream inputFile("waypoints.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open waypoints.txt" << endl;
        return 1;
    }

    vector<Point> points;
    Point p;
    while (inputFile >> p.id >> p.x >> p.y >> p.z) {
        points.push_back(p);
    }

    vector<int> bestPath;
    double totalDistance;

    if (points.size() < 8) {
        totalDistance = bruteForceTSP(points, bestPath);
    } else if (points.size() <= 15) {
        totalDistance = dpTSP(points, bestPath);
    } else {
        totalDistance = nearestNeighborTSP(points, bestPath);
    }

    ofstream outputFile("path.txt");
    if (!outputFile) {
        cerr << "Error: Cannot open path.txt" << endl;
        return 1;
    }

    for (int idx : bestPath) {
        outputFile << points[idx].id << " ";
    }
    outputFile << points[bestPath[0]].id << " " << totalDistance << endl;

    cout << "Path saved to path.txt" << endl;
    return 0;
}
