// Restaurant Managment System
// Code by : Ali Khosronejad
// Web : www.Khosronejad.ir

#include <iostream>
#include <fstream>
#include <string>

#define Table_Reservation_Array_Size 61
#define Food_Reservation_Array_Size 61
#define Food_Name_Array_Size 31
#define Customer_Name_Array_Size 31
#define Customer_Family_Name_Array_Size 31
#define Customer_Address_Array_Size 61
#define Table_Price 50 // ($)
#define NULL 0

using namespace std;

class Food
{
	char Food_Name[Food_Name_Array_Size];
	int Food_Price;
	int Food_Code;
	int Food_Supply;
public:
	friend class Customer;
	friend class Reservation;
	void Get_Food_Information();
	void Edit_Food_Information();
	void Delete_Food_Information();
};

class Customer
{
	char Customer_Name[Customer_Name_Array_Size];
	char Customer_Family_Name[Customer_Family_Name_Array_Size];
	unsigned long int Customer_Phone_Number;
	char Customer_Address[Customer_Address_Array_Size];
	long int Customer_Account_Balance;
	int Customer_Code;
public:
	friend class Reservation;
	friend class Food;
	void Get_Customer_Information();
	void Edit_Customer_Information();
	void Edit_Customer_Account_Balance();
	void Delete_Customer_Information();
};

class Reservation
{
	int Table_Reservation[Table_Reservation_Array_Size];
	int Food_Reservation[Food_Reservation_Array_Size];
	int Table_Reservation_Code;
	int Food_Reservation_Code;
	int Food_Number_Reservation_Code;
	int Table_Number_Reservation_Code;
	int Customer_Code;
	int Food_Price;
public:
	friend class Food;
	friend class Customer;
	void Table_Reservation_Function();
	void Food_Reservation_Function();
};

void Food::Get_Food_Information()
{
	ofstream Food_Information_File;
	Food_Information_File.open("Food Information.dat");
	cout << "Enter Food Name : ";
	cin >> Food_Name;
	cout << "Enter Food Price : ";
	cin >> Food_Price;
	cout << "Enter Food Code : ";
	cin >> Food_Code;
	cout << "Enter Food Supply : ";
	cin >> Food_Supply;
	// Get Food Information Write to File Section
	Food_Information_File << Food_Code << '\t' << Food_Name << '\t' << Food_Supply << '\t' << Food_Price << " ($)" << endl;
	Food_Information_File.close();
}

void Food::Edit_Food_Information()
{
	ofstream Food_Information_File;
	Food_Information_File.open("Food Information.dat");
	cout << "Enter Food Code to Edit : ";
	cin >> Food_Code;
	cout << "Enter New Information for Food with " << Food_Code << " Code : " << endl;
	cout << "Enter New Food Name : ";
	cin >> Food_Name;
	cout << "Enter New Food Price : ";
	cin >> Food_Price;
	cout << "Enter New Food Supply : ";
	cin >> Food_Supply;
	// Edit Food Information Write to File Section
	Food_Information_File << Food_Code << '\t' << Food_Name << '\t' << Food_Supply << '\t' << Food_Price << " ($)" << endl;
	Food_Information_File.close();
}

void Food::Delete_Food_Information()
{
	ofstream Food_Information_File;
	Food_Information_File.open("Food Information.dat");
	cout << "Enter Food Code to Edit : ";
	cin >> Food_Code;
	Food_Name[Food_Name_Array_Size] = NULL;
	Food_Price = NULL;
	Food_Supply = NULL;
	// Delete Food Information in File Section
	Food_Information_File << Food_Code << Food_Name << Food_Supply << Food_Price << endl;
	Food_Information_File.close();
}

void Customer::Get_Customer_Information()
{
	ofstream Customer_Information_File;
	Customer_Information_File.open("Customer Information.dat");
	cout << "Enter Your Name : ";
	cin >> Customer_Name;
	cout << "Enter Your Family Name : ";
	cin >> Customer_Family_Name;
	cout << "Enter Customer Code : ";
	cin >> Customer_Code;
	cout << "Enter Customer Phone Number : ";
	cin >> Customer_Phone_Number;
	cin.ignore();
	cout << "Enter Customer Address : ";
	cin >> Customer_Address;
	cout << "Enter Customer Account Balance : ";
	cin >> Customer_Account_Balance;
	// Get Customer Information Write to File Section
	Customer_Information_File << Customer_Code << '\t' << Customer_Name << ' ' << Customer_Family_Name << '\t' << Customer_Phone_Number << '\t' << Customer_Address << '\t' << Customer_Account_Balance << "($)" << endl;
	Customer_Information_File.close();
}

void Customer::Edit_Customer_Information()
{
	ofstream Customer_Information_File;
	Customer_Information_File.open("Customer Information.dat");
	cout << "Enter Customer Code to Edit : ";
	cin >> Customer_Code;
	cout << "Enter New Information for Customer with " << Customer_Code << " Code : "<<endl;
	cout << "Enter Name : ";
	cin >> Customer_Name;
	cout << "Enter Family Name : ";
	cin >> Customer_Family_Name;
	cout << "Enter Customer Phone Number : ";
	cin >> Customer_Phone_Number;
	cin.ignore();
	cout << "Enter Customer Address : ";
	cin >> Customer_Address;
	cout << "Enter Customer Account Balance : ";
	cin >> Customer_Account_Balance;
	// Edit Customer Information Write to File Section
	Customer_Information_File << Customer_Code << '\t' << Customer_Name << ' ' << Customer_Family_Name << '\t' << Customer_Phone_Number << '\t' << Customer_Address << '\t' << Customer_Account_Balance << "($)" << endl;
	Customer_Information_File.close();
}

void Customer::Edit_Customer_Account_Balance()
{
	ofstream Customer_Account_Balance_File;
	Customer_Account_Balance_File.open("Customer Account Balance.dat");
	cout << "Enter Customer Code to Change Account Balance : ";
	cin >> Customer_Code;
	cout << "Enter new Account Balance : ";
	cin >> Customer_Account_Balance;
	// Edit Customer Account Balance Write to File Section
	Customer_Account_Balance_File << Customer_Code << '\t' << Customer_Account_Balance << "($)" << endl;
	Customer_Account_Balance_File.close();
}

void Customer::Delete_Customer_Information()
{
	ofstream Customer_Information_File;
	Customer_Information_File.open("Customer Information.dat");
	cout << "Enter Customer Code to Delete : ";
	cin >> Customer_Code;
	Customer_Name[Customer_Name_Array_Size] = NULL;
	Customer_Family_Name[Customer_Family_Name_Array_Size] = NULL;
	Customer_Address[Customer_Address_Array_Size] = NULL;
	Customer_Phone_Number = NULL;
	Customer_Account_Balance = NULL;
	// Delete Customer Information in File Section
	Customer_Information_File << Customer_Code << Customer_Name << Customer_Family_Name << Customer_Phone_Number << Customer_Address << Customer_Account_Balance << endl;
	Customer_Information_File.close();
}

void Reservation::Table_Reservation_Function()
{
	ofstream Table_Reservation_File;
	Table_Reservation_File.open("Table Reservation.dat");
	cout << "Enter Your Account Code : ";
	cin >> Customer_Code;
	cout << "Enter a Table Code to Reserve : ";
	cin >> Table_Reservation_Code;
	cout << "Enter Number of Table you want to Reserve : ";
	cin >> Table_Number_Reservation_Code;
	// Table Reservation Factor Console Section
	cout << "User " << Customer_Code << "Resrve Table " <<Table_Reservation_Code<<endl;
	cout << "Factor = " << Table_Price << "($) * " << Table_Number_Reservation_Code << " : " << Table_Price*Table_Number_Reservation_Code << "($)" << endl;
	// Table Reservation Write to File Section
	Table_Reservation_File << "User " << Customer_Code << "Resrve Table " << Table_Reservation_Code << endl;
	Table_Reservation_File << "Factor = " << Table_Price << "($) * " << Table_Number_Reservation_Code << " : " << Table_Price*Table_Number_Reservation_Code << "($)" << endl;
	Table_Reservation_File.close();
}

void Reservation::Food_Reservation_Function()
{
	ofstream Food_Reservation_File;
	Food_Reservation_File.open("Food Reservation.dat");
	cout << "Enter Your Account Code : ";
	cin >> Customer_Code;
	cout << "Enter a Food Code to Resrve : ";
	cin >> Food_Reservation_Code;
	cout << "Enter Number of Food you want : ";
	cin>> Food_Number_Reservation_Code;
	cout << "Enter Food Price ($) : ";
	cin >> Food_Price;
	// Food Reservation Factor Console Section
	cout << "User "<< Customer_Code<<" Reserved Food "<< Food_Reservation_Code<<endl;
	cout << "Factor = " << Food_Price << "($) * " << Food_Number_Reservation_Code << " : " << Food_Price*Food_Number_Reservation_Code<<"($)"<<endl;
	// Food Reservation Write to File Section
	Food_Reservation_File << "User " << Customer_Code << " Reserved Food " << Food_Reservation_Code << endl;
	Food_Reservation_File << "Factor = " << Food_Price << "($) * " << Food_Number_Reservation_Code << " : " << Food_Price*Food_Number_Reservation_Code << "($)" << endl;
	Food_Reservation_File.close();
}

int main()
{
	int x;
	do
	{
		cout << "\n\t **** Restaurant Managment System ****\n" << endl;

		cout << "[1] - Food Operations :" << endl;
		cout << "\t11- Add New Food" << endl;
		cout << "\t12- Edit Food" << endl;
		cout << "\t13- Delete Food" << endl;

		cout << "[2] - Customer Operations :" << endl;
		cout << "\t21- Add New Customer" << endl;
		cout << "\t22- Edit Customer Information" << endl;
		cout << "\t23- Edit Customer Account Balance" << endl;
		cout << "\t23- Delete Customer" << endl;

		cout << "[3] - Reservation System :" << endl;
		cout << "\t31- Reserve Food" << endl;
		cout << "\t32- Reserve Table" << endl;

		cout << "0 - Exit\n" << endl;
		cout << "Enter a Number : ";
		cin >> x;

		switch (x)
		{
		
		case 1:
			cout << "Wrong Input :(";
			break;
		case 11:
			Food FAdd;
			FAdd.Get_Food_Information();
			cout << "New Food Added Successfully :)" << endl;
			break;
		case 12:
			Food FEdit;
			FEdit.Edit_Food_Information();
			cout << "Food Information Updated Successfully :)" << endl;
			break;
		case 13:
			Food FDel;
			FDel.Delete_Food_Information();
			cout << "Food Deleted Successfully :)" << endl;
			break;

		case 2:
			cout << "Wrong Input :(";
			break;
		case 21:
			Customer CAdd;
			CAdd.Get_Customer_Information();
			cout << "New Customer Added Successfully :)" << endl;
			break;
		case 22:
			Customer CEditInfo;
			CEditInfo.Edit_Customer_Information();
			cout << "Customer Information Updated Successfully :)" << endl;
			break;
		case 23:
			Customer CEditBal;
			CEditBal.Edit_Customer_Account_Balance();
			cout << "Customer Account Balance Updated Successfully :)" << endl;
			break;
		case 24:
			Customer CDel;
			CDel.Delete_Customer_Information();
			cout << "Customer Deleted Successfully :)" << endl;
			break;

		case 3:
			cout << "Wrong Input :(";
			break;
		case 31:
			Reservation RF;
			RF.Food_Reservation_Function();
			cout << "Food Reserved Successfully :)" << endl;
			break;
		case 32:
			Reservation RT;
			RT.Table_Reservation_Function();
			cout << "Table Reserved Successfully :)" << endl;
			break;

		case 0:
			return 0;
		default:
			break;
		}

	} while (true);
	return 0;
}