#include "main.h"

void Search(Mnode *arr[])
{
	char str[100];
	printf("enter thr word to be searched\n");
	scanf("%s",str);
	int ind = 0;
	if(isupper(str[0]))
	{
		ind = tolower(str[0]) - 97;
	}
	else if(islower(str[0]))
	{
		ind =str[0] - 97;
	}
	else
	{
	     ind = 26;
    }
	if(arr[ind] == NULL)
		printf("word not present\n");
	else
	{
		Mnode *temp = arr[ind];
		while(temp != NULL)
		{
			if(strcmp(str,temp -> word)==0)
			{
				printf("Word %s is present in %d files\n",str,temp->filecount);
				Snode *temp1 = temp -> slink;
				while(temp1 != NULL)
				{
					printf("%s -> %d\n",temp1->filename,temp1 -> wordcount);
					temp1=temp1->slink;
				}
				break;
			}
			else
			{
				temp = temp->nlink;
			}
		}
	}
}
