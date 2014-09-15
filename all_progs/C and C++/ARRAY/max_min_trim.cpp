#include <iostream>
#include <climits>
using namespace std;
 
int main()
{
    int arr[] = {4, 5, 100, 9, 10, 11, 12, 15, 200};
    int size = sizeof(arr) / sizeof(int);
 
    int longest = 0, start = 0, end = -1;
 
    for (int i = 0; i < size - longest; ++i) 
	{
        int max = INT_MIN;
        int min = INT_MAX;
        for (int j = i; j < size; ++j) 
		{
            if (arr[j] > max)
                max = arr[j];
            if (arr[j] < min)
                min = arr[j];
            if (2 * min <= max)
                break;
            if (j - i + 1 > longest)
			 {
                start = i;
                end = j;
                longest = j - i + 1;
            }
        }
    }
 
    cout << "Trim: " << size - longest << endl;
    for (int i = 0; i < start; ++i)
        cout << arr[i] << " ";
    for (int i = end + 1; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
