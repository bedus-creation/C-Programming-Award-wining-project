
//#include "check_digit.h"
#ifndef SECURITY_H
#define SECURITY_H

#include "passwords.h"
void delete_password(){
   remove("data\\password.dat");
  rmdir("data");
  system("cls");
           printf("\n\n\t\tsucessfully deleted password\n\n\t\t");
           system("pause");
           system("cls");
}
void change_password(){
    FILE *f;
    char c[12];
    char password[200];
 if(main_passwords()){
        printf("\t\tplease enter the new password\n");
        f=fopen("data\\password.dat","w");
         printf("\t\tplese enter new password\n\t\t");
          scanf("%s",password);
          encrypt(password,0xFECA);
          fprintf(f,"%s",password);
           fclose(f);
           system("cls");
           printf("\n\n\t\tsucessfully changed password\n\n\t\t");
           system("pause");
           system("cls");
    }else{
      exit(1);
    }
}
int get_security_choice(){
   char choice[5];
  int x;//to return integer
  printf("\tSELECT THE NUMBER FOR:\n\n"
         "\t1 -change/edit password\n\n"
         "\t2 -delete password:\n\n"
         "\t9 for go main menu\n\n\n\n\t");
 scanf("%s",&choice);
 x=check_degit(choice);
 return x;
}
void main_security(){
  char a[20];
  int c;
  while((c=get_security_choice())!=9){
      switch(c){
           case 1:
               change_password();
               break;
           case 2:
               delete_password();
               break;
           case 9:
            main();
            break;
          default:
              break;
      }
  }
  system("pause");
}

#endif // SECURITY_H
