#include "global_variable.h";
#ifndef SORTING
#define SORTING
void sorting(){
    int i,j;
    struct Applicants temp;
for(i=0;i<200;i++){
   for(j=0;j<200;j++){
     if((array[j].ioerank)!=0){
      if(array[j].priority<array[j+1].priority){
        temp=array[j];
        array[j]=array[j+1];
        array[j+1]=temp;

        }//if district priority is equal
        if(array[j].priority==array[j+1].priority){
            if(array[j].slc>array[j+1].slc){
            temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
            }
            if(array[j].slc==array[j+1].slc){
                if(array[j].hseb>array[j+1].hseb){
                      temp=array[j];
                      array[j]=array[j+1];
                      array[j+1]=temp;
                }
                if(array[j].hseb==array[j+1].hseb){
                         if(array[j].ioerank>array[j+1].ioerank){
                               temp=array[j];
                                array[j]=array[j+1];
                                array[j+1]=temp;
                            }
                            if(array[j].ioerank==array[j+1].ioerank){
                              array[j].disable=0;
                              strcpy(array[j].district,"");
                              strcpy(array[j].fristname,"");
                              array[j].gender=0;
                              array[j].hseb=0;
                              array[j].ioerank=0;
                              strcpy(array[j].lastname,"");
                              array[j].priority="0";
                              array[j].slc=0;
                              array[j].sn=0;
                            }
                            }
                  }
            }
         }
      }
    }
}
#endif // SORTING
