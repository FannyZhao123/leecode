/*
733. Flood Fill
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/
//Runtime: 16 ms, faster than 80.56% of C++ online submissions for Flood Fill.
//Memory Usage: 14.1 MB, less than 11.11% of C++ online submissions for Flood Fill.
class Solution {
public:
    void helper (vector<vector<int>>& image, int sr, int sc, int newColor, int ori_color){
        if (image[sr][sc] != ori_color) return;
        if (image[sr][sc] == newColor) return;
        else image[sr][sc] = newColor;
        if (sr-1>=0) helper(image, sr-1, sc, newColor, ori_color);
        if (sr+1<image.size()) helper(image, sr+1, sc, newColor, ori_color);
        if (sc-1>=0) helper(image, sr, sc-1, newColor, ori_color);
        if (sr+1<image[0].size()) helper(image, sr, sc+1, newColor, ori_color);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int ori_color = image[sr][sc];
        helper(image, sr, sc, newColor, ori_color);
        return image;
    }
};


//DFS
struct Pixel {
    int x;
    int y;
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int target = image[sr][sc];
        if (target != newColor) {
            flood(&image, {sr, sc}, target, newColor);
        }
        return image;
    }
private:
    void flood(vector<vector<int>>* image_ptr, const Pixel& pixel, int target, int newColor) {
        auto& image = *image_ptr;
        image[pixel.x][pixel.y] = newColor;

        for (const auto& next : vector<Pixel>({
            {pixel.x - 1, pixel.y},
            {pixel.x + 1, pixel.y},
            {pixel.x, pixel.y - 1},
            {pixel.x, pixel.y + 1}
        })) {
            if (next.x >= 0 && next.x < image.size() &&
                next.y >= 0 && next.y < image[next.x].size() &&
                image[next.x][next.y] == target) {
                flood(image_ptr, next, target, newColor);
            }
        }
    }
};

//BFS
struct Pixel {
    int x;
    int y;
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        Pixel first_pixel = {sr, sc};
        
        int color = image[first_pixel.x][first_pixel.y];
        queue<Pixel> to_process;
        
        if (color != newColor) {
            to_process.emplace(first_pixel);
        }

        while (!empty(to_process)) {
            auto pixel = to_process.front();
            to_process.pop();
            image[pixel.x][pixel.y] = newColor;

            for (auto next : vector<Pixel>({
                { pixel.x - 1, pixel.y },
                { pixel.x + 1, pixel.y },
                { pixel.x, pixel.y - 1 },
                { pixel.x, pixel.y + 1 }
            })) {
                if (next.x >= 0 && next.x < image.size() &&
                    next.y >= 0 && next.y < image[next.x].size() &&
                    image[next.x][next.y] == color) {
                    to_process.emplace(next);
                }
            }
        }
        
        return image;
    }
};

//

class Solution 
{
public:
   	 void fillImageRec(vector<vector<int>>& image,int x,int y,int origC,int newC){
        if(image[x][y]==origC){
            image[x][y] = newC;
            //check left
            if(y-1 >= 0 && image[x][y-1]==origC)
                fillImageRec(image,x,y-1,origC,newC);
            //check right
            if((y+1 < image[0].size()) && image[x][y+1] == origC)
                 fillImageRec(image,x,y+1,origC,newC);
            //check up
             if(x-1 >= 0 && image[x-1][y]==origC)
                fillImageRec(image,x-1,y,origC,newC);
            //check down
            if((x+1 < image.size()) && image[x+1][y] == origC)
                 fillImageRec(image,x+1,y,origC,newC);
        }
    }
    void fillImageUsingQ(vector<vector<int>>& image, int sr, int sc, int newColor){
        int O = image[sr][sc];
        if(O!=newColor){
            queue<pair<int,int>>q;
            q.push(pair(sr,sc));
            while(!q.empty()){
                auto point = q.front();
                q.pop();
                int x = point.first;
                int y = point.second;
                image[x][y] = newColor;
                //check left
                if(y-1 >=0 && image[x][y-1] == O)
                    q.push(pair(x,y-1));
                //check right
                if((y+1 < image[0].size()) && image[x][y+1] == O)
                    q.push(pair(x,y+1));
                //check up
                if(x-1 >=0 && image[x-1][y] == O)
                    q.push(pair(x-1,y));
                //check down
                if((x+1 < image.size()) && image[x+1][y] == O)
                    q.push(pair(x+1,y));
            }
        } 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) //if this check is omitted it will run forever
		{
            fillImageUsingQ(image,sr,sc,newColor);  // iterative using queue
            // fillImageRec(image,sr,sc,image[sr][sc],newColor); //recursive approach
        }
        return image; 
    }
};

