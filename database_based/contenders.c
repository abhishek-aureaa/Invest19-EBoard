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
  
  if (mysql_query(con, "DROP TABLE IF EXISTS contenders")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "DROP TABLE IF EXISTS manifesto")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "DROP TABLE IF EXISTS IDEA")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE contenders(Name TEXT)")) {      
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE manifesto(contender TEXT, manifesto TEXT, idea1 TEXT , idea2 TEXT , idea3 TEXT)")) {      
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE IDEA(idea TEXT, contender TEXT, citizen TEXT, rating INT)")) {      
      finish_with_error(con);
  }
  
  mysql_close(con);
  exit(0);
}
