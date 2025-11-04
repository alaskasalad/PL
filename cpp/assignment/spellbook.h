#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include "Book.h"

class SpellBook : public Book {
private:
    bool canTalk;

public:
    SpellBook();
    SpellBook(std::string gname, double gprice, bool cantalkparam);
    explicit SpellBook(std::string line);

    ~SpellBook() override;

    bool getCanTalk() const;
    double getRealPrice() const override;
    std::string str() const override;
};

#endif
