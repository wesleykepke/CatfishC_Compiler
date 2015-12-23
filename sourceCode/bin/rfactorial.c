#include <stdio.h>

// recursive factorial function
int factorial(n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n-1);
	}
}

int main()
{
	// dummy int
	int fact;

	// test case
	fact = factorial(10);
	printf("%d \n", fact );
	
	return 0;
}
