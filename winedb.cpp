/*

http://www.codingfriends.com/index.php/2010/02/17/mysql-connection-example/

To compile up this program you will need to link to the mysql libraries and headers that are used within the program, e.g. mysql.h at the top of the program. To gain access to these, there is a nice mysql_config (you may need to install it via your package manager system if you do not have it already).

Here are my outputs of what is required on the command line for the g++ compiler



g++ -I/usr/include/mysql winedb.cpp -o winedb -L/usr/lib/mysql -lmysqlclient


./windb "select * from wineInfo where price > 100"

*/

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "dbconnect.h"

using namespace std;
 

/*
 argv[1] - put sql command in argv[1], otherwise, just 
 use sql "show tables"
*/
int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		if(strcmp(argv[1],"-d")==0) {
			debug = true;
			cout << "*** Debug Mode ****\n";
		}
		if (debug) {
			cout << "Argc: " << argc << " Argv[0]: " << argv[0] << endl;
		}
	}
	
	MYSQL *conn; //Connect
	MYSQL RES *res; //Results
	struct connection_details mysqlID;
	mysqlID.server = (char *)"localhost";
	mysqlID.user = (char *)"cs116";
	mysqlID.password = (char *)"OhloneC$116";
	mysqlID.database = (char *)"mysql";
	
	conn = mysql connection setup(mysqlID);
	
	res = mysql_perform_query(conn, (char *)"use wine");
	
	int selection = 0;
	while (selection != 6)
	{
		//Printmefirst function
		
		//Print Menu
		cout << "Select an option for the wine database" << endl
			 << "\t1: Display wine between two scores" << endl
			 << "\t2: Display wine between two prices" << endl
			 << "\t3: Display top 10 wine" << endl
			 << "\t4: Insert a new wine" << endl
			 << "\t5: Update an existing wine price" << endl
			 << "\t6: Exit the program" << endl;
		cin >> selection;
		
		while (cin.fail() || selection < 1 || selection > 6)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error : Please enter a valid option" << endl;
			cin >> selection;
		}
		
		switch (selection)
		{
			case 1: 
			{
				string statement = scoreBetween(); //re-write this?
				
				res = mysql_perform_query(conn, (char *)statement.c str());
				
				printWineInfo(res);
				if (debug)
					cout << "SQL Statement used: " << statement << "\n\n";
				break;
			}
			case 2:
			{
				string statement = priceBetween();
				
				res = mysql_perform_query(conn, (char *)statement.c str());
				
				printWineInfo(res);
				if (debug)
					cout << "SQL Statement used: " << statement << "\n\n";
				break;
			}
			case 6:
			{
				break;
			}
			
		}
		
		return 0;
				
}
