#include "main.h"

#define MAX_SIZE 1000

void Update(Mnode *arr[])
{
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
	char filename[100];
	printf("enter the file");
	scanf("%s",filename);
	if(strcmp(strstr(filename,"."),".txt")==0)
	{
		FILE *ptr;
	   ptr=fopen(filename,"r");

       // Move the file pointer to the beginning
       fseek(ptr, 0, SEEK_SET);
       // Read the first character
       char firstchar = fgetc(ptr);

       // Move the file pointer to the endchar last;
	   char lastchar;
	   fseek(ptr,-2,SEEK_END);
       //fread(&lastchar, sizeof(char), 1, ptr); // Read the last character
	   lastchar=fgetc(ptr);
	   printf("first %c\n",firstchar);
	   printf("second %c\n",lastchar);
	   //fseek(ptr,0,SEEK_SET);
	   rewind(ptr);
       if(firstchar == lastchar)
	   {
		   char str[100];
		   while(fscanf(ptr,"%s",str) != EOF)
		   {
			  // creating mainnode and updating values from file
			  char *ch = strtok(str,"#;");
			  int ind = atoi(ch);
			  char *word = strtok(NULL,"#;");
			  char *ch1 = strtok(NULL,"#;");
			  int fcount = atoi(ch1);
			  Mnode *newm = malloc(sizeof(Mnode));
			  newm ->nlink = NULL;
			  newm ->slink = NULL;
			  strcpy(newm ->word,word);
			  newm ->filecount=fcount;
			  //if array of ind is null then attach main node to it
			   if(arr[ind] == NULL)
			   {
				   arr[ind] = newm;
			   }
			   // not null attach to pre main node
			   else
			   {
				   Mnode *temp = arr[ind];
				   while(temp -> nlink != NULL)
				   {
					    temp = temp ->nlink;
				   }
				   if(temp -> nlink == NULL)
				   {
					   temp -> nlink = newm;
				   }
			   }
			   //creating subnode for every filecounti
			   Snode *pre = newm -> slink;
			   for(int i = fcount; i > 0; i--)
			   {
				   char *fname = strtok(NULL,"#;");
				   char *ch2 = strtok(NULL,"#;");
				   int wcount = atoi(ch2);
				   Snode *news = malloc(sizeof(Snode));
				   news -> slink = NULL;
				   strcpy(news -> filename, fname);
				   news -> wordcount = wcount;
				   //Snode *pre = NULL;
				   //if new mainnode sublink is null attach subnode to mainnode
				   if(newm -> slink == NULL)
				   {
					 newm -> slink = news;
					  pre = news;
				   }
				   //else attach to pre sublink
				   else
				   {
					   pre -> slink = news;
				   }
			   }

		   }
	   }
       else
	   {
           printf("pass created backupfile\n");
	   }	   

	}
	else
	{
		printf("enter valid .txt file\n");
	}
	}
	else
	{
		printf("database already created cannot be updated enter another option except 5\n");
	}
}
