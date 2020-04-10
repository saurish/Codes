#include "../all_cpp_header.hpp"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        std::deque<int>             w_deque;
        std::deque<int>::iterator   iter;
        
        vector<int>                 output;
        
        // construct the first window of size k
        for (int i=0; i<k; i++){
            
            if (w_deque.empty())
                w_deque.push_front(nums[i]);
            else{
                iter    =   w_deque.begin();
                while(iter != w_deque.end() && *iter > nums[i])
                    iter++;
                w_deque.insert(iter, nums[i]);
            }
        }
        
        output.push_back(w_deque.front());
        
        for (int i = k; i< nums.size(); i++)
        {
            // pop the last element
            iter    =   w_deque.begin();
            while(iter != w_deque.end()){
                if(*iter == nums[i-1]){
                    w_deque.erase(iter);
                    break;
                }
            }
            
            // check if current element is the greatest, 
            // then clear the existing queue
            if (nums[i] >= w_deque.front())
                w_deque.clear();
            
            // place the current element at its correct position
            if(w_deque.empty())
                w_deque.push_front(nums[i]);
            else{
                iter    =   w_deque.begin();
                while(iter != w_deque.end() && *iter > nums[i])
                    iter++;
                w_deque.insert (iter, nums[i]);
            }
            
            output.push_back(w_deque.front());
        }
        
        
        return output;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,3,-1,-3,5,3,6,7};

    for (auto& v : s.maxSlidingWindow(v,3))
        cout << v << " ";
    cout << endl;

    return 1;
}