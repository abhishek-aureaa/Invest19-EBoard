#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{  
  MYSQL *con = mysql_init(NULL);

  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "root", "root_pswd", 
          NULL, 0, NULL, 0) == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }  

/*CREATE USER user12@localhost IDENTIFIED BY '34klq*';
  if (mysql_query(con, "CREATE DATABASE testdb")) */
  //IF NOT EXISTS
  //if (mysql_query(con, "CREATE USER user12@localhost IDENTIFIED BY '34klq*'")) 
  if (mysql_query(con, "CREATE USER IF NOT EXISTS user12@localhost IDENTIFIED BY '34klq*'")) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  mysql_close(con);
  exit(0);
}
