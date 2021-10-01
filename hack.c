/Dashboard for our Project! iCare la Gestion
#include <stdio.h>
#include <st
//Function to sign up
    scanf("%s", &users[i].password);
    for (j = 0; j < strlering.h>
#include <time.h>
#include<math.h>

//LOGIN PART
struct authentic
{
    char username[50];
    char password[50];
} users[20];n(users[i].password); j++)
    {
        if (isdigit(users[i].password[j]))
        {
            counter = 1;
        }
    }
    if (counter 
    }
    printf("Succesfully Registered!\n");
    i++;
}
//function to login
void login()
{
    char temp[50], temp1[50];
    int us = 0;
    printf("En== 0)
    {
        printf("Pasword too Weak, Enter strong password\n");
        goto label;
            us = 1;
            printf("Enter password:\n");
            scanf(
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
      "%s", &temp1);
            if (strcmp(temp1, users[i].password) == 0)
            {
               
            }
            else
            {
                printf("Wrong password!\n");
                login();
            }
        }
    scanf("%s", &users[i].username);
    printf("Enter a strong password\n");
label:
//structure to enter food item details
struct item
{
    int avail;
    int price;
} item[10];t %d \t\t %d\n", item[6].avail, item[6].price);
    printf("Sa
    item[1].price = 30;
    item[2].price = 40;
    item[3].price = 25;
    item[4].price = 18;
    item[5].priceitem[5].avail, item[5].price);
    printf("Veg Puff \
  lad    \t %d \t\t %d\n", item[7].avail, item[7].price);
    printf("Bonda    \t %d \t\t %d\n", item[8].avail, item[8].price);
    printf("Vada     \t %d \t\t %d\n", item[9].avail, item[9].price);
}
