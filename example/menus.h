#include <stdio.h>
#include <stdlib.h>

int menu1()
{
	printf("\nFirst Menu\n");
	int choice;
	do
	{
		printf("1. Choice 1\n");
		printf("2. Choice 2\n");
		printf("3. Choice 3\n");
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
	}while(choice<=0 || choice>3);
}

int menu2()
{
	printf("\nSecond Menu\n");
	int choice;
	do
	{
		printf("1. Choice 1\n");
		printf("2. Choice 2\n");
		printf("3. Choice 3\n");
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
	}while(choice<=0 || choice>3);
}

int menu3()
{
	printf("\nThird and Last Menu\n");
	int choice;
	do
	{
		printf("1. Choice 1\n");
		printf("2. Choice 2\n");
		printf("3. Choice 3\n");
		printf("4. Choice 4\n");
		printf("5. Choice 5\n");
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
	}while(choice<=0 || choice>5);
}

