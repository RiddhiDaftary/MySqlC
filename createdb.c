#include <my_global.h>
#include <mysql.h>
#include <string.h>

int main(int argc, char *argv[]) // main function
{
    char strDBName[100];
    MYSQL *con = mysql_init(NULL);
    char strQuery[] = "CREATE DATABASE ";
    
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(0);
    }
    
    if (mysql_real_connect(con, "localhost", "root", "1", NULL, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(0);
    }
    
printf("arguments - %d",argc);
printf("first arg - %s",argv[0]);

if (argc != 1)
{
    printf("\nEnter the name of the database : \n");
    scanf("%s",strDBName);
}
else
{
//	strDBName = &argv[0];
strcpy(strDBName,argv[0]);
}
    strcat(strQuery,strDBName);
    printf("\n Query is -> : %s \n",strQuery); 
    
    if (mysql_query(con, strQuery))
    {
            fprintf(stderr, "%s\n", mysql_error(con));
            mysql_close(con);
            exit(0);
    }
    mysql_close(con);
    exit(1);
}
