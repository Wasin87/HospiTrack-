#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct patient
{
    int id;
    char patientName[50];
    char patientAddress[50];
    char disease[50];
    char date[12];
} p;

struct doctor
{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
} d;

struct nurse
{
    int id;
    char name[50];
    char department[50];
} n;

struct assignment
{
    int patientID;
    char patientName[50];
    int nurseID;
    char nurseName[50];
    char assignedDate[12];
} a;

struct icu
{
    int icuID;
    int patientID;
    char patientName[50];
    char admissionDate[12];
} icu;

struct test_report
{
    int patientID;
    char diseaseName[50];
    char testName[50];
    char condition[100];
    char testDate[20];
} report;


struct appointment
{
    int patientID;
    char patientName[50];
    char day[10];
    char time[10];
    char ampm[3];
    int roomNumber;
} app;

struct patientBill
{
    int patientID;
    char patientName[50];
    char patientType[30];
    float amount;
    char paymentMethod[30];
    int isPaid;
    // 0 for unpaid, 1 for paid

} bill;

struct bloodDonation
{
    int patientID;
    char donorName[50];
    char bloodGroup[5];
    char address[100];
    char donationDate[12];
} donor;

//File system

FILE *fp;

// Function prototypes

void login();
void admitPatient();
void patientList();
void dischargePatient();
void addDoctor();
void doctorList();
void assignNurse();
void nurseAssignmentList();
void bookICURoom();
void icuRoomList();
void addTestReport();
void viewTestReport();
void scheduleAppointment();
void viewAppointments();
void cancelAppointment();
void managePatientBills();
void viewBillDetails();
void resetAllData();
void addBloodDonation();
void viewBloodDonations();

// Main function
int main()

 {

    // All color
    printf("\033[1;32mThis is Green Text\033[0m\n");
    printf("\033[1;31mThis is Red Text\033[0m\n");
    printf("\033[1;34mThis is Blue Text\033[0m\n");
    printf("\033[1;36mThis is Aqua Text\033[0m\n");
    printf("\033[1;38;5;48mThis is Spring Green Text (Approximation)\033[0m\n");
    int ch;
    login();

    // Ensure user is logged in before accessing the system

    while (1)
    {
        system("cls");
        printf("\033[1;32m-------------------------------------------------------------\033[0m\n");
        printf("\t\033[1;93m         <----WELCOME TO 'HospiTrack'---->\n");
         printf("\033[1;32m-------------------------------------------------------------\033[0m\n\n");
        printf("\033[1;38;5;48m<== Healthcare Management System ==>\n\n");
        printf("1.  Admit Patient\n");
        printf("2.  Patient List\n");
        printf("3.  Discharge Patient\n");
        printf("4.  Add Doctor\n");
        printf("5.  Doctors List\n");
        printf("6.  Assign Nurse\n");
        printf("7.  Nurse Assignment List\n");
        printf("8.  Book ICU Room\n");
        printf("9.  View ICU Room List\n");
        printf("10. Add Test Report\n");
        printf("11. View Test Reports\n");
        printf("12. Schedule Patient Appointment\n");
        printf("13. View Scheduled Appointments\n");
        printf("14. Cancel Appointment\n");
        printf("15. Manage Patient Bills\n");
        printf("16. View Bill Details\n");
        printf("17. Add Blood Donation Details\n");
        printf("18. View Blood Donation Details\n");
        printf("19. Reset All Data\n");
        printf("20. Emergency ambulance mobile number : 017*********\n");
        printf(" 0.  Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

// All cases

        switch (ch)
    {
            case 0:
                exit(0);
            case 1:
                admitPatient();
                break;
            case 2:
                patientList();
                break;
            case 3:
                dischargePatient();
                break;
            case 4:
                addDoctor();
                break;
            case 5:
                doctorList();
                break;
            case 6:
                assignNurse();
                break;
            case 7:
                nurseAssignmentList();
                break;
            case 8:
                bookICURoom();
                break;
            case 9:
                icuRoomList();
                break;
            case 10:
                addTestReport();
                break;
            case 11:
                viewTestReport();
                break;
            case 12:
                scheduleAppointment();
                break;
            case 13:
                viewAppointments();
                break;
            case 14:
                cancelAppointment();
                break;
            case 15:
                managePatientBills();
                break;
            case 16:
                viewBillDetails();
                break;
            case 17:
                addBloodDonation();
                break;
            case 18:
                viewBloodDonations();
                break;
            case 19:
                resetAllData();
                break;
            default:
                printf("Invalid Choice...\n\n");
        }
        printf("\033[1;31m\n\nPress Any Key To Continue --->");
        getchar();
        // To capture the Enter key after choice

        getchar();
        // To wait for user to press any key
    }
    return 0;
}


// ======================= LOGIN FUNCTION =======================

void login()
 {
    char username[20], password[20], ch;
    int i = 0;

    while (1)

    {
        system("cls");
        printf("\033[1;33m<=== LOGIN ===>\n\n");
        printf("Enter Username: ");
        scanf("%s", username);

        printf("Enter Password: ");
        i = 0;
        while (1)

            {
            ch = getch();

            // Enter key
            if (ch == 13)
            {
                password[i] = '\0';
                break;

                // Backspace key
            }

            else if (ch == 8 && i > 0)
            {
                i--;

                 // Erase last character
                printf("\b \b");
            }
             else

            {
                password[i++] = ch;

                // Mask password
                printf("*");
            }
        }
// Project Username and password

        if (strcmp(username, "Hospi") == 0 && strcmp(password, "Hospi123") == 0)
        {
            printf("\nLogin Successful!\n");
            break;
        }

        else

        {
            printf("\033[1;31m\nInvalid Credentials! Try Again.\n");
            getch();
        }
    }
}

// ==================== PATIENT FUNCTIONS =======================

void admitPatient()

{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("patient.txt", "ab");

    if (fp == NULL)

    {
        printf("\033[1;38m Error opening file\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    getchar();
    // To consume the newline left by scanf

    fgets(p.patientName, sizeof(p.patientName), stdin);

    // Remove newline
    p.patientName[strcspn(p.patientName, "\n")] = '\0';

    printf("Enter Patient Address: ");
    fgets(p.patientAddress, sizeof(p.patientAddress), stdin);

    // Remove newline
    p.patientAddress[strcspn(p.patientAddress, "\n")] = '\0';

    printf("Enter Patient Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);

    // Remove newline
    p.disease[strcspn(p.disease, "\n")] = '\0';

    printf("\033[1;96m\nPatient Added Successfully!");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}


// Patient List code

void patientList()

{
    system("cls");
    printf("<== Patient List ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %s\n", "ID", "Patient Name", "Address", "Disease", "Date");
    printf("-----      -------------               --------------                --------------          ----------------\n");

    fp = fopen("patient.txt", "rb");

    if (fp == NULL)

    {
        printf("Error opening file\n");
        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.patientName, p.patientAddress, p.disease, p.date);
    }

    fclose(fp);
}


// Discharge Patient List code

void dischargePatient()
 {
    int id, f = 0;
    system("cls");
    printf("<== Discharge Patient ==>\n\n");
    printf("Enter Patient ID to discharge: ");
    scanf("%d", &id);

    FILE *ft;
    fp = fopen("patient.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL)
    {
        printf("Error opening temporary file\n");
        fclose(fp);

        return;
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
     {
        if (id == p.id)

        {
            f = 1;
        }

        else

        {
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if (f == 1)
    {
        printf("\033[1;96m\n\nPatient Discharged Successfully.");
    }

    else

    {
        printf("\n\nRecord Not Found!");
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");
}

// ===================== DOCTOR FUNCTIONS =======================

void addDoctor()

 {
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    system("cls");
    printf("<== Add Doctor ==>\n\n");

    fp = fopen("doctor.txt", "ab");
    if (fp == NULL)

    {
        printf("Error opening file\n");
        return;
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    getchar();
    // To consume the newline left by scanf

    fgets(d.name, sizeof(d.name), stdin);

    // Remove newline
    d.name[strcspn(d.name, "\n")] = '\0';

    printf("Enter Doctor Address: ");
    fgets(d.address, sizeof(d.address), stdin);

    // Remove newline
    d.address[strcspn(d.address, "\n")] = '\0';
    printf("Doctor Specialize in: ");
    fgets(d.specialize, sizeof(d.specialize), stdin);

    // Remove newline
    d.specialize[strcspn(d.specialize, "\n")] = '\0';

    printf("\033[1;96m\nDoctor Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}


// Doctor list code

void doctorList()
{
    system("cls");
    printf("<== Doctor List ==>\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "ID", "Name", "Address", "Specialize", "Date");
    printf("-----     ---------                    -----------                       -----------                   -----------\n");

    fp = fopen("doctor.txt", "rb");
    if (fp == NULL)

    {
        printf("Error opening file\n");
        return;
    }

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.address, d.specialize, d.date);
    }

    fclose(fp);
}

// ===================== Nurse FUNCTIONS =======================

void assignNurse()

{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(a.assignedDate, myDate);

    fp = fopen("assignments.txt", "ab");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &a.patientID);

    printf("Enter Patient Name: ");
    getchar();
    // To consume the newline left by scanf

    fgets(a.patientName, sizeof(a.patientName), stdin);

    // Remove newline
    a.patientName[strcspn(a.patientName, "\n")] = '\0';

    printf("Enter Nurse ID: ");
    scanf("%d", &a.nurseID);

    printf("Enter Nurse Name: ");
    getchar();
    // To consume the newline left by scanf

    fgets(a.nurseName, sizeof(a.nurseName), stdin);

    // Remove newline
    a.nurseName[strcspn(a.nurseName, "\n")] = '\0';

    printf("\033[1;96m\nNurse Assigned Successfully!\n");

    fwrite(&a, sizeof(a), 1, fp);

    fclose(fp);
}

// Nurse Assignment List code

void nurseAssignmentList()
{
    system("cls");
    printf("<== Nurse Assignment List ==>\n\n");
    printf("%-10s %-22s %-20s %-15s %s\n", "Patient ID", "Patient Name", "Nurse ID", "Nurse Name", "Assigned Date");
    printf("---------- -------------          ---------            -----------    ----------------\n");

    fp = fopen("assignments.txt", "rb");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        printf("%-10d %-22s %-20d %-15s %s\n", a.patientID, a.patientName, a.nurseID, a.nurseName, a.assignedDate);
    }

    fclose(fp);
}

// ================= ICU ROOM BOOKING FUNCTIONS =================

void bookICURoom()
{
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(icu.admissionDate, myDate);

    fp = fopen("icu.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter ICU Room Number: ");
    scanf("%d", &icu.icuID);

    printf("Enter Patient ID: ");
    scanf("%d", &icu.patientID);

    printf("Enter Patient Name: ");
    getchar();
    // To consume the newline left by scanf

    fgets(icu.patientName, sizeof(icu.patientName), stdin);

    // Remove newline
    icu.patientName[strcspn(icu.patientName, "\n")] = '\0';

    printf("\033[1;96m\nICU Room Booked Successfully!");

    fwrite(&icu, sizeof(icu), 1, fp);
    fclose(fp);
}
//ICU Room List Code

void icuRoomList()
{
    system("cls");
    printf("<== ICU Room List ==>\n\n");
    printf("%-10s %-10s %-30s %s\n", "ICU ID", "Patient ID", "Patient Name", "Admission Date");
    printf("-------    ---------- ------------                  ---------------\n");

    fp = fopen("icu.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (fread(&icu, sizeof(icu), 1, fp) == 1)
    {
        printf("%-10d %-10d %-30s %s\n", icu.icuID, icu.patientID, icu.patientName, icu.admissionDate);
    }
    fclose(fp);
}


// Function to add test report

void addTestReport()
{
    system("cls");
    printf("<== Add Test Report ==>\n\n");

    printf("Enter Patient ID: ");
    scanf("%d", &report.patientID);
    getchar();
    // Consume newline after integer input

    printf("Enter Disease Name: ");
    fgets(report.diseaseName, sizeof(report.diseaseName), stdin);

    // Remove trailing newline

    report.diseaseName[strcspn(report.diseaseName, "\n")] = '\0';

    printf("Enter Test Name: ");
    fgets(report.testName, sizeof(report.testName), stdin);

    // Remove trailing newline
    report.testName[strcspn(report.testName, "\n")] = '\0';

    printf("Enter Condition: ");
    fgets(report.condition, sizeof(report.condition), stdin);

    // Remove trailing newline
    report.condition[strcspn(report.condition, "\n")] = '\0';

    printf("Enter Test Date (DD/MM/YYYY): ");
    fgets(report.testDate, sizeof(report.testDate), stdin);

    // Remove trailing newline
    report.testDate[strcspn(report.testDate, "\n")] = '\0';

    fp = fopen("test_reports.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    fwrite(&report, sizeof(report), 1, fp);
    fclose(fp);

    printf("\033[1;96m\nTest report added successfully!\n");
}

// Function to view test reports

void viewTestReport()
{
    system("cls");
    printf("<== View Test Reports ==>\n\n");
    printf("%-10s %-20s %-20s %-30s %-15s\n", "Patient ID", "Disease Name", "Test Name", "Condition", "Test Date");
    printf("---------- ------------         ----------          -----------                     -----------\n");

    fp = fopen("test_reports.txt", "rb");
    if (fp == NULL)
    {
        printf("No test reports recorded or error opening file.\n");
        return;
    }

    while (fread(&report, sizeof(report), 1, fp) == 1)
    {
        printf("%-10d %-20s %-20s %-30s %-15s\n", report.patientID, report.diseaseName, report.testName, report.condition, report.testDate);
    }

    fclose(fp);
}


// ================= Schedule Appointment FUNCTIONS =================

void scheduleAppointment()
 {
    system("cls");
    printf("<== Schedule Patient Appointment ==>\n\n");

    fp = fopen("appointments.txt", "ab");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &app.patientID);

    printf("Enter Patient Name: ");
    getchar();
    fgets(app.patientName, sizeof(app.patientName), stdin);

    // Remove newline
    app.patientName[strcspn(app.patientName, "\n")] = '\0';

    printf("Enter Day (e.g., Monday): ");
    fgets(app.day, sizeof(app.day), stdin);

    // Remove newline
    app.day[strcspn(app.day, "\n")] = '\0';

    printf("Enter Time (e.g., 10:30): ");
    fgets(app.time, sizeof(app.time), stdin);

    // Remove newline
    app.time[strcspn(app.time, "\n")] = '\0';

    printf("Enter AM/PM: ");
    fgets(app.ampm, sizeof(app.ampm), stdin);

    // Remove newline
    app.ampm[strcspn(app.ampm, "\n")] = '\0';

    printf("Enter Room Number: ");
    scanf("%d", &app.roomNumber);

    printf("\033[1;96m\nAppointment Scheduled Successfully!\n");

    fwrite(&app, sizeof(app), 1, fp);
    fclose(fp);
}

// View Appointments code

void viewAppointments() {
    system("cls");
    printf("<== View Scheduled Appointments ==>\n\n");
    printf("%-10s %-30s %-10s %-10s %-5s %-10s\n", "Patient ID", "Patient Name", "Day", "Time", "AM/PM", "Room No.");
    printf("---------- -------------                 -------    -------     ----- ---------\n");

    fp = fopen("appointments.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file or no appointments scheduled.\n");
        return;
    }

    while (fread(&app, sizeof(app), 1, fp) == 1) {
        printf("%-10d %-30s %-10s %-10s %-5s %-10d\n", app.patientID, app.patientName, app.day, app.time, app.ampm, app.roomNumber);
    }
    fclose(fp);
}
// ================= Cancel Appointment FUNCTION =================

void cancelAppointment() {
    int id, found = 0;
    system("cls");
    printf("<== Cancel Appointment ==>\n\n");
    printf("Enter Patient ID to cancel the appointment: ");
    scanf("%d", &id);

    FILE *fp, *ft;
    fp = fopen("appointments.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    ft = fopen("temp.txt", "wb");
    if (ft == NULL) {
        printf("Error opening temporary file\n");
        fclose(fp);
        return;
    }

    while (fread(&app, sizeof(app), 1, fp) == 1) {
        if (id == app.patientID) {
            found = 1;
            // Appointment found

        }

        else
        {
            fwrite(&app, sizeof(app), 1, ft);
            // Keep the appointment in the temporary file

        }
    }

    if (found)
    {
        printf("\033[1;96m\nAppointment canceled successfully.\n");
    }

    else

    {
        printf("\nAppointment not found.\n");
    }

    fclose(fp);
    fclose(ft);

    // Remove the original appointments file and rename the temporary file
    remove("appointments.txt");
    rename("temp.txt", "appointments.txt");
}

// ================= Patient Bills FUNCTIONS =================

void managePatientBills()
 {
    struct patientBill bill;
    system("cls");
    printf("<== Manage Patient Bills ==>\n\n");

    printf("Enter Patient ID: ");
    scanf("%d", &bill.patientID);
    getchar();

    printf("Enter Patient Name: ");
    fgets(bill.patientName, sizeof(bill.patientName), stdin);

    // Remove newline
    bill.patientName[strcspn(bill.patientName, "\n")] = '\0';

    printf("Enter Patient Type (e.g., New patient/Old patient): ");
    fgets(bill.patientType, sizeof(bill.patientType), stdin);

    // Remove newline
    bill.patientType[strcspn(bill.patientType, "\n")] = '\0';

    printf("Enter Amount: ");
    scanf("%f", &bill.amount);
    getchar();

    printf("Enter Payment Method (e.g., Credit Card,Mobile Banking, Cash): ");
    fgets(bill.paymentMethod, sizeof(bill.paymentMethod), stdin);

    // Remove newline
    bill.paymentMethod[strcspn(bill.paymentMethod, "\n")] = '\0';

    printf("Is the bill paid? (1 for Yes, 0 for No): ");
    scanf("%d", &bill.isPaid);

    fp = fopen("patient_bills.txt", "ab");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    fwrite(&bill, sizeof(bill), 1, fp);
    fclose(fp);

    printf("\033[1;96m\nBill details saved successfully!\n");
}

// View Bill Details Code

void viewBillDetails()
{
    struct patientBill bill;
    system("cls");
    printf("<== View Patient Bill Details ==>\n\n");
    printf("%-10s %-30s %-20s %-10s %-20s %-10s\n", "Patient ID", "Patient Name", "Patient Type", "Amount", "Payment Method", "Paid Status");
    printf("---------- --------------                -------------        --------    -------------      --------------  \n");

    fp = fopen("patient_bills.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file or no bills recorded.\n");
        return;
    }

    while (fread(&bill, sizeof(bill), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %-10.2f %-20s %-10s\n", bill.patientID, bill.patientName, bill.patientType, bill.amount, bill.paymentMethod, bill.isPaid ? "Yes" : "No");
    }
    fclose(fp);
}

// ================= Blood Donation FUNCTIONS =================

void addBloodDonation()
 {
    system("cls");
    printf("<== Add Blood Donation Details ==>\n\n");

    printf("Enter Donor Name: ");
    getchar();
    fgets(donor.donorName, sizeof(donor.donorName), stdin);

    // Remove newline
    donor.donorName[strcspn(donor.donorName, "\n")] = '\0';

    printf("Enter Blood Group: ");
    fgets(donor.bloodGroup, sizeof(donor.bloodGroup), stdin);

    // Remove newline
    donor.bloodGroup[strcspn(donor.bloodGroup, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(donor.address, sizeof(donor.address), stdin);

    // Remove newline
    donor.address[strcspn(donor.address, "\n")] = '\0';

    printf("Enter Donation Date (DD/MM/YYYY): ");
    fgets(donor.donationDate, sizeof(donor.donationDate), stdin);

    // Remove newline
    donor.donationDate[strcspn(donor.donationDate, "\n")] = '\0';

    printf("Enter Patient ID to Donate To: ");
    scanf("%d", &donor.patientID);

    fp = fopen("blood_donation.txt", "ab");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fwrite(&donor, sizeof(donor), 1, fp);
    fclose(fp);

    printf("\033[1;96m\nBlood donation details saved successfully!\n");
}

// Function to view all blood donation records

void viewBloodDonations()

 {
    system("cls");
    printf("<== View Blood Donation Details ==>\n\n");
    printf("%-10s %-20s %-10s %-30s %-15s\n", "Patient ID", "Donor Name", "Blood Group", "Address", "Donation Date");
    printf("---------- ----------          ------------ --------                      ---------------\n");

    fp = fopen("blood_donation.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file or no records found.\n");
        return;
    }

    while (fread(&donor, sizeof(donor), 1, fp) == 1)
    {
        printf("%-10d %-20s %-10s %-30s %-15s\n", donor.patientID, donor.donorName, donor.bloodGroup, donor.address, donor.donationDate);
    }

    fclose(fp);
}


// Reset all data function

void resetAllData()
 {
    char confirm;
    system("cls");
    printf("<== Reset All Data ==>\n\n");
    printf("Are you sure you want to delete all records? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        remove("patient.txt");
        remove("doctor.txt");
        remove("assignments.txt");
        remove("icu.txt");
        remove("patient_bills.txt");
        remove("appointments.txt");
        remove("blood_donation.txt");
        remove("test_reports.txt");



        printf("\033[1;96m\nAll records have been deleted successfully!\n");

    }
     else
    {
        printf("\nData reset canceled.\n");
    }
}
