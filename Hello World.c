#include<stdio.h>
#include<stdlib.h>
#include<mysql.h>
#include<string.h>
int main(){
    //Connecting To The Local MySQL Server
    MYSQL *conn;
    MYSQL_RES *res1,*res2;
    MYSQL_ROW row;
    char server[] = "localhost";
    char user[] = "root";
    char password[] = "2023";
    char database[] = "BANK_MANAGEMENT_SYSTEM_DATABASE";
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)){
    printf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
    exit(EXIT_FAILURE);
    }
    else{
     printf("Successfully connected to MySQL database\n");
    }
        //SIGNUP SCREEN
    int welcome_page_options;
    char login_username[100];
    char login_password[100];
    printf("\tWELCOME TO NYAY BANK");
    printf("\nSelect From The Following Options :");
    printf("\n1.Login To Existing Account");
    printf("\t2.Create A New Account");
    printf("\t2.Create A New Account\n");
    scanf("\n%d",&welcome_page_options);
    //Branching INTO EITHER OF THE OPTION
    if(welcome_page_options==1){//logging into existing account
        printf("Username : ");
    }
}
        scanf("%s",&login_username);
        // Check if the value is in the database
        char query1[100];
        sprintf(query1, "SELECT * FROM BMS_DATABASE WHERE Username = '%s'", login_username);
        if (mysql_query(conn, query1)) {
            fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
            exit(1);
        }
        res1 = mysql_store_result(conn);
        if (res1) {
            if (mysql_num_rows(res1) > 0) {
                printf("Password : ");
                scanf("%s",&login_password);
                //checking password
                char query2[100];
                sprintf(query2, "SELECT * FROM BMS_DATABASE WHERE Password = '%s'", login_password);
                if (mysql_query(conn, query2)){
                fprintf(stderr, "Error executing query: %s\n", mysql_error(conn));
                exit(1);
                }
                res2 = mysql_store_result(conn);
                if (res2){
                    if (mysql_num_rows(res2) > 0) {
                    //moving on with correct password
                    printf("Success");
                }
                else {
                    printf("Incorrect Password");
                }
            mysql_free_result(res2);
            }
            }
            else {
            printf("Incorrect Username");
            }
            mysql_free_result(res2);
            }
     }
}
