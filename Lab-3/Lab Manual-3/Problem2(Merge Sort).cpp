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
    count=count+3; //int a = mid - low + 1

    int b = high - mid;
    count=count+2; //int b = high - mid

    int L[a], M[b];

    for (int i = 0; i < a; i++)
        L[i] = arr[low + i];
        count=count+7; //L[i] = arr[low + i]

    for (int j = 0; j < b; j++)

        M[j] = arr[mid + 1 + j];
        count=count+7;  //M[j] = arr[mid + 1 + j]

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    count=count+3; //assignments of i = 0;j = 0;k = low;

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
            count=count+7; //arr[k] = L[i];i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
            count=count+4; //arr[k] = M[j];j++;
        }
        k++;
        count=count+1; //k++;
    }
    while (i < a)
    {
        arr[k] = L[i];
        i++;
        k++;
        count=count+5;  //arr[k] = L[i];i++;k++;
    }
    while (j < b)
    {
        arr[k] = M[j];
        j++;
        k++;
        count=count+5;// arr[k] = M[j];j++;k++ ;
    }
}

void mergeSort(int arr[], int l, int high)
{
    cout << "MERGE-SORT: ( ";
    printArray(arr, l, high);
    cout << ")" << endl;

    if (l < high)
    {
        count=count+1; //l < high

        int m = l + (high - l) / 2;
        count=count+4; //m = l + (high - l) / 2

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, high);

        merge(arr, l, m, high);
    }
}
int main()
{
    int n;

    cout << "Enter the number of elements:";
    cin >> n;

    int arr[n];

    cout << "Enter the elements\n ";
    for ( int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);
    cout << "Total Number of operations done: "<<count;

    cout << "The Sorted Array: ";
    printArray(arr, n);

    return 0;
}
