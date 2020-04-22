/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/ 
 *  Comment         :   runtime O(h) -- height of the element
 *  Algorithm       :   For each element find it's parent in the original non-zigzag binary 
 *                      tree and then find the element which is sitting at symmetrically  
 *                      opposite position at that level. This element is parent element of
 *                      the current element in the zigzag tree. Recrsively do the same till
 *                      you reach the root.
 */

#include "../all_cpp_header.hpp"

class Solution {
public:
    
    int     level_start                 (int level)     { return (int)pow(2, level); }
    int     level_end                   (int level)     { return (int)pow(2, level+1) - 1; }

    int     parent_in_non_zigzag_tree   (int value)     { return value/2; }
    int     opp_elem_on_zigzag_tree     (int value)
    {
        int level   =   (int)log2(value);
        return level_end(level) - (value - level_start(level));
    }
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> output;

        output.emplace(output.begin(), label);
        while(label!=1){
            label = opp_elem_on_zigzag_tree(parent_in_non_zigzag_tree(label));
            output.emplace(output.begin(), label);
        }
        
        return output;
    }
};

int main()
{
    Solution sln;
    auto output = sln.pathInZigZagTree(30);
    for(auto& v : output)
        cout << v << " ";
    cout << endl;
}