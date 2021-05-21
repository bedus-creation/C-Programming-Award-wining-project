#include "global_variable.h"
#include "check_digit.h"
void addRecords(FILE *add)
{
    int variable, i, account, k; //use full
    char ignorestring[200] = "";
    struct Applicants data = {0, "", "", "", 0, 0, 0, 0, 0, 0};
    data.sn = 1;
    char quite[120];
    // start of user input
    do
    {
        //    checking the empty
        for (account = 0; account < 100; account++)
        {
            fseek(add, (account - 1) * sizeof(struct Applicants), SEEK_SET);
            fread(&data, sizeof(struct Applicants), 1, add);
            if (account == 0)
            {
                break;
            }
        }
        while (1)
        {
            printf("\tEnter ioerank:-\t");
            scanf("%s", &ignorestring);
            data.ioerank = check_degit(ignorestring);
            if (data.ioerank > 0 && check_rank(add, data.ioerank))
            {
                break;
            }
        }
        data.sn = 2;
        printf("\n\tfirstname:\t");
        scanf("%s", &data.fristname);
        printf("\n\tlastname:-\t");
        scanf("%s", &data.lastname);
        while (1)
        {
            printf("\n\tdistrict:-\t");
            scanf("%s", &data.district);
            for (i = 0; i < strlen(data.district); i++)
            {
                data.district[i] = tolower(data.district[i]);
            }
            variable = check_district(data.district);
            if (variable > 0)
            {
                break;
            }
            else
            {
                printf("\t\tplease check the speeling.....\n"
                       "\t\tor go to main menu see the district name list\n");
            }
        }
        while (1)
        {
            printf("\n\tdisable\n"
                   "\t\t1 for disable\n"
                   "\t\t2 for fine\n\t");
            scanf("%s", &ignorestring);
            data.disable = check_degit(ignorestring);
            if ((data.disable == 1) || (data.disable == 2))
            {
                break;
            }
            else
            {
                printf("\n\tThe value must between 1 and 2\n");
            }
        }
        while (1)
        {
            printf("\n\tgender\n"
                   "\t\t1 for male\n"
                   "\t\t2 for female\n\t");
            scanf("%s", &ignorestring);
            data.gender = check_degit(ignorestring);
            if ((data.gender == 1) || (data.gender == 2))
            {
                break;
            }
            else
            {
                printf("\n\tThe value must between 1 and 2\n");
            }
        }
        while (1)
        {
            printf("\n\tslc from\n"
                   "\t\t1 for government\n"
                   "\t\t2 for private\n\t");
            scanf("%s", &ignorestring);
            data.slc = check_degit(ignorestring);
            if ((data.slc == 1) || (data.slc == 2))
            {
                break;
            }
            else
            {
                printf("\n\tThe value must between 1 and 2\n");
            }
        }
        system("cls");
        while (1)
        {
            printf("\n\t+2 from \n"
                   "\t\t1 for government college\n"
                   "\t\t2 for private college\n\t");
            scanf("%s", &ignorestring);
            //checking the user input
            data.hseb = check_degit(ignorestring);
            if ((data.hseb == 1) || (data.hseb == 2))
            {
                break;
            }
            else
            {
                printf("\n\tThe value must between 1 and 2\n");
            }
        }
        //end of user input

        if (account != 0)
        {
            printf("please check the list and enter the serial number");
        }
        else
        {
            fseek(add, (account - 1) * sizeof(struct Applicants), SEEK_SET);
            fwrite(&data, sizeof(struct Applicants), 1, add);
            sorting();
        }
        printf("\t\tpress 1 to continue next data\n\t\t"
               "press other key to go main menu\n\n\t\t");
        scanf("%s", &quite);
        variable = check_degit(quite);
    } while (variable == 1);
    system("cls");
}
