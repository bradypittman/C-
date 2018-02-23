#include <fstream>

#include "../includes_usr/fileIO.h"

using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */

int loadBooks(std::vector<book> &books, const char* filename)
{
	ifstream fin(filename);

	if (!fin) {
		return COULD_NOT_OPEN_FILE;
	}
	if (fin.peek() == std::ifstream::traits_type::eof()) {
		return NO_BOOKS_IN_LIBRARY;
	}

	books.clear();

	while (!fin.eof()) {
		book b;
		fin >> b.book_id;
		if (b.book_id < 0) {
			break;
		}
		fin.get();
		getline(fin, b.title, ',');
		getline(fin, b.author, ',');
		int st;
		fin >> st;
		b.state = (book_checkout_state) st;
		fin.get();
		fin >> b.loaned_to_patron_id;
		fin.get();
		books.push_back(b);
	}
	fin.close();

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{

	if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}
	ofstream fout(filename);
	if (!fout) {
		return COULD_NOT_OPEN_FILE;
	}

	for (int i = 0; i < books.size(); i++) {
		book b = books[i];
		fout << b.book_id << ","
				<< b.title << ","
				<< b.author << ","
				<< b.state << ","
				<< b.loaned_to_patron_id << "\n";
	}
	fout.close();

	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream fin(filename);

	if (!fin) {
		return COULD_NOT_OPEN_FILE;
	}
	if (fin.peek() == std::ifstream::traits_type::eof()) {
		return NO_PATRONS_IN_LIBRARY;
	}

	patrons.clear();

	while (!fin.eof()) {
		patron p;
		fin >> p.patron_id;
		if (p.patron_id < 0) {
			break;
		}
		fin.get();
		getline(fin, p.name, ',');
		fin >> p.number_books_checked_out;
		fin.get();
		patrons.push_back(p);
	}
	fin.close();

	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	if (patrons.size() == 0) {
		return NO_PATRONS_IN_LIBRARY;
	}
	ofstream fout(filename);
	if (!fout) {
		return COULD_NOT_OPEN_FILE;
	}

	for (int i = 0; i < patrons.size(); i++) {
		patron p = patrons[i];
		fout << p.patron_id << ","
			 << p.name << ","
			 << p.number_books_checked_out << "\n";
	}
	fout.close();

	return SUCCESS;
}
