//Dashboard for our Project! iCare la Gestion
#include <stdio.h>
#include <string.h>
#include <time.h>
#include<math.h>

//LOGIN PART
struct authentic
{
    char username[50];
    char password[50];
} users[20];

//Function to sign up
void signup()
{
    int i = 0, j = 0, counter = 0;
    printf("Enter an Username\n");
    scanf("%s", &users[i].username);
    printf("Enter a strong password\n");
label:
    scanf("%s", &users[i].password);
    for (j = 0; j < strlen(users[i].password); j++)
    {
        if (isdigit(users[i].password[j]))
        {
            counter = 1;
        }
    }
    if (counter == 0)
    {
        printf("Pasword too Weak, Enter strong password\n");
        goto label;
    }
    printf("Succesfully Registered!\n");
    i++;
}
//function to login
void login()
{
    char temp[50], temp1[50];
    int us = 0;
    printf("Enter valid username\n");
    scanf("%s", &temp);
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(temp, users[i].username) == 0)
        {
            us = 1;
            printf("Enter password:\n");
            scanf("%s", &temp1);
            if (strcmp(temp1, users[i].password) == 0)
            {
                printf("Login Succesfull.\n");
                // i=0;
                return 0;
            }
            else
            {
                printf("Wrong password!\n");
                login();
            }
        }
    }
    if(us != 1)
    {
        login();
    }
}
void authenticate()
{
    int temp;
    int i = 1;
    while (i)
    {
        printf("Enter 1 to Signup\nEnter 2 for login\n");
        scanf("%d", &temp);
        switch (temp)
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            i = 0;
            break;

        default:
            exit(0);
        }
    }
}
