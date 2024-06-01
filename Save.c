#include "main.h"

void Save(Mnode *arr[])
{
	char filename[100];
	printf("enter the file:");
	scanf("%s",filename);
	if(strcmp(strstr(filename,"."),".txt")==0)
	{
		FILE *ptr;
		ptr=fopen(filename,"w+");
		if(ptr == NULL)
			printf("Error opening file");
		else
		{
			//printf("gan");
			for(int i = 0; i < 27; i++)
			{
				if(arr[i] != NULL)
				{
					Mnode *temp = arr[i];
					while(temp != NULL)
					{
					    fprintf(ptr,"#");
					    fprintf(ptr,"%d",i);
					    fprintf(ptr,";");
						fprintf(ptr,"%s",temp -> word);
					    fprintf(ptr,";");
						fprintf(ptr,"%d",temp -> filecount);
					    fprintf(ptr,";");
						Snode *temp1 = temp -> slink;
						while(temp1 != NULL)
						{
							fprintf(ptr,"%s",temp1 ->filename);
							fprintf(ptr,";");
							fprintf(ptr,"%d",temp1 ->wordcount);
							fprintf(ptr,";");
							temp1 = temp1->slink;
						}
						if(temp1 == NULL)
						{
							fprintf(ptr,"#");
							fprintf(ptr,"\n");
						}
						temp = temp -> nlink;
						//printf("%d ",i);
					}

				}
			}

		}
	}
	else
	{
		printf("file is not txt");
	}
}
