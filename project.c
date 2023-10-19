#include <stdio.h>
#include <string.h>

#define Max_Users 20
#define Max_Size 15
#define User_File "vaccine.txt"
#define no_of_vaccines 5


struct User {
    char username[Max_Size];
    char password[Max_Size];
    char full_name[Max_Size];
    char age[Max_Size];
    char phone_number[Max_Size];
};

void registration()
{
    FILE *project = fopen(User_File, "a");
    if (!project) {
        printf("Error opening users file.\n");
        return;
    }

    struct User new_user;
    printf("Enter username: ");
    scanf("%s", new_user.username);

    printf("Enter password: ");
    scanf("%s", new_user.password);

    printf("Enter full name: ");
    scanf("%s",new_user.full_name);

    printf("Enter age: ");
    scanf("%s", new_user.age);

    printf("Enter phone number: ");
    scanf("%s",new_user.phone_number);

    fprintf(project, "%s %s %s %s %s\n", new_user.username, new_user.password, new_user.full_name, new_user.age, new_user.phone_number);
    fclose(project);
    printf("Registration successful!\n");
}

int login() {
    char username[Max_Size];
    char password[Max_Size];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    FILE *project = fopen(User_File, "r");
    if (!project) {
        printf("Error opening users file.\n");
        return -1;
    }

    struct User user;
    int index = 0;
    while (fscanf(project, "%s %s %s %s %s", user.username, user.password, user.full_name, user.age, user.phone_number) != EOF)
    {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
        {
            printf("Welcome %s!\n",user.full_name);
            printf("Login successful!\n");
            fclose(project);
            printf("Login Index: %d",index);
            return index;
        }
        index++;
    }

    fclose(project);
    printf("Login failed.\n");
    return -1;
}

void change_password(int user_index)
{
    if (user_index >= 0 && user_index < Max_Users)
    {
        FILE *project = fopen(User_File, "r+");
        if (!project) {
            printf("Error opening users file.\n");
            return;
        }

        struct User user;
        int index = 0;
        while (fscanf(project, "%s %s %s %s %s", user.username, user.password, user.full_name,user.age, user.phone_number) != EOF)
        {
            if (index == user_index) {
                printf("Enter new password: ");
                scanf("%s", user.password);

                fseek(project, index * (Max_Size+ Max_Size + 2), SEEK_SET);
                fprintf(project, "%s %s %s %s %s\n", user.username, user.password, user.full_name,user.age, user.phone_number);
                fclose(project);
                printf("Password changed successfully!\n");
                return;
            }
            index++;
        }

        fclose(project);
        printf("Invalid user index.\n");
    }
    else {
        printf("Invalid user index.\n");
    }
}

int main()
{
    int v[no_of_vaccines];
    for(int i=0;i<no_of_vaccines;i++)v[i]=5;

    int choice, user_index = -1;
    do {
        printf("\nMenu:\n");
        printf("1. Sign up\n");
        printf("2. Login\n");
        printf("3. Change Password\n");
        printf("4.Take An Appointment\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                user_index = login();
                break;
            case 3:
                change_password(user_index);
                break;
            case 4:
                booking(user_index,v);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

int booking(int user_index, int arr[])
{
        if (user_index >= 0 && user_index < Max_Users)
    {
        FILE *project = fopen(User_File, "r+");
        if (!project) {
            printf("Error opening users file.\n");
            return;
        }
        struct User user;
        int index=0,va=1,choice,center;
        while(fscanf(project, "%s %s %s %s %s", user.username,user.password,user.full_name,user.age,user.phone_number) != EOF)
        {
            if(index==user_index){
                do{
                printf("Available vaccines: \n");
                if(arr[0]>0)printf("%d. Hep B (%d piece available)\n",va,arr[0]),va++;
                if(arr[1]>0)printf("%d. Polio (%d piece available)\n",va,arr[1]),va++;
                if(arr[2]>0)printf("%d. Rotavirus (%d piece available)\n",va,arr[2]),va++;
                if(arr[3]>0)printf("%d. HPV (%d piece available)\n",va,arr[3]),va++;
                if(arr[4]>0)printf("%d. Hib (%d piece available)\n",va,arr[4]),va++;
                printf("0. Exit\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice==0)return;
                else if(choice<0 || choice>=va)printf("Invalid choice. Please try again.\n"),va=1;

                }while(choice<0 || choice>=va);

                do{
                    printf("Vaccination centers: \n");
                    printf("1. Sher-E-Bangla Medical College Hospital\n");
                    printf("2. Sadar Hospital\n");
                    printf("3. Popular Hospital\n");
                    printf("4. Appolo Hospital\n");
                    printf("0. Exit\n");

                    printf("Choose your nearby center: ");
                    scanf("%d", &center);

                    if(center==0){
                            printf("Your booking is not successful.\n");
                            return;
                    }
                    else if(center<0 || center>4)printf("Invalid choice. Please try again.\n");

                }while(center<0 || center>4);

                printf("Hello %s! Your booking is confirmed.\n We have sent the appointment details in %s via massage.",user.full_name,user.phone_number);
                arr[choice-1]--;
                return;
            }
             index++;
        }
        printf("Invalid user index\n");
    }
    else {
        printf("Invalid user index\n");
    }
}
