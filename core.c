/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Victor Ramos
Student ID#: 127468221
Email      : vade-lima-ramos@mysenca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////
// Return a valid whole number

int inputInt(void)
{
    int valueInt;
    int isNotValid = 1;
    char newLine = '\0';
    do
    {
        scanf("%d%c", &valueInt, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            isNotValid = 0;
        }
    } while (isNotValid);
    return valueInt;
}

// Returns and valid positive whole number
int inputIntPositive(void)
{
    int isNotValid = 1;
    int positiveInt;

    do
    {
        positiveInt = inputInt();

        if (positiveInt < 1)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            isNotValid = 0;
        }

    } while (isNotValid);

    return positiveInt;
}

// Returns a valid whole numbe within the accepteble range
int inputIntRange(int lowerNum, int higherNum)
{
    int inputNum;
    int isNotValid = 1;
    int lowNumRange = lowerNum;
    int highNumRange = higherNum;

    do
    {
        inputNum = inputInt();

        if (inputNum < lowNumRange || inputNum > highNumRange)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerNum, higherNum);
        }
        else
        {
            isNotValid = 0;
        }
    } while (isNotValid);

    return inputNum;
}

// Returns a valid single character input by the user
char inputCharOption(const char arrValidChar[])
{
    int isNotVlalid = 1;
    char inputChar[MAX_ELEM + 1] = {0};
    char correctChar;
    char *validChar = NULL;

    do
    {
        scanf("%s", inputChar);
        clearInputBuffer();

        correctChar = inputChar[0];

        if (inputChar[1] == '\0')
        {
            validChar = strchr(inputChar, correctChar);
        }
        if (validChar == NULL)
        {
            printf("ERROR: Character must be one of [%s]: ", arrValidChar);
        }
        else
        {
            isNotVlalid = 0;
        }

    } while (isNotVlalid);

    return correctChar;
}

// Stores a valid string array that is in the range
void inputCString(char arrCString[], int minValid, int maxVlaid)
{
    int isNotValid = 1;
    // int i;
    int stringLength = 0;
    char inputArr[MAX_ELEM + 1] = {0};

    do
    {

        scanf("%999[^\n]", inputArr);
        clearInputBuffer();

        stringLength = strlen(inputArr);

        if (stringLength > maxVlaid || stringLength < minValid)
        {
            if (maxVlaid == minValid)
            {
                printf("ERROR: String length must be exactly %d chars: ", maxVlaid);
            }
            else if (stringLength > maxVlaid)
            {
                printf("ERROR: String length must be no more than %d chars: ", maxVlaid);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", minValid, maxVlaid);
            }
        }
        else
        {
            strcpy(arrCString, inputArr);
            isNotValid = 0;
        }

    } while (isNotValid);
}

// Validates a numuber string length
void inputNumString(char arrString[], int vaidLength)
{
    int isNotValid = 1;
    int stringLength = 0;
    char inputArr[MAX_ELEM + 1] = {0};

    do
    {

        scanf("%999[^\n]", inputArr);
        clearInputBuffer();

        stringLength = strlen(inputArr);

        if (stringLength != vaidLength)
        {
            printf("Invalid %d-digit number! Number: ", vaidLength);
        }

        else
        {
            strcpy(arrString, inputArr);
            isNotValid = 0;
        }

    } while (isNotValid);
}

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
void displayFormattedPhone(const char arrCellDigits[])
{

    int stringLengnth, i;

    if (arrCellDigits != NULL)
    {
        stringLengnth = 0;

        for (i = 0; arrCellDigits[i] != '\0'; i++)
        {

            if (arrCellDigits[i] >= '0' && arrCellDigits[i] <= '9')
            {
                stringLengnth++;
            }
        }

        if (stringLengnth != 10)
        {
            printf("(___)___-____");
        }
        else
        {
            for (i = 0; arrCellDigits[i] != '\0'; i++)
            {
                if (i == 0)
                {
                    putchar('(');
                }
                else if (i == 3)
                {
                    putchar(')');
                }
                else if (i == 6)
                {
                    putchar('-');
                }

                printf("%c", arrCellDigits[i]);
            }
        }
    }
    else
    {
        printf("(___)___-____");
    }
}