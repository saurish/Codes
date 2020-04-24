/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/spiral-matrix/ 
 *  Comment         :   O(MN) algorithm, beat 100% 
 */

#include "../all_cpp_header.hpp"


class Solution {
public:
    
    void        printRightDown      (vector<vector<int>>&   matrix,\
                                    int                     start_x,\
                                    int                     start_y,\
                                    int                     x_limit,\
                                    int                     y_limit,\
                                    vector<int>&            output)
    {
        // at each full cycle start points are moving (+1,+1) direction;
        // and boundary box index is moving in (-1,-1) direction
        if (start_x > x_limit || start_y > y_limit)
            return;
        
        // top row
        for (int y = start_y; y <= y_limit; y++)
            output.push_back(matrix[start_x][y]);
        
        // right column
        for (int x = start_x+1; x <= x_limit-1; x++)
            output.push_back (matrix[x][y_limit]);
        
        printLeftUp (matrix, start_x, start_y, x_limit, y_limit, output);
    }
    
    void        printLeftUp         (vector<vector<int>>&   matrix,\
                                    int                     start_x,\
                                    int                     start_y,\
                                    int                     x_limit,\
                                    int                     y_limit,\
                                    vector<int>&            output)
    {
        // bcos next start point is +1 on x-direction
        if( x_limit <= start_x)
            return;
        
        // bottom row
        for (int y = y_limit; y >= start_y; y--)
            output.push_back(matrix[x_limit][y]);
        
        // the above move is along -y direction;
        // so check if y-width > 1
        if(y_limit <= start_y)
            return;
        
        // left column
        for (int x = x_limit-1; x >= start_x+1; x--)
            output.push_back(matrix[x][start_y]);
        
        printRightDown (matrix, start_x+1, start_y+1, x_limit-1, y_limit-1, output);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>     output;
        
        // base case
        if (matrix.size() == 0)
            return output;
        
        printRightDown (matrix, 0,0, matrix.size()-1, matrix[0].size()-1, output);
        return output;
        
    }
};