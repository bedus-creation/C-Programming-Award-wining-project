//#include "global_variable";
#include "addrecords.h"
#include "get_choice.h"
#include "delete_records.h"
#include "print_final_records.h"
#include "publish_final_list.h"
#include "security.h"
#include "change_theme.h"
void start_the_file(file){
    int choice;

    if((file=fopen("students.dat","rb+"))!=NULL){
                //encript_file(file);
               // decript_file(file);

        while((choice=getchoice())!=9){

                switch(choice){
              case 1:
                  system("cls");
                  addRecords(file);
                  system("cls");
                  break;
              case 2:
                  system("cls");
                  editRecords(file);
                  system("cls");
                  break;
              case 3:
                  system("cls");
                  show_final_list(file);
                  system("cls");
                  break;
              case 4:
                  system("cls");
                  publish_final_result(file);
                  system("cls");
                  break;
              case 5:
                    system("cls");
                    help("main");
                    view_district();//showing district priority---------------------------
                    system("cls");
                      break;
             case 6:
                    system("cls");
                    view_district();
                    system("cls");
                     break;
             case 7:
                   system("cls");
                   main_security();
                   system("cls");
                   break;
             case 8:
                  system("cls");
                  change_theme();
                  system("cls");
                  break;

            default:
                  printf("\n\n\n\tplease enter the number between 1-7\n");
                  system("pause");
                  system("cls");
                }
        }
    }else{
     file=fopen("students.dat","w");
     fclose(file);
     start_the_file(file);
    }
    //encripting file before closing
}

