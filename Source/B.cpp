#include <iostream>
using namespace std;

// recrusion function
float recursion(float r, float s, float N)
{
    // Because V(N,s)==N+1-s, so if r==N, directly return N+1-s
    if (r == N)
        return N + 1 - s;

    // Calculate the r+1 situation
    float add = 0;
    for (int i = 1; i <= r + 1; i++)
        add = add + recursion(r + 1, i, N);
    add = add / (r + 1);

    // Return the max{V(r,s),r+1 situation}
    return max(N + 1 - (N + 1) / (r + 1) * s, add);
}

int main()
{
    float N;
    while (cin >> N)
    {
        cout << recursion(1, 1, N) << endl; // Get into the recursion, output the answer
    }
    return 0;
}
