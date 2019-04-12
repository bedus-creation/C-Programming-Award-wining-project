#include "global_variable.h"
#include "check_digit.h"

void show_final_list(FILE *list){
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
for(j=0;j<i;j++){
array[j]=temp[j];
}
  printf("\t\tfinal Applicants list basis on priority order\t\t");
  printf("\n\n");
   printf("%-6s%-6s%-12s%-12s%-8s%-14s%6s%4s%8s\n","s.n.","rank","fristname","lastname","gender","district","slc","+2","diable");
  sn_to_show=0;
  disableno=0;
  for(j=0;j<i;j++){
    if((array[j].ioerank)!=0){
         printf("%-6d%-6d%-12s%-12s%-8s%-14s%6s%4s%8s\n",j+1,
           array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");

    }
}
  //to sort the structure array according to priority

  printf("\n\t\tpress any key........\n\n");
  getch();
  printf("\t\t final girls Applicants list basis on priority order\t\t");
  printf("\n\n");
  sn_to_show=0;
  for(j=0;j<i;j++){
  if(array[j].gender==2){
        sn_to_show=sn_to_show+1;
      printf("%-6d%-6d%-12s%-12s%-12s%-10s%6s%4s%8s\n",sn_to_show,
           array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
   }
  }
  printf("\n\t\tpress any key.......\n");
  getch();

  printf("\t\t final boys Applicants list basis on priority order\t\t");
  printf("\n\n");
  sn_to_show=0;
  for(j=0;j<i;j++){
  if(array[j].gender==1 && array[j].gender!=0){
        sn_to_show=sn_to_show+1;
      printf("%-6d%-6d%-12s%-12s%-8s%-14s%6s%4s%8s\n",sn_to_show,
           array[j].ioerank,array[j].fristname,array[j].lastname,
           (array[j].gender==1)?"m":"f",array[j].district,
           (array[j].slc==1)?"gov":"pvt",(array[j].hseb==1)?"gov":"pvt",
           (array[j].disable==1)?"yes":"no");
   }
  }
  printf("\n\t\tpress any key.....\n");
  getch();

}

//function--------------------------------------







