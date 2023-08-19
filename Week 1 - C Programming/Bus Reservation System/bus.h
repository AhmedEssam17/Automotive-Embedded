/*
 * bus.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Lenovo
 */

#ifndef BUS_H_
#define BUS_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"



//====================================================================
//						Configuration Structure
//====================================================================

typedef struct{
	uint32_t 	busNum;
	uint8_t 	destination[10];
	uint8_t		seatChart[15][3];
	uint8_t		movingTime[7];
	uint32_t	price;
	uint8_t		availableSeats;
}Bus_t;


typedef struct{
	uint32_t 	tripID;
	Bus_t* 		bus;
	uint32_t	finalPrice;
	uint32_t	seatNum;
}Reservation_t;

typedef struct{
	Reservation_t* 	reservation[3];
	uint32_t		reservationCount;
}User_t;


//====================================================================
//					APIs Prototype Definition
//====================================================================

//-----------------------------
// Login Functionality
//-----------------------------
int CheckCredentials(char* email, char* password);

//-----------------------------
// Buy Ticket Functionality
//-----------------------------
int CheckAvailableBus(Bus_t* BusArr[], int numOfBuses);
Bus_t* SelectBus(Bus_t* BusArr[], int numOfBuses, int busNum, int* checkBusFlag);
int SelectSeat(Bus_t* BusX, int seatNum, int numOfSeats);
int AddPromoCode(char* promoCode, int* originalPrice, int* newPrice);
int ConfirmReservation(Reservation_t* ReservationX);

//-----------------------------
// Cancel Ticket Functionality
//-----------------------------
int ViewPendingReservation(User_t* user);
int CancelReservation(User_t* user, int tripID);


#endif /* BUS_H_ */
