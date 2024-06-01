#include "main.h"

void Create(Slist *filenameh,Mnode *arr[])
{
	//printf("Ganesh1\n");
	//Slist *t = *filenameh;
	int allnull = 1;
	for(int i = 0;i<27;i++)
	{
		if(arr[i] != NULL)
		{
			allnull = 0;
			break;
		}
	}
	if(allnull)
	{
	while(filenameh != NULL)
	{
		FILE *ptr;
		//printf("Ganesh2\n");
	   ptr = fopen(filenameh -> filename,"r");

	   char word[100];
	   while(fscanf(ptr,"%s",word) != EOF)
	   {
		   //tolower
		   int ind = 0;
		   if(word[0] >= 97 && word[0] <= 122)
		   {
		   	  ind = word[0] - 97;
		   }
		   else if(word[0] >= 65 && word[0] <= 90)
		   {
			   ind = word[0] + 32 - 97;
		   }
		   else
		   {
			   ind = 26;
		   }
		   //printf("%d ",ind);
		   //printf("Ganesh3\n");

		   //if array of ind is NULL
		   if(arr[ind] == NULL)
		   {
			   //creating new main and sub nodes
			   Mnode *newm = malloc(sizeof(Mnode));
			   Snode *news = malloc(sizeof(Snode));
			   //printf("ganesh4.1\n");
			   //updating main node
			   newm -> slink = news;
			   newm -> filecount = 1;
			   newm -> nlink = NULL;
			   strcpy(newm -> word, word);
			   //printf("ganesh4.2");
			   //updating sub node
			   news -> wordcount = 1;
			   news -> slink = NULL;
			   strcpy(news -> filename, filenameh -> filename);
			   //updating array
			   arr[ind] = newm;
			   //printf("%s", arr[ind]->word);
			   //printf("Ganesh4\n");

		   }
		   //if array is not NULL
		   else
		   {
			   //creating temp variables
			   Mnode *temp = arr[ind];
			   Mnode *pre = NULL;
			   //loop runs temp of main node reaches null
               while(temp != NULL)
			   {
				   //compare main node word and user word
				   if(strcmp(temp -> word, word)==0)
				   {
					   Snode *temp1 = temp -> slink;
					   Snode *pre1 = NULL;
					   //loop runs temp1 of subnode reaches null
					   while(temp1 != NULL)
					   {
						   //comparing subnode filename with list filename
						   if(strcmp(temp1 -> filename, filenameh -> filename)==0)
						   {
							   (temp1 -> wordcount)++;
							   break;
						   }
					       else
					       {
						        pre1 = temp1;
					            temp1 = temp1 -> slink;
					       }
				       }
					   //creating subnode attached to pre subnode
					   if(temp1 == NULL)
					   {
			           Snode *news = malloc(sizeof(Snode));
				       news -> wordcount = 1;
				       news -> slink = NULL;
				       strcpy(news -> filename, filenameh -> filename);
				       pre1 -> slink = news;
		     	       (temp -> filecount)++;
					   //printf("Ganesh5\n");
					   }
					   break;
				   }
			       else
			       {
				       pre = temp;
				       temp = temp -> nlink;
			       }
			   }
			   //creating mainnode attached to pre mainnode
			   if(temp == NULL)
			   {
			   Mnode *newm = malloc(sizeof(Mnode));
			   Snode *news = malloc(sizeof(Snode));
			   newm -> slink = news;
		       newm -> filecount = 1;
		       newm -> nlink = NULL;
		       strcpy(newm -> word , word);
			   news -> wordcount = 1;
			   news -> slink = NULL;
		       strcpy(news -> filename , filenameh -> filename);
		       pre -> nlink = newm;
			   //printf("Ganesg6\n");
			   }

		   }
	   }
	   filenameh = filenameh -> link;
	   //printf("ganesh7\n");
	}
	printf("Creation completed\n");
	}
	else
	{
		printf("database already updated cannot be created enter another option except 1 \n");
	}
}
