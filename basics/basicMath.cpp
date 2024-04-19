#include <iostream>
#include <math.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

long int reverseNumber(int n)
{
    int rev = 0;
    while (abs(n) > 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int converToBinary(int n)
{
    int result = 0;
    int i = 1;
    while (n != 0)
    {
        int rem = n % 2;
        result = result + rem * i;
        n /= 2;
        i *= 10;
    }
    return result;
}

bool pallindrome(int n)
{
    int original = n;
    int reverse = 0;
    while (n > 0)
    {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }
    if (reverse == original)
        return true;
    else
        return false;
}

bool armstrong(int n)
{
    int result = 0;
    int original = n;
    int digits = (int)log10(n) + 1;
    while (n > 0)
    {
        result = result + pow((n % 10), digits);
        n /= 10;
    }
    return (result == original);
}

bool isPrime(int n)
{
    // Write your code here.
    if (n <= 1)
        return false;
    else if (n == 2)
        return true;
    for (int i = 0; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int findGCD(int a, int b){
    if (b == 0){
        return a;
    }

    return findGCD(a, a%b);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        cout << findGCD(n, m);
    }

    return 0;
}