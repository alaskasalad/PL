#ifndef INVENTORY_H
#define INVENTORY_H

#include <memory>
#include <string>
#include <vector>
#include "Book.h"

class Inventory {
private:
    std::vector<std::unique_ptr<Book>> vec;

public:
    explicit Inventory(std::string fname);
    ~Inventory();

    void readData(const std::string& fname);
    void add(std::unique_ptr<Book> book);
    bool isEmpty() const;
    std::string str() const;
    double getRealTotal() const;
    void searchBook(const std::string& bname) const;
    void menu();
};

#endif
