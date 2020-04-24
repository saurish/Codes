/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/longest-consecutive-sequence/
 *  Comment         :   unorderd_map & DFS based solution; start from a value, travel
 *                      left & right continuous ranges; count size; if greater than 
 *                      current max_count, update. Runtime O(N).
 */

#include "../all_cpp_header.hpp"

class Solution {
public:

    int decr_range(unordered_set<int>& hash, int value, int count)
    {
        if(hash.find(value) == hash.end())
            return count;

        hash.erase(value);
        return decr_range(hash, value-1, count+1);
    }

    int incr_range(unordered_set<int>& hash, int value, int count)
    {
        if(hash.find(value) == hash.end())
            return count;

        hash.erase(value);
        return incr_range(hash, value+1, count+1);
    }

    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        unordered_set<int>  hash;

        // insert all the elements in hash
        for (auto& v : nums)
            hash.insert(v);

        int max_count   = 1;
        for (auto& v : hash)
        {
            int count = 1 + decr_range(hash, v-1, 0) + incr_range(hash, v+1, 0);

            if(count > max_count)
                max_count = count;

            hash.erase(v);
        }

        return max_count;
    }
};

int main()
{
    Solution sln;
    vector<int> v{100,4,200,1,3,2};
    cout << sln.longestConsecutive(v) << endl;
}