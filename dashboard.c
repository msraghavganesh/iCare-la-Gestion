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
