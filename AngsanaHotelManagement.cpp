
#include <iostream>
#include<conio.h>
#include <string>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <unistd.h>

using namespace std;

struct ReservationDetails
{
	string dateIn;
    string dateOut;
	int days;
    char type;
    char facilities;
    int payment;
    string name;
    int phone;
    string email;
    string prompt;
};

// to keep record real time
time_t current = time(0);
char *dt = ctime(&current);

// Function prototypes
void mainMenu();
void reservation(ReservationDetails &);
void calculation(const ReservationDetails &);
void editReservation(ReservationDetails &);
void generateReceipt(const ReservationDetails &, int room);
void displayRoom();
int getValidRating(const string& prompt);
int getValidRating(const string& prompt);
void handleFeedback();
void information();


int main()
{
	cout << "\n";
    cout << "\t\t--WELCOME TO ANGSANA HOTEL--" << endl;
    cout << "ELEGANCE IN EVERY STAY, EXCEPTIONAL EXPERIENCES AWAIT !"  << endl << endl;
    cout <<"\t\tPress any key to continue!!" <<endl;
    getch();

	int room = 0;// Add a variable to track the room number
    int ans;
    int facilitiesRating;
    int roomRating, prompt;
    ReservationDetails reservationDetails;
    bool exitProgram = false;

	do
	{
		mainMenu();
        cout << "\n";
        cout << "\t\tEnter your choice: ";
        cin >> ans;

        switch (ans)
        {
        case 1:
            reservation(reservationDetails); //line 120-187
            displayRoom(); //line 189-205
            generateReceipt(reservationDetails, room); // line 207-245
            break;

		case 2:
			calculation(reservationDetails); // line 247-383
			break;


        case 3:
            editReservation(reservationDetails); // line 385-447
            generateReceipt(reservationDetails, room); //line 207-245
            break;

        case 4:
            handleFeedback(); //line 449-537
            break;

        case 5:
        	information(); //line 539-560
        	break;

        case 0:
            cout << "\t\tExiting program. Thank you for using our services!" << endl;
            break;

        default:
            cout << "\t\tInvalid choice. Please try again." << endl;
            sleep(1);
    		system("CLS");
            break;
        }

	}while (ans !=0);

    return 0;
}

void mainMenu()
{
    cout << endl;
    cout << "\t\t+---+------------------+" << endl;
    cout << "\t\t| 1 | Reservation      |" << endl;
    cout << "\t\t| 2 | Calculation      |" << endl;
    cout << "\t\t| 3 | Edit Reservation |" << endl;
    cout << "\t\t| 4 | Feedback         |" << endl;
    cout << "\t\t| 5 | Hotel Information|" << endl;
    cout << "\t\t| 0 | Exit             |" << endl;
    cout << "\t\t+---+------------------+" << endl;
}

void reservation(ReservationDetails &details)
{

	system ("cls");

	cout << "\n" << endl;
	displayRoom();

	    // Print table

	cout << "\n" << endl;
	
    cout << "\t\tChoose a room : ";
    cin >> details.type;
    
    while(details.type!='A' && details.type!='a' && details.type!='B' && details.type!='b' && details.type!='S' && details.type!='s' && details.type!='V' && details.type!='V')
    {
    	cout << "\t\tInvalid room code. Please refer to the table above for valid room codes."<<endl;
    	cout << "\t\tChoose a room : ";
    	cin >> details.type;
	}
	
   	cout << "\t\tChoose a facility :  ";
    cin >> details.facilities;
    
    while(details.facilities!='A' && details.facilities!='a' && details.facilities!='B' && details.facilities!='b' && details.facilities!='C' && details.facilities!='c' && details.facilities!='D' && details.facilities!='d' )
    {
    	cout << "\t\tInvalid facility code. Please refer to the table above for valid facility codes."<<endl;
    	cout << "\t\tChoose a facility : ";
    	cin >> details.facilities;
	}
	cout << endl;

	cout << "\t\t------------------------------your contact details------------------------------" << endl;
	cout << "\t\tName: ";
    cin >> details.name;
    cout << "\t\tEmail: ";
    cin >> details.email;
    cout << "\t\tPhone: ";
    cin >> details.phone;
    cout << "\t\t------------------------------check in and check out----------------------------" << endl;
    cout << "\t\tCheck-in date (dd/mm/yyyy): ";
    cin >> details.dateIn;
    cout << "\t\tCheck-out date (dd/mm/yyyy): ";
    cin >> details.dateOut;
    cout << "\t\tNumber of days: ";
    cin >> details.days;
	cout << "\t\t------------------------------payment method-----------------------------------" << endl;
    cout << "\t\tChoose your payment method:" << endl;
	cout << "\t\t1. Credit Card" << endl;
    cout << "\t\t2. Cash" << endl;
	cout << endl;
	cout << "\t\tPayment method: ";
	cin >> details.payment;
	while(details.payment!=1 && details.payment!=2 )
    {
    	cout << "\t\tInvalid payment method. Please enter the valid method." ;
    	cin >> details.payment;
	}

	cout << "\t\t-------------------------------------------------------------------------------" << endl;


	cout << "\t\tReservation details saved successfully." << endl;
	system("pause");
	system("cls");

}

void displayRoom()
{
	cout << "\t\t ROOMS AND FACILITIES AVAILABLE : " <<endl;
	cout << "\n";
    cout << "\t+======+=================+======================+===========+" << "\t+======+=================+=============+" << endl;
    cout << "\t| CODE |    ROOM NAME    |       CAPACITY       |   PRICES  |" << "\t| CODE |    FACILITIES    |   PRICES   |" << endl;
    cout << "\t+======+=================+======================+===========+" << "\t+======+=================+=============+" << endl;
    cout << "\t|  S   |  SINGLE ROOM    |  1 OR 2 PEOPLE       |   RM100   |" << "\t|  A   |       BUFFET     |   RM330    |" << endl;
    cout << "\t+------+-----------------+----------------------+-----------+" << "\t+------+-----------------+-------------+" << endl;
    cout << "\t|  A   |  FAMILY ROOM(A) |  3 OR 4 PEOPLE       |   RM270   |" << "\t|  B   |        GYM       |   RM350    |" << endl;
    cout << "\t+------+-----------------+----------------------+-----------+" << "\t+------+-----------------+-------------+" << endl;
    cout << "\t|  B   |  FAMILY ROOM(B) |  5 OR 6 PEOPLE       |   RM350   |" << "\t|  C   |   SWIMMING POOL  |   RM400    |" << endl;
    cout << "\t+------+-----------------+----------------------+-----------+" << "\t+------+-----------------+-------------+" << endl;
    cout << "\t|  V   |  VIP ROOM       |  MAXIMUM 6 PEOPLE    |   RM430   |" << "\t|  D   |        NONE      |    RM0     |" << endl;
    cout << "\t+------+-----------------+----------------------+-----------+" << "\t+------+-----------------+-------------+" << endl;
    cout << "\tNote : Free WiFi is available in all rooms."<<endl;
}

void generateReceipt(const ReservationDetails &details, int room)
{
    system("cls");

	cout << "\n";
	cout << "\t\t+------------------------------------------------------------------+" << endl;
    cout << "\t\t|\t\t  Angsana Hotel Receipt       			   |" << endl;
    cout << "\t\t+------------------------------------------------------------------+" << endl;
    cout << "\t\t             Date and time : " << dt<<endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t               Name: " << details.name << "           	                   " << endl;
	cout << "\t\t               Email:" << details.email << "      				       " << endl;
	cout << "\t\t               Phone: " << details.phone << "       	         		   " << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl;
	cout << "\t\t               Check-in date: " << details.dateIn << "         			   " << endl;
	cout << "\t\t               Check-out date: " << details.dateOut << "       			   " << endl;
	cout << "\t\t               Number of days: " << details.days << "       			   " << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl;
	cout << "\t\t               Type of room: " << details.type << "        		                   " << endl;
	cout << "\t\t               Facilities: " << details.facilities << "					   " << endl;
	cout << "\t\t-------------------------------------------------------------------" << endl;
	if (details.payment==1)
    {
        cout << "\t\t               Payment method: Credit card    	             " << endl;
    }
    else if (details.payment==2)
    {
    	cout << "\t\t               Payment method: CASH                        " << endl;
    }
    
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t|\t    Thank you for using our services!                      |"		   << endl;
	cout << "\t\t|  ELEGANCE IN EVERY STAY, EXCEPTIONAL EXPERIENCES AWAIT !         |" << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;

	system("pause");
	system("cls");
	
}

void calculation(const ReservationDetails &details)
{
	system("cls");
	float totalRoom, totalFaci;
	float total, totalPrice, priceR[4] = {100, 270, 350, 430};
    float priceF[4] = {330, 350, 400, 0};
    float taxRate = 0.06, tax, totalAfterTax, dayDisc, paymentDisc, totalDisc, totalDue;

	//room calc
    if(details.type == 'S' || details.type == 's')
    {
    	totalRoom = priceR[0];
	}

	else if(details.type == 'A' || details.type == 'a')
    {
    	totalRoom = priceR[1];
	}

	else if(details.type == 'B' || details.type == 'b')
    {
    	totalRoom = priceR[2];
	}

	else if(details.type == 'V' || details.type == 'v')
    {
    	totalRoom = priceR[3];
	}

	//faci calc
	if(details.facilities == 'A' || details.facilities == 'a')
	{
		totalFaci = priceF[0];
	}

	else if(details.facilities == 'B' || details.facilities == 'b')
	{
		totalFaci = priceF[1];
	}

	if(details.facilities == 'C' || details.facilities == 'c')
	{
		totalFaci = priceF[2];
	}

	if(details.facilities == 'D' || details.facilities == 'd')
	{
		totalFaci = priceF[3];
	}


	total = (totalRoom + totalFaci)*details.days;

	//tax calc

	tax = total*taxRate;
	totalAfterTax = total + tax;

	// day disc calc
	
	if (details.days < 3 )
	{
		dayDisc = 0.05;
	}

	else if(details.days > 3 && details.days < 7)
	{
		dayDisc = 0.10;
	}

	else if (details.days > 7 )
	{
		dayDisc = 0.25;
	}


	// payment disc calc
	
	//total disc calc
	
	if(details.payment == 1)
	{
		totalDisc = 8 + (dayDisc*total) ; // 8 = discount for credit card 
	}
	
	else 
	{
		totalDisc = 4 + (dayDisc*total) ; // 4 = disconut for cash 
	}

	//grand total

	totalDue = totalAfterTax - totalDisc;

	cout << setiosflags(ios::fixed) << setprecision(2) <<endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
    cout << "\t\t|\t\t\t      Receipt       			   |" << endl;
    cout << "\t\t\t\tDate and time : " << dt<<endl;
    cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t       Name: " << details.name << "           						   " << endl;
	cout << "\t\t       Email:" << details.email << "      						     	   " << endl;
	cout << "\t\t       Phone: " << details.phone << "       						   " << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t       Check-in date: " << details.dateIn << "         					   " << endl;
	cout << "\t\t       Check-out date: " << details.dateOut << "       					  " << endl;
	cout << "\t\t       Number of days: " << details.days << "       				     	   " << endl;
	cout << "\t\t       Payment method: " << details.payment << "                           " << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t       Type of room: " << details.type << "        		     		     	           " << endl;
	cout << "\t\t       Facilities: " << details.facilities << "					         	   " << endl;
	cout << "\t\t       Total : RM " <<total << "                                                    " <<endl;
	cout << "\t\t       Total after 6% tax : RM " <<totalAfterTax<< "                                               "<<endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t       Discount " <<(dayDisc*100)<<" % for staying for " <<details.days<< " days" <<endl;
	if(details.payment == 1)
	{
		cout << "\t\t       RM8 will be deducted for paying using credit card" <<endl;
		
	}

	else if(details.payment == 2)
	{
		cout << "\t\t       RM4 will be deducted for paying using cash" <<endl;
		
	}
	cout << "\t\t       Total discount : RM " <<totalDisc<<endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t       Grand total : "  <<  totalDue << "           " << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t|\t            Thank you for choosing us!  	           |" << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	cout << "\t\t|   ELEGANCE IN EVERY STAY, EXCEPTIONAL EXPERIENCES AWAIT !        |" << endl;
	cout << "\t\t+------------------------------------------------------------------+" << endl;
	system("pause");
	system("cls");
	
}

void editReservation(ReservationDetails &details)
{

	system("cls");
	cout << "\n" << endl;
    cout << "\t\t------------------------------your contact details------------------------------" << endl;

    cout << "\t\tName: " << details.name << endl;
    cout << "\t\tEmail: " << details.email << endl;
    cout << "\t\tPhone: " << details.phone << endl;

    cout << "\t\t------------------------edit check in and check out-----------------------------" << endl;

    cout << "\t\tCheck-in date (dd/mm/yyyy): ";
    cin >> details.dateIn;
    cout << "\t\tCheck-out date (dd/mm/yyyy): ";
    cin >> details.dateOut;
    cout << "\t\tNumber of days: ";
    cin >> details.days;

    cout << "\t\t------------------------------edit your room type-------------------------------" << endl;
    cout << endl;
	displayRoom();
    // Print table
    
    cout << "\t\tChoose a room : ";
    cin >> details.type;
    
    while(details.type!='A' && details.type!='a' && details.type!='B' && details.type!='b' && details.type!='S' && details.type!='s' && details.type!='V' && details.type!='V')
    {
    	cout << "\t\tInvalid room code. Please refer to the table above for valid room codes."<<endl;
    	cout << "\t\tChoose a room : ";
    	cin >> details.type;
	}
	
   	cout << "\t\tChoose a facility :  ";
    cin >> details.facilities;
    
    while(details.facilities!='A' && details.facilities!='a' && details.facilities!='B' && details.facilities!='b' && details.facilities!='C' && details.facilities!='c' && details.facilities!='D' && details.facilities!='d' )
    {
    	cout << "\t\tInvalid facility code. Please refer to the table above for valid facility codes."<<endl;
    	cout << "\t\tChoose a facility : ";
    	cin >> details.facilities;
	}
	cout << endl;

	cout << "\t\t------------------------------payment method------------------------------" << endl;
    cout << "\t\tChoose your payment method:" << endl;
    cout << "\t\t1. Credit Card" << endl;
    cout << "\t\t2. Cash" << endl;
    cout << endl;
    cout << "\t\tPayment method: ";
    cin >> details.payment;
    while(details.payment!=1 && details.payment!=2 )
    {
    	cout << "\t\tInvalid payment method. Please enter the valid method." ;
    	cin >> details.payment;
	}
    cout << "\t\t-------------------------------------------------------------------------------" << endl;

    cout << "\t\tReservation details updated successfully." << endl;

}

int getValidRating(const string& prompt)
{
	system("cls");
    int rating;
    do
	{
        cout << prompt;
        cin >> rating;

        if (rating < 1 || rating > 5)
		{
            cout << "\t\tInvalid rating. Please enter a number between 1 and 5." << endl;
        }
    }

	while (rating < 1 || rating > 5);

    return rating;
}

// Function to calculate the average rating
double calculateAverageRating(int facilitiesRating, int roomRating)
{
    return static_cast<double>(facilitiesRating + roomRating) / 2.0;
}

// Function to handle the entire feedback process
void handleFeedback()
{
	system("cls");

    char resp,add;
    int facilitiesRating, roomRating;
    string comment;
    cout << "\t\tDo you want to give feedback? (Y/N): ";
    cin >> resp;
	do
	{
    if (resp == 'Y' || resp == 'y')
	{
        facilitiesRating = getValidRating("\t\tRate our facilities from 1-5: ");
        roomRating = getValidRating("\t\tRate our room from 1-5: ");

        cin.ignore();

        cout << "\t\tDo you want to comment anything? (Y/N): ";
        cin >> resp;

        if (resp == 'Y' || resp == 'y')
		{
            cout << "\t\tComment: ";
            cin.ignore();
            getline(cin, comment);
        }

        double averageRating = calculateAverageRating(facilitiesRating, roomRating);

        cout << "\t\tThank you for your feedback!" << endl;
        cout << "\t\tFacilities Rating: " << facilitiesRating << endl;
        cout << "\t\tRoom Rating: " << roomRating << endl;
        cout << "\t\tAverage Rating: " << averageRating << endl;

        if (resp == 'Y' || resp == 'y')
		{
            cout << "\t\tComment: " << comment << endl;
        }

        cout << "\t\tHave a great day!" << endl;

        cout << "\t\tDo you want add more? (Y/N): ";
        cin >> add;
    }

	else if (resp == 'N' || resp == 'n')
	{
        cout << "\t\tI hope you enjoyed your stay here. Have a great day!" << endl;
    }
	else
	{
        cout << "\t\tSorry... You've entered the wrong code." << endl;

		return;
    }
	}while (add =='y'|| add =='Y');

	system("pause");
	system("cls");
	
}

void information()
{
    system("ClS");
    cout << "\n\n\n";
    cout << "\t\t\t===============================================================" << endl;
    cout << "\t\t\t         PLEASE CONTACT US IF YOU HAVE ANY QUESITON            " << endl;
    cout << "\t\t\t---------------------------------------------------------------" << endl;
    cout << "\t\t\t                CONTACT US: 012-3456 7890" << endl;
    cout << "\t\t\t                FACEBOOK: angsanahotelpenang" << endl;
    cout << "\t\t\t                INSTAGRAM: angsanahotelpenang" << endl;
    cout << "\t\t\t                TWITTER: angsanahotelpenang" << endl;
    cout << "\t\t\t      LOCATION: Jalan Teluk Kecewa, 11050 Penang, Malaysia" << endl;
    cout << "\t\t\t---------------------------------------------------------------" << endl;
    cout << "\t\t\t                  " << endl;
    cout << "\t\t\t              HUSNIYA RADHWA CEO OF ANGSANA HOTEL  " << endl;
    cout << "\t\t\t                  " << endl;
    cout << "\t\t\t---------------------------------------------------------------" << endl;
    cout << "\t\t\t    ELEGANCE IN EVERY STAY, EXCEPTIONAL EXPERIENCES AWAIT ! " << endl;
    cout << "\t\t\t===============================================================" << endl;
    system("pause");
    system("CLS");
}
