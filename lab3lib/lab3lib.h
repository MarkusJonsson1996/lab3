//lab3lib.h
#pragma once
#include <vector>

using namespace std;

void replace_chars(char* str, char old, char repl);
int avarage_salary(const int* sale, int n);
int str_len(const char* str);
int str_len(char* str);
void swap_sort(int* a, int* b, int* c, bool ascDes);
void swap_sort(int** a, int** b, int** c, bool ascDes);
void shrink_array(int* arr, int len);


bool load_vector_database(vector<string>* const database);
void save_vector_database(vector<string>* const database, string fileName);
bool print_vector_database(vector<string>* const database);
int search_vector_database(vector<string>* const database);
bool clear_vector_database(vector<string>* database);
int delete_vector_database(vector<string>* database, string name);
void insert_vector_database(vector<string>* database);
void vector_database_editor(vector<string>* database);