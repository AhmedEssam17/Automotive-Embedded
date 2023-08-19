/*
 *
 *  Created on: Aug 12, 2023
 *  Author: Ahmed Essam
 *
 */

#include "bus.h"

void addSeatChart(Bus_t* BusX){
	strcpy(BusX->seatChart[0], "-");
	strcpy(BusX->seatChart[1], "-");
	strcpy(BusX->seatChart[2], "1");
	strcpy(BusX->seatChart[3], "X");
	strcpy(BusX->seatChart[4], "3");
	strcpy(BusX->seatChart[5], "4");
	strcpy(BusX->seatChart[6], "5");
	strcpy(BusX->seatChart[7], "X");
	strcpy(BusX->seatChart[8], "7");
	strcpy(BusX->seatChart[9], "X");
	strcpy(BusX->seatChart[10], "X");
	strcpy(BusX->seatChart[11], "X");
	strcpy(BusX->seatChart[12], "11");
	strcpy(BusX->seatChart[13], "X");
	strcpy(BusX->seatChart[14], "X");

	BusX->availableSeats = (uint8_t)6;
}

void CheckCredentialsTest(char* email, char* password, int result){

	int test = CheckCredentials(email, password);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}
}

void CheckAvailableBusTest(Bus_t* BusArr[], int numOfBuses, int result){

	int test = CheckAvailableBus(BusArr, numOfBuses);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}
}

void SelectBusTest(Bus_t* BusArr[], int numOfBuses, int busNum, int* checkBusFlag, Bus_t* result){

	Bus_t* test = SelectBus(BusArr, numOfBuses, busNum, &checkBusFlag);;

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}

}

void SelectSeatTest(Bus_t* BusX, int seatNum, int numOfSeats, int result){

	int test = SelectSeat(BusX, seatNum, numOfSeats);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}

}

void AddPromoCodeTest(char* promoCode, int* originalPrice, int* newPrice, int result){

	int test = AddPromoCode(promoCode, &originalPrice, &newPrice);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}

}

void ViewPendingReservationTest(User_t* user, int result){

	int test = ViewPendingReservation(user);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}

}

void CancelReservationTest(User_t* user, int tripID, int result){

	int test = CancelReservation(user, tripID);

	if(test == result){
		printf("Success\n");
	}
	else{
		printf("Failed\n");
	}

}


int main(){

	int reservationCount = 0;
	int numOfBuses = 3;
	int numOfSeats = 15;
	int reserveBusNum = 0;
	int reserveSeatNum = 0;
	int closeApp = 0;
	Bus_t* selectedBus = NULL;

	Bus_t* Bus1 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus1->busNum = 125;
	Bus1->price = 350;
	strcpy(Bus1->destination, "Dahab");
	strcpy(Bus1->movingTime, "12:00AM");
	addSeatChart(Bus1);

	Bus_t* Bus2 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus2->busNum = 750;
	Bus2->price = 300;
	strcpy(Bus2->destination, "Sahel");
	strcpy(Bus2->movingTime, "7:00AM");
	addSeatChart(Bus2);

	Bus_t* Bus3 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus3->busNum = 500;
	Bus3->price = 350;
	strcpy(Bus3->destination, "Sokhna");
	strcpy(Bus3->movingTime, "10:00PM");
	addSeatChart(Bus3);

	Bus_t* BusArr[] = {Bus1, Bus2, Bus3};

	printf("=====================================\n");
	printf("Welcome to Our Bus Reservation System\n");
	printf("=====================================\n\n");

	char email[20];
	char password[20];

	printf("Please Enter Your Login Credentials\n");
	printf("Email: ");
	fflush(stdout);
	scanf("%s", email);
	fflush(stdin);
	printf("Password: ");
	fflush(stdout);
	scanf("%s", password);
	fflush(stdin);


	while(CheckCredentials(email, password) == 0){
		printf("\nINVALID Entered Credentials\n");
		printf("\nPlease Re-Enter Your Login Credentials\n");
		printf("Email: ");
		fflush(stdout);
		scanf("%s", email);
		fflush(stdin);
		printf("Password: ");
		fflush(stdout);
		scanf("%s", password);
		fflush(stdin);
	}

	printf("Successfully Logged In\n\n");

	User_t* user = (User_t*)malloc(sizeof(User_t));
	user->reservationCount = 0;

	int option = -1;

	while(closeApp != 1){
		printf("------------------------------\n");
		printf("Choose an Option:\n");
		printf("1) Book a Trip\n");
		printf("2) Cancel a Trip\n");
		printf(">>> or 0 to EXIT <<<\n\n");
		printf("Option: ");
		fflush(stdout);
		scanf("%d", &option);
		fflush(stdin);

		switch(option){
		case 0:
			printf(">>>>>>>>>>Good Bye<<<<<<<<<\n");
			fflush(stdout);
			closeApp = 1;
			break;
		case 1:
			if(user->reservationCount == 3){
				printf(">>You reached maximum pending reservations<<\n");
				break;
			}
			printf("Checking Available Buses...\n");
			if(!CheckAvailableBus(BusArr, numOfBuses)){
				printf(">>There is NO Available Bus right now<<\n");
				break;
			}

			printf("\nEnter Bus Number required to Reserve\n");
			printf("Bus Number: ");
			fflush(stdout);
			scanf("%d", &reserveBusNum);
			fflush(stdin);

			int checkBusFlag = 0;
			selectedBus = SelectBus(BusArr, numOfBuses, reserveBusNum, &checkBusFlag);

			while(checkBusFlag == 0){
				printf("\nINVALID Entered Bus Number\n");
				printf("\nPlease Re-Enter Bus Number\n");
				printf("Bus Number: ");
				fflush(stdout);
				scanf("%d", &reserveBusNum);
				fflush(stdin);
				selectedBus = SelectBus(BusArr, numOfBuses, reserveBusNum, &checkBusFlag);
			}

			printf("\nSeat Number: ");
			fflush(stdout);
			scanf("%d", &reserveSeatNum);
			fflush(stdin);

			int checkSeatFlag = 0;
			while(SelectSeat(selectedBus, reserveSeatNum, numOfSeats) == 0){
				printf("\nINVALID Entered Seat Number\n");
				printf("\nPlease Re-Enter Seat Number\n");
				printf("Seat Number: ");
				fflush(stdout);
				scanf("%d", &reserveSeatNum);
				fflush(stdin);
			}

			int promoFlag = 0;
			char promoCode[10];
			int originalPrice = selectedBus->price;
			int newPrice = originalPrice;

			printf("Have a Promo Code ?\n");
			printf("Enter 1 if yes or 0 if no: ");
			fflush(stdout);
			scanf("%d", &promoFlag);
			fflush(stdin);
			if(promoFlag){
				printf("\nPromoCode: ");
				fflush(stdout);
				scanf("%s", &promoCode);
				while(AddPromoCode(promoCode, &originalPrice, &newPrice) == 0){
					printf("\nINVALID Entered Promo Code\n");
					printf("\nPlease Re-Enter Promo Code\n");
					printf("\nPromoCode: ");
					fflush(stdout);
					scanf("%s", &promoCode);
				}
			}

			Reservation_t* reservation = (Reservation_t*)malloc(sizeof(Reservation_t));

			reservation->bus = selectedBus;
			reservation->finalPrice = newPrice;
			reservation->seatNum = reserveSeatNum;

			if(ConfirmReservation(reservation) == 1){
				srand(time(NULL));
				reservation->tripID = rand() % 9000 + 1000;
				strcpy(selectedBus->seatChart[reserveSeatNum + 1], "X");
				user->reservation[user->reservationCount] = reservation;
				user->reservationCount++;
				printf("Your Trip ID = #%d\n", reservation->tripID);
			}
			break;
		case 2:
			printf("Checking Pending Reservations...\n");
			if(ViewPendingReservation(user)){
				int trip = 0;
				printf("\nEnter Trip ID you want to cancel: ");
				fflush(stdout);
				scanf("%d", &trip);
				fflush(stdin);

				while(CancelReservation(user, trip) == 0){
					printf("\nINVALID Entered Trip ID\n");
					printf("\nPlease Re-Enter Trip ID\n");
					printf("\Trip ID: ");
					fflush(stdout);
					scanf("%s", &trip);
					fflush(stdin);
				}
			}
			break;
		default:
			printf("INVALID Option Entered, Please re-enter a valid Option\n");
		}
	}

	/*
	int reservationCount = 0;
	int numOfBuses = 3;
	int numOfSeats = 15;
	int reserveBusNum = 0;
	int reserveSeatNum = 0;
	int closeApp = 0;
	int checkBusFlag = 0;
	Bus_t* selectedBus = NULL;

	Bus_t* FullBus1 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus_t* FullBus2 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus_t* FullBus3 = (Bus_t*)malloc(sizeof(Bus_t));
	FullBus1->availableSeats = 0;
	FullBus2->availableSeats = 0;
	FullBus3->availableSeats = 0;
	Bus_t* FullBusArr[] = {FullBus1, FullBus2, FullBus3};

	int originalPrice = 0;
	int newPrice = 0;

	Bus_t* Bus1 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus1->busNum = 125;
	Bus1->price = 350;
	strcpy(Bus1->destination, "Dahab");
	strcpy(Bus1->movingTime, "12:00AM");
	addSeatChart(Bus1);

	Bus_t* Bus2 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus2->busNum = 750;
	Bus2->price = 300;
	strcpy(Bus2->destination, "Sahel");
	strcpy(Bus2->movingTime, "7:00AM");
	addSeatChart(Bus2);

	Bus_t* Bus3 = (Bus_t*)malloc(sizeof(Bus_t));
	Bus3->busNum = 500;
	Bus3->price = 350;
	strcpy(Bus3->destination, "Sokhna");
	strcpy(Bus3->movingTime, "10:00PM");
	addSeatChart(Bus3);

	Bus_t* BusArr[] = {Bus1, Bus2, Bus3};

	User_t* user1 = (User_t*)malloc(sizeof(User_t));
	user1->reservationCount = 0;
	User_t* user2 = (User_t*)malloc(sizeof(User_t));
	user2->reservationCount = 1;

	Reservation_t* reservation = (Reservation_t*)malloc(sizeof(Reservation_t));
	reservation->tripID = 1234;
	reservation->bus = Bus1;
	reservation->finalPrice = 300;
	reservation->seatNum = 7;

	User_t* user = (User_t*)malloc(sizeof(User_t));
	user->reservationCount = 0;
	user->reservation[user->reservationCount] = reservation;
	user->reservationCount++;


	printf("\nTesting CheckCredentials()...\n");
	printf("Test Case 1: (Invalid Email & Inalid Password) >>> ");
	CheckCredentialsTest("user@gmail", "user12", 0);
	printf("Test Case 2: (Invalid Email & Valid Password) >>> ");
	CheckCredentialsTest("user@gmail", "user1234", 0);
	printf("Test Case 3: (Valid Email & Invalid Password) >>> ");
	CheckCredentialsTest("user@gmail.com", "user12", 0);
	printf("Test Case 4: (Valid Email & Valid Password) >>> ");
	CheckCredentialsTest("user@gmail.com", "user1234", 1);

	printf("\n");

	printf("Testing CheckAvailableBus()...\n");
	printf("Test Case 1: (No Available Buses) >>> ");
	CheckAvailableBusTest(FullBusArr, numOfBuses, 0);
	printf("Test Case 2: (There are Available Buses) >>> ");
	CheckAvailableBusTest(BusArr, numOfBuses, 1);

	printf("\n");

	printf("Testing SelectBus()...\n");
	printf("Test Case 1: (Entering Invalid Bus Number) >>> ");
	SelectBusTest(BusArr, numOfBuses, 1, &checkBusFlag, NULL);
	printf("Test Case 2: (Entering Valid Bus Number) >>> ");
	SelectBusTest(BusArr, numOfBuses, 125, &checkBusFlag, Bus1);

	printf("\n");

	printf("Testing SelectSeat()...\n");
	printf("Test Case 1: (Entering Invalid Seat Number) >>> ");
	SelectSeatTest(Bus1, 8, numOfSeats, 0);
	printf("Test Case 2: (Entering Valid Seat Number) >>> ");
	SelectSeatTest(Bus1, 7, numOfSeats, 1);

	printf("\n");

	printf("Testing AddPromoCode()...\n");
	printf("Test Case 1: (Entering Invalid Promo Code) >>> ");
	AddPromoCodeTest("XYZ123", &originalPrice, &newPrice, 0);
	printf("Test Case 2: (Entering Valid Promo Code) >>> ");
	AddPromoCodeTest("ABC123", &originalPrice, &newPrice, 1);

	printf("\n");

	printf("Testing ViewPendingReservation()...\n");
	printf("Test Case 1: (User has pending reservations) >>> ");
	ViewPendingReservationTest(user1, 0);
	printf("Test Case 2: (User has pending reservations) >>> ");
	ViewPendingReservationTest(user2, 1);

	printf("\n");

	printf("Testing CancelReservation()...\n");
	printf("Test Case 1: (Entering Invalid Trip ID) >>> ");
	CancelReservationTest(user, 1111, 0);
	printf("Test Case 2: (Entering Valid Trip ID) >>> ");
	CancelReservationTest(user, 1234, 1);
	*/
	return 0;
}


