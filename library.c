#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//defining the properties of the fields used in the program

#define IN 1
#define OUT 0

void Add_book();
void Search_book();
void Display_book();
void author();
void stock();
void Exit();

char info[500];

struct
{
    int book_id;
    char book_name[25];
    char author[25];
    int num_of_chaps;
    char title[500];
    int status;
} book;
struct
{
    int member_id;
    char member_name[25];
    char department[25];
    int available_lib_card;
    int phno;

} member;

//initializing the files used in the program

FILE *library_record;
FILE *member_record;

int main()
{
    int choice = 0, i;

    do
    {
        printf("\n\t~~MENU~~\n 1> Add New Book\n 2> Search book \n 3> Display Complete Information\n 4> Display Books of a paticular author\n 5> List the Count of Books (Issued & in stock)\n \n\n\t Enter your choice <1-5>: ");
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            Add_book();
            break;
        case 2:
            Search_book();
            break;
        case 3:
            Display_book();
            break;
        case 4:
            author();
            break;
        case 5:
            stock();
            break;
        case 6:
            Exit();
        default:
            printf(" ! Invalid Input...\n");
        }
    } while (choice != 10);
    return (0);
}

void Add_book()
{
    int i;
    book.status = IN;
    //opening the library_record file
    library_record = fopen("library_record.txt", "a+");
    printf("Enter The uniqueid of The Book :(Integer) \n");
    scanf("%d", &book.book_id);
    printf("Enter The Name of The Book :\n");
    scanf("%s", book.book_name);
    printf("Enter The Name of author :\n");
    scanf("%s", book.author);
    printf("Enter The Number of title Of The Book:(Integer)\n");
    scanf("%d", &book.num_of_chaps);
    fprintf(library_record, "\n%d\t%s\t%s\t%d\t%d\t", book.book_id, book.book_name, book.author, book.status, book.num_of_chaps);
    printf("Enter The title Of The Book : \n");
    for (i = 0; i < book.num_of_chaps; i++)
    {
        scanf("%s", book.title);
        fprintf(library_record, "%s\t", book.title);
    }
    fclose(library_record);
    printf(" (' ' ) A New Book has been Added Successfully...\n");
}

void Display_book()
{
    library_record = fopen("library_record.txt", "a+");
    printf("\nBookid\tName\tAuthor\tStatus\tNo.\tTitles\n", info);
    do
    {
        fgets(info, 500, library_record);
        printf("%s\n", info);
    } while (!feof(library_record));
    fclose(library_record);
    member_record = fopen("member_record.txt", "a+");
    printf("\nMid\tName\tDept\tPh.no\tAvailablecards\n");
    do
    {
        fgets(info, 500, member_record);
        printf("%s\n", info);
    } while (!feof(member_record));
    fclose(member_record);
}

void Search_book()
{
    int i;
    char Target[25], stats[3];
    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The File is Empty...\n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
        scanf("%s", Target);
        while (!feof(library_record) && Found == 0)
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (strcmp(Target, book.book_name) == 0)
                Found = 1;
            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        if (Found)
        {
            if (book.status == IN)
                strcpy(stats, "IN");
            else
                strcpy(stats, "OUT");

            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe author is:  %s\nThe Book Status %s\n\n", book.book_id, book.book_name, book.author, stats);
        }
        else if (!Found)
            printf("! There is no such Entry...\n");
        fclose(library_record);
    }
}

void author()
{
    int i;
    char Target[500];
    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The file is empty... \n\n");
    else
    {
        printf("\nEnter The Name Of author : ");
        scanf("%s", Target);
        printf("\nBooks:");
        while (!feof(library_record))
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (strcmp(Target, book.author) == 0)
            {
                Found = 1;
                printf("\n\t%s", book.book_name);
            }
            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        if (!Found)
            printf(" ! There is no such Entry...\n");
        fclose(library_record);
    }
}

void stock()
{
    int i, stockcount = 0;

    int Found = 0;
    if ((library_record = fopen("library_record.txt", "r")) == NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while (!feof(library_record))
        {
            fscanf(library_record, "%d %s %s %d %d", &book.book_id, book.book_name, book.author, &book.status, &book.num_of_chaps);
            if (book.status == IN)
            {
                stockcount++;
            }

            for (i = 0; i < book.num_of_chaps; i++)
                fscanf(library_record, "%s", book.title);
        }
        fclose(library_record);
        printf("\nCount of  of Books in stock:%d\n", stockcount - 1);
    }
}
void Exit()
{
    exit(0);
}
