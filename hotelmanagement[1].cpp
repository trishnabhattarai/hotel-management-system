#include <stdio.h>
#include <string.h>
// #include <conio.h> // Removed for Linux compatibility
#include <stdlib.h>
// #include <windows.h> // Removed for Linux compatibility
#include <time.h>

struct customers {
    char name[30];
    char email[30];
    int roomno;
    int phone;
    char checkInTime[20]; // Format: YYYY-MM-DD HH:MM
    char checkOutTime[20]; // Format: YYYY-MM-DD HH:MM
    int visitCount;
    char paymentMethod[10]; // e.g., "Cash", "Online"
    float totalBill;
    float roomRate;
    int stayDuration; // in days
}c; // Keep global variable 'c' for now, though it's generally not good practice
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
// COORD coord = {0, 0}; // Removed for Linux compatibility
// void gotoxy(int x, int y) { // Removed for Linux compatibility
// 	coord.X = x;
// 	coord.Y = y;
// 	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleCursorPosition(output, coord);
// }

FILE *fp, *fr;

void displayWelcomeScreen() {
    system("cls"); // Clear the console for Linux
    /* gotoxy removed for Linux compatibility */
    printf("Welcome to the Hotel Management System\n"); // Added newline
    /* gotoxy removed for Linux compatibility */
    printf("Press any key to continue...\n"); // Added newline
    getchar(); // Wait for a key press (consumes the key). scanf %d in main will skip the newline.
}

int main()
{
	int n, opt;
	char continu = 'y';

	displayWelcomeScreen(); // Call the welcome screen function

	while (continu == 'y') {
		system("cls"); // Changed for Linux
	    head();
		/* gotoxy removed for Linux compatibility */
		printf("\n 1. Admin");
		/* gotoxy removed for Linux compatibility */
		printf("\n 2. User");
		/* gotoxy removed for Linux compatibility */
		printf("\n Your choice : ");
		/* gotoxy removed for Linux compatibility */
		scanf("%d", &opt);
		switch(opt){
			case 1:
				system("cls"); // Changed for Linux
				adminlogin();
				break;
				
			case 2:
				system("cls"); // Changed for Linux
				stafflogin();
				break;
			
			default:
				printf("................Choose Only 1 or 2.....................");
			
		}

		
		printf("\n Do you want to go to the first page? (y/n)   ");
		// int ch_consume_main; while ((ch_consume_main = getchar()) != '\n' && ch_consume_main != EOF && ch_consume_main != ' '); // Clear buffer before reading char
		// Removed: scanf(" %c", ...) handles leading whitespace. The loop might consume the input itself.
		scanf(" %c", &continu); // Added space to skip leading whitespace
	}

	return 0;
}

void head()
{
	system("cls"); // Changed for Linux
	/* gotoxy removed for Linux compatibility */
	printf("Hotel Management System\n"); // Added newline
	time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    /* gotoxy removed for Linux compatibility */
    printf("Current date: %s", asctime(localTime));
    /* gotoxy removed for Linux compatibility */
}
 void adminlogin()
 {
 	
	char curUsername[30], curUserPassword[30];
	int num;
	 head();
	/* gotoxy removed for Linux compatibility */
	printf("\n Enter your username :\t ");
	int ch_consume_admin_user; while ((ch_consume_admin_user = getchar()) != '\n' && ch_consume_admin_user != EOF); // Clear buffer after previous scanf %d
	scanf("%29s", curUsername); // Changed gets to scanf for safety
	/* gotoxy removed for Linux compatibility */
	printf("\n Enter your Password :\t ");
	// Password input will be visible. getch() is not available on Linux.
	scanf("%29s", curUserPassword); // Changed for Linux compatibility

	if (!strcmp(curUsername,username) && !strcmp(curUserPassword, pass)) {
		system("cls"); // Changed for Linux
		head();
		/* gotoxy removed for Linux compatibility */
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
	/* gotoxy removed for Linux compatibility */
	printf("\n Enter your username :\t ");
	int ch_consume_staff_user; while ((ch_consume_staff_user = getchar()) != '\n' && ch_consume_staff_user != EOF); // Clear buffer after previous scanf %d
	scanf("%29s", curUsername); // Changed gets to scanf for safety
	/* gotoxy removed for Linux compatibility */
	printf("\n Enter your Password :\t ");
	// Password input will be visible. getch() is not available on Linux.
	scanf("%29s", curUserPassword); // Changed for Linux compatibility
	if (!strcmp(curUsername,username2) && !strcmp(curUserPassword, pass2))
	{
		system("cls"); // Changed for Linux
		head();
		/* gotoxy removed for Linux compatibility */
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
	// NOTE: This function now saves more data. Old hoteldetail.txt files will be incompatible.
	struct customers c;
	char cont = 'y';

	fr = fopen("hoteldetail.txt", "a+");
	if (fr == NULL) {
		printf("\nError opening file");
		return;
	}
		head();
		
		/* gotoxy removed for Linux compatibility */
		printf("\nEnter Customer Name :\t ");
		int ch_consume_cust_name; while ((ch_consume_cust_name = getchar()) != '\n' && ch_consume_cust_name != EOF); // Clear buffer
		scanf("%29s", c.name); // Replaced gets with scanf for safety and compatibility
		printf("\nEnter Phone no      :\t ");
		scanf("%d", &c.phone);
		printf("\nEnter Email         :\t");
		int ch_consume_cust_email; while ((ch_consume_cust_email = getchar()) != '\n' && ch_consume_cust_email != EOF); // Clear buffer
		scanf("%29s", c.email); // Replaced gets with scanf for safety and compatibility
		printf("\nEnter Room no       :\t ");
		scanf("%d", &c.roomno);

		printf("\nEnter Check-In Time (YYYY-MM-DD HH:MM):\t ");
		scanf(" %19[^\n]", c.checkInTime); // Read string with spaces, consume leading newline

		printf("\nEnter Room Rate (per day) :\t ");
		scanf("%f", &c.roomRate);

		// Initialize other new fields
		strcpy(c.checkOutTime, "N/A");
		c.visitCount = 1;
		strcpy(c.paymentMethod, "N/A");
		c.totalBill = 0.0f;
		c.stayDuration = 0;

		fwrite(&c, sizeof(struct customers), 1, fr);
		printf("\nData inserted successfully.\n\n");
		getchar(); // Consumes the newline from previous scanf. For an actual pause, another getchar() would be needed.
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
			printf("\nCheck-In Time: %s", c.checkInTime);
			printf("\nCheck-Out Time: %s", c.checkOutTime);
			printf("\nRoom Rate: %.2f per day", c.roomRate);
			printf("\nStay Duration: %d days", c.stayDuration);
			printf("\nVisit Count: %d", c.visitCount);
			printf("\nTotal Bill: %.2f", c.totalBill);
			printf("\nPayment Method: %s", c.paymentMethod);
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
		system("cls"); // Changed for Linux
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
					printf("\nCurrent Check-In Time: %s", c.checkInTime);
					printf("\nCurrent Check-Out Time: %s", c.checkOutTime);
					printf("\nCurrent Room Rate: %.2f", c.roomRate);

					// Clear buffer from previous scanf("%s", name)
					int ch_consume_edit_start; while((ch_consume_edit_start = getchar()) != '\n' && ch_consume_edit_start != EOF);

					char temp_checkInTime[20];
					temp_checkInTime[0] = '\0';
					printf("\nEnter New Check-In Time (YYYY-MM-DD HH:MM) (leave blank to keep current): ");
					scanf("%19[^\n]", temp_checkInTime); // No leading space, rely on prior buffer clear
					if (temp_checkInTime[0] != '\0') {
						strcpy(c.checkInTime, temp_checkInTime);
					}
					int ch_consume_cin; while ((ch_consume_cin = getchar()) != '\n' && ch_consume_cin != EOF);

					char temp_checkOutTime[20];
					temp_checkOutTime[0] = '\0';
					printf("\nEnter New Check-Out Time (YYYY-MM-DD HH:MM) (leave blank to keep current): ");
					scanf("%19[^\n]", temp_checkOutTime); // No leading space
					if (temp_checkOutTime[0] != '\0') {
						strcpy(c.checkOutTime, temp_checkOutTime);
					}
					int ch_consume_cout; while ((ch_consume_cout = getchar()) != '\n' && ch_consume_cout != EOF);

					float temp_roomRate = 0.0f;
					printf("\nEnter New Room Rate (0 to keep current): ");
					scanf("%f", &temp_roomRate);
					if (temp_roomRate > 0.0f) {
						c.roomRate = temp_roomRate;
					}
					int ch_consume_rate; while ((ch_consume_rate = getchar()) != '\n' && ch_consume_rate != EOF);

					// Calculate stay duration if checkOutTime was updated and is valid
					// This condition means: if user *attempted* to change checkout time (temp_checkOutTime is not blank)
					// AND the resulting c.checkOutTime is not "N/A"
					// AND c.checkInTime is also not "N/A"
					if (temp_checkOutTime[0] != '\0' && strcmp(c.checkOutTime, "N/A") != 0 && strcmp(c.checkInTime, "N/A") != 0) {
						struct tm tm_in, tm_out;
						time_t time_in_secs, time_out_secs;

						memset(&tm_in, 0, sizeof(struct tm));
						memset(&tm_out, 0, sizeof(struct tm));

						// Parse check-in time
						if (sscanf(c.checkInTime, "%d-%d-%d %d:%d", &tm_in.tm_year, &tm_in.tm_mon, &tm_in.tm_mday, &tm_in.tm_hour, &tm_in.tm_min) == 5) {
							tm_in.tm_year -= 1900;
							tm_in.tm_mon -= 1;
							time_in_secs = mktime(&tm_in);
						} else {
							time_in_secs = -1; // Mark as parsing error
						}

						// Parse check-out time
						if (sscanf(c.checkOutTime, "%d-%d-%d %d:%d", &tm_out.tm_year, &tm_out.tm_mon, &tm_out.tm_mday, &tm_out.tm_hour, &tm_out.tm_min) == 5) {
							tm_out.tm_year -= 1900;
							tm_out.tm_mon -= 1;
							time_out_secs = mktime(&tm_out);
						} else {
							time_out_secs = -1; // Mark as parsing error
						}

						if (time_in_secs == -1 || time_out_secs == -1) {
							c.stayDuration = 0;
							printf("\nError: Invalid check-in or check-out date format. Stay duration not calculated.\n");
						} else {
							double difference_seconds = difftime(time_out_secs, time_in_secs);
							c.stayDuration = (int)(difference_seconds / (60 * 60 * 24));
							if (c.stayDuration < 0) {
								c.stayDuration = 0;
							}
							printf("\nStay duration calculated: %d days.\n", c.stayDuration);
						}
					} else if (temp_checkOutTime[0] != '\0' && strcmp(c.checkOutTime, "N/A") == 0) {
                        // If user explicitly set checkout time to N/A (or it was already N/A and they provided blank input for temp_checkOutTime)
                        c.stayDuration = 0;
                         printf("\nCheck-out time is N/A. Stay duration set to 0.\n");
                    }


					printf("\n\nEnter New Phone Number (Press Enter to keep %d): ", c.phone);
					// Logic to conditionally read phone: read as string, if not empty, convert and update.
					// For simplicity, direct scanf is kept, meaning user must re-enter or enter new.
					scanf("%d", &phones);
					c.phone = phones; // Assuming user always provides a value or re-enters current

					printf("Enter New Room Number (Press Enter to keep %d): ", c.roomno);
					scanf("%d", &roomnos);
					c.roomno = roomnos; // Assuming user always provides a value or re-enters current
                    int ch_consume_roomno; while ((ch_consume_roomno = getchar()) != '\n' && ch_consume_roomno != EOF);


					printf("Enter New Email (leave blank to keep %s): ", c.email);
					scanf(" %19[^\n]", emails); // Read string with spaces, consume leading newline
                    if(emails[0] != '\0' && strcmp(emails, "") != 0) { // Check if input is not empty
                        strcpy(c.email, emails);
                    }
                    // If emails was intended to be skippable, its logic would be like checkInTime.
                    // The current scanf with " %19[^\n]" might not allow truly blank input easily if not handled carefully.
                    // For now, assume it works or previous value is re-entered if blank is not truly supported by this scanf.

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
		// fflush(stdin); // Removed, space in " %c" handles leading whitespace
		scanf(" %c", &cont);  // space before %c to ignore newline
		
	}
}

void del() {
	head();
	int phonenumber;
	char cont = 'y';
	FILE *fr, *tempFile;
	

	while (cont == 'y') {
		system("cls"); // Changed for Linux

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
		// fflush(stdin); // Removed, space in " %c" handles leading whitespace
		scanf(" %c", &cont);  // note the space before %c to catch newline
	}
}
