#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string name;
    double price;

public:
    Book();
    Book(std::string btitle, double gprice);
    explicit Book(std::string line);

    virtual ~Book();

    std::string getName() const;
    double getPrice() const;
    void setName(std::string);
    void setPrice(double);

    virtual double getRealPrice() const;
    virtual std::string str() const;
};

#endif
