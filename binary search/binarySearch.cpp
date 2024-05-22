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

/*first and lst occurenece of an element in an array
approach: first occurence is lower bound amd last is upper bound - 1*/
int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int upperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int l = lowerBound(nums, target);
    int u = upperBound(nums, target);
    if (l == nums.size() || nums[l] != target)
    {
        return {-1, -1};
    }
    return {l, u - 1};
}

/*search in sorted but rotated array
approach: for every index, one of the 2 halves will always be sorted. 
First, we identify the sorted half of the array.
Once found, we determine if the target is located within this sorted half.
If not, we eliminate that half from further consideration. else eliminate other half
*/
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
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