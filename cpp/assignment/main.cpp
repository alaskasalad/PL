/* Caitlin Box 52694
    Programming languages COP4020 
    Dr. Salih Safa Bacanli
    =======================
    Entry point for the Book and SpellBook Inventory System, handling user inputs
*/

#include <iostream>
#include <string>
#include "Inventory.h"

int main() {
    // Prompt user for the input file
    std::cout << "Enter filename\n";
    std::string fname;
    std::getline(std::cin, fname);

    // Create an Inventory object using the filename.
    Inventory inv(fname);

    // Launch the interactive menu for searching, listing, and totaling books.
    inv.menu();

    return 0;
}
