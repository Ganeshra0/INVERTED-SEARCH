#include "main.h"

int main(int argc,char *argv[])
{
	int i = 1;
	Mnode *arr[27] = {NULL};
	Slist *filenameh = NULL;
	int flag = 0;
	while(argv[i] != NULL)
	{
		if(strcmp(strstr(argv[i],"."),".txt")==0)
		{
			//printf("file is .txt");
			FILE *file;
			//char filename[100] = "argv[i]";
			long size;

			// Try to open the file
			file = fopen(argv[i], "r");

			// Check if the file pointer is not NULL
			if (file != NULL) 
			{
				// Move the file pointer to the end of the file
				fseek(file, 0, SEEK_END);

				// Get the current position of the file pointer (which is the file size)
				size = ftell(file);

				// Close the file
				fclose(file);

				// Check if the file is empty
				if(size != 0)
				{
					//printf("not empty");
					flag = 1;
					if(filenameh == NULL)
					{
						//creating new node at head
						Slist *new = malloc(sizeof(Slist));
						strcpy(new -> filename,argv[i]);
						new -> link = NULL;
						filenameh = new;
					}
					else
					{
						Slist *temp = filenameh;
						Slist *pre = NULL;
						while(temp != NULL)
						{
							//checking for matching filename
							if(strcmp(temp -> filename,argv[i]) == 0)
							{
								//next argument
								break;
							}
							else
							{
								pre = temp;
								temp = temp -> link;
							}
						}
						//creating node at intermediate
						if(temp == NULL)
						{
							Slist *new = malloc(sizeof(Slist));
							strcpy(new -> filename ,argv[i]);
							new -> link = NULL;
							pre -> link = new;
						}
					}
				}
			}
		}
		//next argument
		i++;
	}
	Slist *p = filenameh;
	while(p != NULL)
	{
		printf("%s ",p -> filename);
		p = p -> link;
	}
	printf("\n");
	if(flag == 0)
	{
		printf("Enter the invalid arguments\n");

	}
	else
	{
		//printf("1.Create\n2.Display\n3.Save\n4.Search\n5.Update\n6.Exit\nEnter any option : ");
		while(1)
		{
			printf("1.Create\n2.Display\n3.Save\n4.Search\n5.Update\n6.Exit\nEnter any option : ");

			/*ask user options*/
			int option;


			scanf("%d", &option);
				
				switch (option)
				{
					case 1:
						printf("Creating Inverted Search : \n");
						Create(filenameh,arr);
						break;
				    case 2:
					    printf("Displaying\n");
					    Display(arr);
					    break;
				    case 3:
					    printf("Saving\n");
					    Save(arr);
					    break;
				    case 4:
					    printf("Searching the element\n");
					    Search(arr);
					    break;
				    case 5:
					    printf("Updating into new\n");
					    Update(arr);
					    break;
				    case 6: return 0;
				    default: printf("Enter proper choice !!\n");
						break;
				}								    				
		}
	}
}
