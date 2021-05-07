#include <iostream>
using namespace std;

int counter1 = 0;
int counter2 = 0;
int counter3 = 0;

int FibRec(int n)
{
    counter1++;
    if (n <= 1)
    {
        counter1++;
        return n;
    }
    else
    {
        counter1 = counter1 + 5;
        cout << "FibRec(" << n - 1 << ") + FibRec(" << n - 2 << ")" << endl;

        return FibRec(n - 1) + FibRec(n - 2);
    }
}

int FibRecDP(int n, int a[])
{
    counter2++;
    if (n <= 1)
    {
        counter2++;
        cout << "if 0 or 1";

        return a[n];
    }

    counter2 = counter2 + 3;
    if (a[n - 1] == -1)
    {
        counter2 = counter2 + 2;
        cout << "FibRecDP[" << n << "-1]\n";
        FibRecDP(n - 1, a);
    }

    counter2 = counter2 + 3;
    if (a[n - 2] == -1)
    {
        counter2 = counter2 + 2;
        cout << "FibRecDP[" << n << "-2]"<< endl;
        FibRecDP(n - 2, a);
    }

    counter2 = counter2 + 7;

    a[n] = a[n - 1] + a[n - 2];

    counter2++;
    return a[n];
}

int FibDPiterative(int n)
{
    counter3++;
    if (n <= 1)
    {
        counter3++;
        return n;
    }

    int a = 0, b = 1, r;

    counter3 = counter3 + 2;

    counter3++;
    for (int i = 2; i <= n; i++)
    {
        cout << "\nIterative : " << a << " + " << b << " = ";


        r = a + b;
        counter3=counter3+2;

        a = b;
        counter3++;

        b = r;
        counter3++;

        cout << r <<endl;
    }

    counter3++;
    return r;
}

int main()
{
    int number;
    cout << "Which Fibonacci number? ";
    cin >> number;

    //WITHOUT MEMOIZATION
    cout << "Fibonacci (" << number << ")\n" << FibRec(number) << endl;
    cout << "\nTime Complexity (Without Memorization): " << counter1 << "\n\n";

    //WITH MEMOIZATION (recursive)
    int F[number + 1];
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= number; i++)
        F[i] = -1;

    cout << "Fibonacci (" << number << ")\n" << FibRecDP(number, F) << endl;
    cout << "\nTime Complexity (With Memorization): " << counter2 << "\n\n";

    //WITH MEMOIZATION (iterative)
    cout << "Fibonacci (" << number << ")\n" << FibDPiterative(number) << endl;
    cout << "\nTime Complexity (Without Memorization (iterative)): " << counter3 << "\n";
}
