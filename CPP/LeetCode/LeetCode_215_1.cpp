/*  Author          :   Sauresh Bhowmick
 *  Problem Link    :   https://leetcode.com/problems/kth-largest-element-in-an-array/
 *  Comment         :   Max-heap solution, runtime O(klogk)
 */

#include "../all_cpp_header.hpp"

typedef         std::pair<int,int>      ElemIndexPair;

class CompareHeapElem
{
    public:
    bool operator()(ElemIndexPair& p1, ElemIndexPair& p2)
    {
        return p1.first < p2.first;
    }
};

class Solution {
public:

    int         left            (int paren_indx)  { return 2*paren_indx + 1; }
    int         right           (int paren_indx)  { return 2*paren_indx + 2; }

    int         left_child      (vector<int>& arr, int paren_indx) { return arr[left(paren_indx)]; }
    int         right_child     (vector<int>& arr, int paren_indx) { return arr[right(paren_indx)]; }

    int         findKthLargest  (vector<int>& nums, int k) {

        if(k == 0)
            return -1;

        std::make_heap(nums.begin(), nums.end());

        vector<ElemIndexPair>     aux_max_heap;
        ElemIndexPair   eip =   std::make_pair(nums[0],0);
        aux_max_heap.push_back(eip);
        
        ElemIndexPair   max_element;
        while(k--){

            max_element     =   aux_max_heap.front();
            std::pop_heap(aux_max_heap.begin(), aux_max_heap.end(), CompareHeapElem());
            aux_max_heap.pop_back();

            //cout << "Max Elem " << max_element.first << " " << max_element.second << endl;

            if (left(max_element.second) < nums.size()){

                aux_max_heap.push_back(make_pair(left_child(nums, max_element.second), left(max_element.second)));
                std::push_heap (aux_max_heap.begin(), aux_max_heap.end(), CompareHeapElem());
            }

            if (right(max_element.second) < nums.size()){
                aux_max_heap.push_back(make_pair(right_child(nums, max_element.second), right(max_element.second)));
                std::push_heap (aux_max_heap.begin(), aux_max_heap.end(), CompareHeapElem());
            }
        }

        return max_element.first;

    }
};

int main()
{
    vector<int> v{3,2,1,5,9,-9,27,6,4};
    Solution sln;
    cout << sln.findKthLargest(v, 4) << endl;
}