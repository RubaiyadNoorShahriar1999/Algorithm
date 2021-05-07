#include <iostream>

using namespace std;

int count = 0;
int compare = 0;

int binarySearch(int arr[], int low, int high, int x)
{
    while (high >= low)
    {
        count = count++; //high >= low

        int mid = (low + high) / 2;
        count = count + 3;  //int mid = (low + high) / 2;

        if (arr[mid] == x)
        {
            cout << arr[mid] << endl;
            count = count + 2; //arr[mid] == x

            compare++;

            return mid;
        }
        if (arr[mid] > x)
        {
            for (int i = 0; i <= mid; i++)
            {
                cout << arr[i] << " ";
            }

            compare++;
            count = count + 2; //arr[mid] > x

            return binarySearch(arr, low, mid - 1, x);
        }
        else
        {
            for (int i = mid+1; i <= high; i++)
            {
                cout << arr[i] << " ";
            }

            compare++;
            return binarySearch(arr, mid + 1, high, x);
        }
    }
    return -1;
}
int main(){

    int n;
    int high, low;

    cout << "\n Enter The number of elements :  ";
    cin >> n;
    cout<< endl;

    int arr[n];  //initializing the array with an index
    cout << "\n Enter the numbers of the array \n ";

    for (int i = 0; i < n; i++)
    {
        cout<<"\n";
        cin >> arr[i];
    }

    int x;
    cout << "\n Enter the number you want to search :  ";
    cin >> x;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        cout << "\n Element is not the in array \n";
    else
        cout << "\n Element is in the array at index :   "<<result;

    cout << "\n count  "<<count;
    cout << "\n comparison " <<compare;

    return 0;
}
