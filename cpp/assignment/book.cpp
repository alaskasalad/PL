// Implements the Book class, which represents a literature book.

#include "Book.h"
#include <sstream>
#include <iomanip>

// Default constructor
Book::Book() : name(""), price(100.0) {}

// Parameterized constructor
Book::Book(std::string btitle, double gprice) 
    : name(std::move(btitle)), price(gprice) {}

// Constructor that parses a line of text discards the 'b', then extracts the name and price
Book::Book(std::string line) : name(""), price(100.0) {
    std::istringstream iss(line);
    char type;
    iss >> type >> name >> price;
}

// Destructor: empty
Book::~Book() = default;

// Getters and Setters
std::string Book::getName() const { return name; }
double Book::getPrice() const { return price; }
void Book::setName(std::string n) { name = std::move(n); }
void Book::setPrice(double p) { price = p; }

// Returns the price of a literature book
double Book::getRealPrice() const { 
    return price * 0.8; 
}

// Returns a formatted string rep of the book
std::string Book::str() const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(6);
    out << "Literature Book:" << name 
        << " price:" << getRealPrice();
    return out.str();
}
