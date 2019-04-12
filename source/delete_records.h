#include "global_variable.h"
#include "check_digit.h"

void editRecords(FILE *edit){
    struct Applicants data={0,"","","",0,0,0,0,0,0};
    struct Applicants blank={0,"","","",0,0,0,0,0,0};
    char variable[20];
    int serialno=0,j,i=0,file_sirial_no=0;
    int disableno=0,sn_to_show=0;
    int qota[2]={0,0} ;//rank numbe
    while(serialno==0){
     printf("\t\tEnter the rank of you want to delete\n\t\t");
    scanf("%s",&variable);
    serialno=check_degit(variable);
    }

    rewind(edit);
   while(!feof(edit)){
        fread(&array[i],sizeof(struct Applicants),1,edit);
        array[i].sn=i+1;
         i=i+1;
   }
    //moving file pointer
    //finding the serial number of rank-------------
for(j=0;j<i;j++){
  if((array[j].ioerank)==serialno){
     file_sirial_no=array[j].sn;
 }
}
if(file_sirial_no>0){
    rewind(edit);
     //moving file pointer
    fseek(edit,(file_sirial_no-1)*sizeof(struct Applicants),SEEK_SET);
    fread(&data,sizeof(struct Applicants),1,edit);
    if(data.sn==0){
        printf("\n\t\tno information\n");
        system("pause");
    }else{
    printf("\t\tyou want to delete:\n"
           "\t\trank     :\t\t%d\n"
           "\t\tfristname:\t\t%s\n"
           "\t\tlastname :\t\t%s\n\n",data.ioerank,data.fristname,data.lastname);
             printf("\t\tare you sure ?"
           "\tpress y or n\n\t\t");
            scanf("%s",&variable);
           if(strcmp(variable,"y")==0){

           fseek(edit,(file_sirial_no-1)*sizeof(struct Applicants),SEEK_SET);
            fwrite(&blank,sizeof(struct Applicants),1,edit);
            system("cls");
            printf("\t\tsucessfully deleted:\n"
           "\t\tioerank:\t\t%d\n"
           "\t\tfristname:\t\t%s\n"
           "\t\tlastname:\t\t%s\n\n",data.ioerank,data.fristname,data.lastname);
           sorting();
           system("pause");
           }
        }
  }else {
    printf("\t\tnoinformation\n");
    system("pause");
  }
}
