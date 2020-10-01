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
/* CANTEEN PART
 * iCare la Gestion!
 */

//structer to enter coustmer details
struct user
{
    char name[50];
    char type;
    int ward_num;
} u[100];

//structure to enter food item details
struct item
{
    int avail;
    int price;
} item[10];

//function to display menu
void display_menu()
{
    item[0].price = 20;
    item[1].price = 30;
    item[2].price = 40;
    item[3].price = 25;
    item[4].price = 18;
    item[5].price = 20;
    item[6].price = 10;
    item[7].price = 8;
    item[8].price = 19;
    item[9].price = 35;
    printf("Snack:\n Item name: \t Available \t Price\n");
    printf("Samosa   \t %d \t\t %d\n", item[0].avail, item[0].price);
    printf("Cutlet   \t %d \t\t %d\n", item[1].avail, item[1].price);
    printf("Sandwich \t %d \t\t %d\n", item[2].avail, item[2].price);
    printf("Vada Pav \t %d \t\t %d\n", item[3].avail, item[3].price);
    printf("Bhelpuri \t %d \t\t %d\n", item[4].avail, item[4].price);
    printf("Dhokla   \t %d \t\t %d\n", item[5].avail, item[5].price);
    printf("Veg Puff \t %d \t\t %d\n", item[6].avail, item[6].price);
    printf("Salad    \t %d \t\t %d\n", item[7].avail, item[7].price);
    printf("Bonda    \t %d \t\t %d\n", item[8].avail, item[8].price);
    printf("Vada     \t %d \t\t %d\n", item[9].avail, item[9].price);
}

//function to take coustmers order
void manager_update()
{
    printf("To update do the following steps\n Press 0 for Samosa\n");
    printf("Press 1 for Cutlet\n");
    printf("Press 2 for Sandwich\n");
    printf("Press 3 for Vada Pav\n");
    printf("Press 4 for Bhelpuri\n");
    printf("Press 5 for Dhokla\n");
    printf("Press 6 for Veg puff\n");
    printf("Press 7 for Salad\n");
    printf("Press 8 for Bonda\n");
    printf("Press 9 for Vada\n");

    int i;
    scanf("%d", &i);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Update Current Available Items\n");
    scanf("%d", &item[i].avail);
}

//fumction to give bill
void billing()
{
    item[0].price = 20;
    item[1].price = 30;
    item[2].price = 40;
    item[3].price = 25;
    item[4].price = 18;
    item[5].price = 20;
    item[6].price = 10;
    item[7].price = 8;
    item[8].price = 19;
    item[9].price = 35;
    int i = 0, temp1, temp2, bill = 0, order_next = 1, next_cust = 1;
    while (next_cust)
    {
        printf("Enter Customers name: ");
        //printf("Debug");
        scanf("%s", u[i].name);
        //printf("BUG");
        //asking coustmer for ward delivery
        printf("\nTakeaway or ward delivery? ENTER 'TAKE' OR (T) / 'WARD' OR (W)\n");
        scanf("%s", &u[i].type);
        if (u[i].type == 'W')
        {
            printf("Ward number\n");
            scanf("%d", &u[i].ward_num);
        }

        //asking coustmer for next order
        while (order_next)
        {
            printf("To order do the following steps\n Press 0 for Samosa\n");
            printf("Press 1 for Cutlet\n");
            printf("Press 2 for Sandwich\n");
            printf("Press 3 for Vada Pav\n");
            printf("Press 4 for Bhelpuri\n");
            printf("Press 5 for Dhokla\n");
            printf("Press 6 for Veg puff\n");
            printf("Press 7 for Salad\n");
            printf("Press 8 for Bonda\n");
            printf("Press 9 for Vada\n");
            scanf("%d", &temp1);
            printf("Enter quantity\n");
            scanf("%d", &temp2);
            //to check availability of the stock
            if (item[temp1].avail >= temp2)
            {
                item[temp1].avail = item[temp1].avail - temp2;
                bill = bill + (item[temp1].price) * temp2;
            }
            else
            {
                printf("OUT OF STOCK, We are really sorry!\n");
            }

            printf("Order one more item? Enter any non-zero value \n");
            scanf("%d", &order_next);
        }
        if (u[i].ward_num != NULL)
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Your total bill is Rs %d inclusive of Rs 10 Delivery charge to ward number %d\n", bill + 10, u[i].ward_num);
            
        }
        else
        {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Your total bill is Rs %d", bill);
        }  
        printf("Customer on line? Press 1 else 0");
        scanf("%d", &next_cust);
        i++;
    }
    temp1 = 0, temp2 = 0;
    bill = 0;
}

//canteen reception
void canteen()
{
    int temp;
    while (1)
    {
        printf("Enter 1 to Display Menu\nEnter 2 for Updating stocks\nEnter 3 for Bill\nAny other key to exit\n");
        scanf("%d", &temp);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        switch (temp)
        {
        case 1:
            display_menu();
            break;
        case 2:
            manager_update();
            break;
        case 3:
            billing();
            break;
        default:
            exit(0);
        }
    }
}
