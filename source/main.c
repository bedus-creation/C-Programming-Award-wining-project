#include <stdio.h>
#include <stdlib.h>

#include "start.h"
  //end of district declaration
#include "welcome.h"
#include "passwords.h"
//#include "check_digit.h"
int main()
{
    char sa[12];
    FILE *file;
    //
     system("color 60");
    printf("\n\t do you want to change the color  press y/n bed ?\n\n\n\t\t");
    scanf("%s",sa);

    if(strcmp(sa,"y")==0){
      change_theme();
    }
    system("cls");
    welcome();

    system("cls");

     if(!main_passwords()){
        printf("\n\t\tplease reinstall this software\n\n\t");
        exit(1);
    }
    system("cls");
    start_the_file(file);
    return 0;
}
