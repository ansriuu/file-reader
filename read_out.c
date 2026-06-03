#include <stdio.h>
#include <unistd.h>
#include <string.h>
void slowprint(char text[])
{
	for (int i =0 ;text[i] != '\0';i++)
	{	
		printf("%c",text[i]);
		fflush(stdout);
		usleep(100000);
	}
}

int main()
{
	char filename[100],buffer[200];
	FILE *fptr;
	int pr;
	
	fgets(filename,100,stdin);
	filename[strcspn(filename,"\n")] = '\0'; 


	fptr = fopen(filename,"r");

	if (fptr != NULL)
	{
	while (fgets(buffer,200,fptr))
		{	
			slowprint(buffer);
		}
	}
	fclose(fptr);

	printf("\n");
	return 0



}
