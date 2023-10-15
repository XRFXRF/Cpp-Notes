#include <iostream>
#include <math.h>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main()
{
    int expert;                             // input the number of the expert
    float w[5] = {0.2, 0.2, 0.2, 0.2, 0.2}; // build the w array
    while (cin >> expert)
    {
        float sum = 0; // the sum of w[j]*exp(z[i])
        float z[5];    // build the z array for every time
        for (int i = 0; i < sizeof(w) / sizeof(w[0]); i++)
        {
            if (i == expert - 1)
            {
                z[i] = 1;
            }
            else
            {
                z[i] = 0;
            }
        }

        for (int i = 0; i < sizeof(w) / sizeof(w[0]); i++)
        {
            sum = sum + w[i] * exp(z[i]); // sum the w[i] * exp(z[i])
        }

        for (int i = 0; i < sizeof(w) / sizeof(w[0]); i++)
        {
            w[i] = w[i] * exp(z[i]) / sum; // calculate the w[i] and output it in setprecision(3)
            cout << setprecision(3) << w[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
