#ifndef MAIN_H
#define MAIN_L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	char filename[100];
	struct node *link;
}Slist;


typedef struct mnode
{
	char word[100];
	int filecount;
	struct snode *slink;
	struct mnode *nlink;
}Mnode;


typedef struct snode
{
	int wordcount;
	char filename[100];
	struct snode *slink;
}Snode;

void Create(Slist *filenameh,Mnode *arr[]);
void Display(Mnode *arr[]);
void Search(Mnode *arr[]);
void Save(Mnode *arr[]);
void Update(Mnode *arr[]);
#endif
