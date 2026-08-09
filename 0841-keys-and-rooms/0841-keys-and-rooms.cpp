class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms,
             vector<bool>& visited) {

        visited[room] = true;

        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        // Start from room 0
        dfs(0, rooms, visited);

        // Check if every room was reached
        for (bool roomVisited : visited) {
            if (!roomVisited)
                return false;
        }

        return true;
    }
};