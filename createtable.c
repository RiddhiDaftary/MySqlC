#include <my_global.h>
#include <mysql.h>
#include <string.h>

void finish_with_error(MYSQL *con)
{
	  fprintf(stderr, "%s\n", mysql_error(con));
	  mysql_close(con);
	  exit(1);        
}

typedef struct description
{
	char DataType[20];
	char ColName[50];
}desc;


int main(int argc, char **argv)
{
	int colno,i;
	desc column[50];    
	char strDBName[100],strTableName[100];
    char strCreateDB[] = "CREATE DATABASE ";
	char strCreateTable[]="CREATE TABLE ";
    MYSQL *con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(0);
    }
    
    if (mysql_real_connect(con, "localhost", "root", "fantastic", NULL, 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
    
	printf("\nEnter the name of a database : \n");
    scanf("%s",strDBName);
	strcat(strCreateDB,strDBName);
    printf("\n Query is -> : %s \n",strCreateDB);

	if (mysql_query(con, strCreateDB))
    {
    	finish_with_error(con);
    }

	printf("\nEnter the name of a table : \n");
    scanf("%s",strTableName);
	strcat(strCreateTable,strTableName);
    
	printf("\nEnter the no. of columns : \n");
    scanf("%d",&colno);

	strcat(strCreateTable,"(");
	for(i=0;i<colno;i++)
	{
		printf("enter datatype and column name of column %d : \n",(i+1));
		scanf("%s %s",column[i].ColName,column[i].DataType);
		if(i!=0)
			strcat(strCreateTable,",");
		strcat(strCreateTable,column[i].ColName);
		strcat(strCreateTable," ");
		strcat(strCreateTable,column[i].DataType);
		
	}
	strcat(strCreateTable,")");

	printf("\n Query is -> : %s \n",strCreateTable);

	if (mysql_query(con, strCreateTable))
    {
    	finish_with_error(con);
    }

	mysql_close(con);
    exit(1);
}
