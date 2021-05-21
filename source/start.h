//#include "global_variable";
#include "addrecords.h"
#include "get_choice.h"
#include "delete_records.h"
#include "print_final_records.h"
#include "publish_final_list.h"
void execute()
{
    FILE *file;

    int choice;

    if ((file = fopen("students.dat", "rb+")) != NULL)
    {

        while ((choice = getchoice()) != 9)
        {

            switch (choice)
            {
            case 1:
                system("clear");
                addRecords(file);
                system("clear");
                break;
            case 2:
                system("clear");
                editRecords(file);
                system("clear");
                break;
            case 3:
                system("clear");
                show_final_list(file);
                system("clear");
                break;
            case 4:
                system("clear");
                publish_final_result(file);
                system("clear");
                break;
            case 5:
                system("clear");
                help("main");
                view_district(); //showing district priority---------------------------
                system("clear");
                break;

            default:
                printf("\n\n\n\tplease enter the number between 1-5\n");
                system("pause");
                system("clear");
            }
        }
    }
    else
    {
        file = fopen("students.dat", "w");
        fclose(file);
        execute();
    }
}
