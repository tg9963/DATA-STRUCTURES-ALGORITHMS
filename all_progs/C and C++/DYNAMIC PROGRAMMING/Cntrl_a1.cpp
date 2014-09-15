#include <iostream>
using namespace std;

void A(int N)
{
    int a[N+1], r[N+1];
    char result[N+2];
    a[0] = 0;

    for (int i = 1; i <= N; ++i) {
        a[i] = 0;
        for (int j = 4; j < i; ++j) {
            int scp = a[i - j] * (j - 2);
            if (scp >= a[i]) {
                a[i] = scp;
                r[i] = j; // We added a sequence of j keys.
            } else
                // Break if we started decreasing, since a[i-j] * (j-2) only
                // decreases after it's done increasing.
                break;
        }
        if (a[i-1] + 1 >= a[i]) {
            a[i] = a[i-1] + 1;
            r[i] = 1; // We added a sequence of 1 key.
        }
    }

    // Reconstruct the solution using r[]
    for (int i = N; i > 0; i -= r[i]) {
        if (r[i] == 1) {
            result[i] = 'A';
        } else {
            result[i-r[i]+1] = 'S';
            result[i-r[i]+2] = 'C';
            for (int k = i - r[i] + 3; k <= i; ++k)
                result[k] = 'P';
        }
    }
    result[N+1] = 0;

    cout << "N=" << N << " A=" << a[N] << " \tseq=" << (result + 1) << endl;
}

int main()
{
    for (int N = 0; N <= 55; ++N)
        A(N);
}