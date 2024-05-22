#include <iostream>
#include <vector>
using namespace std;

/*binary search*/
int search(vector<int> &nums, int target)
{

    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return -1;
}

/*lower bound*/
int findFloor(vector<long long> v, long long n, long long x)
{

    long long lo = 0, hi = n - 1;
    long long ans = -1;
    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;
        if (v[mid] <= x)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

/*search insert position*/
int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

/*floor and ceil in sorted array*/
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1;
    if (x < a[low])
        return {-1, a[low]};
    if (x > a[high])
        return {a[high], -1};

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return {a[mid], a[mid]};
        }
        if (a[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return {a[high], a[low]};
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 1; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    int bs = search(arr, 9);
    cout << bs;

    return 0;
}