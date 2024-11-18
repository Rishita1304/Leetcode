class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& image, int oldColor, int newColor){
        if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) return;
        if (image[x][y] != oldColor) return;
        
        image[x][y] = newColor;
        dfs(x + 1, y, image, oldColor, newColor); // Down
        dfs(x - 1, y, image, oldColor, newColor); // Up
        dfs(x, y + 1, image, oldColor, newColor); // Right
        dfs(x, y - 1, image, oldColor, newColor); // Left
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor = image[sr][sc];
        if (inColor != color) {
            dfs(sr, sc, image, inColor, color);
        }
        return image;
    }
};