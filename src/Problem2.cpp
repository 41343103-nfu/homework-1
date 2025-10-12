#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    char S[20];

    cout << "輸入集合元素個數 n: ";
    cin >> n;

    cout << "輸入 " << n << " 個元素 (字元): ";
    for (int i = 0; i < n; i++)
        cin >> S[i];

    cout << "Powerset(S):" << endl;

    int total = pow(2, n);

    for (int i = 0; i < total; i++)
    {
        cout << "{";

        bool first = true;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                if (!first) cout << ", ";
                cout << S[j];
                first = false;
            }
        }

        cout << "}" << endl;
    }

    return 0;
}