#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {3, 4, 7, 9};

    auto pushinto = [&](int m){
        v1.push_back(m);
        v2.push_back(m);
    };

    pushinto(23);

    auto print = [v1, &v2](){
        v2.push_back(34);

        for (auto p = v1.begin(); p != v1.end(); p++)
            cout<<*p<<" ";
        cout<<endl;

        for (auto p = v2.begin(); p != v2.end(); p++)
            cout<<*p<<" ";
        cout<<endl;
    };
    print();
    return 0;
}