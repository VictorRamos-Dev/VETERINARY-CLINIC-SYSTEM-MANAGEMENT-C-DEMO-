/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Victor Ramos
Student ID#: 127468221
Email      : vade-lima-ramos@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #2 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// 7 Stores a valid string array that is in the range
void inputCString(char arrCString[], int minValid, int maxVlaid);

// 8 Validates a numuber string length
void inputNumString(char arrString[], int vaidLength);

// 9 Displays a Vlaid formated cellphone number
void displayFormattedPhone(const char arrCellDigits[]);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

#define MAX_ELEM 1000

// 1 Clear the standard input buffer
void clearInputBuffer(void);

// 2 Wait for user to input the "enter" key to continue
void suspend(void);

// 3 Return a valid whole number
int inputInt(void);

// 4 Returns and valid positive whole number
int inputIntPositive(void);

// 5 Returns a valid whole numbe within the accepteble range
int inputIntRange(int lowerNum, int higherNum);

// 6 Returns a valid single character input by the user
char inputCharOption(const char arrValidChar[]);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
