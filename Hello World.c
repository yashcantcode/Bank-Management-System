#include<stdio.h>
#include<stdlib.h>
int main(){
    int welcome_page_options;
    printf("\tWELCOME TO NYAY BANK");
    printf("\nSelect From The Following Options :");
    printf("\n1.Login To Existing Account");
    printf("\t2.Create A New Account");
    scanf("\n%d",&welcome_page_options);
    //Branching INTO EITHER OF THE OPTION
    if(welcome_page_options==1){//logging into existing account
        printf("Username : ");
    }
}