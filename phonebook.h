/********************************************************************************************************************
 * File Name   : phonebook.h
 * Version     : 1.0
 * Description : This file includes C library functions, Global variable, Macro definitions, Structure and Function 
 		         declarations.
*********************************************************************************************************************
Author                  Date
---------------------------------------------------------------------------------------------------------------------
AKHIL K A               23-03-2023
********************************************************************************************************************/
/********************************************************************************************************************
* Includes <System Includes> , "Project Includes"
 ********************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/********************************************************************************************************************
* Variable Decleration
********************************************************************************************************************/
int giFlag= 0; // global variable
/*******************************************************************************************************************
* Macro Definition
/*******************************************************************************************************************/
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define RUN                  1
#define VIEW_ALLCONTACTS     1
#define ADD_ACONTACT         2
#define SEARCH_ACONTACT      3
#define REMOVE_ACONTACT      4
#define UPDATE_ACONTACT      5
#define REMOVE_WHOLECONTACTS 6
#define SIZE                 100
/********************************************************************************************************************
Structure Decleration : Defining phonebook data type.
********************************************************************************************************************/
typedef struct 
{
    char cName[SIZE];
    char cCountryCode[SIZE];
    long int lMobileNumber;
    char cSex[SIZE];
    char cMailId[SIZE];
} Sphonebook;

Sphonebook p;
/********************************************************************************************************************
 All function Declrations
 *******************************************************************************************************************/

void removeWholeContacts();
void viewAllPhonebookOptions();
void addAContact();
void viewAllContacts();
void searchAContact();
void removeAContact();
void updateAContact();
void insertContactDetails();
void start();

/*******************************************************************************************************************/
#endif // PHONEBOOK_H
