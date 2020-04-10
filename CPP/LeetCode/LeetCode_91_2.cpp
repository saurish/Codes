/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/decode-ways/   
 *  Comment         :   DP-based efficient solution
 */

#include "../all_cpp_header.hpp"

class Solution {
public:
    bool valid_1_digit (string& s, int index)
    {
        return (s[index] - '0') > 0;
    }
    
    bool valid_2_digit (string& s, int index)
    {
        return (s[index] == '1') || (s[index] == '2' && (s[index+1]-'0') <= 6);
    }
    
    int numDecodings(string s) {
        
        if (s.size() == 0)      return 0;
        
        if (s.size() == 1)
            return s[0] == '0'? 0 : 1;
        
        vector<int>     dp_table(s.size(), 0);
        
        // base cases
        dp_table[0] = (int)valid_1_digit(s, 0);
    
        if  (valid_1_digit(s, 1))
            dp_table[1] += dp_table[0];
        if  (valid_2_digit(s, 0))
            dp_table[1]++;
        
        for (int i = 2; i<s.size(); i++){
            
            if (valid_1_digit(s, i))
                dp_table[i] += dp_table[i-1];
            
            if (valid_2_digit(s, i-1))
                dp_table[i] += dp_table[i-2];
        }
        
        return dp_table[s.size()-1];
    }
};

int main()
{
    Solution s;
    RunTimeProfiler rtp;

    rtp.start("dp-based");
    cout << "Count " << s.numDecodings("9317949759856497357254398763219839323723136763131916377913495416692666785978758414629119614215967159") << endl;
    rtp.end("dp-based");
    return 1;
}