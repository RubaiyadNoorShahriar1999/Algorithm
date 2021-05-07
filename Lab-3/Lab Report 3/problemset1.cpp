#include <iostream>
using namespace std;
int count = 0;
int countCompare = 0;
int binarySearch(int arr[], int low, int high, int x)
{
    while (high >= low)
    {
        count = count++;
        int mid = (low + high) / 2;
        count = count + 3;
        if (arr[mid] == x)
        {
            cout << arr[mid] << endl;
            count = count + 2;
            countCompare++;
            return mid;
        }
        if (arr[mid] > x)
        {
            for (int i = 0; i <= mid; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            countCompare++;
            count = count + 2;
            return binarySearch(arr, low, mid - 1, x);
        }
        else
        {
            for (int i = mid+1; i <= high; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            countCompare++;
            return binarySearch(arr, mid + 1, high, x);
        }
    }
    return -1;
}
int main(void)
{
    int n, i;
    int high, low;
    cout << "Enter n:"; //array size
    cin >> n;
    int arr[n];
    cout << "Enter the numbers "; //array size
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; //array elements
    }
    int x;
    cout << "Enter the number you want to search ";
    cin >> x;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    cout << "\ncount " << count;
    cout << "\ncount compare " << countCompare;
    return 0;
}
