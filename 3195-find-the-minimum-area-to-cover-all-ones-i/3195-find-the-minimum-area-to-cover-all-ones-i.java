class Solution {
    public int minimumArea(int[][] grid) {
        
        int tleft = 1001;
        int tright = -1;
        int dup = 1001;
        int down = -1;

        int r = grid.length;
        int c = grid[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    tleft = Math.min(tleft,j);
                    tright=Math.max(tright,j);
                    dup=Math.min(dup,i);
                    down=Math.max(down,i);
                }
            }
        }
        return (tright-tleft+1)*(down-dup+1);
    }
}