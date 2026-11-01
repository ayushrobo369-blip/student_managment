
#include <iostream>
#include <string>
#include <fstream>

class temp {

    std::string id, name, author, search;
    std::fstream file;

public:

    void showall_book();
    void extract_book();
    void add_books();

} obj;


int main() {

    char choise;

    do {

        std::cout << "\n--------------------------------" << std::endl;
        std::cout << "------Library Management System------" << std::endl;
        std::cout << "--------------------------------" << std::endl;

        std::cout << "\nContent---" << std::endl;
        std::cout << "1. Show all Books" << std::endl;
        std::cout << "2. Extract Books" << std::endl;
        std::cout << "3. Add Books (ADMIN)" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cout << "\nEnter your choice: ";
        std::cin >> choise;
        std::cin.ignore(1000, '\n');

        switch (choise) {

            case '1':
                obj.showall_book();
                break;

            case '2':
                obj.extract_book();
                break;

            case '3':
                obj.add_books();
                break;

            case '4':
                std::cout << "Exiting program..." << std::endl;
                break;

            default:
                std::cout << "Invalid data.....!" << std::endl;
                break;
        }

    } while (choise != '4');

    return 0;
}


// ADD BOOKS

void temp::add_books() {

    std::cout << "\n--------------------" << std::endl;
    std::cout << "Adding books -" << std::endl;

    std::cout << "Book Name - ";
    std::getline(std::cin, name);

    std::cout << "Book ID - ";
    std::getline(std::cin, id);

    std::cout << "Book Author - ";
    std::getline(std::cin, author);

    file.open("fill.txt", std::ios::out | std::ios::app);

    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    file << name << "*" << id << "*" << author << std::endl;

    file.close();

    std::cout << "\nBook added successfully!" << std::endl;
}


// SHOW ALL BOOKS

void temp::showall_book() {

    std::cout << "\nShowing all books" << std::endl;

    file.open("fill.txt", std::ios::in);

    if (!file) {
        std::cout << "Oops! No data found." << std::endl;
        return;
    }

    std::cout << "\nBook ID\t\tBook Name\t\tAuthor Name\n";
    std::cout << "------------------------------------------------\n";

    while (
        std::getline(file, name, '*') &&
        std::getline(file, id, '*') &&
        std::getline(file, author, '\n')
    ) {

        std::cout << id << "\t\t"
                  << name << "\t\t"
                  << author << std::endl;
    }

    file.close();
}


// EXTRACT / SEARCH BOOK

void temp::extract_book() {

    showall_book();

    std::cout << "\nEnter Book ID: ";
    std::getline(std::cin, search);

    file.open("fill.txt", std::ios::in);

    if (!file) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    bool found = false;

    while (
        std::getline(file, name, '*') &&
        std::getline(file, id, '*') &&
        std::getline(file, author, '\n')
    ) {

        if (search == id) {

            std::cout << "\nBook Found Successfully!\n";

            std::cout << "Book Name: " << name << std::endl;
            std::cout << "Book ID: " << id << std::endl;
            std::cout << "Author: " << author << std::endl;

            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "\nBook not found!" << std::endl;
    }

    file.close();
}
