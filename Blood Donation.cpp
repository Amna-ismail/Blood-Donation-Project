#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct Donor {
	string name;
	string blood_group;
	int age;
	float weight;
	string gender;
	int phone_number;
	string email;
	string dep;
};
struct Donor donor[200];

void printDonorDetails(Donor& donor);
void saveToFile(fstream& file, Donor donorsList[200], int numOfDonors);

int main()
{
	int numOfDonor=0;
	string search;
	int menuItem;


start:
	cout << "=======================================" << endl;
	cout << "|----BLOOD GROUP MANAGEMENT SYSTEM----| " << endl;
	cout << "=======================================" << endl;
	cout<< endl;
	cout << "To add a new data,		 (1)" << endl;
	cout << "To view list of donors,		 (2)" << endl;
	cout << "To search donor,		(3)" << endl;
	cout << "To exit,			(4) \n" << endl;

	cout << "enter a number ";
	cin >> menuItem;
	switch (menuItem)
	{
	case 1:
		cout << "number of donors ";
		cin >> numOfDonor;
		for (int i = 0; i < numOfDonor; i++)
		{
			cout << "enter name	";
			cin >> donor[i].name;
			cout << "enter age	";
			cin >> donor[i].age;
			cout << "enter weight	";
			cin >> donor[i].weight;
			cout << "enter blood group	";
			cin >> donor[i].blood_group;
			cout << "enter gender	";
			cin >> donor[i].gender;
			cout << "enter department	";
			cin >> donor[i].dep;
			cout << "enter phone number	";
			cin >> donor[i].phone_number;
			cout << "Email of donor ";
			cin >> donor[i].email;
			cout << endl;
			if (i != numOfDonor - 1)
			{
				cout << "-----next donor------" << endl;
			}
		}
		break;
	case 2:
	{
		cout << endl;
		cout << "---LIST OF DONORS---" << endl;
		for (int i = 0; i < numOfDonor; i++)
		{
			cout << "----" << i+1 << " donor ----" << endl;
			printDonorDetails(donor[i]);
		}

		break;
	}

	case 3:
	{
		cout << "Search with Name/Department/Blood Group" << endl;
		cin >> search;
		for (int i = 0; i <= numOfDonor; i++)
		{
			if (donor[i].name == search || donor[i].dep == search || donor[i].blood_group == search)
			{
				printDonorDetails(donor[i]);
			}
		}
		cout << endl << endl << endl;
		break;
	}
	case 4:
	{
		return 0;
	}
	}
	string userAnswer;
	cout << "Do you want to save this information? Enter YES for saving NO to exit" << endl;
	cin >> userAnswer;
	cout << endl;
	if (userAnswer == "YES")
	{
		fstream file;
		file.open("E:blood donors.txt", ios::app);
		saveToFile(file, donor, numOfDonor);
		file.close();
		cout << "Information saved to file." << endl;
	}
	else
	{
		cout << endl;

	}
	goto start;
	system("pause");
	return 0;
}

void saveToFile(fstream& file, Donor donorsList[200], int numOfDonors) {
	for (int i = 0; i < numOfDonors; i++)
	{
		file << "------------Donor--------" << endl;
		file << "Name " << donorsList[i].name << endl;
		file << "Age  " << donorsList[i].age << endl;
		file << "Weight " << donorsList[i].weight << endl;
		file << "Gender " << donorsList[i].gender << endl;
		file << "Blood group  " << donorsList[i].blood_group << endl;
		file << "Department " << donorsList[i].dep << endl;
		file << "Email " << donorsList[i].email << endl;
		file << "Phone number " << donorsList[i].phone_number << endl;
	}
}

void printDonorDetails(Donor& donor)
{
	cout << " name of the donor	";
	cout << donor.name << endl;
	cout << " age of the donor	";
	cout << donor.age << endl;
	cout << " weight of the donor	";
	cout << donor.weight << endl;
	cout << " blood group of the donor	";
	cout << donor.blood_group << endl;
	cout << " gender of the donor	";
	cout << donor.gender << endl;
	cout << " department of the donor	";
	cout << donor.dep << endl;
	cout << "-CONTACT INFORMATION-" << endl;
	cout << " phone number of the donor	";
	cout << donor.phone_number << endl;
	cout << "Email of donor " << endl;
	cout << donor.email << endl;
} 				 
