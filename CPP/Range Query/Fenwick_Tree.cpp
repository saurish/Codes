#include "../all_cpp_header.hpp"

class FenwickTree
{
    public:
        FenwickTree(vector<int>& n) : nums(n) 
        { 
            for (int i = 0; i < (nums.size() + 1); i++)
                binary_indexed_tree.push_back(0);
        }

        int     parent              (int id)    {   return id - (id&-id); }
        int     next                (int id)    {   return id + (id&-id); }

        void    constitute_bitree   ();                             //  O(NlogN)
        int     prefix_sum          (int range_i);                  //  O(logN) 
        int     range_query         (int range_i, int range_j);     //  O(logN)
        void    update_value        (int idx, int add_value);       //  O(logN)


    private:
        vector<int>&        nums;
        vector<int>         binary_indexed_tree;
};

void FenwickTree::constitute_bitree()
{
    for (int i =0; i < nums.size(); i++)
    {
        update_value(i, nums[i]);
    }
}

int FenwickTree::prefix_sum(int range_i)
{
    if (range_i < 0)
        return 0;

    range_i++;

    int sum  =  0;
    while(range_i){
        sum +=  binary_indexed_tree[range_i];
        range_i = parent(range_i);
    }

    return sum;
}

int FenwickTree::range_query(int range_i, int range_j)
{
    return prefix_sum(range_j) - prefix_sum(range_i-1);
}

void FenwickTree::update_value(int idx, int add_value)
{
    idx++;

    while(idx < binary_indexed_tree.size())
    {
        binary_indexed_tree[idx] += add_value;
        idx =   next(idx); 
    }
}

int main()
{
    vector<int> nums{1,2,-5,45,9,7,-32,35,78,56, 12, -9, 39, 22, 17};

    FenwickTree fnwick_tree(nums);
    fnwick_tree.constitute_bitree();

    cout << "RANGE_SUM(2,7) : " << fnwick_tree.range_query(2,7) << endl; 
    cout << "RANGE_SUM(0,7) : " << fnwick_tree.range_query(0,7) << endl; 
    cout << "RANGE_SUM(3,9) : " << fnwick_tree.range_query(2,7) << endl; 
    cout << "UPDATE_VALUE (3,4)" << endl;
    fnwick_tree.update_value(3,4);
    cout << "RANGE_SUM(2,7) : " << fnwick_tree.range_query(2,7) << endl; 

    cout << "Success." << endl;
}