#ifndef PASSWORD_H
#define PASSWORD_H

void encrypt(char password[],int key)
{
    unsigned int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i]+ key;
    }
}
void decrypt(char password[],int key)
{
    unsigned int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i] - key;
    }
}
int create_password_dat(){
    FILE *f;
    char c[12];
    char password[200];
    int status;
        if(opendir("data")){
            printf("\n\n\t\tyou delete password.dat file\n\n\t\t");
            system("pause");
            status=0;
        }else{
             printf("\t\tdo you want to set password y/n?\n\t\t");
             scanf("%s",c);
              if(strcmp(c,"y")==0){
        mkdir("data");
         f=fopen("data\\password.dat","w");

          printf("\t\tplese enter new password\n\t\t");
          scanf("%s",password);
          encrypt(password,0xFECA);
          fprintf(f,"%s",password);
           fclose(f);

        }
        status=1;
      }
      //it doesnot matter whether user set password or not
      return status;
}
int main_passwords(){
    char password[200]="";
    char data[200]="";
    FILE *f;
    f=fopen("data\\password.dat","r");
    int toreturn=0,i=0;
    if(f!=NULL){
     rewind(f);
       fscanf(f,"%s",data);
         fclose(f);
        //decrypt(data,0xFACA);//array does not requiree to return
        //check if password file is empty....
        if(strcmp(data,"")!=0){
                //decripting data
                decrypt(data,0xFACA);
           //three chance ..........
            for(i=0;i<3;i++){
              printf("\t\tenter password to go\n\n\t\t");
              scanf("%s",password);
            if(strcmp(data,password)==0){
                toreturn=1;
                break;
           }else {
           printf("\t\tyou have %d chance\n",2-i);
           printf("\t\totherwise you loss the data\n");
           }
         }
       }else{
          printf("\n\n\n\t\tyou delete the passwords.\n"
                 "\t\tyou lost the data please reinstall\n\n");
          system("pause");
       }
        //end of while-----------------------
        }//end od checking null data
     else{
    toreturn=create_password_dat();
    }
    return toreturn;
}


#endif // PASSWORD_H
