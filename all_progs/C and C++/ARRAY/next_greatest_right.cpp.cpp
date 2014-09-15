#include <stdio.h>
#include <stack>
using namespace std;
typedef stack<int> stack_t;
static stack_t s;
void get_nge(int in[], int out[], int len)
{
	for(int i=0; i<len; i++)
	 {
		while(!s.empty() && in[s.top()] < in[i]) 
		{
			out[s.top()] = in[i];
			s.pop();
		}
		s.push(i);
	}
	for(; !s.empty(); s.pop()) {
		out[s.top()] = -1;
	}
}
int main(void) {
	int in[9] = {12,15,22,7,2,18,23,27,26};
	int out[sizeof(in)];
	get_nge(in, out, sizeof(in)/sizeof(int));
	for(int i=0; i<sizeof(in)/sizeof(int); i++) {
		printf("%d: %d - %d\n", i, in[i], out[i]);
	}
	printf("\n");
	return 0;
}
