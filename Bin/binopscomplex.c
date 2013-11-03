#include <stdio.h>

int main(void) {
int a=2,
	b=5,
	c=10,
	d=-10,
	e=-1;
	
	printf("%d\n",c/10+b-d*e*(c+12));
	printf("%d\n",(a*((c+b)-(a*a)))*(-1));
	printf("%d\n",-d*-e*c*b*a);
	printf("%d\n",a+b+c+d+e);
	printf("%d\n",a*b/(-c+d)+e);
	
	system("PAUSE");
	return 0;
}