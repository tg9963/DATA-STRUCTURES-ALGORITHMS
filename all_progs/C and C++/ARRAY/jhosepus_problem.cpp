#include <stdio.h>
 
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position 
       k%n + 1 as position 1 */
  
    return (josephus(n - 1, k) + k-1) % n + 1;
/*
int r=0,i=1;
while(i<=n)
{
	printf("i: %d \n",i);
	printf("r: %d \n",r);
	printf("k: %d \n",k);
	r=(r+k)%i;
	i+=1;
	printf("r: %d \n",r);
	printf("i: %d \n********\n",i);
	//printf("k: %d \n",k);
}
*/
//return r+1;
}
 
// Driver Program to test above function
//FLAMES problem 

int main()
{
  int n = 5;
  int k = 2;
  
  printf("The chosen place is %d", josephus(n, k));
  return 0;
}
