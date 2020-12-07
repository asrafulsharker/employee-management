#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>






/** List of Global Variable */
COORD coord = {0,0}; /// top-left corner of window




/**

    function : gotoxy
    @param input: x and y coordinates
    @param output: moves the cursor in specified position of console

*/






void gotoxy(int x,int y)

{

    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}





/** Main function started */

void login()
{

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do

{

printf("            Welcome To.....");

printf("\n             _   _   ___  _    _______ _   _   ___   _   _ _____                     \n");
printf("            | \\ | | / _ \\| |  | | ___ \\ | | | / _ \\ | \\ | |_   _|                 \n");
printf("            |  \\| |/ /_\\ \\ |  | | |_/ / |_| |/ /_\\ \\|  \\| | | |                  \n");
printf("            | . ` ||  _  | |/\\| | ___ \\  _  ||  _  || . ` | | |                      \n");
printf("            | |\\  || | | \\  /\\  / |_/ / | | || | | || |\\  |_| |_                   \n");
printf("            \\_| \\_/\\_| |_/\\/  \\/\\____/\\_| |_/\\_| |_/\\_| \\_/\\___/            \n");





    printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
    printf("\n                        PLEASE ENTER USERNAME:-");
	scanf("%s", &uname);
	printf("\n                        PLEASE ENTER PASSWORD:-");
	while(i<10)


	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}


	pword[i]='\0';
	//char code=pword;

	i=0;

	//scanf("%s",&pword);

		if(strcmp(uname,"nirob")==0 && strcmp(pword,"toxic")==0)

	{

	printf("  \n\n\n       WELCOME TO EMPLOYEE RECORD MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL\n");
	    printf("\n                          LOADING PLEASE WAIT...");
    for(i=0; i<10; i++)

    {

        printf(".");
        Sleep(100);

    }





	printf("\n\n\n\t\t\tPress any key to continue...");


	getch();//holds the screen
	break;

	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;


		getch();//holds the screen

	}
}


	while(a<=2);
	if (a>2)


	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}


		system("cls");


}

int main()


{
    system("color 3f");
	int i=0;
	login();
    FILE *fp, *ft; /// file pointers
    char another, choice;



    /** structure that represent a employee */
    struct emp


    {
        char name[40]; ///name of employee
        int age; /// age of employee
        char address[20];//address of employee
        float bs; /// basic salary of employee
        int mobile;


    };

    struct emp e; /// structure variable creation

    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee


    fp = fopen("Database.txt","rb+");
    if(fp == NULL)


    {
        fp = fopen("Database.txt","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }


    }

    /// sizeo of each record i.e. size of structure variable e
    recsize = sizeof(e);


    /// infinite loop continues untile the break statement encounter


    while(1)
    {

        system("cls"); ///clear the console window



printf(" \n  ::::::::::::::::::::::::::  |EMPLOYEES RECORD MANAGEMENT|  :::::::::::::::::::::::::::::: \n");
printf(" \n  ::::::::::::::::::::::::::  |............by.............|  :::::::::::::::::::::::::::::: \n");
printf("                  _   _   ___  _    _______ _   _   ___   _   _ _____                     \n");
printf("                 | \\ | | / _ \\| |  | | ___ \\ | | | / _ \\ | \\ | |_   _|                 \n");
printf("                 |  \\| |/ /_\\ \\ |  | | |_/ / |_| |/ /_\\ \\|  \\| | | |                  \n");
printf("                 | . ` ||  _  | |/\\| | ___ \\  _  ||  _  || . ` | | |                      \n");
printf("                 | |\\  || | | \\  /\\  / |_/ / | | || | | || |\\  |_| |_                   \n");
printf("                 \\_| \\_/\\_| |_/\\/  \\/\\____/\\_| |_/\\_| |_/\\_| \\_/\\___/            \n");





        gotoxy(30,15); /// move the cursor to postion 30, 10 from top-left corner

		printf("1> Add Employee's Records"); /// option for add record

        gotoxy(30,17);

        printf("2> List Employee's Records"); /// option for showing existing record

        gotoxy(30,19);

        printf("3> Modify Employee's Records"); /// option for editing record

        gotoxy(30,21);

        printf("4> Delete Employee's Records"); /// option for deleting record

        gotoxy(30,23);

        printf("5> Exit System"); /// exit from the program

        gotoxy(30,25);

        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5

        fflush(stdin); /// flush the input buffer

        choice  = getche(); /// get the input from keyboard

        switch(choice)


        {

        case '1':  /// if user press 1
            system("cls");
            fseek(fp,0,SEEK_END); /// search the file and move cursor to end of the file
            /// here 0 indicates moving 0 distance from the end of the file

            another = 'y';

            while(another == 'y')  /// if user want to add another record

            {

                printf("\n                Enter name: ");

                scanf("%s",e.name);

                printf("\n                Enter age: ");

                scanf("%d", &e.age);

                printf("\n                Enter Address:");

                scanf("%s",e.address);

                printf("\n                Enter basic salary: ");

                scanf("%f", &e.bs);

                printf("\n                Enter mobile number: ");

                scanf("%d", &e.mobile);

                fwrite(&e,recsize,1,fp); /// write the record in the file


                printf("\n                Add another record(y/n) ");

                fflush(stdin);

                another = getche();

            }

            break;

        case '2':

            system("cls");

            printf("EMPLOYEE's RECORD LIST (name, age, address, salary)");

             printf("\n\n                       \t Name \t Age \t  Address    Salary \t Mobile\n\n");

            rewind(fp); ///this moves file cursor to start of the file

            while(fread(&e,recsize,1,fp)==1)  /// read the file and fetch the record one record per fetch
            {

                printf("\t                 %s\t  %d\t  %s\t     %.2f\t 0%d\n",e.name,e.age,e.address,e.bs,e.mobile); /// print the name, age and basic salary
                
                

            }
            getch();

            break;

        case '3':  /// if user press 3 then do editing existing record

            system("cls");

            another = 'y';

            while(another == 'y')

            {
                printf("Enter the employee name to modify: ");

                scanf("%s", empname);

                rewind(fp);

                while(fread(&e,recsize,1,fp)==1)  /// fetch all record from file

                {

                    if(strcmp(e.name,empname) == 0)  ///if entered name matches with that in file

                    {

                        printf("\nEnter new name,age,address and bs: ");

                        scanf("%s%d%s%f",e.name,&e.age,&e.address,&e.bs);

                        fseek(fp,-recsize,SEEK_CUR); /// move the cursor 1 step back from current position

                        fwrite(&e,recsize,1,fp); /// override the record

                        break;

                    }
                }

                printf("\nModify another record(y/n)");

                fflush(stdin);

                another = getche();

            }
            break;

        case '4':

            system("cls");

            another = 'y';

            another = 'y';

            while(another == 'y')

            {

                printf("\nEnter name of employee to delete: ");

                scanf("%s",empname);

                ft = fopen("Temp.txt","wb");  /// create a intermediate file for temporary storage

                rewind(fp); /// move record to starting of file

                while(fread(&e,recsize,1,fp) == 1)  /// read all records from file

                {

                    if(strcmp(e.name,empname) != 0)  /// if the entered record match

                    {

                        fwrite(&e,recsize,1,ft); /// move all records except the one that is to be deleted to temp file

                    }

                }

                fclose(fp);

                fclose(ft);

                remove("Database.txt"); /// remove the orginal file

                rename("Temp.txt","Database.txt"); /// rename the temp file to original file name

                fp = fopen("Database.txt", "rb+");

                printf("Delete another record(y/n)");

                fflush(stdin);

                another = getche();

            }

            break;

        case '5':

            fclose(fp);  /// close the file

            exit(0); /// exit from the program

        }

    }

    return 0;

}
