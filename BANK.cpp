#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BANK.h"
int main()
{
	int choice;
	do
	{
	  system ("cls");
		printf("\n*** Bank Management System Menu ***\n");
        printf("1. Create a new account\n");
        printf("2. Sign in\n");
        printf("3. Exit\n");
          printf("=====================================================================================================================================================");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				NACCOUNT();
				break;
		
			case 2:
				signin();
				break;
			case 3:
				printf("\nExitting\n");
				break;
			default:
				printf("\nInvalid Choice\n");
				break;
		} 
		printf("\n");
	 system("pause");
	}
	while(choice!=3);
	return-1;
}

