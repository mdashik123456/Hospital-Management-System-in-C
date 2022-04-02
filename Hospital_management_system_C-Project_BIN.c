#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>

void main_function();
void login();
void info();
void contact();
void Exit();
void admin_login();
void admin_menu();
void user_login();
void loading();
void loading_login();
void loading_logout();
void loading_starting();

void patient_menu();
void create_patient_entry();
void admit_patient();
void release_patient();
void unavailable_bed_no();
void search_patient_entry();
void modify_patient_entry();
void delete_patient_entry();
void all_patient_list();
void patient_payment();

void doctor_menu();
void create_doctor_entry();
void search_doctor_entry();
void modify_doctor_entry();
void delete_doctor_entry();
void about_doctor();

void nurse_menu();
void create_nurse_entry();
void search_nurse_entry();
void modify_nurse_entry();
void delete_nurse_entry();
void nurse_list();

void staff_menu();
void create_staff_entry();
void search_staff_entry();
void modify_staff_entry();
void delete_staff_entry();
void staff_list();

void doctor_login();
void doctor_login_panel();
void modify_doctor_entry_by_doctor();
void modify_patient_entry_by_doctor();

void nurse_login();
void nurse_login_panel();
void modify_nurse_entry_by_nurse();

void staff_login();
void staff_login_panel();
void modify_staff_entry_by_staff();

void patient_login();
void patient_login_panel();
void modify_patient_entry_by_patient();

void available_bed_info();
void unavailable_bed_save();
void modify_hospital_bed();

struct hospital
{
    int cabin, icu, ccu, nicu, general_bed;
} hospital;

struct doctor
{
    char usr[25], pass[20], name[20], age[5], phone[15], email[30], address[50], room[5], duty_time[10];
} doctor;

struct patient
{
    char usr[25], pass[20], name[20], age[5], phone[15], email[30], address[50], diseases[60], diseases_description[500], test[20], test_result[500];
    double due, pay, payable, paid;
    int cabin_no;
} patient;

struct nurse
{
    char usr[25], pass[20], name[20], age[5], phone[15], email[30], address[50], duty_time[10], salary[10];
} nurse;

struct staff
{
    char usr[25], pass[20], name[20], age[5], phone[15], email[30], address[50], duty_time[10], salary[10];
} staff;

int main()
{

    // getch () ;
    system("color 3");
    main_function();

    return 0;
}

void main_function()
{

    system("cls");
    char choice;

    printf("\n");
    printf("\n");
    loading_starting();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t1. Login\n");
    printf("\t2. Information\n");
    printf("\t3. Contact Us\n");
    printf("\t0. EXIT\n");
    printf("\t\tEnter your choice : ");

    // scanf("%d", &choice);
    fflush(stdin);
    choice = getche();
    system("cls");
    switch (choice)
    {
    case '1':
        login();
        break;
    case '2':
        info();
        break;
    case '3':
        contact();
        break;
    case '0':
        Exit();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        main_function();
        break;
    }
}

void login()
{
    system("cls");
    printf("\n\t\t\t\t==== Login Panel ====\n\n\n");
    printf("\n\t1. Admin Login");
    printf("\n\t2. User Login");
    printf("\n\t3. <= Back");
    printf("\n\t0. EXIT");
    char choice;
    printf("\n\n\tEnter Your Choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        Exit();
        break;
    case '1':
        admin_login();
        break;
    case '2':
        user_login();
        break;
    case '3':
        main_function();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        login();
        break;
    }
}

void user_login()
{
    system("cls");
    printf("\n\t\t\t\t==== User Login Panel ====\n\n\n");
    char choice;
    printf("\n\t\t1. Doctor Login.");
    printf("\n\t\t2. Nurse Login.");
    printf("\n\t\t3. Staff Login.");
    printf("\n\t\t4. Patient Login.");
    printf("\n\t\t0. <= Back.");
    printf("\n\t\t\tEnter Your Choice : ");
    choice = getche();

    switch (choice)
    {
    case '0':
        login();
        break;
    case '1':
        doctor_login();
        break;
    case '2':
        nurse_login();
        break;
    case '3':
        staff_login();
        break;
    case '4':
        patient_login();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        user_login();
        break;
    }
}

void patient_login()
{
    system("cls");
    FILE *fp;
    char temp_usr[20], temp_pass[20], choice, flag = '0';
    printf("\n\t\t\t\t==== Login For Patient ====\n\n\n");
    printf("\n\t\tEnter Username : ");
    gets(temp_usr);
    printf("\t\tEnter Password : ");
    gets(temp_pass);

    fp = fopen("patient.BIN", "r");

    while (fread(&patient, sizeof(patient), 1, fp) == 1)
    {
        if (strcmp(patient.usr, temp_usr) == 0 && strcmp(patient.pass, temp_pass) == 0)
        {
            // printf ("Login Success") ;
            // getch();
            flag = '1';
            fclose(fp);
            loading_login();
            patient_login_panel();
        }
    }
    if (flag == '0')
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tYou've entered wrong username or password\n");
        printf("\n\n\t\t\t\tPress 1 to try again!\n");
        printf("\t\t\t\tPress Any key to go back to User Login Menu....\n");
        choice = getche();
        if (choice == '1')
        {
            patient_login();
        }
        else
        {
            fclose(fp);
            user_login();
        }
    }
}

void staff_login()
{
    system("cls");
    FILE *fp;
    char temp_usr[20], temp_pass[20], choice, flag = '0';
    printf("\n\t\t\t\t==== Login For Staff ====\n\n\n");
    printf("\n\t\tEnter Username : ");
    gets(temp_usr);
    printf("\t\tEnter Password : ");
    gets(temp_pass);
    fp = fopen("staff.BIN", "r");

    while (fread(&staff, sizeof(staff), 1, fp) == 1)
    {
        if (strcmp(staff.usr, temp_usr) == 0 && strcmp(staff.pass, temp_pass) == 0)
        {
            // printf ("Login Success") ;
            // getch();
            flag = '1';
            fclose(fp);
            loading_login();
            staff_login_panel();
        }
    }
    if (flag == '0')
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tYou've entered wrong username or password\n");
        printf("\n\n\t\t\t\tPress 1 to try again!\n");
        printf("\t\t\t\tPress Any key to go back to User Login Menu....\n");
        choice = getche();
        if (choice == '1')
        {
            staff_login();
        }
        else
        {
            fclose(fp);
            user_login();
        }
    }
}

void nurse_login()
{
    system("cls");
    FILE *fp;
    char temp_usr[20], temp_pass[20], choice, flag = '0';
    printf("\n\t\t\t\t==== Login For Nurse ====\n\n\n");
    printf("\n\t\tEnter Username : ");
    gets(temp_usr);
    printf("\t\tEnter Password : ");
    gets(temp_pass);
    fp = fopen("nurse.BIN", "r");

    while (fread(&nurse, sizeof(nurse), 1, fp) == 1)
    {
        if (strcmp(nurse.usr, temp_usr) == 0 && strcmp(nurse.pass, temp_pass) == 0)
        {
            // printf ("Login Success") ;
            // getch();
            flag = '1';
            fclose(fp);
            loading_login();
            nurse_login_panel();
        }
    }
    if (flag == '0')
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tYou've entered wrong username or password\n");
        printf("\n\n\t\t\t\tPress 1 to try again!\n");
        printf("\t\t\t\tPress Any key to go back to User Login Menu....\n");
        choice = getche();
        if (choice == '1')
        {
            nurse_login();
        }
        else
        {
            fclose(fp);
            user_login();
        }
    }
}

void doctor_login()
{
    system("cls");
    FILE *fp;
    char temp_usr[20], temp_pass[20], choice, flag = '0';
    printf("\n\t\t\t\t==== Login For Doctor's ====\n\n\n");
    printf("\n\t\tEnter Username : ");
    gets(temp_usr);
    printf("\t\tEnter Password : ");
    gets(temp_pass);
    fp = fopen("doctor.BIN", "r");

    while (fread(&doctor, sizeof(doctor), 1, fp) == 1)
    {
        if (strcmp(doctor.usr, temp_usr) == 0 && strcmp(doctor.pass, temp_pass) == 0)
        {
            flag = '1';
            fclose(fp);
            loading_login();
            doctor_login_panel();
        }
    }
    if (flag == '0')
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tYou've entered wrong username or password\n");
        printf("\n\n\t\t\t\tPress 1 to try again!\n");
        printf("\t\t\t\tPress Any key to go back to User Login Menu....\n");
        choice = getche();
        if (choice == '1')
        {
            doctor_login();
        }
        else
        {
            fclose(fp);
            user_login();
        }
    }
}

void patient_login_panel()
{
    system("cls");
    FILE *fp;
    char choice, flag = '0', p_usr[20];
    printf("\n\t\t\t\t==== Patient Panel ====\n\n\n");
    printf("\n\n\t1. Show Details.");
    printf("\n\t2. Update Informations.");
    printf("\n\t0. Logout.");
    printf("\n\t\tEnter Your Choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        loading_logout();
        user_login();
        break;
    case '1':
        system("cls");
        fp = fopen("patient.BIN", "r");
        printf("\n\n\t\tEnter Username for Search : ");
        fflush(stdin);
        gets(p_usr);

        while (fread(&patient, sizeof(patient), 1, fp) == 1)
        {
            if (strcmp(patient.usr, p_usr) == 0)
            {
                flag = '1';

                printf("\nPatient Name : ");
                puts(patient.name);

                printf("\nPatient Age : ");
                puts(patient.age);

                printf("\nPatient Phone NO : ");
                puts(patient.phone);

                printf("\nPatient Email : ");
                puts(patient.email);

                printf("\nPatient Address : ");
                puts(patient.address);

                printf("\nPatient Bed No : ");
                printf("%d", patient.cabin_no);

                printf("\n\nPatient Diseases : ");
                puts(patient.diseases);

                printf("\nPatient Diseases Description : ");
                puts(patient.diseases_description);

                printf("\nPatient Test : ");
                puts(patient.test);

                printf("\nPatient Test Result : ");
                puts(patient.test_result);

                printf("\n.............................................................................................................\n");
                printf("\nTotal Payable (BDT) : %.2lf\t\tTotal Paid (BDT) : %.2lf\t\tTotal Due (BDT) : %.2lf\n", patient.payable, patient.paid, patient.due);

                printf("\n\n\t................ Press Any Key for OK ..................");
                getch();
            }
        }
        if (flag == '0')
        {
            system("cls");
            printf("\n\n\t\t\tSorry! You Have Entered Wrong Username");
            printf("\n\t\t\tPress Any Key to Continue....");
            getch();
        }
        fclose(fp);
        break;
    case '2':
        modify_patient_entry_by_patient();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        patient_login_panel();
        break;
    }
    patient_login_panel();
}

void staff_login_panel()
{
    system("cls");
    FILE *fp;
    char choice, flag = '0', s_usr[20];
    printf("\n\t\t\t\t==== Staff Panel ====\n\n\n");
    printf("\n\n\t1. Show Details.");
    printf("\n\t2. Update Informations.");
    printf("\n\t0. Logout.");
    printf("\n\t\tEnter Your Choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        loading_logout();
        user_login();
        break;
    case '1':
        system("cls");
        fp = fopen("staff.BIN", "r");
        printf("\n\n\t\tEnter Username for Search : ");
        fflush(stdin);
        gets(s_usr);

        while (fread(&staff, sizeof(staff), 1, fp) == 1)
        {
            if (strcmp(staff.usr, s_usr) == 0)
            {
                system("cls");
                flag = '1';
                printf("\nStaff Name : ");
                puts(staff.name);

                printf("\nNurse Age : ");
                puts(staff.age);

                printf("\nStaff Phone NO : ");
                puts(staff.phone);

                printf("\nStaff Email : ");
                puts(staff.email);

                printf("\nStaff Address : ");
                puts(staff.address);

                printf("\nStaff Duty Time : ");
                puts(staff.duty_time);

                printf("\nStaff Salary : ");
                puts(staff.salary);

                printf("\n\n\t................ Press Any Key for OK ..................");
                getch();
            }
        }
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tSorry! You Have Entered Wrong Username");
            printf("\n\t\t\tPress Any Key to Continue....");
            getch();
        }
        fclose(fp);
        break;
    case '2':
        modify_staff_entry_by_staff();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        staff_login_panel();
        break;
    }
    staff_login_panel();
}

void nurse_login_panel()
{
    system("cls");
    FILE *fp;
    char choice, flag = '0', n_usr[20];
    printf("\n\t\t\t\t==== Nurse Panel ====\n\n\n");
    printf("\n\n\t1. Show Details.");
    printf("\n\t2. Update Informations.");
    printf("\n\t0. Logout.");
    printf("\n\t\tEnter Your Choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        loading_logout();
        user_login();
        break;
    case '1':
        system("cls");
        fp = fopen("nurse.BIN", "r");
        printf("\n\n\t\tEnter Username for Search : ");
        fflush(stdin);
        gets(n_usr);

        while (fread(&nurse, sizeof(nurse), 1, fp) == 1)
        {
            if (strcmp(nurse.usr, n_usr) == 0)
            {
                system("cls");
                flag = '1';
                printf("\nNurse Name : ");
                puts(nurse.name);

                printf("\nNurse Age : ");
                puts(nurse.age);

                printf("\nNurse Phone NO : ");
                puts(nurse.phone);

                printf("\nNurse Email : ");
                puts(nurse.email);

                printf("\nNurse Address : ");
                puts(nurse.address);

                printf("\nNurse Duty Time : ");
                puts(nurse.duty_time);

                printf("\nNurse Salary : ");
                puts(nurse.salary);

                printf("\n\n\t................ Press Any Key for OK ..................");
                getch();
            }
        }
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tSorry! You Have Entered Wrong Username");
            printf("\n\t\t\tPress Any Key to Continue....");
            getch();
        }
        fclose(fp);
        break;
    case '2':
        modify_nurse_entry_by_nurse();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        nurse_login_panel();
        break;
    }
    nurse_login_panel();
}

void doctor_login_panel()
{
    system("cls");
    FILE *fp;
    char choice, flag = '0', d_usr[20];
    printf("\n\t\t\t\t==== Doctor's Panel ====\n\n\n");
    printf("\n\n\t1. Show Details.");
    printf("\n\t2. Update Informations.");
    printf("\n\t3. Add Patient Details.");
    printf("\n\t0. Logout.");
    printf("\n\t\tEnter Your Choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        loading_logout();
        user_login();
        break;
    case '1':
        system("cls");
        fp = fopen("doctor.BIN", "r");
        printf("\n\n\t\tEnter Username for Search : ");
        fflush(stdin);
        gets(d_usr);

        while (fread(&doctor, sizeof(doctor), 1, fp) == 1)
        {
            if (strcmp(doctor.usr, d_usr) == 0)
            {
                system("cls");
                flag = '1';
                printf("\nDoctor Name : ");
                puts(doctor.name);

                printf("\nDoctor Age : ");
                puts(doctor.age);

                printf("\nDoctor Phone NO : ");
                puts(doctor.phone);

                printf("\nDoctor Email : ");
                puts(doctor.email);

                printf("\nDoctor Address : ");
                puts(doctor.address);

                printf("\nDoctor Room No : ");
                puts(doctor.room);

                printf("\nDoctor Duty Time : ");
                puts(doctor.duty_time);

                printf("\n\n\t................Press Any Key for OK ..................\n\n\n\n\n");
                getch();
            }
        }
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tSorry! You Have Entered Wrong Username");
            printf("\n\t\t\tPress Any Key to Continue....");
            getch();
        }
        fclose(fp);
        break;
    case '2':
        modify_doctor_entry_by_doctor();
        break;
    case '3':
        modify_patient_entry_by_doctor();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        fclose(fp);
        doctor_login_panel();
        break;
    }
    fclose(fp);
    doctor_login_panel();
}

void admin_login()
{
    system("cls");
    char choice;
    char usr_name[10], usr_pass[10], admin_name[] = "admin", admin_pass[] = "admin";
    printf("\n\t\t\t\t==== Admin Login Panel ====\n\n\n");
    printf("\n\n\tUsername : ");
    fflush(stdin);
    gets(usr_name);
    printf("\tPassword : ");
    fflush(stdin);
    gets(usr_pass);

    if ((strcmp(usr_pass, admin_pass) == 0) && (strcmp(usr_name, admin_name) == 0))
    {
        loading_login();
        admin_menu();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\tYou've entered wrong username or password\n");
        printf("\n\n\t\t\t\tPress 1 to try again!\n");
        printf("\t\t\t\tPress Any key to go back to Main Menu.....\n");
        choice = getche();
        if (choice == '1')
        {
            admin_login();
        }
        else
        {
            login();
        }
    }
}

void admin_menu()
{
    system("cls");
    char choice;
    printf("\n\t\t\t\t==== Admin Menu ====\n\n\n");
    printf("\n\t1. Patient ");
    printf("\n\t2. Doctor ");
    printf("\n\t3. Nurse ");
    printf("\n\t4. Staff ");
    printf("\n\t5. Modify Hospital Bed ");
    printf("\n\t0. Logout ");

    printf("\n\n\t\tEnter your choice : ");
    choice = getche();

    switch (choice)
    {
    case '0':
        loading_logout();
        login();
        break;
    case '1':
        patient_menu();
        break;
    case '2':
        doctor_menu();
        break;
    case '3':
        nurse_menu();
        break;
    case '4':
        staff_menu();
        break;
    case '5':
        modify_hospital_bed();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        admin_menu();
        break;
    }
}

void staff_menu()
{
    system("cls");
    char ch;
    printf("\n\t\t\t\t==== Staff Menu ====\n\n\n");
    printf("\n\t\t1. Enter a New Entry");
    printf("\n\t\t2. Search an Entry");
    printf("\n\t\t3. Modify Existing");
    printf("\n\t\t4. Delete an Entry");
    printf("\n\t\t5. Staff List");
    printf("\n\t\t0. <= Back");
    printf("\n\n\t\tEnter your choice here: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '0':
        admin_menu();
        break;
    case '1':
        create_staff_entry();
        break;
    case '2':
        search_staff_entry();
        break;
    case '3':
        modify_staff_entry();
        break;
    case '4':
        delete_staff_entry();
        break;
    case '5':
        staff_list();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        staff_menu();
        break;
    }
}

void nurse_menu()
{
    system("cls");
    char ch;
    printf("\n\t\t\t\t==== Nurse Menu ====\n\n\n");
    printf("\n\t\t1. Enter a New Entry");
    printf("\n\t\t2. Search an Entry");
    printf("\n\t\t3. Modify Existing");
    printf("\n\t\t4. Delete an Entry");
    printf("\n\t\t5. Nurse List");
    printf("\n\t\t0. <= Back");
    printf("\n\n\t\tEnter your choice here: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '0':
        admin_menu();
        break;
    case '1':
        create_nurse_entry();
        break;
    case '2':
        search_nurse_entry();
        break;
    case '3':
        modify_nurse_entry();
        break;
    case '4':
        delete_nurse_entry();
        break;
    case '5':
        nurse_list();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        nurse_menu();
        break;
    }
}

void staff_list()
{
    system("cls");
    FILE *staff_lst = fopen("staff.BIN", "r");
    printf("\n\t\t\t\t==== About Staff's ====\n\n\n");
    while (fread(&staff, sizeof(staff), 1, staff_lst) == 1)
    {
        printf("\nStaff Name : ");
        puts(staff.name);

        printf("\nStaff Age : ");
        puts(staff.age);

        printf("\nStaff Phone NO : ");
        puts(staff.phone);

        printf("\nStaff Email : ");
        puts(staff.email);

        printf("\nStaff Address : ");
        puts(staff.address);

        printf("\nStaff Duty Time : ");
        puts(staff.duty_time);

        printf("\nStaff Salary : ");
        puts(staff.salary);

        printf("\n\n......................................................................\n\n");
    }
    printf("\n\n\n\t................ Press Any Key for OK ..................\n\n");
    getch();
    fclose(staff_lst);
    staff_menu();
}

void nurse_list()
{
    system("cls");
    FILE *nurse_lst = fopen("nurse.BIN", "r");
    printf("\n\t\t\t\t==== About Nurse's ====\n\n\n");
    while (fread(&nurse, sizeof(nurse), 1, nurse_lst) == 1)
    {
        printf("\nNurse Name : ");
        puts(nurse.name);

        printf("\nNurse Age : ");
        puts(nurse.age);

        printf("\nNurse Phone NO : ");
        puts(nurse.phone);

        printf("\nNurse Email : ");
        puts(nurse.email);

        printf("\nNurse Address : ");
        puts(nurse.address);

        printf("\nNurse Duty Time : ");
        puts(nurse.duty_time);

        printf("\nNurse Salary : ");
        puts(nurse.salary);

        printf("\n\n......................................................................\n\n");
    }
    printf("\n\n\n\t................ Press Any Key for OK ..................\n\n");
    getch();
    fclose(nurse_lst);
    nurse_menu();
}

void patient_menu()
{
    system("cls");
    char ch;
    printf("\n\t\t\t\t==== Patient Menu ====\n\n\n");
    printf("\n\t\t1. Enter a New Patient Entry");
    printf("\n\t\t2. Admit Existing Patient");
    printf("\n\t\t3. Release Admited Patient");
    printf("\n\t\t4. Check Unavailable Beds");
    printf("\n\t\t5. Search an Entry");
    printf("\n\t\t6. Modify Existing");
    printf("\n\t\t7. Delete an Patient Entry");
    printf("\n\t\t8. All Patient List");
    printf("\n\t\t9. Payment");
    printf("\n\t\t0. <= Back");
    printf("\n\n\t\tEnter your choice here: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '0':
        admin_menu();
        break;
    case '1':
        create_patient_entry();
        break;
    case '2':
        admit_patient();
        break;
    case '3':
        release_patient();
        break;
    case '4':
        unavailable_bed_no();
        break;
    case '5':
        search_patient_entry();
        break;
    case '6':
        modify_patient_entry();
        break;
    case '7':
        delete_patient_entry();
        break;
    case '8':
        all_patient_list();
        break;
    case '9':
        patient_payment();
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        patient_menu();
        break;
    }
}

void patient_payment()
{
    system("cls");
    FILE *fp_pay1 = fopen("patient.BIN", "r");
    FILE *fp_pay2 = fopen("tmp.BIN", "a");
    char p_usr[20], flag = '0';
    printf("\n\t\t\t\t==== Patient Payment Panel ====\n\n\n");
    printf("\n\n\t\tEnter Username : ");
    fflush(stdin);
    gets(p_usr);
    while (fread(&patient, sizeof(patient), 1, fp_pay1) == 1)
    {
        if (strcmp(patient.usr, p_usr) == 0)
        {
            flag = '1';
            system("cls");
            printf("\n\n\t\tEnter Amount : ");
            scanf("%lf", &patient.pay);

            patient.paid = patient.pay + patient.paid;
            patient.due = patient.payable - patient.paid;
        }
        fwrite(&patient, sizeof(patient), 1, fp_pay2);
    }
    fclose(fp_pay1);
    fclose(fp_pay2);

    remove("patient.BIN");
    rename("tmp.BIN", "patient.BIN");
    printf("................................................................");
    if (flag == '0')
    {
        char con;
        system("cls");
        printf("\n\n\t\t\tYou Have Entered Wrong Username");
        printf("\n\t\t\tPress 1 to Continue Pay or Press any key (without 1) to Patient Menu....");
        con = getche();
        if (con == '1')
        {
            patient_payment();
        }
        else
        {
            patient_menu();
        }
    }
    fclose(fp_pay1);
    fclose(fp_pay2);
    patient_menu();
}

void all_patient_list()
{
    system("cls");
    FILE *patient_lst = fopen("patient.BIN", "r");
    printf("\n\t\t\t\t==== About Patient's ====\n\n\n");
    while (fread(&patient, sizeof(patient), 1, patient_lst) == 1)
    {
        printf("\nPatient Name : ");
        puts(patient.name);

        printf("\nPatient Age : ");
        puts(patient.age);

        printf("\nPatient Phone NO : ");
        puts(patient.phone);

        printf("\nPatient Email : ");
        puts(patient.email);

        printf("\nPatient Address : ");
        puts(patient.address);

        printf("\nPatient Bed No : ");
        printf("%d", patient.cabin_no);

        printf("\n\nPatient Diseases : ");
        puts(patient.diseases);

        printf("\nPatient Diseases Description : ");
        puts(patient.diseases_description);

        printf("\nPatient Test : ");
        puts(patient.test);

        printf("\nPatient Test Result : ");
        puts(patient.test_result);

        printf("\n.............................................................................................................\n");
        printf("\nTotal Payable (BDT) : %.2lf\t\tTotal Paid (BDT) : %.2lf\t\tTotal Due (BDT) : %.2lf\n", patient.payable, patient.paid, patient.due);
        printf("\n\n\n.............................................................................................................\n");
    }
    printf("\n\n\n\t................ Press Any Key for OK ..................\n\n");
    getch();
    fclose(patient_lst);
    patient_menu();
}

void doctor_menu()
{
    system("cls");
    char ch;
    printf("\n\t\t\t\t==== Doctor Menu ====\n\n\n");
    printf("\n\t\t1. Enter a New Entry");
    printf("\n\t\t2. Search an Entry");
    printf("\n\t\t3. Modify Existing");
    printf("\n\t\t4. Delete an Entry");
    printf("\n\t\t5. All Doctors List");
    printf("\n\t\t0. <= Back");
    printf("\n\n\t\tEnter your choice here: ");
    fflush(stdin);
    ch = getche();
    switch (ch)
    {
    case '0':
        admin_menu();
        break;
    case '1':
        create_doctor_entry();
        break;
    case '2':
        search_doctor_entry();
        break;
    case '3':
        modify_doctor_entry();
        break;
    case '4':
        delete_doctor_entry();
        break;
    case '5':
        about_doctor(1);
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        doctor_menu();
        break;
    }
}

void create_staff_entry()
{

    char another = 'y';
    char s_usr[25];
    FILE *fp, *fp1;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("staff.BIN", "a");
        fp1 = fopen("staff.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Creating Staff Account ====\n\n\n");
    s_w:
        printf("\nEnter Username : ");
        fflush(stdin);
        gets(s_usr);
        rewind(fp1);
        while (fread(&staff, sizeof(staff), 1, fp1) == 1)
        {
            if (strcmp(staff.usr, s_usr) == 0)
            {
                system("cls");
                printf("\n\n\t\tSORRY! THIS USERNAME ALREADY EXISTS.");
                printf("\n\t\tPLEASE ENTER ANOTHER USERNAME....");
                goto s_w;
            }
        }
        strcpy(staff.usr, s_usr);

        printf("\nEnter Password : ");
        fflush(stdin);
        gets(staff.pass);

        printf("\nEnter Staff Name : ");
        fflush(stdin);
        gets(staff.name);

        printf("\nEnter Staff Age : ");
        fflush(stdin);
        gets(staff.age);

        printf("\nEnter Staff Phone NO : ");
        fflush(stdin);
        gets(staff.phone);

        printf("\nEnter Staff Email : ");
        fflush(stdin);
        gets(staff.email);

        printf("\nEnter Staff Address : ");
        fflush(stdin);
        gets(staff.address);

        printf("\nEnter Staff Duty Time : ");
        fflush(stdin);
        gets(staff.duty_time);

        printf("\nEnter Staff salary : ");
        fflush(stdin);
        gets(staff.salary);

        fwrite(&staff, sizeof(staff), 1, fp);
        fclose(fp);
        fclose(fp1);

        printf("Do you want to create another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    fclose(fp1);
    staff_menu();
}

void create_nurse_entry()
{

    char another = 'y';
    char n_usr[25];
    FILE *fp, *fp1;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("nurse.BIN", "a");
        fp1 = fopen("nurse.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Creating Nurse Account ====\n\n\n");
    n_w:
        printf("\nEnter Username : ");
        fflush(stdin);
        gets(n_usr);
        rewind(fp1);
        while (fread(&nurse, sizeof(nurse), 1, fp1) == 1)
        {
            if (strcmp(nurse.usr, n_usr) == 0)
            {
                system("cls");
                printf("\n\n\t\tSORRY! THIS USERNAME ALREADY EXISTS.");
                printf("\n\t\tPLEASE ENTER ANOTHER USERNAME....");
                goto n_w;
            }
        }
        strcpy(nurse.usr, n_usr);

        printf("\nEnter Password : ");
        fflush(stdin);
        gets(nurse.pass);

        printf("\nEnter Nurse Name : ");
        fflush(stdin);
        gets(nurse.name);

        printf("\nEnter Nurse Age : ");
        fflush(stdin);
        gets(nurse.age);

        printf("\nEnter Nurse Phone NO : ");
        fflush(stdin);
        gets(nurse.phone);

        printf("\nEnter Nurse Email : ");
        fflush(stdin);
        gets(nurse.email);

        printf("\nEnter Nurse Address : ");
        fflush(stdin);
        gets(nurse.address);

        printf("\nEnter Nurse Duty Time : ");
        fflush(stdin);
        gets(nurse.duty_time);

        printf("\nEnter Nurse salary : ");
        fflush(stdin);
        gets(nurse.salary);

        fwrite(&nurse, sizeof(nurse), 1, fp);
        ;
        fclose(fp);
        fclose(fp1);

        printf("Do you want to create another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    fclose(fp1);
    nurse_menu();
}

void create_doctor_entry()
{

    char another = 'y';
    char d_usr[25];
    FILE *fp, *fp1;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("doctor.BIN", "a");
        fp1 = fopen("doctor.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Creating Doctor Account ====\n\n\n");
    d_w:
        printf("\nEnter Username : ");
        fflush(stdin);
        gets(d_usr);
        rewind(fp1);
        while (fread(&doctor, sizeof(doctor), 1, fp1) == 1)
        {
            if (strcmp(doctor.usr, d_usr) == 0)
            {
                system("cls");
                printf("\n\n\t\tSORRY! THIS USERNAME ALREADY EXISTS.");
                printf("\n\t\tPLEASE ENTER ANOTHER USERNAME....");
                goto d_w;
            }
        }
        strcpy(doctor.usr, d_usr);

        printf("\nEnter Password : ");
        fflush(stdin);
        gets(doctor.pass);

        printf("\nEnter Doctor Name : ");
        fflush(stdin);
        gets(doctor.name);

        printf("\nEnter Doctor Age : ");
        fflush(stdin);
        gets(doctor.age);

        printf("\nEnter Doctor Phone NO : ");
        fflush(stdin);
        gets(doctor.phone);

        printf("\nEnter Doctor Email : ");
        fflush(stdin);
        gets(doctor.email);

        printf("\nEnter Doctor Address : ");
        fflush(stdin);
        gets(doctor.address);

        printf("\nEnter Doctor Room No : ");
        fflush(stdin);
        gets(doctor.room);

        printf("\nEnter Doctor Duty Time : ");
        fflush(stdin);
        gets(doctor.duty_time);

        fwrite(&doctor, sizeof(doctor), 1, fp);
        ;
        fclose(fp);
        fclose(fp1);

        printf("Do you want to create another account ? (Y/N) : ");
        another = getche();
    }
    fclose(fp);
    fclose(fp1);
    doctor_menu();
}

void create_patient_entry()
{

    char another = 'y';
    char p_usr[25];
    FILE *fp, *fp1;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("patient.BIN", "a");
        fp1 = fopen("patient.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Creating Patient Account ====\n\n\n");

    p_w:
        printf("\nEnter Username : ");
        fflush(stdin);
        gets(p_usr);
        rewind(fp1);
        while (fread(&patient, sizeof(patient), 1, fp1) == 1)
        {
            if (strcmp(patient.usr, p_usr) == 0)
            {
                system("cls");
                printf("\n\n\t\tSORRY! THIS USERNAME ALREADY EXISTS.");
                printf("\n\t\tPLEASE ENTER ANOTHER USERNAME....");
                goto p_w;
            }
        }
        fseek(fp, 0, SEEK_END);

        strcpy(patient.usr, p_usr);

        printf("\nEnter Password : ");
        fflush(stdin);
        gets(patient.pass);

        printf("\nEnter Patient Name : ");
        fflush(stdin);
        gets(patient.name);

        printf("\nEnter Patient Age : ");
        fflush(stdin);
        gets(patient.age);

        printf("\nEnter Patient Phone NO : ");
        fflush(stdin);
        gets(patient.phone);

        printf("\nEnter Patient Email : ");
        fflush(stdin);
        gets(patient.email);

        printf("\nEnter Patient Address : ");
        fflush(stdin);
        gets(patient.address);

        printf("\nEnter Patient Diseases : ");
        fflush(stdin);
        gets(patient.diseases);

        printf("\nEnter Patient Diseases Description : ");
        fflush(stdin);
        gets(patient.diseases_description);

        printf("\nEnter Patient Test : ");
        fflush(stdin);
        gets(patient.test);

        printf("\nEnter Patient Test Result : ");
        fflush(stdin);
        gets(patient.test_result);

        printf("\nTotal Payable (BDT) : ");
        fflush(stdin);
        scanf("%lf", &patient.payable);

        printf("\n Pay (BDT) : ");
        fflush(stdin);
        scanf("%lf", &patient.pay);

        patient.cabin_no = 0;

        patient.due = 0;
        patient.paid = 0;

        patient.due = patient.payable - patient.pay;
        patient.paid = patient.pay + patient.paid;

        fwrite(&patient, sizeof(patient), 1, fp);
        fclose(fp);
        fclose(fp1);

        printf("Do you want to create another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    fclose(fp1);
    patient_menu();
}

void search_staff_entry()
{

    char another = 'y', ch;
    char s_usr[25], s_name[20], flag = '0';
    FILE *fp;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("staff.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Searching Staff Account ====\n\n\n");

        printf("\n\n\t1. Search by Username.");
        printf("\n\t2. Search by Name.");
        printf("\n\t3. <= Back.");
        printf("\n\n\tEnter your Choice : ");
        ch = getche();

        switch (ch)
        {
        case '1':
            printf("\n\n\tEnter Username for Search : ");
            fflush(stdin);
            gets(s_usr);
            rewind(fp);

            while (fread(&staff, sizeof(staff), 1, fp) == 1)
            {
                if (strcmp(staff.usr, s_usr) == 0)
                {
                    flag = '1';

                    printf("\nStaff Name : ");
                    puts(staff.name);

                    printf("\nStaff Age : ");
                    puts(staff.age);

                    printf("\nStaff Phone NO : ");
                    puts(staff.phone);

                    printf("\nStaff Email : ");
                    puts(staff.email);

                    printf("\nStaff Address : ");
                    puts(staff.address);

                    printf("\nStaff Duty Time: ");
                    puts(staff.duty_time);

                    printf("\nStaff Salary  : ");
                    puts(staff.salary);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue searching or Press any key (without 1) to Nurse Menu....");
                con = getche();
                if (con == '1')
                {
                    search_nurse_entry();
                }
                else
                    nurse_menu();
            }
            fclose(fp);
            break;
        case '2':
            printf("\n\n\tEnter Name for Search : ");
            fflush(stdin);
            gets(s_name);
            rewind(fp);

            while (fread(&staff, sizeof(staff), 1, fp) == 1)
            {
                if (strcmp(staff.name, s_name) == 0)
                {
                    flag = '1';

                    printf("\nStaff Name : ");
                    puts(staff.name);

                    printf("\nStaff Age : ");
                    puts(staff.age);

                    printf("\nStaff Phone NO : ");
                    puts(staff.phone);

                    printf("\nStaff Email : ");
                    puts(staff.email);

                    printf("\nStaff Address : ");
                    puts(staff.address);

                    printf("\nStaff Duty Time: ");
                    puts(staff.duty_time);

                    printf("\nStaff Salary  : ");
                    puts(staff.salary);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue Searching or Press any key (without 1) to Staff Menu....");
                getch();
                con = getche();
                if (con == '1')
                {
                    search_staff_entry();
                }
                else
                    staff_menu();
            }
            fclose(fp);
            break;
        case '3':
            fclose(fp);
            staff_menu();
            break;
        default:
            system("cls");
            printf("\n\t\tSorry! Your choice is incorrect.\n\n");
            printf("\t\tPress any key to continue......");
            getch();
            fclose(fp);
            search_staff_entry();
            break;
        }
        fclose(fp);
        printf("Do you want to search another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    staff_menu();
}

void search_nurse_entry()
{

    char another = 'y', ch;
    char n_usr[25], n_name[20], flag = '0';
    FILE *fp;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("nurse.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Searching Nurse Account ====\n\n\n");

        printf("\n\n\t1. Search by Username.");
        printf("\n\t2. Search by Name.");
        printf("\n\t3. <= Back.");
        printf("\n\n\tEnter your Choice : ");
        ch = getche();

        switch (ch)
        {
        case '1':
            printf("\n\n\tEnter Username for Search : ");
            fflush(stdin);
            gets(n_usr);
            rewind(fp);

            while (fread(&nurse, sizeof(nurse), 1, fp) == 1)
            {
                if (strcmp(nurse.usr, n_usr) == 0)
                {
                    flag = '1';

                    printf("\nNurse Name : ");
                    puts(nurse.name);

                    printf("\nNurse Age : ");
                    puts(nurse.age);

                    printf("\nNurse Phone NO : ");
                    puts(nurse.phone);

                    printf("\nNurse Email : ");
                    puts(nurse.email);

                    printf("\nNurse Address : ");
                    puts(nurse.address);

                    printf("\nNurse Duty Time : ");
                    puts(nurse.duty_time);

                    printf("\nNurse Salary : ");
                    puts(nurse.salary);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue searching or Press any key (without 1) to Nurse Menu....");
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_nurse_entry();
                }
                else
                {
                    fclose(fp);
                    nurse_menu();
                }
            }
            fclose(fp);
            break;
        case '2':
            printf("\n\n\tEnter Name for Search : ");
            fflush(stdin);
            gets(n_name);
            rewind(fp);

            while (fread(&nurse, sizeof(nurse), 1, fp) == 1)
            {
                if (strcmp(nurse.name, n_name) == 0)
                {
                    flag = '1';

                    printf("\nNurse Name : ");
                    puts(nurse.name);

                    printf("\nNurse Age : ");
                    puts(nurse.age);

                    printf("\nNurse Phone NO : ");
                    puts(nurse.phone);

                    printf("\nNurse Email : ");
                    puts(nurse.email);

                    printf("\nNurse Address : ");
                    puts(nurse.address);

                    printf("\nNurse Duty Time: ");
                    puts(nurse.duty_time);

                    printf("\nNurse Salary  : ");
                    puts(nurse.salary);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue Searching or Press any key (without 1) to Nurse Menu....");
                getch();
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_nurse_entry();
                }
                else
                {
                    fclose(fp);
                    nurse_menu();
                }
            }
            fclose(fp);
            break;
        case '3':
            fclose(fp);
            nurse_menu();
            break;
        default:
            system("cls");
            printf("\n\t\tSorry! Your choice is incorrect.\n\n");
            printf("\t\tPress any key to continue......");
            getch();
            fclose(fp);
            search_nurse_entry();
            break;
        }
        fclose(fp);
        printf("Do you want to search another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    nurse_menu();
}

void search_doctor_entry()
{

    char another = 'y', ch;
    char d_usr[25], d_name[20], flag = '0';
    FILE *fp;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("doctor.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Searching Doctor Account ====\n\n\n");

        printf("\n\n\t1. Search by Username.");
        printf("\n\t2. Search by Name.");
        printf("\n\t3. <= Back.");
        printf("\n\n\tEnter your Choice : ");
        ch = getche();

        switch (ch)
        {
        case '1':
            printf("\n\n\tEnter Username for Search : ");
            fflush(stdin);
            gets(d_usr);
            rewind(fp);

            while (fread(&doctor, sizeof(doctor), 1, fp) == 1)
            {
                if (strcmp(doctor.usr, d_usr) == 0)
                {
                    flag = '1';

                    printf("\nDoctor Name : ");
                    puts(doctor.name);

                    printf("\nDoctor Age : ");
                    puts(doctor.age);

                    printf("\nDoctor Phone NO : ");
                    puts(doctor.phone);

                    printf("\nDoctor Email : ");
                    puts(doctor.email);

                    printf("\nDoctor Address : ");
                    puts(doctor.address);

                    printf("\nDoctor Room No : ");
                    puts(doctor.room);

                    printf("\nDoctor Duty Time : ");
                    puts(doctor.duty_time);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue searching or Press any key (without 1) to Doctor Menu....");
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_doctor_entry();
                }
                else
                {
                    fclose(fp);
                    doctor_menu();
                }
            }
            fclose(fp);
            break;
        case '2':
            printf("\n\n\tEnter Name for Search : ");
            fflush(stdin);
            gets(d_name);
            rewind(fp);

            while (fread(&doctor, sizeof(doctor), 1, fp) == 1)
            {
                if (strcmp(doctor.name, d_name) == 0)
                {
                    flag = '1';

                    printf("\nDoctor Name : ");
                    puts(doctor.name);

                    printf("\nDoctor Age : ");
                    puts(doctor.age);

                    printf("\nDoctor Phone NO : ");
                    puts(doctor.phone);

                    printf("\nDoctor Email : ");
                    puts(doctor.email);

                    printf("\nDoctor Address : ");
                    puts(doctor.address);

                    printf("\nDoctor Address : ");
                    puts(doctor.room);

                    printf("\nDoctor Duty Time : ");
                    puts(doctor.duty_time);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Name");
                printf("\n\t\t\tPress 1 to Continue Searching or Press any key (without 1) to Doctor Menu....");
                getch();
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_doctor_entry();
                }
                else
                {
                    fclose(fp);
                    doctor_menu();
                }
            }
            fclose(fp);
            break;
        case '3':
            fclose(fp);
            doctor_menu();
            break;
        default:
            system("cls");
            printf("\n\t\tSorry! Your choice is incorrect.\n\n");
            printf("\t\tPress any key to continue......");
            getch();
            fclose(fp);
            search_doctor_entry();
            break;
        }
        fclose(fp);
        printf("Do you want to search another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    doctor_menu();
}

void search_patient_entry()
{

    char another = 'y', ch;
    char p_usr[25], p_name[20], flag = '0';
    FILE *fp;
    while (another == 'y' || another == 'Y')
    {

        fp = fopen("patient.BIN", "r");

        system("cls");
        printf("\n\t\t\t\t==== Searching Patient Account ====\n\n\n");

        printf("\n\n\t1. Search by Username.");
        printf("\n\t2. Search by Name.");
        printf("\n\t3. <= Back.");
        printf("\n\n\tEnter your Choice : ");
        ch = getche();

        switch (ch)
        {
        case '1':
            printf("\n\n\tEnter Username for Search : ");
            fflush(stdin);
            gets(p_usr);
            rewind(fp);

            while (fread(&patient, sizeof(patient), 1, fp) == 1)
            {
                if (strcmp(patient.usr, p_usr) == 0)
                {
                    flag = '1';

                    printf("\nPatient Name : ");
                    puts(patient.name);

                    printf("\nPatient Age : ");
                    puts(patient.age);

                    printf("\nPatient Phone NO : ");
                    puts(patient.phone);

                    printf("\nPatient Email : ");
                    puts(patient.email);

                    printf("\nPatient Address : ");
                    puts(patient.address);

                    printf("\nPatient Bed No : ");
                    printf("%d", patient.cabin_no);

                    printf("\n\nPatient Diseases : ");
                    puts(patient.diseases);

                    printf("\nPatient Diseases Description : ");
                    puts(patient.diseases_description);

                    printf("\nPatient Test : ");
                    puts(patient.test);

                    printf("\nPatient Test Result : ");
                    puts(patient.test_result);

                    printf("\n.............................................................................................................\n");
                    printf("\nTotal Payable (BDT) : %.2lf\t\tTotal Paid (BDT) : %.2lf\t\tTotal Due (BDT) : %.2lf\n", patient.payable, patient.paid, patient.due);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue Searching or Press any key (without 1) to Patient Menu....");
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_patient_entry();
                }
                else
                {
                    fclose(fp);
                    patient_menu();
                }
            }
            fclose(fp);
            break;
        case '2':
            printf("\n\n\tEnter Name for Search : ");
            fflush(stdin);
            gets(p_name);
            rewind(fp);

            while (fread(&patient, sizeof(patient), 1, fp) == 1)
            {
                if (strcmp(patient.name, p_name) == 0)
                {
                    flag = '1';

                    printf("\nPatient Name : ");
                    puts(patient.name);

                    printf("\nPatient Age : ");
                    puts(patient.age);

                    printf("\nPatient Phone NO : ");
                    puts(patient.phone);

                    printf("\nPatient Email : ");
                    puts(patient.email);

                    printf("\nPatient Address : ");
                    puts(patient.address);

                    printf("\nPatient Bed No : ");
                    printf("%d", patient.cabin_no);

                    printf("\n\nPatient Diseases : ");
                    puts(patient.diseases);

                    printf("\nPatient Diseases Description : ");
                    puts(patient.diseases_description);

                    printf("\nPatient Test : ");
                    puts(patient.test);

                    printf("\nPatient Test Result : ");
                    puts(patient.test_result);

                    printf("\n.............................................................................................................\n");
                    printf("\nTotal Payable (BDT) : %.2lf\t\tTotal Paid (BDT) : %.2lf\t\tTotal Due (BDT) : %.2lf\n", patient.payable, patient.paid, patient.due);
                }
            }
            if (flag == '0')
            {
                char con;
                system("cls");
                printf("\n\n\t\t\tYou Have Entered Wrong Username");
                printf("\n\t\t\tPress 1 to Continue searching or Press any key (without 1) to Patient Menu....");
                getch();
                con = getche();
                if (con == '1')
                {
                    fclose(fp);
                    search_patient_entry();
                }
                else
                {
                    fclose(fp);
                    patient_menu();
                }
            }
            fclose(fp);
            break;
        case '3':
            fclose(fp);
            patient_menu();
            break;
        default:
            system("cls");
            printf("\n\t\tSorry! Your choice is incorrect.\n\n");
            printf("\t\tPress any key to continue......");
            getch();
            fclose(fp);
            search_patient_entry();
            break;
        }
        fclose(fp);
        printf("Do you want to search another account ? (Y or N) : ");
        another = getche();
    }
    fclose(fp);
    patient_menu();
}

void modify_staff_entry()
{
    system("cls");
    char another = 'y', s_user[10], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {
        system("cls");

        fp1 = fopen("staff.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Modifying Staff Account ====\n\n\n");
        printf("Enter Staff Username to Modify : ");
        fflush(stdin);
        gets(s_user);
        // rewind (fp1) ;

        while (fread(&staff, sizeof(staff), 1, fp1) == 1)
        {
            if (strcmp(staff.usr, s_user) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Username.");
                printf("\n\t2. Password.");
                printf("\n\t3. Name.");
                printf("\n\t4. Age.");
                printf("\n\t5. Phone No.");
                printf("\n\t6. Email.");
                printf("\n\t7. Room No.");
                printf("\n\t8. Duty Time.");
                printf("\n\t9. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    // rename("new.BIN", "staff.BIN");
                    staff_menu();
                    break;
                case '1':
                    system("cls");
                    printf("\n\t\t Enter Staff New Username : ");
                    fflush(stdin);
                    gets(staff.usr);
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter Staff New Password : ");
                    fflush(stdin);
                    gets(staff.pass);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter Staff New Name : ");
                    fflush(stdin);
                    gets(staff.name);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter Staff New Age : ");
                    fflush(stdin);
                    gets(staff.age);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter Staff New Phone No : ");
                    fflush(stdin);
                    gets(staff.phone);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter Staff New Email : ");
                    fflush(stdin);
                    gets(staff.email);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter Staff New Salary : ");
                    fflush(stdin);
                    gets(staff.salary);
                    break;
                case '8':
                    system("cls");
                    printf("\n\t\t Enter Staff New Duty Time : ");
                    fflush(stdin);
                    gets(staff.duty_time);
                    break;
                case '9':
                    system("cls");
                    printf("\n\t\t Enter Staff Address : ");
                    fflush(stdin);
                    gets(staff.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_staff_entry();
                    break;
                }
            }
            fwrite(&staff, sizeof(staff), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("staff.BIN");
        rename("new.BIN", "staff.BIN");
        // system ("del /f nurse") ;
        // system ("rename new nurse") ;
        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Staff Menu....");
            con = getche();
            if (con == '1')
            {
                fclose(fp1);
                fclose(fp2);
                modify_staff_entry();
            }
            else
            {
                fclose(fp1);
                fclose(fp2);
                staff_menu();
            }
        }
        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    staff_menu();
}

void modify_nurse_entry()
{
    system("cls");
    char another = 'y', n_user[10], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {
        system("cls");
        fp1 = fopen("nurse.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Modifying Nurse Account ====\n\n\n");
        printf("Enter Nurse Username to Modify : ");
        fflush(stdin);
        gets(n_user);
        // rewind (fp1) ;

        while (fread(&nurse, sizeof(nurse), 1, fp1) == 1)
        {
            if (strcmp(nurse.usr, n_user) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Username.");
                printf("\n\t2. Password.");
                printf("\n\t3. Name.");
                printf("\n\t4. Age.");
                printf("\n\t5. Phone No.");
                printf("\n\t6. Email.");
                printf("\n\t7. Room No.");
                printf("\n\t8. Duty Time.");
                printf("\n\t9. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    nurse_menu();
                    break;
                case '1':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Username : ");
                    fflush(stdin);
                    gets(nurse.usr);
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Password : ");
                    fflush(stdin);
                    gets(nurse.pass);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Name : ");
                    fflush(stdin);
                    gets(nurse.name);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Age : ");
                    fflush(stdin);
                    gets(nurse.age);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Phone No : ");
                    fflush(stdin);
                    gets(nurse.phone);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Email : ");
                    fflush(stdin);
                    gets(nurse.email);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Salary : ");
                    fflush(stdin);
                    gets(nurse.salary);
                    break;
                case '8':
                    system("cls");
                    printf("\n\t\t Enter Nurse New Duty Time : ");
                    fflush(stdin);
                    gets(nurse.duty_time);
                    break;
                case '9':
                    system("cls");
                    printf("\n\t\t Enter Nurse Address : ");
                    fflush(stdin);
                    gets(nurse.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_nurse_entry();
                    break;
                }
            }
            fwrite(&nurse, sizeof(nurse), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("nurse.BIN");
        rename("new.BIN", "nurse.BIN");
        // system ("del /f nurse") ;
        // system ("rename new nurse") ;
        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Nurse Menu....");
            con = getche();
            if (con == '1')
            {
                modify_nurse_entry();
            }
            else
            {
                nurse_menu();
            }
        }
        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    nurse_menu();
}

void modify_patient_entry_by_patient()
{
    system("cls");
    char another = 'y', p_user[20], p_pass[20], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {

        system("cls");
        fp1 = fopen("patient.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Update Information ====\n\n\n");
        printf("Enter Your Username : ");
        fflush(stdin);
        gets(p_user);
        printf("Enter Your Password : ");
        fflush(stdin);
        gets(p_pass);
        // rewind (fp1) ;

        while (fread(&patient, sizeof(patient), 1, fp1) == 1)
        {
            if (strcmp(patient.usr, p_user) == 0 && strcmp(patient.pass, p_pass) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Update ? :");
                printf("\n\t1. Password.");
                printf("\n\t2. Name.");
                printf("\n\t3. Age.");
                printf("\n\t4. Phone No.");
                printf("\n\t5. Email.");
                printf("\n\t6. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    patient_login_panel();
                    break;
                case '1':
                again_pass2:
                    system("cls");
                    char conf_pass1[20], conf_pass2[20];
                    printf("\n\t\t Enter New Password : ");
                    fflush(stdin);
                    gets(conf_pass1);
                    printf("\n\t\t Enter Password Again : ");
                    fflush(stdin);
                    gets(conf_pass2);
                    if (strcmp(conf_pass1, conf_pass2) == 0)
                    {
                        strcpy(patient.pass, conf_pass2);
                        system("cls");
                        printf("\n\n\t\tYour password has been updated successfully.\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\t\tSorry! Password Not Matched\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                        goto again_pass2;
                    }
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter New Name : ");
                    fflush(stdin);
                    gets(patient.name);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter New Age : ");
                    fflush(stdin);
                    gets(patient.age);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter New Phone No : ");
                    fflush(stdin);
                    gets(patient.phone);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter New Email : ");
                    fflush(stdin);
                    gets(patient.email);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter New Address : ");
                    fflush(stdin);
                    gets(patient.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_patient_entry_by_patient();
                    break;
                }
            }
            fwrite(&patient, sizeof(patient), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("patient.BIN");
        rename("new.BIN", "patient.BIN");
        // system ("del /f patient") ;
        // system ("rename new patient") ;
        printf("\n................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Patient Panel....");
            con = getche();
            if (con == '1')
            {
                modify_patient_entry_by_patient();
            }
            else
            {
                patient_login_panel();
            }
        }
        printf("\nUpdate another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    patient_login_panel();
}

void modify_staff_entry_by_staff()
{
    system("cls");
    char another = 'y', s_user[20], s_pass[20], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {

        system("cls");
        fp1 = fopen("staff.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Update Information ====\n\n\n");
        printf("Enter Your Username : ");
        fflush(stdin);
        gets(s_user);
        printf("Enter Your Password : ");
        fflush(stdin);
        gets(s_pass);
        // rewind (fp1) ;

        while (fread(&staff, sizeof(staff), 1, fp1) == 1)
        {
            if (strcmp(staff.usr, s_user) == 0 && strcmp(staff.pass, s_pass) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Update ? :");
                printf("\n\t1. Password.");
                printf("\n\t2. Name.");
                printf("\n\t3. Age.");
                printf("\n\t4. Phone No.");
                printf("\n\t5. Email.");
                printf("\n\t6. Duty Time.");
                printf("\n\t7. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    staff_login_panel();
                    break;
                case '1':
                again_pass1:
                    system("cls");
                    char conf_pass1[20], conf_pass2[20];
                    printf("\n\t\t Enter New Password : ");
                    fflush(stdin);
                    gets(conf_pass1);
                    printf("\n\t\t Enter Password Again : ");
                    fflush(stdin);
                    gets(conf_pass2);
                    if (strcmp(conf_pass1, conf_pass2) == 0)
                    {
                        strcpy(staff.pass, conf_pass2);
                        system("cls");
                        printf("\n\n\t\tYour password has been updated successfully.\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\t\tSorry! Password Not Matched\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                        goto again_pass1;
                    }
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter New Name : ");
                    fflush(stdin);
                    gets(staff.name);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter New Age : ");
                    fflush(stdin);
                    gets(staff.age);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter New Phone No : ");
                    fflush(stdin);
                    gets(staff.phone);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter New Email : ");
                    fflush(stdin);
                    gets(staff.email);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter New Duty Time : ");
                    fflush(stdin);
                    gets(staff.duty_time);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter New Address : ");
                    fflush(stdin);
                    gets(staff.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_staff_entry_by_staff();
                    break;
                }
            }
            fwrite(&staff, sizeof(staff), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("staff.BIN");
        rename("new.BIN", "staff.BIN");
        // system ("del /f staff") ;
        // system ("rename new staff") ;
        printf("\n................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Staff Panel....");
            con = getche();
            if (con == '1')
            {
                modify_staff_entry_by_staff();
            }
            else
            {
                staff_login_panel();
            }
        }
        printf("\nUpdate another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    staff_login_panel();
}

void modify_nurse_entry_by_nurse()
{
    system("cls");
    char another = 'y', n_user[20], n_pass[20], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {

        system("cls");
        fp1 = fopen("nurse.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Update Information ====\n\n\n");
        printf("Enter Your Username : ");
        fflush(stdin);
        gets(n_user);
        printf("Enter Your Password : ");
        fflush(stdin);
        gets(n_pass);
        // rewind (fp1) ;

        while (fread(&nurse, sizeof(nurse), 1, fp1) == 1)
        {
            if (strcmp(nurse.usr, n_user) == 0 && strcmp(nurse.pass, n_pass) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Password.");
                printf("\n\t2. Name.");
                printf("\n\t3. Age.");
                printf("\n\t4. Phone No.");
                printf("\n\t5. Email.");
                printf("\n\t6. Duty Time.");
                printf("\n\t7. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    nurse_login_panel();
                    break;
                case '1':
                again_pass:
                    system("cls");
                    char conf_pass1[20], conf_pass2[20];
                    printf("\n\t\t Enter New Password : ");
                    fflush(stdin);
                    gets(conf_pass1);
                    printf("\n\t\t Enter Password Again : ");
                    fflush(stdin);
                    gets(conf_pass2);
                    if (strcmp(conf_pass1, conf_pass2) == 0)
                    {
                        strcpy(nurse.pass, conf_pass2);
                        system("cls");
                        printf("\n\n\t\tYour password has been updated successfully.\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\t\tSorry! Password Not Matched\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                        goto again_pass;
                    }
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter New Name : ");
                    fflush(stdin);
                    gets(nurse.name);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter New Age : ");
                    fflush(stdin);
                    gets(nurse.age);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter New Phone No : ");
                    fflush(stdin);
                    gets(nurse.phone);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter New Email : ");
                    fflush(stdin);
                    gets(nurse.email);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter New Duty Time : ");
                    fflush(stdin);
                    gets(nurse.duty_time);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter New Address : ");
                    fflush(stdin);
                    gets(nurse.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_nurse_entry_by_nurse();
                    break;
                }
            }
            fwrite(&nurse, sizeof(nurse), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("nurse.BIN");
        rename("new.BIN", "nurse.BIN");
        // system ("del /f nurse") ;
        // system ("rename new nurse") ;
        printf("\n................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Nurse Panel....");
            con = getche();
            if (con == '1')
            {
                modify_nurse_entry_by_nurse();
            }
            else
            {
                nurse_login_panel();
            }
        }
        printf("\nUpdate another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    nurse_login_panel();
}

void modify_doctor_entry_by_doctor()
{
    system("cls");
    char another = 'y', d_user[20], d_pass[20], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {

        system("cls");
        fp1 = fopen("doctor.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Update Information ====\n\n\n");
        printf("Enter Your Username : ");
        fflush(stdin);
        gets(d_user);
        printf("Enter Your Password : ");
        fflush(stdin);
        gets(d_pass);
        // rewind (fp1) ;

        while (fread(&doctor, sizeof(doctor), 1, fp1) == 1)
        {
            if (strcmp(doctor.usr, d_user) == 0 && strcmp(doctor.pass, d_pass) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Password.");
                printf("\n\t2. Name.");
                printf("\n\t3. Age.");
                printf("\n\t4. Phone No.");
                printf("\n\t5. Email.");
                printf("\n\t6. Room No.");
                printf("\n\t7. Duty Time.");
                printf("\n\t8. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    // rename("new.BIN", "doctor.BIN");
                    doctor_login_panel();
                    break;
                case '1':
                again_pass:
                    system("cls");
                    char conf_pass1[20], conf_pass2[20];
                    printf("\n\t\t Enter New Password : ");
                    fflush(stdin);
                    gets(conf_pass1);
                    printf("\n\t\t Enter Password Again : ");
                    fflush(stdin);
                    gets(conf_pass2);
                    if (strcmp(conf_pass1, conf_pass2) == 0)
                    {
                        strcpy(doctor.pass, conf_pass2);
                        system("cls");
                        printf("\n\n\t\tYour password has been updated successfully.\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\t\tSorry! Password Not Matched\n\n");
                        printf("\t\tPress Any key to continue.....");
                        getch();
                        goto again_pass;
                    }
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter New Name : ");
                    fflush(stdin);
                    gets(doctor.name);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter New Age : ");
                    fflush(stdin);
                    gets(doctor.age);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter New Phone No : ");
                    fflush(stdin);
                    gets(doctor.phone);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter New Email : ");
                    fflush(stdin);
                    gets(doctor.email);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter New Room No : ");
                    fflush(stdin);
                    gets(doctor.room);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter New Duty Time : ");
                    fflush(stdin);
                    gets(doctor.duty_time);
                    break;
                case '8':
                    system("cls");
                    printf("\n\t\t Enter New Address : ");
                    fflush(stdin);
                    gets(doctor.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_doctor_entry_by_doctor();
                    break;
                }
            }
            fwrite(&doctor, sizeof(doctor), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("doctor.BIN");
        rename("new.BIN", "doctor.BIN");
        // system ("del /f doctor") ;
        // system ("rename new doctor") ;
        printf("\n................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Doctor's Panel....");
            con = getche();
            if (con == '1')
            {
                modify_doctor_entry_by_doctor();
            }
            else
            {
                doctor_login_panel();
            }
        }
        printf("\nUpdate another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    doctor_login_panel();
}

void modify_doctor_entry()
{
    system("cls");
    char another = 'y', d_user[10], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {
        system("cls");
        fp1 = fopen("doctor.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Modifying Doctor Account ====\n\n\n");
        printf("Enter Doctor Username to Modify : ");
        fflush(stdin);
        gets(d_user);
        // rewind (fp1) ;

        while (fread(&doctor, sizeof(doctor), 1, fp1) == 1)
        {
            if (strcmp(doctor.usr, d_user) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Username.");
                printf("\n\t2. Password.");
                printf("\n\t3. Name.");
                printf("\n\t4. Age.");
                printf("\n\t5. Phone No.");
                printf("\n\t6. Email.");
                printf("\n\t7. Room No.");
                printf("\n\t8. Duty Time.");
                printf("\n\t9. Address.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    doctor_menu();
                    break;
                case '1':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Username : ");
                    fflush(stdin);
                    gets(doctor.usr);
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Password : ");
                    fflush(stdin);
                    gets(doctor.pass);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Name : ");
                    fflush(stdin);
                    gets(doctor.name);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Age : ");
                    fflush(stdin);
                    gets(doctor.age);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Phone No : ");
                    fflush(stdin);
                    gets(doctor.phone);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter Doctor New Email : ");
                    fflush(stdin);
                    gets(doctor.email);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter Doctor Room No : ");
                    fflush(stdin);
                    gets(doctor.room);
                    break;
                case '8':
                    system("cls");
                    printf("\n\t\t Enter Doctor Duty Time : ");
                    fflush(stdin);
                    gets(doctor.duty_time);
                    break;
                case '9':
                    system("cls");
                    printf("\n\t\t Enter Doctor Address : ");
                    fflush(stdin);
                    gets(doctor.address);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_doctor_entry();
                    break;
                }
            }
            fwrite(&doctor, sizeof(doctor), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("doctor.BIN");
        rename("new.BIN", "doctor.BIN");
        // system ("del /f doctor") ;
        // system ("rename new doctor") ;
        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Doctor Menu....");
            con = getche();
            if (con == '1')
            {
                modify_doctor_entry();
            }
            else
            {
                doctor_menu();
            }
        }
        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    doctor_menu();
}

void modify_patient_entry_by_doctor()
{
    system("cls");
    char another = 'y', p_user[10], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {
        system("cls");

        fp1 = fopen("patient.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Patient Checkup Details ====\n\n\n");
        printf("Enter Patient Username : ");
        fflush(stdin);
        gets(p_user);
        // rewind (fp1) ;

        while (fread(&patient, sizeof(patient), 1, fp1) == 1)
        {
            if (strcmp(patient.usr, p_user) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\t1. Diseases.");
                printf("\n\t2. Diseases Description.");
                printf("\n\t3. Name of Test.");
                printf("\n\t4. Test Result.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    // rename("new.BIN", "patient.BIN");
                    doctor_login_panel();
                    break;
                case '1':
                    system("cls");
                    printf("\n\t\t Enter Patient Diseases : ");
                    fflush(stdin);
                    gets(patient.diseases);
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter Patient Diseases Description : ");
                    fflush(stdin);
                    gets(patient.diseases_description);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter Name of Test : ");
                    fflush(stdin);
                    gets(patient.test);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter Patient Test Result : ");
                    fflush(stdin);
                    gets(patient.test_result);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_patient_entry_by_doctor();
                    break;
                }
            }
            fwrite(&patient, sizeof(patient), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        // system ("del /f patient") ;
        // system ("rename new patient") ;
        remove("patient.BIN");
        rename("new.BIN", "patient.BIN");
        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Add or Press any key (without 1) to Doctor's Panel....");
            con = getche();
            if (con == '1')
            {
                modify_patient_entry_by_doctor();
            }
            else
            {
                doctor_login_panel();
            }
        }
        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    doctor_login_panel();
}

void modify_patient_entry()
{
    system("cls");
    char another = 'y', p_user[10], ch, flag = '0';
    FILE *fp1, *fp2;

    while (another == 'Y' || another == 'y')
    {
        system("cls");

        fp1 = fopen("patient.BIN", "r");
        fp2 = fopen("new.BIN", "a");

        printf("\n\t\t\t\t==== Modifying Patient Account ====\n\n\n");
        printf("\tEnter Patient Username to Modify : ");
        fflush(stdin);
        gets(p_user);
        // rewind (fp1) ;

        while (fread(&patient, sizeof(patient), 1, fp1) == 1)
        {
            if (strcmp(patient.usr, p_user) == 0)
            {
                flag = '1';
                system("cls");
                printf("\n\tWhich option you want to Modify ? :");
                printf("\n\t1. Username.");
                printf("\n\t2. Password.");
                printf("\n\t3. Name.");
                printf("\n\t4. Age.");
                printf("\n\t5. Phone No.");
                printf("\n\t6. Email.");
                printf("\n\t7. Address.");
                printf("\n\t8. Bed No.");
                printf("\n\t0. <= Back.");
                printf("\n\t\tEnter yor choice : ");
                ch = getche();

                switch (ch)
                {
                case '0':
                    fclose(fp1);
                    fclose(fp2);
                    remove("new.BIN");
                    patient_menu();
                    break;
                case '1':
                    system("cls");
                    printf("\n\t\t Enter Patient New Username : ");
                    fflush(stdin);
                    gets(patient.usr);
                    break;
                case '2':
                    system("cls");
                    printf("\n\t\t Enter Patient New Password : ");
                    fflush(stdin);
                    gets(patient.pass);
                    break;
                case '3':
                    system("cls");
                    printf("\n\t\t Enter Patient New Name : ");
                    fflush(stdin);
                    gets(patient.name);
                    break;
                case '4':
                    system("cls");
                    printf("\n\t\t Enter Patient New Age : ");
                    fflush(stdin);
                    gets(patient.age);
                    break;
                case '5':
                    system("cls");
                    printf("\n\t\t Enter Patient New Phone No : ");
                    fflush(stdin);
                    gets(patient.phone);
                    break;
                case '6':
                    system("cls");
                    printf("\n\t\t Enter Patient New Email : ");
                    fflush(stdin);
                    gets(patient.email);
                    break;
                case '7':
                    system("cls");
                    printf("\n\t\t Enter Patient New Address : ");
                    fflush(stdin);
                    gets(patient.address);
                    break;
                case '8':
                    system("cls");
                    printf("\n\t\t Enter Patient New Bed No : ");
                    fflush(stdin);
                    scanf("%d", &patient.cabin_no);
                    break;
                default:
                    system("cls");
                    printf("\n\t\tSorry! Your choice is incorrect.\n\n");
                    printf("\t\tPress any key to continue......");
                    getch();
                    fclose(fp1);
                    fclose(fp2);
                    modify_patient_entry();
                    break;
                }
            }
            fwrite(&patient, sizeof(patient), 1, fp2);
        }
        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        // system ("del /f patient") ;
        // system ("rename new patient") ;
        remove("patient.BIN");
        rename("new.BIN", "patient.BIN");
        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Modify or Press any key (without 1) to Patient Menu....");
            con = getche();
            if (con == '1')
            {
                modify_patient_entry();
            }
            else
            {
                patient_menu();
            }
        }
        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    patient_menu();
}

void delete_staff_entry()
{
    FILE *fp1, *fp2;
    char flag = '0', s_usr[20], another = 'y';
    while (another == 'y' || another == 'Y')
    {
        system("cls");

        fp1 = fopen("staff.BIN", "r");
        fp2 = fopen("new.BIN", "a");
        system("cls");

        printf("\n\t\t\t\t==== Removing Staff Account ====\n\n\n");
        printf("Enter Staff Username to Remove : ");
        fflush(stdin);
        gets(s_usr);

        while (fread(&staff, sizeof(staff), 1, fp1) == 1)
        {
            if (strcmp(staff.usr, s_usr) == 0)
            {
                flag = '1';
                continue;
            }

            fwrite(&staff, sizeof(staff), 1, fp2);
        }

        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("staff.BIN");
        rename("new.BIN", "staff.BIN");
        // system ("del /f doctor") ;
        // system ("rename new staff") ;

        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Delete Operation or Press any key (without 1) to Staff Menu....");
            con = getche();
            if (con == '1')
            {
                delete_staff_entry();
            }
            else
            {
                staff_menu();
            }
        }
        printf("\nDelete another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    staff_menu();
}

void delete_nurse_entry()
{
    FILE *fp1, *fp2;
    char flag = '0', n_usr[20], another = 'y';
    while (another == 'y' || another == 'Y')
    {

        fp1 = fopen("nurse.BIN", "r");
        fp2 = fopen("new.BIN", "a");
        system("cls");

        printf("\n\t\t\t\t==== Removing Nurse Account ====\n\n\n");
        printf("Enter Nurse Username to Remove : ");
        fflush(stdin);
        gets(n_usr);

        while (fread(&nurse, sizeof(nurse), 1, fp1) == 1)
        {
            if (strcmp(nurse.usr, n_usr) == 0)
            {
                flag = '1';
                continue;
            }

            fwrite(&nurse, sizeof(nurse), 1, fp2);
        }

        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("nurse.BIN");
        rename("new.BIN", "nurse.BIN");
        // system ("del /f doctor") ;
        // system ("rename new nurse") ;

        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Delete Operation or Press any key (without 1) to Nurse Menu....");
            con = getche();
            if (con == '1')
            {
                fclose(fp1);
                fclose(fp2);
                delete_nurse_entry();
            }
            else
            {
                fclose(fp1);
                fclose(fp2);
                nurse_menu();
            }
        }
        printf("\nDelete another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    nurse_menu();
}

void delete_doctor_entry()
{
    FILE *fp1, *fp2;
    char flag = '0', d_usr[20], another = 'y';
    while (another == 'y' || another == 'Y')
    {

        fp1 = fopen("doctor.BIN", "r");
        fp2 = fopen("new.BIN", "a");
        system("cls");

        printf("\n\t\t\t\t==== Removing Doctor Account ====\n\n\n");
        printf("Enter Doctor Username to Remove : ");
        fflush(stdin);
        gets(d_usr);

        while (fread(&doctor, sizeof(doctor), 1, fp1) == 1)
        {
            if (strcmp(doctor.usr, d_usr) == 0)
            {
                flag = '1';
                continue;
            }

            fwrite(&doctor, sizeof(doctor), 1, fp2);
        }

        fclose(fp1);
        fclose(fp2);
        // fclose(fp1) ;
        // fclose(fp2) ;
        // sync();
        remove("doctor.BIN");
        rename("new.BIN", "doctor.BIN");
        // system ("del /f doctor") ;
        // system ("rename new doctor") ;

        printf("................................................................");
        // remove ("new.BIN") ;
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Delete Operation or Press any key (without 1) to doctor Menu....");
            con = getche();
            if (con == '1')
            {
                fclose(fp1);
                fclose(fp2);
                delete_doctor_entry();
            }
            else
            {
                fclose(fp1);
                fclose(fp2);
                doctor_menu();
            }
        }
        printf("\nDelete another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    doctor_menu();
}

void delete_patient_entry()
{
    FILE *fp1, *fp2;
    char flag = '0', p_usr[20], another = 'y';
    while (another == 'y' || another == 'Y')
    {

        fp1 = fopen("patient.BIN", "r");
        fp2 = fopen("new.BIN", "a");
        system("cls");

        printf("\n\t\t\t\t==== Removing Patient Account ====\n\n\n");
        printf("Enter Patient Username to Remove  : ");
        fflush(stdin);
        gets(p_usr);

        while (fread(&patient, sizeof(patient), 1, fp1) == 1)
        {
            if (strcmp(patient.usr, p_usr) == 0)
            {
                flag = '1';
                continue;
            }

            fwrite(&patient, sizeof(patient), 1, fp2);
        }

        fclose(fp1);
        fclose(fp2);
        // sync();
        remove("patient.BIN");
        rename("new.BIN", "patient.BIN");
        // system ("del /f patient") ;
        // system ("rename new patient") ;
        printf("................................................................");
        if (flag == '0')
        {
            char con;
            system("cls");
            printf("\n\n\t\t\tYou Have Entered Wrong Username");
            printf("\n\t\t\tPress 1 to Continue Delete Operation or Press any key (without 1) to Patient Menu....");
            con = getche();
            if (con == '1')
            {
                fclose(fp1);
                fclose(fp2);
                delete_patient_entry();
            }
            else
            {
                fclose(fp1);
                fclose(fp2);
                patient_menu();
            }
        }
        printf("\nDelete another Record ? (Y/N) : ");
        fflush(stdin);
        another = getche();
    }
    fclose(fp1);
    fclose(fp2);
    patient_menu();
}

void info()
{
    system("cls");
    char choice;
    printf("\n\t\t\t\t==== Information Panel ====\n\n\n");
    printf("\n\t\tWhich Information you want to know ? ");
    printf("\n\t\t1. About Available Bed");
    printf("\n\t\t2. About Doctors");
    printf("\n\t\t0. <= Back");
    printf("\n\t\tEnter your choice : ");
    choice = getche();
    switch (choice)
    {
    case '0':
        main_function();
        break;
    case '1':
        available_bed_info();
        break;
    case '2':
        about_doctor(0);
        break;
    default:
        system("cls");
        printf("\n\t\tSorry! Your choice is incorrect.\n\n");
        printf("\t\tPress any key to continue......");
        getch();
        info();
        break;
    }
}

void modify_hospital_bed()
{
    char ch, another = 'y';
    FILE *fp;
    while (another == 'y' || another == 'Y')
    {
        system("cls");
        fp = fopen("hospital.txt", "w");

        printf("\n\t\t\t\t==== Modify Hospital Beds ====\n\n\n");
        printf("\n\t1. General Bed");
        printf("\n\t2. ICU");
        printf("\n\t3. NICU");
        printf("\n\t4. CCU");
        printf("\n\t5. Cabin)");
        printf("\n\t0. <== Back");
        printf("\n\tEnter your choice : ");
        ch = getche();
        switch (ch)
        {
        case '0':
            fclose(fp);
            admin_menu();
            break;
        case '1':
            printf("\n\n\tEnter Bed : ");
            scanf("%d", &hospital.general_bed);
            fprintf(fp, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            break;
        case '2':
            printf("\n\n\tEnter Bed : ");
            scanf("%d", &hospital.icu);
            fprintf(fp, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            break;
        case '3':
            printf("\n\n\tEnter Bed : ");
            scanf("%d", &hospital.nicu);
            fprintf(fp, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            break;
        case '4':
            printf("\n\n\tEnter Bed : ");
            scanf("%d", &hospital.ccu);
            fprintf(fp, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            break;
        case '5':
            printf("\n\n\tEnter Bed : ");
            scanf("%d", &hospital.cabin);
            fprintf(fp, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            break;
        default:
            system("cls");
            printf("\n\t\tSorry! Your choice is incorrect.\n\n");
            printf("\t\tPress any key to continue......");
            getch();
            fclose(fp);
            modify_hospital_bed();
            break;
        }

        printf("\nModify another Record (Y/N) : ");
        fflush(stdin);
        another = getche();
        fclose(fp);
    }
    fclose(fp);
    admin_menu();
}

void available_bed_info()
{
    system("cls");
    printf("\n\t\t\t\t==== Available Beds ====\n\n\n");
    FILE *fp = fopen("hospital.txt", "r");

    fscanf(fp, "%d %d %d %d %d", &hospital.cabin, &hospital.icu, &hospital.ccu, &hospital.nicu, &hospital.general_bed);
    if (hospital.general_bed != 0)
    {
        printf("\n\n\t\tGeneral Bed : Available");
    }
    else
    {
        printf("\n\n\t\tGeneral Bed : Not Available");
    }
    if (hospital.icu != 0)
    {
        printf("\n\n\t\tICU : Available");
    }
    else
    {
        printf("\n\n\t\tICU : Not Available");
    }
    if (hospital.nicu != 0)
    {
        printf("\n\n\t\tNICU : Available");
    }
    else
    {
        printf("\n\n\t\tNICU : Not Available");
    }
    if (hospital.ccu != 0)
    {
        printf("\n\n\t\tCCU : Available");
    }
    else
    {
        printf("\n\n\t\tCCU : Not Available");
    }
    if (hospital.cabin != 0)
    {
        printf("\n\n\t\tCabin : Available");
    }
    else
    {
        printf("\n\n\t\tCabin : Not Available");
    }

    printf("\n\n.........................................................................................");
    printf("\n\n\t................ Press Any Key for OK ..................\n\n");
    getch();
    info();
}

void contact()
{
    system("cls");
    printf("\n\t\t\t\t\t==== Contuct Us ====\n\n\n");
    printf("\n\n\t\t\t\t\tABCD Hospital LTD\n");
    printf("\n\t\t18/F, Bir Uttam Qazi Nuruzzaman Sarak, West Panthapath,Dhaka 1205");
    printf("\n\t\t\t\t\tTelephone No : 10101");
    printf("\n\t\t\t\t     Email : inf@abcdhospital.com");

    printf("\n\n\n\n\t\t\t\t    ABCD Hospital Uttara Branch\n");
    printf("\n\t\t\tPlot-37, Sonargaon Janapath, Sector-7, Uttara, Dhaka 1230");
    printf("\n\t\t\t\t\tTelephone No : 10101");
    printf("\n\t\t\t\t     Email : inf@abcdhospital.com");

    printf("\n\n\n\n\t\t\t\t    ABCD Hospital Mirpur Branch\n");
    printf("\nMadhuri Bhaban (3rd Floor), Holding No- 2, Road No- 3, Section- 7, Pallabi, Mirpur- 11, Bus Stand, Dhaka- 1216.");
    printf("\n\t\t\t\t\tTelephone No : 10101");
    printf("\n\t\t\t\t     Email : inf@abcdhospital.com");
    printf("\n\n\n\n\t\t........................ Press Any Key for OK ........................\n\n");
    getch();
    main_function();
}
void Exit()
{
    system("cls");
    char loop[] = "\n\n\t\t\tTHIS PROJECT IS BY MD. ASHIQUR RAHMAN\n\t\t\t  DEPERTMENT OF SOFTWARE ENGINEERING\n";
    for (int i = 0; i < sizeof(loop); i++)
    {
        usleep(25000);
        printf("%c", loop[i]);
    }
    printf("\n\t\t\t  Press any key to exit ......\n");
    getch();
    system("cls");
    exit(0);
    // system ("exit") ;
}

void admit_patient()
{
    system("cls");
    printf("\n\t\t\t\t==== Admit Patient ====\n\n\n");
    FILE *fp1 = fopen("patient.BIN", "r");
    FILE *fp2 = fopen("temp.BIN", "a");
    char search[15], flag = '0';
    int bed;
    printf("\n\n\t\tEnter Patient Username : ");
    gets(search);
    while (fread(&patient, sizeof(patient), 1, fp1) == 1)
    {
        if (strcmp(patient.usr, search) == 0)
        {
        bed_chs:
            flag = '1';
            char cab[5], flag1 = '0';
            char choice_bed, check_bed;
            FILE *fp_bed1 = fopen("hospital.txt", "r");
            FILE *fp_bed2 = fopen("tmp.txt", "w");
            FILE *bed_ch = fopen("hospital_bed.txt", "r");
            fscanf(fp_bed1, "%d %d %d %d %d", &hospital.cabin, &hospital.icu, &hospital.ccu, &hospital.nicu, &hospital.general_bed);
            // fseek(fp_bed,-24,2);
            printf("\n\n\tEnter where to Admit");
            printf("\n\t1. General Bed (100-199)");
            printf("\n\t2. ICU (200-299)");
            printf("\n\t3. NICU (300-399)");
            printf("\n\t4. CCU (400-499)");
            printf("\n\t5. Cabin (500-599)");
            printf("\n\t0. <== Back");
            printf("\n\tEnter your choice : ");
            choice_bed = getche();
            switch (choice_bed)
            {
            case '0':
                fclose(fp_bed1);
                fclose(fp_bed2);
                fclose(bed_ch);
                remove("tmp.BIN");
                patient_menu();
                break;
            case '1':
                printf("\n\n\t\tEnter Bed No : ");
                scanf("%d", &bed);
                while (fscanf(bed_ch, "%d", &patient.cabin_no) != EOF)
                {
                    if (bed == patient.cabin_no)
                    {
                        printf("\n\t\t\tSorry! Bed is Not Available\n\n\t\tPlease Enter another bed....");
                        getch();
                        fclose(fp_bed1);
                        fclose(fp_bed2);
                        fclose(bed_ch);
                        goto bed_chs;
                    }
                }
                hospital.general_bed -= 1;
                patient.due += 1000;
                patient.payable += 1000;
                fclose(bed_ch);
                patient.cabin_no = bed;
                break;
            case '2':
                printf("\n\n\t\tEnter Bed No : ");
                scanf("%d", &bed);
                while (fscanf(bed_ch, "%d", &patient.cabin_no) != EOF)
                {
                    if (bed == patient.cabin_no)
                    {
                        printf("\n\t\t\tSorry! Bed is Not Available\n\n\t\tPlease Enter another bed....");
                        getch();
                        fclose(fp_bed1);
                        fclose(fp_bed2);
                        fclose(bed_ch);
                        goto bed_chs;
                    }
                }
                hospital.icu -= 1;
                patient.due += 2000;
                patient.payable += 2000;
                fclose(bed_ch);
                patient.cabin_no = bed;
                break;
            case '3':
                printf("\n\n\t\tEnter Bed No : ");
                scanf("%d", &bed);
                while (fscanf(bed_ch, "%d", &patient.cabin_no) != EOF)
                {
                    if (bed == patient.cabin_no)
                    {
                        printf("\n\t\t\tSorry! Bed is Not Available\n\n\t\tPlease Enter another bed....");
                        getch();
                        fclose(fp_bed1);
                        fclose(fp_bed2);
                        fclose(bed_ch);
                        goto bed_chs;
                    }
                }
                hospital.nicu -= 1;
                patient.due += 2000;
                patient.payable += 2000;
                fclose(bed_ch);
                patient.cabin_no = bed;
                break;
            case '4':
                printf("\n\n\t\tEnter Bed No : ");
                scanf("%d", &bed);
                while (fscanf(bed_ch, "%d", &patient.cabin_no) != EOF)
                {
                    if (bed == patient.cabin_no)
                    {
                        printf("\n\t\t\tSorry! Bed is Not Available\n\n\t\tPlease Enter another bed....");
                        getch();
                        fclose(fp_bed1);
                        fclose(fp_bed2);
                        fclose(bed_ch);
                        goto bed_chs;
                    }
                }
                hospital.ccu -= 1;
                patient.due += 2000;
                patient.payable += 2000;
                fclose(bed_ch);
                patient.cabin_no = bed;
                break;
            case '5':
                printf("\n\n\t\tEnter Bed No : ");
                scanf("%d", &bed);
                while (fscanf(bed_ch, "%d", &patient.cabin_no) != EOF)
                {
                    if (bed == patient.cabin_no)
                    {
                        printf("\n\t\t\tSorry! Bed is Not Available\n\n\t\tPlease Enter another bed....");
                        getch();
                        fclose(fp_bed1);
                        fclose(fp_bed2);
                        fclose(bed_ch);
                        goto bed_chs;
                    }
                }
                hospital.cabin -= 1;
                patient.due += 5000;
                patient.payable += 5000;
                fclose(bed_ch);
                patient.cabin_no = bed;
                break;
            default:
                system("cls");
                printf("\n\n\nYou Have Entered Wrong Option\n");
                printf("\nPress Any Key to Continue......\n");
                getch();
                fclose(fp_bed1);
                fclose(fp_bed2);
                fclose(bed_ch);
                goto bed_chs;
                break;
            }
            fprintf(fp_bed2, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            fclose(fp_bed1);
            fclose(fp_bed2);
            remove("hospital.txt");
            rename("tmp.txt", "hospital.txt");
        }
        fwrite(&patient, sizeof(patient), 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("patient.BIN");
    rename("temp.BIN", "patient.BIN");
    printf("................................................................");
    unavailable_bed_save();
    if (flag == '0')
    {
        char con;
        system("cls");
        printf("\n\n\t\t\tYou Have Entered Wrong Username");
        printf("\n\t\t\tPress 1 to Continue or Press any key (without 1) to Patient Menu....");
        con = getche();
        if (con == '1')
        {
            admit_patient();
        }
        else
            patient_menu();
    }
    patient_menu();
}

void release_patient()
{
    system("cls");
    printf("\n\t\t\t\t==== Release Patient ====\n\n\n");
    FILE *fp1 = fopen("patient.BIN", "r");
    FILE *fp2 = fopen("temp.BIN", "a");
    char search[15], flag = '0';
    printf("\n\n\t\tEnter Patient Username : ");
    gets(search);
    while (fread(&patient, sizeof(patient), 1, fp1) == 1)
    {
        if (strcmp(patient.usr, search) == 0)
        {
            flag = '1';
            char cab[5];
            char choice_bed, check_bed;
            FILE *fp_bed1 = fopen("hospital.txt", "r");
            FILE *fp_bed2 = fopen("tmp.BIN", "w");
            fscanf(fp_bed1, "%d %d %d %d %d", &hospital.cabin, &hospital.icu, &hospital.ccu, &hospital.nicu, &hospital.general_bed);
        // fseek(fp_bed,-24,2);
        bed_chs:
            printf("\n\n\tWhich department has patient admission ?");
            printf("\n\t1. General Bed (101-200)");
            printf("\n\t2. ICU (201-300)");
            printf("\n\t3. NICU (301-400)");
            printf("\n\t4. CCU (401-500)");
            printf("\n\t5. Cabin (501-600)");
            printf("\n\tEnter your choice : ");
            choice_bed = getche();
            switch (choice_bed)
            {
            case '1':
                hospital.general_bed += 1;
                patient.cabin_no = 0;
                break;
            case '2':
                hospital.icu += 1;
                patient.cabin_no = 0;
                break;
            case '3':
                hospital.nicu += 1;
                patient.cabin_no = 0;
                break;
            case '4':
                hospital.ccu += 1;
                patient.cabin_no = 0;
                break;
            case '5':
                hospital.cabin += 1;
                patient.cabin_no = 0;
                break;
            default:
                system("cls");
                printf("\n\n\nYou Have Entered Wrong Option\n");
                printf("\nPress Any Key to Continue......\n");
                getch();
                goto bed_chs;
                break;
            }
            fprintf(fp_bed2, "%d %d %d %d %d", hospital.cabin, hospital.icu, hospital.ccu, hospital.nicu, hospital.general_bed);
            fclose(fp_bed1);
            fclose(fp_bed2);
            remove("hospital.txt");
            rename("tmp.txt", "hospital.txt");
        }
        fwrite(&patient, sizeof(patient), 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    remove("patient.BIN");
    rename("temp.BIN", "patient.BIN");
    printf("................................................................");
    unavailable_bed_save();
    if (flag == '0')
    {
        char con;
        system("cls");
        printf("\n\n\t\t\tYou Have Entered Wrong Username");
        printf("\n\t\t\tPress 1 to Continue or Press any key (without 1) to Patient Menu....");
        con = getche();
        if (con == '1')
        {
            admit_patient();
        }
        else
            patient_menu();
    }
    patient_menu();
}

void about_doctor(int x)
{
    system("cls");
    printf("\n\t\t\t\t==== About Doctor's ====\n\n\n");
    FILE *about_doc = fopen("doctor.BIN", "r");
    while (fread(&doctor, sizeof(doctor), 1, about_doc) == 1)
    {
        printf("\nDoctor Name : ");
        puts(doctor.name);
        printf("\nDoctor Phone NO : ");
        puts(doctor.phone);
        printf("\nDoctor Email : ");
        puts(doctor.email);
        printf("\nDoctor Room No : ");
        puts(doctor.room);
        printf("\nDoctor Duty Time : ");
        puts(doctor.duty_time);
        printf("\n\n.......................................................................\n\n\n");
    }
    fclose(about_doc);
    printf("\n\n\t................ Press Any Key for OK ..................\n\n");
    getch();
    if (x == 1)
    {
        doctor_menu();
    }
    else if (x == 0)
    {
        info();
    }
}

void unavailable_bed_save()
{
    FILE *bed = fopen("patient.BIN", "r");
    FILE *fp = fopen("hospital_bed.txt", "w");
    while (fread(&patient, sizeof(patient), 1, bed) == 1)
    {
        fprintf(fp, "%d ", patient.cabin_no);
    }
    fclose(bed);
    fclose(fp);
}

void unavailable_bed_no()
{
    system("cls");
    FILE *fp_bed_save = fopen("hospital_bed.txt", "r");
    int i, con;
    char ch, flag = '0';
bed_chs1:
    printf("\n\t\t\t\t==== Search Beds ====\n\n\n");
    printf("\n\t1. General Bed (100-199)");
    printf("\n\t2. ICU (200-299)");
    printf("\n\t3. NICU (300-399)");
    printf("\n\t4. CCU (400-499)");
    printf("\n\t5. Cabin (500-599)");
    printf("\n\t0. <== Back");
    printf("\n\tEnter your choice : ");
    ch = getche();
    switch (ch)
    {
    case '0':
        patient_menu();
        break;
    case '1':
        printf("\n\n\t\tUnavailable General Beds are : ");
        while (fscanf(fp_bed_save, "%d ", &patient.cabin_no) != EOF)
        {
            for (i = 100; i <= 199; i++)
            {
                if (patient.cabin_no == i)
                {
                    printf("%d ", i);
                }
            }
        }

        fclose(fp_bed_save);
        printf("\n\n\t................ Press Any Key for OK ..................\n\n");
        getch();
        break;
    case '2':
        printf("\n\n\t\tUnavailable ICU Beds are : ");
        while (fscanf(fp_bed_save, "%d", &patient.cabin_no) != EOF)
        {
            for (i = 200; i <= 299; i++)
            {
                if (patient.cabin_no == i)
                {
                    printf("%d ", i);
                }
            }
        }
        fclose(fp_bed_save);
        printf("\n\n\t................ Press Any Key for OK ..................\n\n");
        getch();
        break;
    case '3':
        printf("\n\n\t\tUnavailable NICU Beds are : ");
        while (fscanf(fp_bed_save, "%d", &patient.cabin_no) != EOF)
        {
            for (i = 300; i <= 399; i++)
            {
                if (patient.cabin_no == i)
                {
                    printf("%d ", i);
                }
            }
        }
        fclose(fp_bed_save);
        printf("\n\n\t................ Press Any Key for OK ..................\n\n");
        getch();
        break;
    case '4':
        printf("\n\n\t\tUnavailable CCU Beds are : ");
        while (fscanf(fp_bed_save, "%d", &patient.cabin_no) != EOF)
        {
            for (i = 400; i <= 499; i++)
            {
                if (patient.cabin_no == i)
                {
                    printf("%d ", i);
                }
            }
        }
        fclose(fp_bed_save);
        printf("\n\n\t................ Press Any Key for OK ..................\n\n");
        getch();
        break;
    case '5':
        printf("\n\n\t\tUnavailable Cabin Beds are : ");
        while (fscanf(fp_bed_save, "%d", &patient.cabin_no) != EOF)
        {
            for (i = 500; i <= 599; i++)
            {
                if (patient.cabin_no == i)
                {
                    printf("%d ", i);
                }
            }
        }
        fclose(fp_bed_save);
        printf("\n\n\t................ Press Any Key for OK ..................\n\n");
        getch();
        break;
    default:
        system("cls");
        printf("\n\n\nYou Have Entered Wrong Option\n");
        printf("\nPress Any Key to Continue......\n");
        getch();
        goto bed_chs1;
        break;
    }
    unavailable_bed_no();
}

void loading()
{
    system("cls");
    int loop = 1;
    printf("\n\n\n\n\n\t\t\t\t\tLoading\n");
    printf("\t\t\t\t");
    while (loop)
    {
        for (int i = 0; i < 24; i++)
        {
            usleep(25000);
            printf("#");
        }
        loop = 0;
    }
    system("cls");
}
void loading_logout()
{
    system("cls");
    int loop = 1;
    printf("\n\n\n\n\n\t\t\t\t\tLogging Out\n");
    printf("\t\t\t\t");
    while (loop)
    {
        for (int i = 0; i < 24; i++)
        {
            usleep(25000);
            printf("#");
        }
        loop = 0;
    }
    system("cls");
}
void loading_login()
{
    system("cls");
    int loop = 1;
    printf("\n\n\n\n\n\t\t\t\t\tLoggin In\n");
    printf("\t\t\t\t");
    while (loop)
    {
        for (int i = 0; i < 24; i++)
        {
            usleep(25000);
            printf("#");
        }
        loop = 0;
    }
    system("cls");
}

void loading_starting()
{
    system("cls");
    char loop[] = "\n\t\t\t\t********************* ABCD Hospital **********************\n\t\t\t\t*************** Hospital Management System ***************\n\t\t\t\t************ C-Project by Md. Ashiqur Rahman *************";
    for (int i = 0; i < sizeof(loop); i++)
    {
        usleep(25000);
        printf("%c", loop[i]);
    }
}