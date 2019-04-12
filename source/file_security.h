#include "global_variable.h"
#include "passwords.h"
#ifndef file_encript
#define file_encript

void encript_file(FILE *list){
    struct Applicants temp[200];
  int j=0;
  int i=0;
  int disableno=0;
  int sn_to_show=0;
  int qota[2]={0,0};
  FILE *write;
  rewind(list);
  //to store the data of file to structure array
   while(!feof(list)){
         fread(&array[i],sizeof(struct Applicants),1,list);
         if((array[i].priority=check_district(array[i].district))>0){
         i=i+1;
         }
   }
  sorting();
  for(j=0;j<i;j++){
        if(array[j].disable==1 && sn_to_show<2){
                qota[sn_to_show]=array[j].ioerank;
                disableno=disableno+1;
                temp[sn_to_show]=array[j];
                  sn_to_show=sn_to_show+1;
        }
}  //end of for
   for(j=0;j<i;j++){
    if((array[j].ioerank)!=0){
            if((array[j].ioerank)!=qota[0] &&
           (array[j].ioerank)!=qota[1]){
                     temp[sn_to_show]=array[j];
                    sn_to_show=sn_to_show+1;
                }
          }
}
rewind(list);
for(j=0;j<sn_to_show;j++){
    encrypt(array[j].fristname,0xFACA);
    encrypt(array[j].lastname,0xFACA);
    encrypt(array[j].district,0xFACA);
  // fseek(list,(j)*sizeof(struct Applicants),SEEK_SET);
//fwrite(&array[j],sizeof(struct Applicants),1,list);
}
if((write=fopen("students.txt","w"))!=NULL){
   //disable frist
   //
fprintf(write,"\t\tfinal list of  Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t-----------------------------------------------------\n");
i=0;
for(j=0;j<sn_to_show;j++){
        if(array[j].ioerank>0){
                i+=1;
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",i,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
          }
        } //end of for

fprintf(write,"\n\n\t\tfinal list of girls Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t----------------------------------------------------\n");
for(j=0;j<sn_to_show;j++){
        if(array[j].gender==2){
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",j+1,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
        }
    }
fprintf(write,"\n\n\t\tfinal list of boys Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t-------------------------------------------------------\n");
i=0;
for(j=0;j<sn_to_show;j++){
        if(array[j].gender==1){
            i+=1;
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",i,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
        }
    }
     fclose(write);
    system("cls");
      printf("\t\tsucessfully executed the test file\n\n");
    printf("\t\tpress any key.......\n\n");
      system("pause");
   }else{
     printf("unable to open file");
   }
}
void decript_file(FILE *list){
  FILE *write;
    struct Applicants temp[200];
  int j=0;
  int i=0;
  int disableno=0;
  int sn_to_show=0;
  int qota[2]={0,0};
  rewind(list);
  //to store the data of file to structure array
   while(!feof(list)){
         fread(&array[i],sizeof(struct Applicants),1,list);
         if(array[i].ioerank!=0){
            sn_to_show=i;
            i+=1;
         }
         }
  rewind(list);
for(j=0;j<i;j++){
   decrypt(array[j].fristname,0xFACA);
   decrypt(array[j].lastname,0xFACA);
   decrypt(array[j].district,0xFACA);
  // fseek(list,(j)*sizeof(struct Applicants),SEEK_SET);
   // fwrite(&array[j],sizeof(struct Applicants),1,list);
}
if((write=fopen("students.txt","w"))!=NULL){
   //disable frist
   //
fprintf(write,"\t\tfinal list of  Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t-----------------------------------------------------\n");
i=0;
for(j=0;j<sn_to_show;j++){
        if(array[j].ioerank>0){
                i+=1;
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",i,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
          }
        } //end of for

fprintf(write,"\n\n\t\tfinal list of girls Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t----------------------------------------------------\n");
for(j=0;j<sn_to_show;j++){
        if(array[j].gender==2){
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",j+1,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
        }
    }
fprintf(write,"\n\n\t\tfinal list of boys Applicants\n\n");
fprintf(write,"%-4s%-6s%-8s%-8s%-8s%-6s%6s%4s%8s\n","s.n.","rank",
           "fristn.","lastn.","gend.","dist","slc","+2","disable");
fprintf(write,"\t-------------------------------------------------------\n");
i=0;
for(j=0;j<sn_to_show;j++){
        if(array[j].gender==1){
            i+=1;
           fprintf(write,"%d.%4d%8s%8s%3s%14s%7s%5s%8s\n",i,
            array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
        }
    }
     fclose(write);
    system("cls");
      printf("\t\tsucessfully executed the test file\n\n");
    printf("\t\tpress any key.......\n\n");
      system("pause");
   }else{
     printf("unable to open file");
   }
}
#endif // file_encript
