// Implements the SpellBook class, derived from Book.

#include "SpellBook.h"
#include <sstream>
#include <iomanip>
#include <utility>

// Default constructor
SpellBook::SpellBook() : Book("", 100.0), canTalk(true) {}

// Parameterized constructor
SpellBook::SpellBook(std::string gname, double gprice, bool cantalkparam)
    : Book(std::move(gname), gprice), canTalk(cantalkparam) {}

// Constructor that parses a line of text
SpellBook::SpellBook(std::string line) : Book("", 100.0), canTalk(true) {
    std::istringstream iss(line);
    char type;
    std::string n;
    double p;
    int talkInt;
    iss >> type >> n >> p >> talkInt;

    setName(n);
    setPrice(p);
    canTalk = (talkInt != 0); // convert int to bool
}

// Destructor: empty
SpellBook::~SpellBook() = default;

// Returns whether this SpellBook can talk
bool SpellBook::getCanTalk() const { 
    return canTalk; 
}

// Returns the price of the SpellBook
double SpellBook::getRealPrice() const {
    return getCanTalk() ? getPrice() * 1.1 : getPrice();
}

// Returns a formatted string representation of the SpellBook
std::string SpellBook::str() const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(6);

    if (canTalk) {
        out << "Speaking Book:" << getName() 
            << " price:" << getRealPrice();
    } else {
        out << "Spell Book:" << getName() 
            << " price:" << getRealPrice();
    }
    return out.str();
}
