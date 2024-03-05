#include<iostream>
#include<string>
#include<map>

using namespace std;



int main() {
	map<string, string>Contacts;
	Contacts["Amaan"] = "0348-19025";
	Contacts["Arham"] = "0336-12425";
	Contacts["Siawish"] = "0317-52898";

	string searchName;
	cout << "Enter the name to Search Contact: ";
	getline(cin, searchName);
	
	if (!searchName.empty()) {
		searchName[0] = toupper(searchName[0]);
	}

	if (Contacts.find(searchName) != Contacts.end()) {
		cout << searchName << ": " << Contacts[searchName] << endl;
	}
	else
		cout << "Contact not found" << endl;
	return 0;
}