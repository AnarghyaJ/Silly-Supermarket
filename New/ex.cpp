int i=1;
void hi (char *);
#include<stdio.h>
main()
{

	
	printf("\nhere Im for %dth time",i++);
		
		char *ch="Aish!";
		hi(ch);
		main();
}
void hi(char *ch)
{
	printf("\n%s",ch);
	return;
}
