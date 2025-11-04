// Implements the Inventory class for managing Books and SpellBooks.

#include "Inventory.h"
#include "SpellBook.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib> // for exit()

// Constructor calls readData to populate the inventory from a file
Inventory::Inventory(std::string fname) { 
    readData(fname); 
}

// Destructor
Inventory::~Inventory() = default;

// Reads book data from file and fills the vector with Book/SpellBook objects
void Inventory::readData(const std::string& fname) {
    std::ifstream fin(fname);
    if (!fin) {
        std::cout << "Error opening file " << fname << "\n";
        exit(1);
    }

    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty()) continue; // skip blank lines

        char type = line[0]; // 'b' or 's'
        if (type == 'b') {
            add(std::make_unique<Book>(line));
        } else if (type == 's') {
            add(std::make_unique<SpellBook>(line));
        }
    }
}

// Adds into the vector
void Inventory::add(std::unique_ptr<Book> book) { 
    vec.push_back(std::move(book)); 
}

// Returns true if inventory has no books
bool Inventory::isEmpty() const { 
    return vec.empty(); 
}

// Returns a string with all books joined by newlines
std::string Inventory::str() const {
    std::ostringstream out;
    for (size_t i = 0; i < vec.size(); i++) {
        out << vec[i]->str();
        if (i + 1 < vec.size()) out << "\n";
    }
    return out.str();
}

// Computes the sum of all real book prices
double Inventory::getRealTotal() const {
    double sum = 0.0;
    for (const auto& b : vec) {
        sum += b->getRealPrice();
    }
    return sum;
}

// Searches for books containing substring 'bname' in their title
void Inventory::searchBook(const std::string& bname) const {
    bool found = false;
    for (const auto& b : vec) {
        if (b->getName().find(bname) != std::string::npos) {
            std::cout << b->str() << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No result found\n";
    }
}

// Interactive menu loop for user commands
void Inventory::menu() {
    if (isEmpty()) return;

    std::string input;
    while (true) {
        std::cout << "Enter option search BOOKNAME/all/total/done\n";
        if (!std::getline(std::cin, input)) break;

        if (input.rfind("search ", 0) == 0) {
            // user typed "search <name>"
            std::string key = input.substr(7);
            std::cout << "Searched book name: " << key << "\n";
            searchBook(key);
        } else if (input == "all") {
            // print all books
            std::cout << "The book/s in the inventory is/are\n" << str() << "\n";
        } else if (input == "total") {
            // print total price of all books
            std::cout << std::fixed << std::setprecision(6)
                      << "Total price of the books is " << getRealTotal() << "\n";
        } else if (input == "done") {
            break;
        } else {
            std::cout << "Invalid option\n";
        }
    }
}
