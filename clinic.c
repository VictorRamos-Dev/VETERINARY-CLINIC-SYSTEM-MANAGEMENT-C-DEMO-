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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient, const struct Appointment *appoint, int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int len = max;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();

        for (i = 0; i < len; i++)
        {
            if (patient[i].patientNumber != 0)
            {
                displayPatientData(&patient[i], fmt);
            }
        }
    }
    else
    {
        putchar('\n');
        printf("*** No records found ***");
    }
    putchar('\n');
}
// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int searchOption;
    int done = 0;
    do
    {

        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        searchOption = inputIntRange(0, 2);
        putchar('\n');
        switch (searchOption)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            break;

        case 2:
            searchPatientByPhoneNumber(patient, max);
            break;

        default:
            done = 1;
            break;
        }

    } while (!done);
}
// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int isNotVlaid = 1;

    for (i = 0; isNotVlaid && i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {

            patient[i].patientNumber = nextPatientNumber(patient, max);
            inputPatient(&patient[i]);
            puts("*** New patient record added ***");
            isNotVlaid = 0;
        }
    }
    if (isNotVlaid != 0)
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    putchar('\n');
}
// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int inputNum;
    int result;

    printf("Enter the patient number: ");
    inputNum = inputIntPositive();
    putchar('\n');
    result = findPatientIndexByPatientNum(inputNum, patient, max);

    result != -1 ? menuPatientEdit(&patient[result]) : puts("ERROR: Patient record not found!");
}
// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int inputNum;
    int result;
    char userSelect;

    printf("Enter the patient number: ");
    inputNum = inputIntPositive();
    putchar('\n');

    result = findPatientIndexByPatientNum(inputNum, patient, max);

    if (result != -1)
    {
        displayPatientData(&patient[result], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        userSelect = inputCharOption("yn");

        if (userSelect == 'y')
        {
            patient[result].patientNumber = '\0';
            puts("Patient record has been removed!\n");
        }
        else
        {
            puts("Operation aborted.\n");
        }
    }
    else
    {
        puts("ERROR: Patient record not found!\n");
    }
}
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int i, j;

    if (data->appointments->patientNumber != 0)
    {
        displayScheduleTableHeader(&data->appointments->date, 1);
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->patients[j].patientNumber && data->appointments[i].patientNumber)
                {
                    if (data->patients[j].patientNumber == data->appointments[i].patientNumber)
                    {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                    }
                }
            }
        }
    }
    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    struct Date dates = {0};

    int i, j, notValid = 1;

    dateValidation(&dates);

    putchar('\n');

    displayScheduleTableHeader(&dates, 0);

    for (i = 0; i < data->maxAppointments; i++)
    {
        if (dates.day == data->appointments[i].date.day &&
            dates.month == data->appointments[i].date.month &&
            dates.year == data->appointments[i].date.year)
        {
            for (j = 0; j < data->maxAppointments; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    notValid = 0;
                }
            }
        }
    }
    if (notValid != 0)
    {
        printf("Schedule not Found!\n");
    }
    putchar('\n');
}
// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *appt, int maxAppnt, struct Patient *ptn, int maxPatn)
{
    struct Date dates;
    struct Time times = {0};

    int invalid = 1;
    int skipDate = 1;
    int allAppointmensDay = 0;
    int nextApptIndex;
    int notFull, patiantNumber, indexPaintiant;

    nextApptIndex = indexFollowingApp(appt, maxAppnt);

    if (nextApptIndex != -1)
    {
        printf("Patient Number: ");
        patiantNumber = inputIntPositive();

        indexPaintiant = findPatientIndexByPatientNum(patiantNumber, ptn, maxPatn);

        if (indexPaintiant != -1)
        {
            do
            {
                if (skipDate)
                {
                    dateValidation(&dates);
                }

                validTime(&times);

                notFull = timeSlotValidation(appt, dates, times, maxPatn); //// FIX ME

                allAppointmensDay = dailyApptCount(dates, appt, maxAppnt);

                if (!(notFull) || allAppointmensDay == MAX_DAILY_APPOINTS)
                {
                    printf("\n");

                    if (!(notFull))
                    {
                        printf("ERROR: Appointment timeslot is not available!\n\n");
                    }
                    else if (allAppointmensDay == MAX_DAILY_APPOINTS)
                    {
                        printf("***Time availabilaty is FULL***\n\n");
                    }
                }
                else
                {
                    if ((times.hour < OPENING_HOUR || times.hour > CLOSING_HOUR) || (times.hour == CLOSING_HOUR && times.min > 0) || (times.min % INTRELVAL_APPOINT != 0))
                    {
                        printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", OPENING_HOUR, CLOSING_HOUR, INTRELVAL_APPOINT);
                    }
                    else
                    {
                        invalid = 0;
                    }

                    skipDate = 0;
                }
            } while (invalid);

            printf("\n");

            appt[nextApptIndex].date = dates;
            appt[nextApptIndex].time = times;
            appt[nextApptIndex].patientNumber = ptn[indexPaintiant].patientNumber;

            printf("*** Appointment scheduled! ***\n\n");

            sort(appt, maxAppnt);
        }
        else
        {
            printf("ERROR: Paitient record not found!\n\n");
        }
    }
    else
    {
        printf("ERROR: Appointment listing is FULL!\n");
    };
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *appt, int maxAppnt, struct Patient *ptn, int maxAppoint)
{
    struct Date dates = {0};

    int indexAppoint = -1;
    int numberPaitien, indexPaitient;
    char pullOut;

    printf("Patient Number: ");
    numberPaitien = inputIntPositive();

    indexPaitient = findPatientIndexByPatientNum(numberPaitien, ptn, maxAppoint);

    if (indexPaitient != -1)
    {
        dateValidation(&dates);

        indexAppoint = appointmentSearch(dates, appt, numberPaitien, maxAppoint);

        if (indexAppoint < 0)
        {
            printf("ERROR: Patient record not found!\n\n");
        }
        else
        {
            printf("\n");
            displayPatientData(&ptn[indexPaitient], FMT_FORM);

            printf("Are you sure you want to remove this appointment (y,n): ");
            pullOut = inputCharOption("yn");

            printf("\n");

            if (pullOut == 'y')
            {
                appt[indexAppoint].patientNumber = 0;
                appt[indexAppoint].date.year = 0;
                appt[indexAppoint].date.month = 0;
                appt[indexAppoint].date.day = 0;
                appt[indexAppoint].time.hour = 0;
                appt[indexAppoint].time.min = 0;

                printf("Appointment record has been removed!\n");
            }
            else
            {
                printf("Operation aborted.\n");
            }
            putchar('\n');
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int inputNum, result;

    printf("Search by patient number: ");
    inputNum = inputIntPositive();
    putchar('\n');

    result = findPatientIndexByPatientNum(inputNum, patient, max);

    result != -1 ? displayPatientData(&patient[result], FMT_FORM) : puts("*** No records found ***");

    printf("\n");
    suspend();
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int numFound = 0;
    int count = 0;
    char inputPhoneNum[PHONE_LEN + 1] = {'\0'};

    printf("Search by phone number: ");
    inputCString(inputPhoneNum, PHONE_LEN, PHONE_LEN);
    putchar('\n');
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        numFound = strcmp(patient[i].phone.number, inputPhoneNum);

        if (numFound == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++;
        }
    }
    if (count == 0)
    {
        putchar('\n');
        puts("*** No records found ***");
    }
    printf("\n");
    suspend();
}
// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i;
    int maxNum;
    int nextNum;
    maxNum = patient[0].patientNumber;

    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber > maxNum)
        {
            maxNum = patient[i].patientNumber;
        }
    }
    nextNum = maxNum + 1;
    return nextNum;
}
// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    int index = -1;

    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber && patient[i].patientNumber != 0)
        {
            index = i;
        }
    }
    return index;
}

// sort an array of Appointment structs in ascending order
void sort(struct Appointment appoints[], int maxSize)
{

    int i, j, indexMin;
    struct Appointment temp;
    long long date1, date2;

    for (i = 0; i < maxSize; i++)
    {
        if (appoints[i].patientNumber > 0)
        {
            indexMin = i;

            for (j = i + 1; j < maxSize; j++)
            {
                if (appoints[j].patientNumber > 0)
                {
                    date1 = wholeNum(&appoints[j]);
                    date2 = wholeNum(&appoints[indexMin]);
                    if (date1 < date2)
                    {
                        indexMin = j;
                    }
                }
            }

            if (indexMin != i)
            {
                temp = appoints[i];
                appoints[i] = appoints[indexMin];
                appoints[indexMin] = temp;
            }
        }
    }
}

// Convert date, month, day, hour and time into a whhole number.
long long wholeNum(struct Appointment *appoints)
{
    long long date;

    date = ((appoints->date.year * 100000000) +
            (appoints->date.month * 1000000) +
            (appoints->date.day * 10000) +
            (appoints->time.hour * 100) +
            (appoints->time.min));

    return date;
}

// Returs a positive integer if time slot is not full
int timeSlotValidation(struct Appointment appointments[], const struct Date date, const struct Time time, int maxApp)
{
    int notAvailable = 1, i;

    for (i = 0; i < maxApp && notAvailable; i++)
    {
        if ((date.year == appointments[i].date.year &&
             date.month == appointments[i].date.month &&
             date.day == appointments[i].date.day &&
             time.hour == appointments[i].time.hour &&
             time.min == appointments[i].time.min))
        {
            notAvailable = 0;
        }
    }
    return notAvailable;
}

// Search for appointment that matches with paitien number
int appointmentSearch(struct Date dates, struct Appointment *appoint, int numberPaitient, int maxappoint)
{
    int index = -1;
    int i = 1;

    for (i = 0; i < maxappoint; i++)
    {
        if (appoint[i].patientNumber == numberPaitient && appoint[i].date.year && appoint[i].date.month == dates.month && appoint[i].date.day)
        {
            index = i;
        }
    }
    return index;
}
// Counts the quantity of appointments in a day
int dailyApptCount(struct Date date, struct Appointment appoint[], int maxAppoint)
{
    int i;
    int counter = 0;

    for (i = 0; i < maxAppoint; i++)
    {
        if (date.year == appoint[i].date.year &&
            date.month == appoint[i].date.month &&
            date.day == appoint[i].date.day)
        {
            counter++;
        }
    }
    return counter;
}
// Search the index of the next appointment
int indexFollowingApp(struct Appointment appoints[], int maxAppnt)
{
    int available = 0;
    int i = 0;

    while (i < maxAppnt && !(available))
    {
        if (appoints[i].patientNumber < 1)
        {
            available = 1;
        }
        i++;
    }
    return i;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient *paitient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", paitient->patientNumber);

    printf("Name  : ");
    inputCString(paitient->name, 1, NAME_LEN);
    putchar('\n');

    inputPhoneData(&paitient->phone);
}
// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone *phone)
{
    int contactChoice;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n"
           "2. Home\n"
           "3. Work\n"
           "4. TBD\n");
    printf("Selection: ");
    contactChoice = inputIntRange(1, 4);
    putchar('\n');

    switch (contactChoice)
    {
    case 1:
        strcpy(phone->description, "CELL");

        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;

    default:
        strcpy(phone->description, "TBD");

        break;
    }

    if (contactChoice != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputNumString(phone->number, PHONE_LEN);
        putchar('\n');
    }
}
// Validates the date (year, month and day) input by the user
void dateValidation(struct Date *date)
{
    int daysInMonth;

    printf("Year        : ");
    date->year = inputIntPositive();

    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);

    if (date->year % 4 == 0 && date->month == 2)
    {
        daysInMonth = 29;
    }
    else if (date->month == 2)
    {
        daysInMonth = 28;
    }
    else if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11)
    {
        daysInMonth = 30;
    }
    else
    {
        daysInMonth = 31;
    }
    printf("Day (1-%d)  : ", daysInMonth);
    date->day = inputIntRange(1, daysInMonth);
}

// Validates user input timer (hour and minute);
void validTime(struct Time *times)
{
    printf("Hour (0-%d)  : ", 23);
    times->hour = inputIntRange(0, 23);

    printf("Minute (0-%d): ", 59);
    times->min = inputIntRange(0, 59);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    int i = 0;

    FILE *fp;
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]\n", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF && i < max)
        {
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: File could NOT be open\n");
    }
    return i;
}
// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    int i = 0;
    char ch;

    FILE *fp;
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%d, %d, %d, %d,%d,%d%c", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min, &ch) != EOF)
        {
            if (ch != '\n')
            {
                while (fgetc(fp) != '\n')
                    ;
            }
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        printf("ERROR: File could NOT be open\n");
    }

    sort(appoints, max);
    // sort(data->appointments, data->maxAppointments);

    return i;
}
