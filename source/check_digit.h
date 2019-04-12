#include "global_variable.h";
#include "sorting.h"
#ifndef CHECK_DIGIT
#define CHECK_DIGIT
 // CHECK_DIGIT
int check_degit(char a[]){
    int s;
    s=atoi(a);
    if(s>10000){
        printf("\n\tplease less than 10000\n");
    }
    else if(s>0){
        return s;
    }else{
      printf("\n\tnot a valid integer\n");
      return 0;
    }
}
int check_rank(FILE *read,int rank){
    int i=0,j=0;
    rewind(read);
  while(!feof(read)){
        fread(&array[i],sizeof(struct Applicants),1,read);
         if((array[i].priority=check_district(array[i].district))>0){
         i=i+1;
         }
   }
  // sorting();
    for(j=0;j<i;j++){
    if((array[j].ioerank)==rank){
      break;
     }
  }
  if((array[j].ioerank)==rank){
      printf("\n\t\tAlready exits rank....\n");
      return 0;
     }
     else {
        return rank;
     }
}
int check_district(char *dis){
    int j;
    //district having high priority is in increasing order
    for(j=0;j<size_dis;j++){
        if(strcmp(district[j],dis)==0){
            return (j+1)*10;
            break;
        }
     }
     return 0;
}
void view_district(){
int i;
 for(i=1;i<size_dis+1;i++){
 int j=size_dis-i;
 if(strcmp(district[j],"")!=0){
 printf("\t\t%d:\t\t%s\n",i,district[j]);
  }
 }
 printf("\n\n\t\t");
 system("pause");
}

#endif
