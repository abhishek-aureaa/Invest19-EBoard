#steps to install and run mysql 

sudo apt-get remove --purge mysql* -y
sudo apt-get purge mysql* -y
sudo apt-get autoremove -y
sudo apt-get autoclean -y
sudo apt-get remove dbconfig-mysql -y
sudo apt-get dist-upgrade -y
sudo apt-get install mysql-server -y
sudo apt-get install libmysqlclient-dev -y


#install google test and google mock
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib


#Compile and run the tests:
cmake CMakeLists.txt
make
./runTests


#install build-essentials

#gcc version.c  -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc createdb.c -o createdb  -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc createuser.c -o createuser -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc grantuser.c -o grantuser -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
#gcc createtableinsert.c -o createtableinsert -I/usr/include/mysql -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc nominate.c  -o nominate  -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc manifesto.c  -o manifesto -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc listmanifesto.c  -o listmanifesto -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient

#contenders.c
gcc contenders.c -o contenders -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient
gcc rate.c -o rate -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient
#deleterate.c
gcc deleterate.c -o deleterate -I/usr/include/mysql  -L/usr/lib/x86_64-linux-gnu -lmysqlclient


#testing 
./createdb
./createuser
./contenders
./nominate abhishek
./manifesto  abhishek MANIFESTO IDEA1 IDEA2 IDEA3
./manifesto  abhishek MANIFESTO IDEA1 IDEA2
./manifesto  abhishek MANIFESTO IDEA1
./manifesto  abhishek MANIFESTO
./listmanifesto
./rate IDEA1 abhishek ravi 6
./deleterate IDEA1 abhishek



#sql command : use testdb;
#select user  from mysql.user;

#https://ubuntu.com/download/desktop/thank-you?version=18.04.4&architecture=amd64
#http://releases.ubuntu.com/19.10/ubuntu-19.10-desktop-amd64.iso
