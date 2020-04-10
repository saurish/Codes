#include "../all_cpp_header.hpp"

class Solution {
public:
    int numDecodings(string s) {
        // base cases
        if (s.size() == 0)      return 0;
        
        if (s.size() == 1)
            return s[0] == '0'? 0 : 1;
        
        int     count       =   0;
        numDecondingsUtil (s, 0, count);
        return count;
    }
    
    void numDecondingsUtil  (string& s, int start_index, int& count){
        
        if (start_index >= s.size()){
            count++;
            return;
        }
        
        if (s[start_index] != '0')
            numDecondingsUtil (s, start_index+1,count);
        
        if(start_index < s.size()-1){
            
            int w_2_num     = stoi(s.substr(start_index,2));   
            if (w_2_num >= 10 && w_2_num <= 26) // 02 will not be considered as a legit 2-digit number
                numDecondingsUtil (s, start_index+2,count);
        }
        
        return;
    }
};

int main()
{
    Solution s;
    cout << "Count " << s.numDecodings("9317949759856497357254398763219839323723136763131916377913495416692666785978758414629119614215967159") << endl;
    return 1;
}