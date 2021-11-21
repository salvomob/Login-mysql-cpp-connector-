#include <mysql/mysql.h>
#include "connection.h"
#include <iostream>
#include <unistd.h>
#include <string.h>


MYSQL * connection_setup(Connection c)
{
    MYSQL *connection = mysql_init(NULL);
    if(!mysql_real_connect(connection,c.getServer(),c.getUser(),c.getPassword(),c.getDatabase(),0,NULL,0))
    {
        std::cerr << "ERRORE DI CONNESSIONE : " << mysql_error(connection) << std::endl;
        exit(1);
    }
   /* std::cout << "WORKS HERE\n";
    std::cout << "c.getS = "<< c.getServer() << "\n";
    std::cout << "c.getU = "<< c.getUser() << "\n";
    std::cout << "c.getP = "<< c.getPassword() << "\n";
    std::cout << "c.getD = "<< c.getDatabase() << "\n";
   */
    return connection;
}

MYSQL_RES * execute_query(MYSQL* connection,const char* query)
{
    if(mysql_query(connection,query))
    {
            std::cerr << "Errore : " << mysql_error(connection) << std::endl;
    }
    return mysql_store_result(connection);
}

bool login(char* a,char* b)
{
	int l1 = strlen(a);
	int l2 = strlen(b);
	int counter = 0;
	if(l1!=l2) return false;
	for(int i = 0; i < l1;i++)
	{
		if(a[i] == b[i]) counter++;
		else return false;
	}
	if(counter == l1) return true;
	return false;
}

int main(){
	std::cout << "Inserisci il tuo username:";
	char *usnm;
	char* pasw;
	std::cin >> usnm;
	std::cout << "Inserisci la tua password:";
	std::cin>>pasw;
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;

    Connection con(""/*here the server*/,""/*here the username*/,""/*here the password*/,""/*here the database*/);


    connection = connection_setup(con);
    result = execute_query(connection,"select * from logins;");
    int counter = 0;
    bool checkUs = false;
    bool checkPw = false;
    int n = mysql_num_fields(result);//numero di campi <-> numero colonne presenti 
    while((row = mysql_fetch_row(result))!=NULL)
    {
    	/*
    	for(int i = 0; i < n; i++)
    	{
    		std::cout << row[i] << " | " ;
     	}
     	std::cout << std::endl;
     	*/
    	checkUs = login(row[0],usnm);
    	checkPw = login(row[1],pasw);
    	if(checkUs && checkPw)
    	{
    		system("clear");
	   		std::cout << "LOGGED AS " << row[0] << std::endl;
	   		system("date");
	   		while(1)
	   		{
	   			char *command = new char[80];
    			std::cin >> command;
    			if(!strcmp((const char *)command,"exit"))
    				break;
    			else std::cout << "no\n";
	    	}
      		break;
    	}
    }
    std::cout << "goodbye!\n";
	mysql_free_result(result);
    mysql_close(connection);
    return 0;
}
