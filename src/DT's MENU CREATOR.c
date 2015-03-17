#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare Helper Functions
void main_menu();
void create_menus();
void help();
void credits();

int main()
{
	printf("DT's MENU CREATOR v.0.6\n");
	printf("================================================================================");
	main_menu();
}

void main_menu()
{
	//Declare necessary variables
	int yes_no = 0;
	
	//Menu Structure
	do
	{
		//Main menu choices
		printf("\nMain Menu\n");
		printf("\n1. Create new menu file\n2. Help\n3. Credits\n4. Exit\n\n");
		printf("Please enter your choice: ");
		scanf("%d",&yes_no);
	}while(yes_no < 1 || yes_no >4);
	
	//Select what to do
	if (yes_no == 1)
		create_menus();
	else if (yes_no == 2)
		help();
	else if (yes_no == 3)
		credits();
	else
	{
		printf("\n================================================================================");
		printf("\nThank you for using DT's MENU CREATOR\n");
		printf("\n================================================================================\n");
		system("PAUSE");
	}
}

void create_menus()
{
	//Declare necessary variables
	int filenamelen, add_choices_len, i, j, menu_number, choices_number, yes_no = 0, count = 0;
	//Filename necessary dynamic variable
	char *text = malloc(200 * sizeof(char));
	char *filename, *choices, *choices_text, *add_choices, *menu_title;
	char int_to_string[10];
	
	//Get Filename from user
	printf("\n================================================================================");
	printf("\nPlease enter your desired filename (MAX: 200 characters): ");
	scanf(" %[^\n]s",text);
	filenamelen = strlen(text) + 1;
	filename = (char*)malloc(filenamelen * sizeof(char));
	strcpy(filename, text);
	strncat(filename, ".h",2);
	
	//File Creation
	FILE *f = fopen(filename, "r");
	if (f == NULL)
	{
		f = fopen(filename, "w");
		printf("The %s file was created!\n\n",filename);
		free(filename);
		free(text);
	}
	else
	{
		do
		{
			printf("The file already exist.Do you want to overwrite it?\n");
			printf("1. if you want to overwrite it\n2. if you don't want to overwrite it\n");
			printf("Please enter your choice: ");
			scanf("%d",&yes_no);
		}while(yes_no != 1 && yes_no != 2);
	}
	
	if (yes_no == 1)
	{
		f = fopen(filename, "w");
		printf("The %s file was created!\n\n",filename);
		free(filename);
		free(text);
	}
	else if (yes_no == 2)
	{
		main_menu();
	}
	
	//Menu adder
	
	printf("================================================================================");
	printf("\nHow many menus do you want to create? ");
	scanf("%d",&menu_number);
	while (menu_number <= 0)
	{
		printf("\nYou must enter a number that is greater than 0");
		printf("\nPlease insert your number again: ");
		scanf("%d",&menu_number);
	}
	printf("\n================================================================================");
	
	//Start writing to file
	fprintf(f, "#include <stdio.h>\n");
	fprintf(f, "#include <stdlib.h>\n\n");
	
	for(i=0;i<menu_number;i++)
	{
		//Declare Function
		fprintf(f, "int menu%d()\n{\n\t",i+1);
		
		//Choices of the menu
		printf("\nHow many choices do you want for the menu %d: ",i+1);
		scanf("%d",&choices_number);
		while (choices_number <= 0)
		{
			printf("\nYou must enter a number that is greater than 0");
			printf("\nHow many choices do you want for the menu %d: ",i+1);
			scanf("%d",&choices_number);
		}
		choices = malloc(choices_number * sizeof(char));
		choices_text = malloc(1000 * sizeof(char));
		
		//Function body
		//Menu Header
		menu_title = malloc(1000* sizeof(char));
		printf("\nPlease enter menu title (MAX: 1000 characters): ");
		scanf(" %[^\n]s",menu_title);
		fprintf(f, "printf(\"\\n");
		fprintf(f, "%s",menu_title);
		fprintf(f, "\\n\");\n");
		free(menu_title);
		
		//Start menu choices
		fprintf(f,"\tint choice;\n");
		fprintf(f,"\tdo\n\t{\n");
		for(j=0;j<choices_number;j++)
		{
			printf("\nPlease enter your %d choice text (MAX: 1000 characters/choice): ",j+1);
			scanf(" %[^\n]s",choices_text);
			while (choices_number <= 0)
			{
				printf("\nYou must enter a number that is greater than 0");
				printf("\nPlease enter your %d choice text (MAX: 1000 characters/choice): ",j+1);
				scanf("%d",&choices_number);
			}
			add_choices_len = strlen(choices_text) + 4;
			add_choices = (char*)malloc(add_choices_len * sizeof(char));
			//Adding number in front of choice
			strcpy(add_choices, itoa(j+1,int_to_string,10));
			strncat(add_choices, ". ",2);
			strncat(add_choices,choices_text,strlen(choices_text));
			fprintf(f,"\t\tprintf(\"");
			fprintf(f, add_choices);
			fprintf(f,"\\n\");\n");
		}
		fprintf(f,"\t\tprintf(\"\\nPlease enter your choice: \");\n");
		fprintf(f,"\t\tscanf(\"%%d\",&choice);\n");
		fprintf(f,"\t\tprintf(\"\\n\");\n");
		fprintf(f,"\t}while(choice<=0 || choice>%d);\n}\n\n",choices_number);
		printf("\n================================================================================");
		
		free(choices);
		free(choices_text);
		free(add_choices);
	}
	fclose(f);
	
	main_menu();
}

//Help
void help()
{
	printf("\n================================================================================");
	printf("\n- Step 1: Create a menu header file with my wizard by entering 1 in main menu.");
	printf("\n- Step 2: Complete all the steps in wizard.");
	printf("\n- Step 3: Create your .c file.");
	printf("\n- Step 4: Add #include \"your_created_filename.h\".");
	printf("\n- Step 5: The menu functions has names as menu1, menu2... as many as you created.");
	printf("\n- Step 6: All the functions return a number of user choice so that you can add ");
	printf("\n a switch case to add functionallity to your code.");
	printf("\n- Step 7: That's it! You have fully functional menus.");
	printf("\n\nMore info:\nYou can download an example program at general.tsikopoulos.eu.");
	printf("\n\nCredits:\nDT's MENU CREATOR v.0.6 - Created by Tsikopoulos Dimitrios \n");
	printf("\n================================================================================");
	main_menu();
}

//Credits
void credits()
{
	printf("\n================================================================================");
	printf("\n                 #########################################");
	printf("\n                 #                                       #");
	printf("\n                 #    Created by Tsikopoulos Dimitrios   #");
	printf("\n                 #                                       #");
	printf("\n                 #        DT's MENU CREATOR v.0.6        #");
	printf("\n                 #                                       #");
	printf("\n                 #    Website: general.tsikopoulos.eu    #");
	printf("\n                 #                                       #");
	printf("\n                 #########################################");
	printf("\n\n================================================================================");
	main_menu();
}
