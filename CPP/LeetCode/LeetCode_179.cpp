#include "../all_cpp_header.hpp"

// Problem Link : https://leetcode.com/problems/largest-number/

class Solution {
public:
    
    class CustomCompare // custom greater operator
    {
    public:
        
      bool compare_prefix (string prefix, string rest_part)
      {
          string s1 =   prefix + rest_part;
          string s2 =   rest_part + prefix;
          
          for (int i = 0; i < s1.size(); i++)
          {
              if (s1[i] != s2[i])
                  return s1[i] > s2[i];
          }
          return false;
      }
        
      bool compare_util (const string& s, const string& t, int index)
      {
         
         if(s[index] != t[index])
              return s[index] > t[index];
         
          else { // s[index] == t[index]
              
              // case 1 : s == t
              if (index == s.size() -1 && index == t.size() -1)
                  return false;
              // case 2 : s is prefix of t (= s.x), compate gt (s.x, x.s)
              else if (index == s.size()-1){
                  
                  return compare_prefix (s, t.substr(s.size(),t.size()-s.size()));
              }
              // case 3 : t is prefix of s (= t.x), compate gt (t.x, x.t)
              else if (index == t.size()-1){
                  
                  return compare_prefix (s.substr(t.size(),s.size()-t.size()), t);
              }
              else 
                  return compare_util(s,t,index+1);
          }  
      }
        
      bool operator()(const string& s, const string& t)
      {
          return compare_util (s,t,0);
      }
        
    };
    
    
    string largestNumber(vector<int>& nums) {
        
        if (nums.size() == 0)
            return "";
        
        vector<string> num_str_vec;
        
        for (auto& num : nums){
            string  num_str     =   to_string(num);
            num_str_vec.push_back (num_str);
        }
        
        std::sort (num_str_vec.begin(), num_str_vec.end(), CustomCompare());
        
        string      output  =   "";
        for (auto& v : num_str_vec){
            output += v;
        }
        
        // corner case : removing leading 0s
        while(output[0] == '0' && output.size() >= 2)
            output.erase(0,1);
        
        return output;
    }
};