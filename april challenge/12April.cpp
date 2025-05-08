
// Find Kth Rotation(GFG)
// o(n)
int findKRotation(vector<int> &arr)
{
    // Code Here
    int n = arr.size();
    if (arr[0] < arr[n - 1])
    {
        return 0;
    }
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            break;
        }
    }
    return i + 1;
}

// efficient O(logn)
int findKRotation(vector<int> &arr)
{
    // Code Here
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > arr[high])
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
// Search in Rotated Sorted Array
// O(n)
int search(vector<int> &arr, int key)
{
    // complete the function here
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
////efficient O(logn)

int search(vector<int> &arr, int key)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (key >= arr[low] && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else
        {
            if (key > arr[mid] && key <= arr[high])
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
