#include <iostream>
#include <vector>
using namespace std;

// print 1 -> n using recursion
void printNums(int n)
{
    if (n == 0)
        return;
    printNums(n - 1);
    cout << n << " ";
}

/*
probelm: return a sorted array containing all the factorial numbers <= n
Approach: initialise a factorial var x = 1, and a counter var i = 1. for factorial
multiply x with i, while incrementing i by 1 each funnction call.
*/

void factorial(long long x, int i, int n, vector<long long> &factorials)
{
    if (x > n)
        return;
    factorials.push_back(x);
    x *= ++i;
    factorial(x, i, n, factorials);
}
vector<long long> factorialNumbers(long long n)
{
    vector<long long> factorials;
    factorial(1, 1, n, factorials);
    return factorials;
}

/*
problem: reverse array
approach: initialise to pointers start, end of array. swap start and end elements.
and with every recursive call, increment start and decrement end by 1.
*/
void reverseArray(int start, int end, vector<int> &nums)
{
    if (start > end)
        return;
    swap(nums[start], nums[end]);
    reverseArray(start + 1, end - 1, nums);
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    reverseArray(0, n - 1, nums);
    return nums;
}

// fibbonacci series
int fibonacci(int n)
{
    if (n <= 2)
        return n - 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// check if string is a pallindrome
bool isPallindrome(int i, string &str)
{
    if (i == str.size() / 2)
        return true;
    else if (str[i] != str[str.size() - i - 1])
        return false;
    return isPallindrome(i + 1, str);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        cout << isPallindrome(0, s);
    }
}