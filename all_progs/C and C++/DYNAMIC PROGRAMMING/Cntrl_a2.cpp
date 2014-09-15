#include <iostream>
using namespace std;

void A(int N)
{
    int a[N+1], r[N+1];
    char result[N+2];
    a[0] = 0;

    for (int i = 1; i <= N; ++i) {
        a[i] = 0;
        int start = 4, end = i-1;

        // Get maximum value for the Nth key ending with a
        // "select all, copy, paste, paste, paste..." sequence
        //
        // Binary search for maximum a[i-j] * (j-2), since it increases first,
        // then decreases.
        while (start <= end) {
            int j = (start + end) / 2;
            a[i] = a[i-j] * (j-2);
            r[i] = j; // We added a sequence of j keys.
            int left = (start == j) ? 0 : a[i-(j-1)] * ((j-1)-2);
            int right = (start == end) ? 0 : a[i-(j+1)] * ((j+1)-2);

            if (a[i] > left && a[i] > right) {
                break;
            } else if (a[i] >= left && a[i] >= right) {
                // handle getting stuck in equal neighbours
                bool found = false;
                for (int c = j+1; c <= end; ++c) {
                    int val = a[i-c] * (c-2);
                    if (val > a[i]) {
                        start = c;
                        found = true;
                        break;
                    }
                    if (val < a[i]) {
                        end = j-1;
                        found = true;
                        break;
                    }
                }
                for (int c = j-1; c >= start; --c) {
                    int val = a[i-c] * (c-2);
                    if (val > a[i]) {
                        end = c;
                        found = true;
                        break;
                    }
                    if (val < a[i]) {
                        start = j+1;
                        found = true;
                        break;
                    }
                }
                if (!found) // all we saw were duplicates
                    break;
            } else if (left > a[i])
                end = j-1;
            else
                start= j+1;
        }

        // If we can do better by just adding an 'A', do that.
        if (a[i-1] + 1 > a[i]) {
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