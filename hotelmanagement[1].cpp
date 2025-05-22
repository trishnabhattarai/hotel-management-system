#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

struct customers{
	char name[30];
	char email[30];
	int roomno;
	int phone;
}c;
static char username[] = "admin";
static char username2[] = "staff";
static char pass[] = "1111";
static char pass2[] = "2222";
void head();
void adminlogin();
void edit();
void del();

void searchcustomer_by_number();
void displayss();

void stafflogin();
void addcustomer();
COORD coord = {0, 0};

void gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, coord);
}

FILE *fp, *fr;

int main()
{
	int n, opt;
	char continu = 'y';

	while (continu == 'y') {
		system("cls");
	    head();
		gotoxy(50,10);
		printf("\n 1. Admin");
		gotoxy(50,12);
		printf("\n 2. User");
		gotoxy(50,14);
		printf("\n Your choice : ");
		gotoxy(18,15);
		scanf("%d", &opt);
		switch(opt){
			case 1:
				system("cls");
				adminlogin();
				break;
				
			case 2:
				system("cls");
				stafflogin();
				break;
			
			default:
				printf("................Choose Only 1 or 2.....................");
			
		}

		
		printf("\n Do you want to go to the first page? (y/n)   ");
		fflush(stdin);
		scanf("%c", &continu);
	}

	return 0;
}

void head()
{
	system("cls");
	gotoxy(60, 4);
	printf("Hotel Management System");
	time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    gotoxy(0, 0);
    printf("Current date: %s", asctime(localTime));
    gotoxy(0,8);
}
 void adminlogin()
 {
 	
	char curUsername[30], curUserPassword[30];
	int num;
	 head();
	gotoxy(50,12);
	printf("\n Enter your username :\t ");
	fflush(stdin);
	gets(curUsername);
	gotoxy(50,14);
	printf("\n Enter your Password :\t ");
	char ch;
	int i = 0;
	while (1) {
		ch = getch();
		if (ch == '\r') {  
			curUserPassword[i] = '\0';
			break;
		} else if (ch == '\b' && i > 0) { 
			i--;
			printf("\b \b"); 
		} else {
			curUserPassword[i] = ch;
			i++;
			printf("*"); // Print a '' for each character to the screen
		}
	}

	if (!strcmp(curUsername,username) && !strcmp(curUserPassword, pass)) {
		system("cls");
		head();
		gotoxy(0,8);
		printf("\n1. See  all record");
		printf("\n2. Search");
		printf("\n3. Edit information");
		printf("\n4. Delete information");
		printf("\n5. Exit");
		printf("\n\nYour choice : ");
		scanf("%d", &num); 
		switch(num){
			case 1:
				displayss();
				break;
				
			case 2:
				searchcustomer_by_number();
			    break;
				
			case 3:
				edit();
			   	break;
			   	
			case 4:
				del();
			   	break;
			   	
			case 5:
				exit(0);
			   	break;				
		}
	
 }
 
}

void stafflogin()
{
	char curUsername[30], curUserPassword[30];
	int num;
	 head();
	gotoxy(50,12);
	printf("\n Enter your username :\t ");
	fflush(stdin);
	gets(curUsername);
	gotoxy(50,14);
	printf("\n Enter your Password :\t ");
	char ch;
	int i = 0;
	while (1) {
		ch = getch();
		if (ch == '\r') {  
			curUserPassword[i] = '\0';
			break;
		} else if (ch == '\b' && i > 0) { 
			i--;
			printf("\b \b"); 
		} else {
			curUserPassword[i] = ch;
			i++;
			printf("*"); // Print a '' for each character to the screen
		}
	}
	if (!strcmp(curUsername,username2) && !strcmp(curUserPassword, pass2))
	{
		system("cls");
		head();
		gotoxy(0,8);
		printf("1. Add Customer.\n");
		printf("2. View Record.\n");
		printf("3. Search.\n");
		printf("4. Back.\n");
		printf("5. Exit.\n");
		printf("=");
		scanf("%d", &num); 
		switch(num)
		{
			case 1:
				addcustomer();
				break;
			case 2:
				displayss();
				break;
				
			case 3:
				searchcustomer_by_number();
				break;
			
			case 4:
				main();
				break;
				
			case 5:
				exit(0);
				
		}
	}
}

void addcustomer(){
	struct customers c;
	char cont = 'y';

	fr = fopen("hoteldetail.txt", "a+");
	if (fr == NULL) {
		printf("\nError opening file");
		return;
	}
		head();
		
		gotoxy(0,8);
		printf("\nEnter Customer Name :\t ");
		fflush(stdin);
		gets(c.name);
		printf("\nEnter Phone no      :\t ");
		scanf("%d", &c.phone);
		printf("\nEnter Email         :\t");
		fflush(stdin);
		gets(c.email);
		printf("\nEnter Room no       :\t ");
		scanf("%d", &c.roomno);
		fwrite(&c, sizeof(struct customers), 1, fr);
		printf("\nData inserted successfully.\n\n");
		getch();
	fclose(fr);
}

void searchcustomer_by_number() {
	head();
	
	fr = fopen("hoteldetail.txt", "r+");
	int searchnumber;
	printf("Enter the phone Number:");
	scanf("%d",&searchnumber);
	
	if (fr == NULL) {
		printf("\nNo data available");
		return;
	}

	int found = 0;
	while (fread(&c, sizeof(struct customers), 1, fr) == 1) {
		if (c.phone == searchnumber) {
			printf("\nCustomer Name: %s", c.name);
			printf("\nCustomer Phone Number: %d", c.phone);
			printf("\nRoom no : %d", c.roomno);
			printf("\nCustomer Email: %s", c.email);
			printf("\n");
			found = 1;
		}
	}

	if (!found) {
		printf("\nNo Customer found %d\n", searchnumber);
	}

	fclose(fr);
}

void displayss()
{
	head();
	
	fr = fopen("hoteldetail.txt", "r+");
	
	if (fr == NULL) {
		printf("\nNo data available");
		return;
	}

	int found = 0;
	while (fread(&c, sizeof(struct customers), 1, fr) == 1) {
		
			printf("\nCustomer Name: %s", c.name);
			printf("\nCustomer Phone Number: %d", c.phone);
			printf("\nRoom no : %d", c.roomno);
			printf("\nCustomer Email: %s", c.email);
			printf("\n");
			printf("_______________________________________________________________________________________________________________");
			found = 1;
		
	}



	fclose(fr);
}


void edit() {
	head();
	struct customers c;

	char cont = 'y';
	char name[30];
	char emails[30];
	int roomnos;
	int phones;
	FILE *fr;

	while (cont == 'y') {
		system("cls");
		head();

		printf("\nEnter Customer Name: ");
		scanf("%s", name);

		fr = fopen("hoteldetail.txt", "rb");  // open for reading in binary mode
		if (fr == NULL) {
			printf("\nNo data available\n");
		} else {
			FILE *tempFile = fopen("temp.txt", "wb");  // binary mode

			int found = 0;
			while (fread(&c, sizeof(struct customers), 1, fr) == 1) {
				if (strcmp(c.name, name) == 0) {
					found = 1;
					printf("\nCustomer Name: %s", c.name);
					printf("\nRoom Number: %d", c.roomno);
					printf("\nPhone Number: %d", c.phone);
					printf("\nEmail: %s", c.email);

					printf("\n\nEnter New Phone Number: ");
					scanf("%d", &phones);
					printf("Enter New Room Number: ");
					scanf("%d", &roomnos);
					printf("Enter New Email: ");
					scanf(" %[^\n]", emails); // read string with spaces

					c.phone = phones;
					c.roomno = roomnos;
					strcpy(c.email, emails);
				}
				fwrite(&c, sizeof(struct customers), 1, tempFile);
			}

			fclose(fr);
			fclose(tempFile);

			if (!found) {
				printf("\n\n%s Data Not Found.\n", name);
				remove("temp.txt");  // Delete temp file if no data was modified
			} else {
				remove("hoteldetail.txt");
				rename("temp.txt", "hoteldetail.txt");
				printf("\nData updated successfully.\n\n");
			}
		}

		printf("\nDo you want to continue? (y/n): ");
		fflush(stdin);
		scanf(" %c", &cont);  // space before %c to ignore newline
		
	}
}

void del() {
	head();
	int phonenumber;
	char cont = 'y';
	FILE *fr, *tempFile;
	

	while (cont == 'y') {
		system("cls");

		printf("\nEnter customer phone number to delete: ");
		scanf("%d", &phonenumber);

		fr = fopen("hoteldetail.txt", "rb");
		if (fr == NULL) {
			printf("\nNo data available.\n");
			return;
		}

		tempFile = fopen("temp.txt", "wb");
		if (tempFile == NULL) {
			printf("\nError opening temporary file.\n");
			fclose(fr);
			return;
		}

		int found = 0;
		while (fread(&c, sizeof(struct customers), 1, fr) == 1) {
			if (c.phone == phonenumber) {
				found = 1;
				printf("\nCustomer Found:");
				printf("\nName: %s", c.name);
				printf("\nRoom Number: %d", c.roomno);
				printf("\nPhone Number: %d", c.phone);
				printf("\nEmail: %s\n", c.email);
			} else {
				fwrite(&c, sizeof(struct customers), 1, tempFile);
			}
		}

		fclose(fr);
		fclose(tempFile);

		if (found) {
			remove("hoteldetail.txt");
			rename("temp.txt", "hoteldetail.txt");
			printf("\nCustomer record deleted successfully.\n");
		} else {
			remove("temp.txt");  // clean up
			printf("\nNo customer found with phone number: %d\n", phonenumber);
		}

		printf("\nDo you want to continue? (y/n): ");
		fflush(stdin);
		scanf(" %c", &cont);  // note the space before %c to catch newline
	}
}

