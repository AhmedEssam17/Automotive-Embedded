/*
 * bus.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Lenovo
 */

#include "bus.h"


/**================================================================
 * @Fn				-CheckCredentials
 * @brief 			-Checks Validity of the Entered Email and Password
 * @param [in]	 	-Email
 * @param [in]	 	-Password
 * @retval 			-1 for Success, 0 for Failure
 * Requirements		-If User has entered the correct email and password, he will be navigated
 * 					 to the main screen
 * 					-If User has entered an incorrect email or password, he will be asked
 * 					 to enter the correct credentials again
 */
int CheckCredentials(char* email, char* password){

	char validEmail[] = "user@gmail.com";
	char validPassword[] = "user1234";

	if(strcmp(email, validEmail) == 0 && strcmp(password, validPassword) == 0)
		return 1;
	else
		return 0;
}


/**================================================================
 * @Fn				-CheckAvailableBus
 * @brief 			-Checks Available Bus Trips Offered by the System
 * @param [in]	 	-BusArr
 * @param [in]	 	-numOfBuses
 * @retval 			-NONE
 * Requirements		-If There are available buses with empty seats, all their details will be
 * 					 displayed to the user
					-If No current buses available to be reserved, A message will be displayed
					 to the user regarding unavailability of buses right now
 */
int CheckAvailableBus(Bus_t* BusArr[], int numOfBuses){
	int availableBus = 0;
	for(int i = 0; i < numOfBuses; i++){
		if(BusArr[i]->availableSeats > 0){
			availableBus = 1;
			printf("-----------------------------\n");
			printf("Bus Number: %d\n", BusArr[i]->busNum);
			printf("Destination: %s\n", BusArr[i]->destination);
			printf("Moving Time: %s\n", BusArr[i]->movingTime);
			printf("Number of Available Seats: %d\n", BusArr[i]->availableSeats);
			printf("Price: %d\n", BusArr[i]->price);
		}
	}
	printf("-----------------------------\n");
	return availableBus;
}


/**================================================================
 * @Fn				-SelectBus
 * @brief 			-User chooses the desired trip from the offered Bus Trips
 * @param [in]	 	-BusArr
 * @param [in]	 	-numOfBuses
 * @param [in]	 	-busNum
 * @param [in]	 	-checkBusFlag
 * @retval 			-Bus_t*
 * Requirements		-If User enters an available bus number, he will proceed to the SelectSeat phase
 * 					-If User enters an unavailable bus number, he will be asked to re-enter a valid
 * 					 bus number from the displayed bus details
 */
Bus_t* SelectBus(Bus_t* BusArr[], int numOfBuses, int busNum, int* checkBusFlag){
	for(int i = 0; i < numOfBuses; i++){
		if(BusArr[i]->busNum == busNum){
			printf("\nChoose a Seat from the following Seat Chart: \n");
			for (int row = 0; row < 5; row++) {
				for (int col = 0; col < 3; col++) {
					int index = col + row * 3; // Convert 2D index to 1D index
					printf("%s  ", BusArr[i]->seatChart[index]);
				}
				printf("\n");
			}
			*checkBusFlag = 1;
			return BusArr[i];
		}
	}
	return NULL;
}


/**================================================================
 * @Fn				-SelectSeat
 * @brief 			-User selects the desired seat from the available seats displayed
 * @param [in]	 	-BusX
 * @param [in]	 	-seatNum
 * @param [in]	 	-numOfSeats
 * @retval 			-1 for success, 0 for failed
 * Requirements		-If User enters an available seat number, he will proceed to the AddPromoCode phase
 * 					-If User enters an unavailable seat number, he will be asked to re-enter a valid
 * 					 seat number from the displayed seats chart
 */
int SelectSeat(Bus_t* BusX, int seatNum, int numOfSeats){

	char numStr[3];
	sprintf(numStr, "%d", seatNum);

	for(int i = 0; i < numOfSeats; i++){
		if(strcmp(BusX->seatChart[i], numStr) == 0) {
			return 1;
		}
	}
	return 0;
}


/**================================================================
 * @Fn				-AddPromoCode
 * @brief 			-User will be asked to enter a promoCode (if available) to get a discount
 * @param [in]	 	-promoCode
 * @param [in]	 	-originalPrice
 * @param [in]	 	-newPrice
 * @retval 			-1 for success, 0 for failed
 * Requirements		-If User enters an available promoCode, he will get a discount on his reservation price
 * 					-If User enters an unavailable promoCode, he will be asked to re-enter a valid promoCode
 * 					 or to proceed without entering one
 */
int AddPromoCode(char* promoCode, int* originalPrice, int* newPrice){
	char promo[]= "ABC123";

	for(int i = 0; i < 2; i++){
		if(strcmp(promoCode, promo) == 0){
			*newPrice = *originalPrice / 2;
			printf("New Trip Price = %d", *newPrice);
			return 1;
		}
	}
	return 0;
}


/**================================================================
 * @Fn				-ConfirmReservation
 * @brief 			-All ride details will be displayed for the user to confirm it
 * @param [in]	 	-ReservationX
 * @retval 			-1 for success, 0 for failed
 * Requirements		-If User enters 1 to confirm the reservation, Reservation is completed
 * 					 and saved in the pending reservations.
 * 					-If User enters 0 to decline to the reservation, Reservation is declined,
 * 					 nothing will be saved and the user will be navigated to the main screen
 */
int ConfirmReservation(Reservation_t* ReservationX){
	printf("\n----------------------------\n");
	printf("-----Final Trip Details-----\n");
	printf("----------------------------\n");
	printf("Bus Number: %d\n",ReservationX->bus->busNum);
	printf("Destination: %s\n", ReservationX->bus->destination);
	printf("Moving Time: %s\n", ReservationX->bus->movingTime);
	printf("Seat Number: %d\n", ReservationX->seatNum);
	printf("Price: %d\n", ReservationX->finalPrice);
	printf("----------------------------\n");

	int confirm = 0;
	printf("\nEnter 1 to confirm Reservation or 0 to decline: ");
	fflush(stdout);
	scanf("%d", &confirm);

	if(confirm)
		return 1;
	else
		return 0;
}


/**================================================================
 * @Fn				-ViewPendingReservation
 * @brief 			-Pending Trips IDs will be displayed to the user to select one to cancel
 * @param [in]	 	-user
 * @retval 			-1 for success, 0 for failed
 * Requirements		-If User already has pending trips, Trip details with its tripID will be displayed
 * 					-IfUser hasn't reserved a trip before, A message concerning "No Pending Trips" will
 * 					 be displayed instead
 */
int ViewPendingReservation(User_t* user){

	if(user->reservationCount){
		for(int i = 0; i < user->reservationCount; i++){
			printf("\n----------------------------\n");
			printf("Trip ID: #%d\n", user->reservation[i]->tripID);
			printf("Bus Number: %d\n", user->reservation[i]->bus->busNum);
			printf("Destination: %s\n", user->reservation[i]->bus->destination);
			printf("Moving Time: %s\n", user->reservation[i]->bus->movingTime);
			printf("Seat Number: %d\n", user->reservation[i]->seatNum);
			printf("Price: %d\n", user->reservation[i]->finalPrice);
		}
		//printf("-----------------------------\n");
		return 1;
	}
	else{
		printf("\nThere is NO Pending Reservations\n");
		return 0;
	}
}


/**================================================================
 * @Fn				-CancelReservation
 * @brief 			-User will get to choose a tripID to cancel their reservation
 * @param [in]	 	-user
 * @param [in]	 	-tripID
 * @retval 			-1 for success, 0 for failed
 * Requirements		-If User entered a valid tripID, Reservation will be canceled successfully
 * 					-If User entered an invalid tripID, he will be asked to re-enter a valid
 * 					 tripID from the displayed pending reservations
 */
int CancelReservation(User_t* user, int tripID){

	int foundFlag = 0;
	for(int i = 0; i < user->reservationCount; i++){
		if(tripID == user->reservation[i]->tripID){
			foundFlag = 1;
			char seat[3];
			sprintf(seat, "%d", user->reservation[i]->seatNum);
			strcpy(user->reservation[i]->bus->seatChart[user->reservation[i]->seatNum + 1], seat);
			for(int j = i; j < user->reservationCount - 1; j++){
				user->reservation[j] = user->reservation[j+1];
			}
			user->reservationCount--;
			printf("\n>>Reservation Canceled Successfully<<\n\n");
		}
	}

	if(!foundFlag){
		return 0;
	}

	return 1;
}



