#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {

        const int INF = 1e9;

        // price[i] = cheapest price to reach city i
        // using at most the current number of flights
        vector<int> price(n, INF);

        price[src] = 0;

        /*
         * At most k stops means at most k + 1 flights.
         */
        for (int stops = 0; stops <= k; stops++) {

            // IMPORTANT:
            // Use a copy so that one iteration only represents
            // paths with one additional flight.
            vector<int> nextPrice = price;

            for (auto& flight : flights) {

                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if (price[from] == INF) {
                    continue;
                }

                nextPrice[to] = min(
                    nextPrice[to],
                    price[from] + cost
                );
            }

            price = nextPrice;
        }

        return price[dst] == INF
            ? -1
            : price[dst];
    }
};