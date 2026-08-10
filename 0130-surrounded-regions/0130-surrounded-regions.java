class Solution {
    public void solve(char[][] board) {

        int rows = board.length;
        int cols = board[0].length;

        // 1. Mark all border-connected O's as safe
        for (int r = 0; r < rows; r++) {
            dfs(board, r, 0);
            dfs(board, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(board, 0, c);
            dfs(board, rows - 1, c);
        }

        // 2. Flip surrounded O's to X
        //    Restore safe O's
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    private void dfs(char[][] board, int r, int c) {

        int rows = board.length;
        int cols = board[0].length;

        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        // Only process O
        if (board[r][c] != 'O') {
            return;
        }

        // Mark as safe
        board[r][c] = '#';

        // Explore 4 directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }
}