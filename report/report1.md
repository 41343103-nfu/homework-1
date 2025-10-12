**1.解題說明**

1.問題描述:
使用遞迴和非遞迴兩個方法 寫出Ackermann函式A(m,n):
- 若 m=0 則回傳 n+1
- 若 n=0 且 m>0 則回傳 A(m−1,1)
- 否則回傳 A(m−1,A(m,n−1))

2.解題策略:
- 遞迴:使用數學定義直接遞迴呼叫
- 非遞迴:使用陣列來模擬這個堆疊

**2.程式實作**

```cpp
#include <iostream>
using namesapce std;

int A(int m, int n)
{
 if (m == 0)
  return n + 1;
 else if (n == 0)
  return A(m - 1, 1);
 else
  return A(m - 1, A(m, n - 1));
 }

int Ac(int m, int n)
{
    const int MAX = 100000;
    int stack[MAX];
    int top = -1;
    stack[++top] = m;

    while (top >= 0)
    {
        m = stack[top--];
        if (m == 0)
        {
            n = n + 1;
        }
        else if (n == 0)
        {
            n = 1;
            stack[++top] = m - 1;
        }
        else
        {
            stack[++top] = m - 1;
            stack[++top] = m;
            n = n - 1;
        }
    }
    return n;
}
int main()
{
 int m, n;

 cout << "輸入 m,n :" << endl;
 cin >> m >> n;
 cout << "A(" << m << "," << n << ")=" << A(m, n) << endl;

    cout << "A(" << m << "," << n << ")=" << Ac(m, n) << endl;

 return 0;
}
```

**3.效能分析**

1.時間複雜度:
Ackermann函式成長極快 約等於A(m,n+1)-1
- m=0：O(1)
- m=1：O(n)
- m=2：O(n)
- m=3：約 O(2^n)
   
2.空間複雜度:
- 遞迴:遞迴深度與展開路徑相關
- 非遞迴:以陣列堆疊模擬，最多需要與遞迴深度同階的堆疊空間
  
**4.測試與驗證**
$ g++ problem1.cpp -std=c++17 -O2 -o p1.exe
$ ./p1.exe
輸入 m,n:
2 3
A(2,3)=9
A(2,3)=9

**5.申論及開發報告**
- 使用遞迴演算法 能直接對應數學式 程式碼也比較淺顯易懂
- 使用堆疊資料結構 模擬遞迴能避免系統遞迴深度的限制 也方便觀察呼叫順序


