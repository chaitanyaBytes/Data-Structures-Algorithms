#include <iostream>
#include <vector>
#include <math.h>
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
int searchh(vector<int> &nums, int target)
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

/*search in sorted array but rotated with duplicates
Approach: same as last one. only edge case when arr[low] = arr[mid] = arr[high]*/
bool searchDuplicates(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == k)
            return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= k && k <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

/*find min in rotated sorted array
Approach: if both sides of an array are sorted then the leftmost index has the minimum value.
*/
int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = 10000000;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;

    // int low = 0, high = nums.size() - 1;
    // while (low < high)
    // {
    //     int mid = low + (high - low) / 2;
    //     if (nums[mid] > nums[high])
    //     {
    //         low = mid + 1;
    //     }
    //     else
    //     {
    //         high = mid;
    //     }
    // }
    // return nums[low];
}

/*find how many times array is rotated*/
int findKRotation(int nums[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

/*find single element in sorted row
Approach: in left half of single element, indices of duplicate elements are (even, odd)
but in right half they are (odd, even). eleminate the half in which single element may
not be present*/
int singleNonDuplicate(vector<int> &nums)
{
    int low = 1, high = nums.size() - 2;
    int n = nums.size();
    if (n == 1)
        return nums[0];
    else if (nums[0] != nums[1])
        return nums[0];
    else if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }

        if ((nums[mid] == nums[mid - 1] && mid % 2 == 1) ||
            (nums[mid] == nums[mid + 1] && mid % 2 == 0))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/*find peak element
Approach: peak is at i if nums[i - 1] < nums[i] > nums[i + 1].
if nums[i] > nums[i + 1], it means it is an increasing curve and left half is eliminated.
else right half id eliminated. */
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1 || nums[0] > nums[1])
        return 0;
    if (nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;

    int low = 1, high = nums.size() - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;

    // linear search
    // int n = nums.size();
    // if (n == 1 || nums[0] > nums[1])
    //     return 0;
    // if (nums[n - 1] > nums[n - 2])
    //     return n - 1;
    // for (int i = 1; i < n - 1; i++)
    // {
    //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
    //     {
    //         return i;
    //     }
    // }
}

/*find square root*/
long long int floorSqrt(long long int x)
{
    long long int low = 1, high = x;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (mid * mid > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}
/*finding nth root of int m*/
int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (pow(mid, n) <= m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return pow(high, n) == m ? high : -1;
}

/*koko eats bananas
approach: calculate the total time(required to consume all the bananas in the array)
i.e. totalH using the function calculateTotalHours(a[], mid).
If totalH <= h:  we will eliminate the right half and consider the left half(i.e. high = mid-1).
otherwise, we will eliminate the left half and consider the right half(i.e. low = mid+1).*/
int findMax(vector<int> &arr)
{
    int ans = -100000;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = max(ans, arr[i]);
    }
    return ans;
}
int findHours(vector<int> &piles, int speed)
{
    int totalHours = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totalHours += ((piles[i] + speed - 1) / speed);
    }
    return totalHours;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 0, high = findMax(piles);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalHours = findHours(piles, mid);
        if (totalHours <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;

    // int l = 1, r = 1000000000;
    //     while (l < r) {
    //         int m = (l + r) / 2, total = 0;
    //         for (int p : piles)
    //             total += (p + m - 1) / m;
    //         if (total > h)
    //             l = m + 1;
    //         else
    //             r = m;
    //     }
    //     return l;
}

/*minimum days to make m bouquets
Approach: we have to check from min[arr] to max[arr]. if making required bouquets is possible for
at a day then for all days ahead of it will be of no use and we can eleminate that half.
else we can eleminate left half as if bouquets cant be made on that day then previous days are also useless*/
int findMinn(vector<int> &arr)
{
    int ans = 100000000;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = min(ans, arr[i]);
    }
    return ans;
}
int possible(vector<int> &arr, int day, int m, int k)
{
    int cnt = 0, bouquets = 0;
    for (int a : arr)
    {
        if (a <= day)
            cnt++;
        else
        {
            bouquets += cnt / k;
            cnt = 0;
        }
    }
    bouquets += cnt / k;
    return bouquets;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    if ((long long)m * k > (long long)bloomDay.size())
        return -1;
    int low = findMinn(bloomDay);
    int high = findMax(bloomDay);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k) < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int n, h;
    cin >> n >> h;

    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    int bs = minEatingSpeed(arr, h);
    cout << bs;

    return 0;
}