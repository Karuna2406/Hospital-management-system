#include <stdio.h>
#define MAX_P 100
#define MAX_D 100
#define MAX_A 100
#define MAX_B 100
#define MAX_H 100

struct Hospital
{
    int hid;
    char name[100];
    char city[100];
    int beds;
    float price;
    float rating;
    int review;
};

struct Patient
{
    int pid;
    char pname[50];
    char gender;
    struct dateofbirth
    {
        int day;
        int month;
        int year;
    } dob;
    char p_contact[50];
    char address[100];
    char med_hist[200];
    char insurance[100];
};

struct Doctor
{
    int did;
    char dname[50];
    char specs[50];
    char d_contact[50];
    char available[50];
    char dept[20];
    float experience;
};

struct Appointment
{
    int aid;
    int pid;
    int did;
    struct appointment_date
    {
        int day;
        int month;
        int year;
        int hour;
        int minute;
    } a_date;
    char reason[100];
    char status[20];
};

struct Bill
{
    int bid;
    int pid;
    int did;
    char services[200];
    struct date_ofService
    {
        int day;
        int month;
        int year;
    } b_date;
    float cost;
    char payment[20];
};

// global variables to store data
struct Hospital hospitals[MAX_H];
int numH = 0;
struct Patient p[MAX_P];
int numP = 0;
struct Doctor d[MAX_D];
int numD = 0;
struct Appointment a[MAX_A];
int numA = 0;
struct Bill b[MAX_B];
int numB = 0;

int currentHospitalIndex = -1;

void add_hospital()
{
    if (numH < MAX_H)
    {
        printf("Enter hospital name: ");
        scanf("%s", hospitals[numH].name);
        printf("Enter city name: ");
        scanf("%s", hospitals[numH].city);
        printf("Enter the number of beds: ");
        scanf("%d", &hospitals[numH].beds);
        printf("Enter the price: ");
        scanf("%f", &hospitals[numH].price);
        printf("Enter the rating: ");
        scanf("%f", &hospitals[numH].rating);
        printf("Enter the review: ");
        scanf("%d", &hospitals[numH].review);

        hospitals[numH].hid = numH + 1;

        numH++;
    }
    else
    {
        printf("Maximum number of Hospitals reached.\n");
    }
}

void selectHospital()
{
    int choice,i;
    printf("Select a hospital:\n");
    for (i = 0; i < numH; i++)
    {
        printf("%d. %s\n", i + 1, hospitals[i].name);
    }
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice > 0 && choice <= numH)
    {
        currentHospitalIndex = choice - 1;
        printf("Hospital \"%s\" selected.\n", hospitals[currentHospitalIndex].name);
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

void add_patient()
{
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    if (numP < MAX_P)
    {
        printf("Enter patient name: ");
        scanf("%s", p[numP].pname);
        printf("Enter gender (M/F): ");
        scanf(" %c", &p[numP].gender);
        printf("Enter date of birth (DD MM YYYY): ");
        scanf("%d %d %d", &p[numP].dob.day, &p[numP].dob.month, &p[numP].dob.year);
        printf("Enter contact information: ");
        scanf("%s", p[numP].p_contact);
        printf("Enter address: ");
        scanf("%s", p[numP].address);
        printf("Enter medical history: ");
        scanf("%s", p[numP].med_hist);
        printf("Enter insurance information: ");
        scanf("%s", p[numP].insurance);

        p[numP].pid = numP + 1;

        numP++;
    }
    else
    {
        printf("Maximum number of patients reached.\n");
    }
}

void add_doctor()
{
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    if (numD < MAX_D)
    {
        printf("Enter doctor name: ");
        scanf("%s", d[numD].dname);
        printf("Enter specialization: ");
        scanf("%s", d[numD].specs);
        printf("Enter contact information: ");
        scanf("%s", d[numD].d_contact);
        printf("Enter schedule: ");
        scanf("%s", d[numD].available);
        printf("Enter department: ");
        scanf("%s", d[numD].dept);
        printf("Enter experience (in years): ");
        scanf("%f", &d[numD].experience);

        d[numD].did = numD + 1;

        numD++;
    }
    else
    {
        printf("Maximum number of doctors reached.\n");
    }
}

void add_appointment()
{
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    if (numA < MAX_A)
    {
        printf("Enter patient ID: ");
        scanf("%d", &a[numA].pid);
        printf("Enter doctor ID: ");
        scanf("%d", &a[numA].did);
        printf("Enter appointment date and time (DD MM YYYY HH MM): ");
        scanf("%d %d %d %d %d", &a[numA].a_date.day,
              &a[numA].a_date.month,
              &a[numA].a_date.year,
              &a[numA].a_date.hour,
              &a[numA].a_date.minute);
        printf("Enter reason for appointment: ");
        scanf("%s", a[numA].reason);
        printf("Enter appointment status: ");
        scanf("%s", a[numA].status);

        a[numA].aid = numA + 1;

        numA++;
    }
    else
    {
        printf("Maximum number of appointments reached.\n");
    }
}

void add_bill()
{
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    if (numB < MAX_B)
    {
        printf("Enter patient ID: ");
        scanf("%d", &b[numB].pid);
        printf("Enter doctor ID: ");
        scanf("%d", &b[numB].did);
        printf("Enter services provided: ");
        scanf("%s", b[numB].services);
        printf("Enter date of service (DD MM YYYY): ");
        scanf("%d %d %d", &b[numB].b_date.day, &b[numB].b_date.month, &b[numB].b_date.year);
        printf("Enter cost: ");
        scanf("%f", &b[numB].cost);
        printf("Enter payment status: ");
        scanf("%s", b[numB].payment);

        b[numB].bid = numB + 1;

        numB++;
    }
    else
    {
        printf("Maximum number of bills reached.\n");
    }
}

void displayHospital()
{
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    printf("Hospital:\n");
    printf("Hospital ID: %d\n", hospitals[currentHospitalIndex].hid);
    printf("Name: %s\n", hospitals[currentHospitalIndex].name);
    printf("City: %s\n", hospitals[currentHospitalIndex].city);
    printf("Number of Beds available: %d\n", hospitals[currentHospitalIndex].beds);
    printf("Price: %f\n", hospitals[currentHospitalIndex].price);
    printf("Rating: %f\n", hospitals[currentHospitalIndex].rating);
    printf("Review: %d\n", hospitals[currentHospitalIndex].review);
}

void displayPatients()
{
	int i;
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    printf("Patients:\n");
    for (i = 0; i < numP; i++)
    {
        printf("Patient ID: %d\n", p[i].pid);
        printf("Name: %s\n", p[i].pname);
        printf("Gender: %c\n", p[i].gender);
        printf("Date of Birth: %d-%d-%d\n", p[i].dob.day, p[i].dob.month, p[i].dob.year);
        printf("Contact Information: %s\n", p[i].p_contact);
        printf("Address: %s\n", p[i].address);
        printf("Medical History: %s\n", p[i].med_hist);
        printf("Insurance Information: %s\n\n", p[i].insurance);
    }
}

void displayDoctors()
{
	int i;
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    printf("Doctors:\n");
    for ( i = 0; i < numD; i++)
    {
        printf("Doctor ID: %d\n", d[i].did);
        printf("Name: %s\n", d[i].dname);
        printf("Specialization: %s\n", d[i].specs);
        printf("Contact Information: %s\n", d[i].d_contact);
        printf("Schedule: %s\n", d[i].available);
        printf("Department: %s\n", d[i].dept);
        printf("Experience: %.2f years\n\n", d[i].experience);
    }
}

void displayAppointments()
{
	int i;
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    printf("Appointments:\n");
    for ( i = 0; i < numA; i++)
    {
        printf("Appointment ID: %d\n", a[i].aid);
        printf("Patient ID: %d\n", a[i].pid);
        printf("Doctor ID: %d\n", a[i].did);
        printf("Appointment Date and Time: %d-%d-%d %d:%d\n", a[i].a_date.day,
               a[i].a_date.month, a[i].a_date.year,
               a[i].a_date.hour, a[i].a_date.minute);
        printf("Reason for Appointment: %s\n", a[i].reason);
        printf("Status: %s\n\n", a[i].status);
    }
}

void displayBills()
{
	int i;
    if (currentHospitalIndex == -1)
    {
        printf("Please select a hospital first.\n");
        return;
    }

    printf("Bills:\n");
    for (i = 0; i < numB; i++)
    {
        printf("Bill ID: %d\n", b[i].bid);
        printf("Patient ID: %d\n", b[i].pid);
        printf("Doctor ID: %d\n", b[i].did);
        printf("Services Provided: %s\n", b[i].services);
        printf("Date of Service: %d-%d-%d\n", b[i].b_date.day, b[i].b_date.month, b[i].b_date.year);
        printf("Cost: %.2f\n", b[i].cost);
        printf("Payment Status: %s\n\n", b[i].payment);
    }
}

int main()
{
    int choice;

    do
    {

        printf("\n~~~~~~Hospital Management System~~~~~~\n");
        printf("----------------------------------------\n");
        printf("__________________________\n");
        printf("|1. |Add Hospital         |\n");
        printf("|___|_____________________|\n");
        printf("|2. |Select Hospital      |\n");
        printf("|___|_____________________|\n");
        printf("|3. |Add Patient          |\n");
        printf("|___|_____________________|\n");
        printf("|4. |Add Doctor           |\n");
        printf("|___|_____________________|\n");
        printf("|5. |Add Appointment      |\n");
        printf("|___|_____________________|\n");
        printf("|6. |Add Bill             |\n");
        printf("|___|_____________________|\n");
        printf("|7. |Display Hospital     |\n");
        printf("|___|_____________________|\n");
        printf("|8. |Display Patients     |\n");
        printf("|___|_____________________|\n");
        printf("|9. |Display Doctors      |\n");
        printf("|___|_____________________|\n");
        printf("|10.| Display Appointments|\n");
        printf("|___|_____________________|\n");
        printf("|11.| Display Bills       |\n");
        printf("|___|_____________________|\n");
        printf("|12.| Exit                |\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_hospital();
            break;
        case 2:
            selectHospital();
            break;
        case 3:
            add_patient();
            break;
        case 4:
            add_doctor();
            break;
        case 5:
            add_appointment();
            break;
        case 6:
            add_bill();
            break;
        case 7:
            displayHospital();
            break;
        case 8:
            displayPatients();
            break;
        case 9:
            displayDoctors();
            break;
        case 10:
            displayAppointments();
            break;
        case 11:
            displayBills();
            break;
        case 12:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 12.\n");
        }
    } while (choice != 12);

    return 0;
}

