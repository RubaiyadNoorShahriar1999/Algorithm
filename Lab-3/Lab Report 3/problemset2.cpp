#include <iostream>
using namespace std;
int count=0;
void printArray(int arr[], int i, int e)
{
    for (int j = i; j <= e; j++)
        cout << arr[j] << " ";
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int low, int mid, int high)
{
    int a = mid - low + 1;
    count=count+3;
    int b = high - mid;
    count=count+2;
    int L[a], M[b];

    for (int i = 0; i < a; i++)

        L[i] = arr[low + i];
    count=count+7;
    for (int j = 0; j < b; j++)

        M[j] = arr[mid + 1 + j];
    count=count+7;

    int i, j, k;
    i = 0;
    j = 0;
    k = low;
    count=count+3;

    cout << "MERGE: ( ";
    printArray(L, 0, a - 1);
    cout << "| ";
    printArray(M, 0, b - 1);
    cout << ")" << endl;

    while (i < a && j < b)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
            count=count+7;
        }
        else
        {
            arr[k] = M[j];
            j++;
            count=count+4;
        }
        k++;
        count=count+1;
    }
    while (i < a)
    {
        arr[k] = L[i];
        i++;
        k++;
        count=count+5;
    }
    while (j < b)
    {
        arr[k] = M[j];
        j++;
        k++;
        count=count+5;
    }
}

void mergeSort(int arr[], int l, int high)
{
    cout << "MERGE-SORT: ( ";
    printArray(arr, l, high);
    cout << ")" << endl;

    if (l < high)
    {
        count=count+1;
        int m = l + (high - l) / 2;
        count=count+4;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, high);

        merge(arr, l, m, high);
    }
}
int main()
{
    int i, n;
    cout << "Enter n:"; //array size
    cin >> n;

    int arr[n];
    cout << "Enter the numbers "; //array size
    for (i = 0; i < n; i++)
        cin >> arr[i]; //array elements

    mergeSort(arr, 0, n - 1);
    cout << "Total Operations: "<<count;
    cout << "\nSorted array: ";
    printArray(arr, n);
    return 0;
}
