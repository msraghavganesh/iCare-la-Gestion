Abstract contents:

#include<stdio.h>
#include<string.h>

struct authentic{
    char username[50];
    char password[50];
}users[20];

void signup()
{
    int i=0;
    printf("Enter an Username\n");
    scanf("%s",&users[i].username);
    printf("Enter a strong pssword");
    scanf("%s",&users[i].password);
    printf("Succesfully Registered!\n");
    i++;
    login();
}

void login()
{
    char temp[50],temp1[50];
    printf("Enter valid username\n");
    scanf("%s",&temp);
    for(int i=0;i<20;i++)
    {
        if(strcmp(temp,users[i].username) == 0)
        {
            printf("Enter password:\n");
            scanf("%s",&temp1);
            if(strcmp(temp1,users[i].password) == 0)
            {
                printf("Login Succesfull.");
            }
            else
            {
                printf("Wrong password!");
            }          

        }
    
    }
}
void authenticate()
{
    int temp;
    while (1)
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
            break;
       
        default:
            exit(0);
        }
    }
}
