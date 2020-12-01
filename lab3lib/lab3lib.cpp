//lab3lib.cpp
//compile with cl /c /EHsc lab3lib.cpp
//post-build command: lib lab3lib.obj

#include <iostream>
#include <fstream>
#include <vector>
#include "lab3lib.h"

using namespace std;

void replace_chars(char* str, char old, char repl) {

	int nxt = 0;

	while (*(str + nxt) != '\0') {

		if (*(str + nxt) == old) *(str + nxt) = repl;
		nxt++;

	}

}
void swap_sort(int* a, int* b, int* c, bool ascDes) {

	int sort[3] = { *a, *b, *c };
	int temp;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 3; j++) {

			if (sort[i] > sort[j] && ascDes) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}

			else if (sort[i] < sort[j] && !ascDes) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}

		}

	}

	*a = sort[0];
	*b = sort[1];
	*c = sort[2];

}
void swap_sort(int** a, int** b, int** c, bool ascDes) {
	return swap_sort(*a, *b, *c, ascDes);
}
void shrink_array(int* arr, int len) {

	int i = 0;
	int j = 0;

	while (i < len) {

		if (i == len - 1) {
			arr[j] = arr[i];
			j++;
			break;
		}

		arr[j] = arr[i] + arr[i + 1];


		j++;
		i += 2;

	}


	while (j < len) {
		arr[j] = 0;
		j++;
	}
}
int str_len(char* str) {
	int len = 0;

	while (*(str + len) != '\0') len++;

	return len;
}
int str_len(const char* str) {
	int len = 0;

	while (*(str + len) != '\0') len++;

	return len;
}
int avarage_salary(const int* sale, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) sum += *(sale + i);
	sum = sum / n;

	return sum;
}

bool load_vector_database(vector<string>* const database) {
	string fileName;
	string nxtName;
	bool sucess = true;

	cout << "Please enter name of the file: ";
	cin >> fileName;

	fileName = fileName + ".txt";

	ifstream loadFile(fileName.c_str());

	if (loadFile) clear_vector_database(database);
	else sucess = false;

	while (loadFile) {
		loadFile >> nxtName;
		if (loadFile.eof()) break;

		database->push_back(nxtName);
	}

	return sucess;
}
void save_vector_database(vector<string>* const database, string fileName) {
	
	fileName = fileName + ".txt";
	ofstream newFile(fileName.c_str(), ios::out);

	for (unsigned int i = 0; i < database->size(); i++) newFile << database->at(i) << endl;
}
bool print_vector_database(vector<string>* const database) {
	bool success = 1;

	if (!database->size()) success = 0;

	for (unsigned int i = 0; i < database->size(); i++)
		cout << i << ". " << database->at(i) << endl;

	return success;
}
int search_vector_database(vector<string>* const database) {
	string suIn;
	int errorMsg = 0;

	if (!database->size()) errorMsg = 2;

	cout << "Enter full/part of name to search in database: ";
	cin >> suIn;

	for (unsigned int i = 0; i < database->size(); i++) {
		if (database->at(i).find(suIn) != string::npos)
			cout << i << ". " << database->at(i) << endl;

		else
			cout << i << " -------" << endl;

	}

	return errorMsg;
}
bool clear_vector_database(vector<string>* database) {
	bool success = true;

	if (!database->size()) success = false;
	else
		database->clear();

	return success;
}
int delete_vector_database(vector<string>* database, string name) {
	int errorMsg = 0;

	if (!database->size()) errorMsg = 2;
	else {

		for (unsigned int i = 0; i < database->size(); i++) {

			if (database->at(i) == name) {
				database->erase(database->begin() + i);
				break;
			}
			else if (i == database->size() - 1) errorMsg = 1;
		}
	}
	return errorMsg;
}
void insert_vector_database(vector<string>* database) {
	string suIn;

	while (1) {
		cout << "Enter name to insert in database (exit w/ q/Q): ";
		cin >> suIn;

		if (suIn == "q" || suIn == "Q") break;
		database->push_back(suIn);
	}
}
void vector_database_editor(vector<string>* database) {
	bool run = true;
	int iuIn = 0;
	string uIn;

	cout << "VECTOR DATABASE EDITOR" << endl;

	while (run) {
		cout << "MENU:" << endl << endl;

		cout << " 1. initialise database" << endl;
		cout << " 2. insert" << endl;
		cout << " 3. search" << endl;
		cout << " 4. delete" << endl;
		cout << " 5. print" << endl;
		cout << " 6. save" << endl;
		cout << " 7. load" << endl;
		cout << " 8. quit" << endl << endl;

		cout << "Choose a command: ";
		scanf_s("%d", &iuIn);
		cout << endl;

		switch (iuIn) {

		case 1:
			if (!clear_vector_database(database)) cout << "Database was empty";
			break;

		case 2:
			insert_vector_database(database);
			break;

		case 3:
			search_vector_database(database);
			break;

		case 4:
			cout << "Enter the name to delete: ";
			cin >> uIn;

			delete_vector_database(database, uIn);
			break;

		case 5:
			if (!print_vector_database(database)) cout << "Database was empty";
			break;

		case 6:
			cout << "Please enter name of the file: ";
			cin >> uIn;

			save_vector_database(database, uIn);
			break;

		case 7:
			if (!load_vector_database(database)) cout << "Error reading file";
			break;
		case 8:
			run = false;
			break;

		default:
			cout << "Sorry, unknown command" << endl;

			break;
		}

		cout << endl;
	}
}