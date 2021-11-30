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

void printWineHeader()
{
	cout << "    " << setw(42) << left << "Wine Name"
				   << setw(9) << "Vintage"
				   << setw(9) << "Rating"
				   << setw(8) << "Price"
				   << setw(3) << "  " << "Type" << endl;
				   
	cout << "    " << setw(42) << left << "---------"
				   << setw(9) << "-------"
				   << setw(9) << "------"
				   << setw(8) << "-----"
				   << setw(3) << " " << "-----" << endl;
}

void printWineInfo(MYSQL_RES *res)
{
	MYSQL_ROW row;
	int count = 0;
	int score = 0;
	int redWine = 0;
	int redScore = 0;
	
	int whiteWine = 0;
	int whiteScore = 0;
	
	double price = 0;
	double redPrice = 0;
	double whitePrice = 0;
	
	printWineHeader();
	
	while ((row = mysql_fetch_row(res)) !=NULL)
	{
		count++;
		score += stod(row[2]);
		price += stod(row[3]);
		string type = row[4];
		if (type == "Red" || type == "red")
		{
			redWine++;
			redScore += stod(row[2]);
			redPrice += stod(row[3]);
		}
		if (type == "White" || type == "white")
		{
			whiteWine++;
			whiteScore += stod(row[2]);
			whitePrice += stod(row[3]);
		}
		
		cout << "    " << setw(42) << left << row [0] << "  "
					   << setw(8) << row[1] << "   "
					   << setw(6) << row[2] << "   "
					   << setw(8) << row[3] << "   "
					   << setw(8) << row[4] << "   "
					   << endl;
	}
	
	cout << "\n\n" << endl;
	
	cout << "Number of wines:       " << setw(4) << left << count
		 << "Average Price:         $" << fixed << setprecision(2) << price/count
		 << "Average Score/Rating:      " << score/count << endl;
		
	if (redWine != 0 && whiteWine == 0)
	{
		cout << "Number of Red Wines: " << setw(4) << left << redWine 
			 << "    Average Red Wines Price: $" << fixed << setprecision(2) << redPrice/redWine 
			 << "    Average Red wine score/rating: " << redScore/redWine << endl;
		cout << "Number of White Wines: " << setw(4) << left << "0"
			 << "    Average White Wines Price: $" << fixed << setprecision(2) << "0"
			 << "    Average White Wines score/rating: " << "0" << endl;
	}
	else if (whiteWine != 0 && redWine == 0)
	{
		cout << "Number of Red Wines: " << setw(4) << left << "0" 
			 << "    Average Red Wines Price: $" << fixed << setprecision(2) << "0" 
			 << "    Average Red wine score/rating: " << "0" << endl;
		cout << "Number of White Wines: " << setw(4) << left << whiteWine
			 << "    Average White Wines Price: $" << fixed << setprecision(2) << whitePrice/whiteWine
			 << "    Average White Wines score/rating: " << whiteScore/whiteWine << endl;
	}
	else if (whiteWine != 0 && redWine != 0)
	{
		cout << "Number of Red Wines: " << setw(4) << left << redWine 
			 << "    Average Red Wines Price: $" << fixed << setprecision(2) << redPrice/redWine 
			 << "    Average Red wine score/rating: " << redScore/redWine << endl;
		cout << "Number of White Wines: " << setw(4) << left << whiteWine
			 << "    Average White Wines Price: $" << fixed << setprecision(2) << whitePrice/whiteWine
			 << "    Average White Wines score/rating: " << whiteScore/whiteWine << endl;
	}
	
	cout << "\n\n\n";
}


string scoreBetween()
{
	int x, y = 0;
	cout << "Enter the first score you want to use between 0-100: ";
	cin >> x;
	
	while (cin.fail() || x < 1 || x > 100)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		if (x < 1 || x > 100)
			{cout << "Error: Please enter a score between 1-100" << endl;}
		else
			{cout << "Error: Please enter a valid option" << endl;}
		cin >> x;
	}
	
	cout << "Enter the second score you want to use between 0-100: ";
	cin >> y;
	
	while (cin.fail() || y < 1 || y > 100)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		if (y < 1 || y > 100)
			{cout << "Error: Please enter a score between 1-100" << endl;}
		else
			{cout << "Error: Please enter a valid option" << endl;}
		cin >> y;
	}
	
	string scoreBetweenStatement;
	if (x > y)
		{scoreBetweenStatement = "SELECT * FROM wineInfo WHERE rating BETWEEN "+ to_string(x) +" AND "+ to_string(y) + " ORDER BY rating";}
	else
		{scoreBetweenStatement = "SELECT * FROM wineInfo WHERE rating BETWEEN "+ to_string(y) +" AND "+ to_string(x) + " ORDER BY rating";}
	
	return scoreBetweenStatement;
}

string priceBetween()
{
	
	string option2 = "SELECT * FROM wineInfo LIMIT 10";
	
	return option2;
}
