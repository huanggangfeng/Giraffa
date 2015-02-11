#include <stdio.h>

int main()
{
	int n = 0;
	n = getpagesize();
	printf("The page size of current OS is %d\n", n);
	return 0;
}
