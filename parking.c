#include <stdio.h>
#include <time.h>
#include <string.h>
struct vehicle
{
    int id;
    int type;
    float entry_time;
    float exit_time;
    float diff_time;
    int vacancy;
} park[100];

int find_least_slot(struct vehicle *park)
{
    int k = 0, i = 0;
    while (park[i].vacancy == 0 && i < 100)
    {
        k++;
        i++;
    }
    return k;
}

float time_calculation()
{
    time_t get_time;
    time(&get_time);
    return (difftime(0,get_time));
}

void exit_parking(struct vehicle *park)
{
    int id_check, temp = 0;
    printf("Enter your unique id: \n");
    scanf("%d", &id_check);
    for (int i = 0; i < 100; i++)
    {
        if (park[i].id == id_check)
        {
            temp = i;
        }
    }
    park[temp].exit_time = time_calculation();
    printf("%f", park[temp].diff_time);
    payment(&park,temp);
    park[temp].vacancy = 0;
}

void payment(struct vehicle *park,int m)
{
    int fare = 0;
    if(park[m].type == 2)
    {
        if(park[m].diff_time< 60*60)
        {
            fare = 30;
        }
        else if(park[m].diff_time< 2*60*60)
        {
            fare = 50;
        }
        else
        {
            fare = 50 + (ceil(park[m].diff_time/60*60))*10;
        }
    }
    else
    {
        if(park[m].diff_time< 60*60)
        {
            fare = 50;
        }
        else if(park[m].diff_time< 2*60*60)
        {
            fare = 80;
        }
        else
        {
            fare = 80 + (ceil(park[m].diff_time/60*60))*10;
        }
    }
    printf("Your total fare was = Rs%d\n",fare);
}

void main()
{
    int i, j, temp = 1;
    for (i = 0; i < 100; i++)
    {
        park[i].vacancy = 0;
    }

    while (temp)
    {
        int least_slot_available = find_least_slot(&park);
        printf("Enter your unique id\n");
        scanf("%d", &park[least_slot_available].id);

        j = 0;
        for (i = 0; i < 100; i++)
        {
            if (park[i].vacancy == 0)
                break;
            else
                j++;
        }
        park[least_slot_available].entry_time = time_calculation();

        printf("Enter vehicle type:\n");
        printf("2-wheeler\tPress 2\n4-wheeler\tPress 4\nType:\t");
        scanf("%d", &park[j].type);
        printf("Park at cabin number %d\n", j);
        park[j].vacancy = 1;
        printf("The next car is in queue? \n");
        scanf("%d", &temp);
        if (temp == 3)
        {
            exit_parking(&park);
        }
        else if(temp>=100)
        {
            exit(1);
        }
    }
}
