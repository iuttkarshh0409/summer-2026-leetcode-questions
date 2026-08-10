#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // minDist[i] = cheapest edge currently known
        // to connect point i to the growing MST
        vector<int> minDist(n, INT_MAX);

        // Already included in MST?
        vector<bool> used(n, false);

        // Start from point 0
        minDist[0] = 0;

        int totalCost = 0;

        for (int count = 0; count < n; count++) {

            // Find unused point with smallest connection cost
            int current = -1;

            for (int i = 0; i < n; i++) {

                if (!used[i] &&
                    (current == -1 ||
                     minDist[i] < minDist[current])) {

                    current = i;
                }
            }

            // Add this point to MST
            used[current] = true;
            totalCost += minDist[current];

            // Update distances to the MST
            for (int next = 0; next < n; next++) {

                if (used[next]) {
                    continue;
                }

                int distance =
                    abs(points[current][0] - points[next][0]) +
                    abs(points[current][1] - points[next][1]);

                minDist[next] = min(
                    minDist[next],
                    distance
                );
            }
        }

        return totalCost;
    }
};