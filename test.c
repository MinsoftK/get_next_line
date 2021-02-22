#include <stdio.h>
int main()
{
	char *temp = "abcdefg";
	char *temp1;

	*temp1 = *(temp + 4);
	printf("%s", temp1);

}
