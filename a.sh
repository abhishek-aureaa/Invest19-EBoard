sudo apt-get remove --purge mysql* -y
sudo apt-get purge mysql* -y
sudo apt-get autoremove -y
sudo apt-get autoclean -y
sudo apt-get remove dbconfig-mysql -y
sudo apt-get dist-upgrade -y
sudo apt-get install mysql-server -y
sudo apt-get install libmysqlclient-dev -y
#install build-essentials
gcc version.c  -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc createdb.c   -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc grantuser.c   -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc createtableinsert.c    -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc nominate.c   -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient


#sql command : use testdb;
#select user  from mysql.user;

#https://ubuntu.com/download/desktop/thank-you?version=18.04.4&architecture=amd64
#http://releases.ubuntu.com/19.10/ubuntu-19.10-desktop-amd64.iso
