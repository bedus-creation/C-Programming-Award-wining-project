
int getchoice()
{
    char choice[20];
    int x; //to return integer
    printf("\tSELECT THE NUMBER FOR:\n\n"
           "\t1 -add new Applicants to list\n\n"
           "\t2 -delete a applicants data from :\n\n"
           "\t3 -show final list of Applicants\n\n"
           "\t4 -publish the final result in text file\n\n"
           "\t5 -help..........\n\n"
           "\t6 -view the district priority list\n\n"
           "\t7-security.............\n\n"
           "\t8 -to chane the color setting\n\n"
           "\t9 for exit\n\n\n\n\t");
    scanf("%s", &choice);
    x = check_degit(choice);
    return x;
}

void help(char help[])
{
    if (strcmp(help, "main") == 0)
    {
        printf("\t%s\n\n", "help:-");
        printf("\t\tthanks for choosing hostel system\n"
               "\t\tyou can add student records to system\n"
               "\t\twhich is stored in the form of dat file\n"
               "\t\tStoring the data in the dat file helps\n"
               "\t\tyou to keep data permanently.\n"
               "\t\tthe final list of applicants are published\n"
               "\t\taccording to the district priority ");
    }
    else
    {
        printf("uable to help you");
    }
    printf("\n\n\t\t");
    system("pause");
}
