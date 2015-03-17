#include <stdio.h>
#include <stdlib.h>
//Including menus that i have generated
#include "menus.h"

int main()
{
	//Get the menu displayed and keep the number that user enters
	int e = menu1();
	//Switch case statement for the program to choose what to do with the users choice
	switch (e)
	{
		case 1:
			//The printf can be a function
			printf("You have selected 1\n");
			break;
		case 2:
			printf("You have selected 2\n");
			break;
		case 3:
			printf("You have selected 3\n");
			break;
		default:
			printf("You have selected wrong number\n");
			break;
	}
	e = menu2();
	switch (e)
	{
		case 1:
			printf("You have selected 1\n");
			break;
		case 2:
			printf("You have selected 2\n");
			break;
		case 3:
			printf("You have selected 3\n");
			break;
		default:
			printf("You have selected wrong number\n");
			break;
	}
	e = menu3();
	switch (e)
	{
		case 1:
			printf("You have selected 1\n");
			break;
		case 2:
			printf("You have selected 2\n");
			break;
		case 3:
			printf("You have selected 3\n");
			break;
		case 4:
			printf("You have selected 4\n");
			break;
		case 5:
			printf("You have selected 5\n");
			break;
		default:
			printf("You have selected wrong number\n");
			break;
	}
	system("PAUSE");
}
