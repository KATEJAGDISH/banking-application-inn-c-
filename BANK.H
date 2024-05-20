FILE* fp;
 struct Bank {
	char fname[20];// first 
	char lname[20];//last
	char mname[20];//mother
	char ffname[20];//father name 
	char address[50] , type[20], uname[20]/*username */ ,password[20];
	int date , month, year,phoneno ;
	int  balance=0;
    
};
typedef  struct Bank bank;
void NACCOUNT(){
	
   bank b;
	fp = fopen("newinfocust.txt", "ab");

	if(fp == NULL)
	{
		printf("\nUnable to open file");
		return;
	}
	printf("\n========================================================fill the all information==================================================================\n ");
	printf("\n frist Name: ");
	scanf("%19[^\n]s", &b.fname);
	fflush(stdin);
	printf("\n Last  Name: ");
	scanf("%19[^\n]s", &b.lname);
	fflush(stdin);
	printf("\n Mother Name: ");
	scanf("%19[^\n]s", &b.mname);
	fflush(stdin);
	printf("\n Father Name: ");
	scanf("%19[^\n]s", &b.ffname);
	fflush(stdin);
	printf("\n Address : ");
	scanf("%19[^\n]s", &b.address);
	fflush(stdin);
	
	printf("\n Account type : ");
	scanf("%19[^\n]s", &b.type );
	fflush(stdin);
	printf("\n DATE OF BIRTH");
	printf("\n DATE : ");
	scanf("%d", &b.date );
	fflush(stdin);
		printf("\n MONTH : ");
	scanf("%d", &b.month );
	fflush(stdin);
		printf("\n YEAR : ");
	scanf("%d", &b.year );
	fflush(stdin);
	printf("\n phone number  : ");
	scanf("%d", &b.phoneno );
	fflush(stdin);
	
	printf("\n UserNmae  : ");
	scanf("%19[^\n]s", &b.uname);
	fflush(stdin);
	printf("\n password  : ");
	scanf("%19[^\n]s", &b.password );
	fflush(stdin);
	
	fwrite(&b, sizeof(bank), 1, fp);
	fclose(fp);
	printf("\n account Create sucessfuly... ");
}



void info() {
    FILE *fp;
    bank b ; 
    fp = fopen("newinfocust.txt", "rb");

    if (fp == NULL) {
        printf("\nUnable to open file");
        return;
    }

    char username[50];
    
    printf("\nEnter Username: ");
    scanf("%s", username);



    while (fread(&b, sizeof(bank), 1, fp) > 0) {
        strcpy(b.uname, strlwr(b.uname));
        if (strcmp(username, b.uname) == 0) {
           printf("\n=======================================================================YOUR ACCOUNT INFORMATION==============================================================================\n");
            int phoneno;
                printf("\nAccount HolderName : %s%s \nFATHER'S NAME : %s  \nMOTHER'S NAME : %s  \nMOBILE NUMBER: %d  \nDATE OF BIRTH: %d-%d-%d \nADDRESS: %s   ", b.fname, b.lname, b.ffname , b.mname , b.phoneno, b.year, b.month , b.date, b.address) ;
            fclose(fp);
            return;
        }
    }


    printf("Username not found. Account information not available.\n");
    fclose(fp);
}
 
void transfer() {
	 FILE *fp;
    bank b, sender, receiver;
    char senderUsername[50], receiverUsername[50];
    int amount;

    printf("\n From (Your Username): ");
    scanf("%s", senderUsername);

    printf("\n To (Username of recipient): ");
    scanf("%s", receiverUsername);

    printf("\n Enter Amount to Transfer: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    fp = fopen("newinfocust.txt", "rb+");

    if (fp == NULL) {
        printf("\nUnable to open file for reading/writing.\n");
        return;
    }

    while (fread(&sender, sizeof(bank), 1, fp) > 0) {
        if (strcmp(senderUsername, sender.uname) == 0) {
            fseek(fp, -sizeof(bank), SEEK_CUR);
            sender.balance -= amount;
            fwrite(&sender, sizeof(bank), 1, fp);

            fseek(fp, 0, SEEK_SET);

            while (fread(&receiver, sizeof(bank), 1, fp) > 0) {
                if (strcmp(receiverUsername, receiver.uname) == 0) {
                    fseek(fp, -sizeof(bank), SEEK_CUR);
                    receiver.balance += amount;
                    fwrite(&receiver, sizeof(bank), 1, fp);

                    printf("Money transferred successfully!\n");
                    fclose(fp);
                    return;
                }
            }

            printf("Recipient's account not found.\n");
            fclose(fp);
            return;
        }
    }

    printf("Sender's account not found.\n");
    fclose(fp);
}


void balance() {
	 FILE *fp;
    bank b;
    char username[50];

    printf("\nEnter your username: ");
    scanf("%s", username);

    fp = fopen("newinfocust.txt", "rb");

    if (fp == NULL) {
        printf("\nUnable to open file for reading.\n");
        return;
    }

    while (fread(&b, sizeof(bank), 1, fp) > 0) {
        if (strcmp(b.uname, username) == 0) {
            printf("%s, your balance is %d\n", b.uname, b.balance);
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}



void addmoney() {
    bank b;
    char username[30];
    double amount;

    printf("\nEnter your username: ");
    scanf("%s", username);

    printf("\nEnter deposit amount: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Please enter a positive value.\n");
        return;
    }

    fp = fopen("newinfocust.txt", "rb+");

    if (fp == NULL) {
        printf("\nUnable to open file for reading/writing.\n");
        return;
    }

    while (fread(&b, sizeof(bank), 1, fp) > 0) {
        if (strcmp(b.uname, username) == 0) {
            fseek(fp, -sizeof(bank), SEEK_CUR);
            b.balance += (int)amount;
            fwrite(&b, sizeof(bank), 1, fp);

            printf("Money added successfully! New balance: %d\n", b.balance);
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}



void signin() {
    FILE *fp;
    bank b; 
    fp = fopen("newinfocust.txt", "rb");

    if (fp == NULL) {
        printf("\nUnable to open file");
        return;
    }
	int e;
    char sign[50];
    char pass[50];
    printf("\nEnter Username: ");
    scanf("%s", sign);
    printf("\nEnter Password: ");
    scanf("%s", pass);



    
    strcpy(sign, strlwr(sign));
    strcpy(pass, strlwr(pass));
    while (fread(&b, sizeof(bank), 1, fp) == 1) {
        strcpy(b.uname, strlwr(b.uname));
        strcpy(b.password, strlwr(b.password));

        if (strcmp(sign, b.uname) == 0 && strcmp(pass, b.password) == 0) {
            printf("\n=====================================================================Login successful=======================================================================\n");
            printf("\n=====================================================================WELCOME %s =======================================================================\n ",b.uname);	
	            printf("\n=================================================================HOME ======================================================================================\n ");		
			
            printf("1. Check Balance\n2. Transfer Money\n3. Check Your Information\n4. Add Money\n5. Logout\n6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &e);

            switch (e) {
                case 1:
                    balance();
                    break;
                case 2:
                    transfer();
                    break;
                case 3:
                    info();
                    break;
                case 4:
                    addmoney();
                    break;
                case 5:
                    printf("\nLogged out successfully.\n");
                    break;
                case 6:
                    printf("\nExiting . Have a nice day !\n");
                    break;
                default:
                    printf("\nInvalid Choice\n");
                    break;
			}
            fclose(fp);
            return;
        }
    }

  
    printf("Login failed. Username or password incorrect.\n");
    fclose(fp);
}












