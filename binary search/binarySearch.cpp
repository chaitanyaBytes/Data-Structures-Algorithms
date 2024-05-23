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
    int ans = INT_MAX;
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