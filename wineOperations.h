#ifndef WINEOPERATIONS_H
#define WINEOPERATIONS_H

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <climits>
#include <string>

#include "dbconnect.h"
#include "wineOperations.h"

using namespace std;


void printWineHeader();
void printWineInfo(MYSQL_RES *res);

string scoreBetween();
string priceBetween();

#endif
