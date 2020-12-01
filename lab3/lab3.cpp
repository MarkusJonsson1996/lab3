#include <iostream>
#include "lab3lib.h"

#define EMPLOYEES 5

using namespace std;

int main() {
	unsigned int task = 0;

	int employ[EMPLOYEES] = { 0 };
	
	int swapSort[3] = {};
	int* a = &swapSort[0];
	int* b = &swapSort[1];
	int* c = &swapSort[2];
	bool ascDec = true;

	char replChars[50];
	char replOld;
	char replNew;

	vector<string> database;

	bool run = true;
	string uIn;

	while (run) {
		cout << "Enter task to run (1-6), 0 to exit: ";
		scanf_s("%i", &task);

		switch (task)
		{
		case 0:
			run = false;

			break;

		case 1:
			cout << "Enter a string: ";
			cin >> uIn;

			cout << "Word is " << str_len(uIn.c_str()) << "characters long" << endl;

			break;

		case 2:
			cout << "Enter salary for "<< EMPLOYEES <<" employees" << endl;

			for (int i = 0; i < EMPLOYEES; i++) cin >> employ[i];

			cout << "Avarage salary is: " << avarage_salary(employ, EMPLOYEES) << endl;
			
			break;

		case 3:
			cout << "Enter 3 numbers to sort" << endl;
			for (int i = 0; i < 3; i++) cin >> swapSort[i];

			cout << "Sort in Ascending or Descending order (1/0)?: ";
			cin >> ascDec;

			swap_sort(&swapSort[0], &swapSort[1], &swapSort[2], ascDec);
			for (int i = 0; i < 3; i++) cout << swapSort[i] << " ";

			break;

		case 4:
			cout << "Enter 3 numbers to sort" << endl;
			for (int i = 0; i < 3; i++) cin >> swapSort[i];

			cout << "Sort in Ascending or Descending order (1/0)?: ";
			cin >> ascDec;

			swap_sort(&a, &b, &c, ascDec);
			for (int i = 0; i < 3; i++) cout << swapSort[i] << " ";
			
			break;

		case 5:
			cout << "Enter a string be manipulated (max 49 characters): ";
			cin >> uIn;
			strcpy_s(replChars, uIn.c_str());


			cout << "What characters should be replaced?: ";
			cin >> replOld;

			cout << "What should replace it?: ";
			cin >> replNew;

			replace_chars(replChars, replOld, replNew);

			cout << "The new word is: " << replChars;

			break;

		case 6:
			vector_database_editor(&database);

			break;

		default:
			cout << "Sorry, unknown command" << endl;

			break;
		}
		
		cout << endl;
	}

	return 0;
}