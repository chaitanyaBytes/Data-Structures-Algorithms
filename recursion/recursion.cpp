#include <iostream>
using namespace std;

void printNums(int n)
{
    if (n == 0)
        return;
    printNums(n-1);
    cout << n << " ";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        printNums(n);
    }
}