/*#include <iostream>*/
#include <my_global.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
  if(argv[1] == NULL)
  {
	printf("please provide name in the command line\n"); 
        return 0;
  }

  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }  

  if (mysql_real_connect(con, "localhost", "user12", "34klq*", 
          "testdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
   char requete[500];
   memset(requete,'\0',500);

   strcpy(requete, "INSERT INTO manifesto VALUES ('");
   strcat(requete, argv[1]);
  
   printf("111\n");

   if(argv[2] != NULL)
   {
      strcat(requete, "','");
      strcat(requete, argv[2]);
   }

   printf("222\n");
   if(argv[3] != NULL)
   {
      strcat(requete, "','");
      strcat(requete, argv[3]);
   }

   printf("333\n");
   if(argv[4] != NULL)
   //if(argv[4] == "")
   {
      strcat(requete, "','");
      strcat(requete, argv[4]);
   }

   printf("444\n");
   if(argv[5] != NULL)
   //if(argv[5] == NULL)
   {
      strcat(requete, "','");
      strcat(requete, argv[5]);
   }
   strcat(requete, "')");
   printf("5555\n");

   if (mysql_query(con,requete)) {
      finish_with_error(con);
  }
   printf("666\n");

  
  mysql_close(con);
  exit(0);
}
