**1.解題說明**

1.問題描述:使用遞迴函式計算集合S的所有子集合
- powerset(S) 代表集合 S 的所有可能子集
  
2.解題策略:
- 遞迴：每次只看集合中的一個元素 決定要或不要加入目前的子集合
  
**2.程式實作**

```cpp
#include <iostream>
using namespace std;

int powerset(char S[], char subset[], int n, int i, int j)
{
    if (i == n)
    {
        cout << "{ ";
        for (int k = 0; k < j; k++)
            cout << subset[k] << " ";
        cout << "}" << endl;
        return 0;
    }


    powerset(S, subset, n, i + 1, j);

    subset[j] = S[i];
    powerset(S, subset, n, i + 1, j + 1);

    return 0;
}

int main()
{
    int n;
    char S[20];
    char subset[20];

    cout << "輸入集合元素個數 n: ";
    cin >> n;

    cout << "輸入 " << n << " 個元素 (字元): ";
    for (int i = 0; i < n; i++)
        cin >> S[i];

    cout << "powerset(S):" << endl;
    powerset(S, subset, n, 0, 0);

    return 0;
}
```

**3.效能分析**

1.時間複雜度:
2ⁿ=O(n × 2ⁿ)

2.空間複雜度:
S[n]=O(n)

**4.測試與驗證**

```shell
$ g++ problem2.cpp --std=c++17 -o problem2.exe
$ ./problem2.exe
輸入集合元素個數 n:3
輸入3個元素 (字元):a b c
Powerset(S):
{}
{a}
{b}
{c}
{a, b}
{a, c}
{b, c}
{a, b, c}
```

**5.申論及開發報告**
- 使用「位元運算的演算法來列舉所有子集合
- 利用整數的二進位表示法，每個位元代表集合中一個元素的要或不要狀態
- 當共有 n 個元素時，所有可能的組合數為 2ⁿ

