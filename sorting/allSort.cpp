#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

void bubbleSort(vector<int> &arr, int n)
{
    bool didSwap = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap)
            break;
    }
}

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
                swap(arr[j], arr[j - 1]);
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int hi)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= hi)
    {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= hi)
        temp.push_back(arr[right++]);

    for (int i = low; i <= hi; i++)
        arr[i] = temp[i - low];
}
void mergeSort(vector<int> &arr, int low, int hi)
{
    if (low >= hi)
        return;
    int mid = low + (hi - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, low, mid, hi);
}

int partitionArray(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start, j = end;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= end - 1)
            i++;
        while (arr[j] > pivot && j >= start + 1)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}
void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partitionArray(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}