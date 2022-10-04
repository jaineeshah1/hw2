#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <iostream>

class Book: public Product {
  public: 
    Book(const std::string category, 
      const std::string name, 
      double price, 
      int qty, 
      std::string author,
      std::string isbn
      );
    std::string author_;
    std::string isbn_;
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
};

#endif