#include "main.h"

void Display(Mnode *arr[])
{
	printf(" [Index]   Word      Filecount     Filename     Wordcount  \n");
	printf("******************************************************************************************************\n");
	for(int i = 0; i < 27; i++)
	{

		if(arr[i] != NULL)
		{
			//printf("asp");
			Mnode *temp = arr[i];
			while(temp != NULL)
			{
				printf(" [%d]      ",i);
				printf(" %s        ",temp -> word);
				printf(" %d        ",temp -> filecount);
				Snode *temp1 = temp -> slink;
				while(temp1 != NULL)
				{
					printf(" %s         ",temp1 -> filename);
					printf(" %d         ",temp1 ->wordcount);
					temp1 = temp1 -> slink;
				}
				temp = temp -> nlink;
				printf("\n");
			}
		}

	}


}
