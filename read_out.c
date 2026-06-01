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
	//so we  type a string and it is read one word att a time as in lyric
	char filename[100],buffer[100];
	FILE *fptr;
	int pr;
	fgets(filename,100,stdin);
	filename[strcspn(filename,"\n")] = '\0';  //tooo important of a line if yypu do not want a segmentation error
	
	//strcspn here gives the no of elements before newlinne characcter appears then replaces it with \0 as fgets also reads newline character
	//strcspn returns bytes but herre its simplified one 

	fptr = fopen(filename,"r");

	if (fptr != NULL)
	{
	while (fgets(buffer,100,fptr))
		{	
			slowprint(buffer);
		}
	}
	fclose(fptr);

	printf("\n");
//	slowprint(buffer);
	return 0;


}
