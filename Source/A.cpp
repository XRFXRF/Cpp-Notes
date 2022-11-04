#include <iostream>
#include <unordered_map>
using namespace std;

// recrusion function
float recursion(float r, float s, float N,std::unordered_map <std::string,float> &map)
{
    string rstr=std::to_string((int)r);
    string sstr=std::to_string((int)s);
    if (map.find(rstr+","+sstr) != map.end())
        return map[rstr+","+sstr];
    // Because V(N,s)==N+1-s, so if r==N, directly return N+1-s
    if (r == N){
        map[rstr+","+sstr]=N+1-s;
        return N + 1 - s;
    }
        

    // Calculate the r+1 situation
    float add = 0;
    for (int i = 1; i <= r + 1; i++)
        add = add + recursion(r + 1, i, N,map);
    add = add / (r + 1);

    // Return the max{V(r,s),r+1 situation}
    float Max=max(N + 1 - (N + 1) / (r + 1) * s, add);
    map[rstr+","+sstr]=Max;
    return Max;
}

int main()
{
    float N;
    
    while (cin >> N)
    {
        // Use a map to record the V(r,s)
        std::unordered_map <std::string,float> map;
        cout << recursion(1, 1, N,map) << endl; // Get into the recursion, output the answer
    }
    return 0;
}
