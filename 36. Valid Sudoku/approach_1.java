class Solution {
    public boolean isValidSudoku(char[][] board) {
        return areRowsValid(board) && areColsValid(board) && areSubBoxsValid(board);
    }

    private boolean areRowsValid(char[][] board) {
        boolean ok = true;
        for (int i = 0; i < 9; ++i) {
            ok &= isRowValid(board[i]);
        }
        return ok;
    }

    private boolean isRowValid(char[] row) {
        Set<Character> filled = new HashSet<>();
        for (char cell : row) {
            if (cell == '.') {
                continue;
            }

            if (filled.contains(cell)) {
                return false;
            }

            filled.add(cell);
        }
        return true;
    }

    private boolean areColsValid(char[][] board) {
        boolean ok = true;
        for (int i = 0; i < 9; ++i) {
            ok &= isColValid(i, board);
        }
        return ok;
    }

    private boolean isColValid(int c, char[][] board) {
        Set<Character> filled = new HashSet<>();
        for (int r = 0; r < 9; ++r) {
            if (board[r][c] == '.') {
                continue;
            }

            if (filled.contains(board[r][c])) {
                return false;
            }

            filled.add(board[r][c]);
        }
        return true;
    }

    private boolean areSubBoxsValid(char[][] board) {
        boolean ok = true;
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                ok &= isSubBoxValid(r, c, board);
            }
        }
        return ok;
    }

    private boolean isSubBoxValid(int r, int c, char[][] board) {
        Set<Character> filled = new HashSet<>();
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if (filled.contains(board[i][j])) {
                    return false;
                }

                filled.add(board[i][j]);
            }
        }
        return true;
    }
}
