#include <stdlib.h>
void change_theme(){
 int num;
 int quite=1;
 char c[5];
 num=1+rand()%4;

    while(num!=9){
         switch(quite){

          case 1:
            system("color 80");
             break;
          case 2:
             system("color 9c");
             break;
          case  3:
               system("COLOR 60");
               break;
          case 4:
                system("color 70");
                break;
          case 5:
                system("COLOR 0e");
                break;
          case 6:
                system("COLOR 0e");
                break;
          case  7:
              system("color 30");
              break;
          case 8:
            system("color 5c");
             break;
          case 9:
            system("color a0");
             break;
          default :
             system("color fc");
             quite=0;
             break;
         }
        printf("\n\tdo you like it ?\n"
               "\n\t press 9 if you like -------------\n"
               "\t otherwise press any key\n\n\t");
        scanf("%s",c);
        num=check_degit(c);
        quite=quite+1;
        system("cls");
    }
}
