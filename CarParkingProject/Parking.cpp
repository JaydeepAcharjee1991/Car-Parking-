#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;

/* front end */
class Parking
{
public:
	int sum = 0;

	void display()
	{
	park:
		system("cls");
		int option;int count = 0;
		cout << "\n\t***** WELCOME TO PARKING LOT APP  *****\n";
		cout << "\n\n\t\tPress 1 for 2wheelers\n";
		cout << "\t\tPress 2 for light 4 wheelers\n";
		cout << "\t\tPress 3 for heavy 4 wheelers\n";
		cout << "\t\tPress 4 to show records\n";
		cout << "\t\tPress 5 to delete records\n";
		cout << "\n\t*****************************************\n";
		cin >> option;
		if (option == 5)
		{
			deleteRecord(option);
			_getch();
			goto park;
		}
		if (option == 4)
		{
			showRecord(option);
			_getch();
			goto park;
		}
		else
		{
			//vehicle(option);
			count++;
			if (count <= 5)
			{
				cout << "Please mind the foramt " << "Eg:- MH-01-0001" << endl;
				vehicle(option);
				_getch();
				goto park;
			}
			else
			{
				cout << "Sorry No space";
			}
		}


	}

	/* For parking fees */

	void vehicle(int option)
	{
		ofstream fout;
		fout.open("C:\\Users\\jaydeep\\Desktop\\c++file\\parking.dat", ios::app);
		string number;
		int fee;


		if (option == 1)
		{
			fee = 100;
			cout << "Enter the twoWheeler number\n";
			cin >> number;
			fout << "\n********************************************\n";
			fout << "Car Number" << "\t";
			cout << "Parking fee is 100" << endl;
			fout << "Parking fees" << "\t";
			fout << " Car type" << endl;
			fout << number << "\t";
			fout << fee << "  " << "\t\t";
			fout << "TwoWheeler" << endl;
			fout << "********************************************\n";
			cout << "Added to database" << endl;
			sum += 100;


		}
		if (option == 2)
		{
			fee = 200;
			cout << "Enter the Light 4 wheeler number\n";
			cin >> number;
			fout << "\n********************************************************\n";
			fout << "Car Number" << "\t";
			cout << "Parking fee is 200" << endl;
			fout << "Parking fees" << "\t";
			fout << " Car type" << endl;
			fout << number << "\t";
			fout << fee << "  " << "\t\t";
			fout << "Light FourWheeler" << endl;
			fout << "********************************************************\n";
			cout << "Added to database" << endl;
			sum += 200;

		}
		if (option == 3)
		{
			fee = 300;
			cout << "Enter the Heavy 4 wheeler number\n";
			cin >> number;
			fout << "\n***************************************************\n";
			fout << "Car Number" << "\t";
			cout << "Parking fee is 300" << endl;
			fout << "Parking fees" << "\t";
			fout << " Car type" << endl;
			fout << number << "\t";
			fout << fee << "  " << "\t\t";
			fout << "Heavy Four Wheeler" << endl;
			fout << "***************************************************\n";
			cout << "Added to database" << endl;
			sum += 300;

		}
		else if (option < 0 && option>3)
		{
			cout << "Invalid input" << endl;
		}

		fout.close();
		balance(sum);

	}
	void balance(int sum)
	{
		ofstream fout;
		fout.open("C:\\Users\\jaydeep\\Desktop\\c++file\\parking.dat", ios::app);
		fout << "Total money is: " << sum << endl;
	}

	void showRecord(int option)
	{
		ifstream fin;
		fin.open("C:\\Users\\jaydeep\\Desktop\\c++file\\parking.dat");
		if (option == 4)
		{
			string line;
			while (fin)
			{
				getline(fin, line);
				cout << line << endl;
			}
		}
	}
	void deleteRecord(int option)
	{
		if (option == 5)
		{
			remove("C:\\Users\\jaydeep\\Desktop\\c++file\\parking.dat");
		}
		cout << "Deleted";
	}
};


int main()
{

	Parking p;
	p.display();
	_getch();
}
