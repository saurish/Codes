#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <algorithm>
#include <fstream>
#include "Profiler.hpp"

using namespace std;

#define     max(a,b)        a>b?a:b
#define     min(a,b)        a<b?a:b
#define     max3(a,b,c)     max(max(a,b),max(b,c))
#define     min3(a,b,c)     min(min(a,b),min(b,c))
#define     max4(a,b,c,d)   max(max(a,b),max(c,d))
#define     min4(a,b,c,d)   min(min(a,b),min(c,d))

/// Priority Queue

template <typename T>
using Max_heap  =   std::priority_queue<T>;

template <typename T>
using Min_heap  =   std::priority_queue<T, vector<T>, std::greater<T> >;

 