#pragma once
//tạo đối tượng sách
//Xử lý CRUD, search

struct Book
{
	int id;
	char title[100];
	char author[100];
	int year;
	int quantity;
};

typedef struct Book Book;

void showBook();
void addBook();
void editBook();
void deleteBook();
void searchBook();

