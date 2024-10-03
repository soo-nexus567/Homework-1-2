#include <algorithm>                                                  // max()
#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted(), ios::failbit
#include <iostream>                                                   // istream, ostream, ws()
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()
#include <vector>
#include <memory>
#include "GroceryItem.hpp"

int main() {
    /*
    Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.
    enclose string entries in quotes, separate fields with comas
    for example:  "00016000306707", "Betty Crocker", "Betty Crocker Double Chocolate Chunk Cookie Mix", 17.19
    Enter CTL-Z (Windows) or CTL-D (Linux) to quit
    */
    std::vector<std::unique_ptr<GroceryItem >> items;
    GroceryItem line;
    std::cout << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information.";
    std::cout << "enclose string entries in quotes, separate fields with comas";
    std::cout << "for example:  " << "00016000306707, " << "Betty Crocker" << ", Betty Crocker Double Chocolate Chunk Cookie Mix" << ", 17.19";
    std::cout << "Enter CTL-Z (Windows) or CTL-D (Linux) to quit \n";
    // Loop to read input until EOF
    while (std::cout << "Enter UPC, Product Brand, Product Name, and Price \n", std::cin >>line) {
        // Prompt for data
        if (std::cin.eof()) {
            break;  // End of file
        }
        
        // Create a new GroceryItem object and parse input
        // std::istringstream iss(line);
        // auto item = std::make_unique<GroceryItem>();
        // iss >> *item;
        
        // Store the pointer in the vector
        items.emplace_back(std::make_unique<GroceryItem>(std::move(line)));
        std::cout << "Item added to shopping cart: " << *items.back();
        std::cout << "\n\n";
    }

    // Write grocery items to standard output in reverse order
    std::cout << "\n";
    std::cout << "Here is an itemized list of the items in your shopping cart: " << std::endl;
    for (auto it = items.crbegin(); it != items.crend(); ++it) {
        std::cout << **it << "\n";
    }
    
    //   for (auto i = shoppingCart.crbegin(); i < shoppingCart.crend(); ++i) std::cout << **i << '\n';
    return 0;
}
