#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include <iostream>

class Clothing: public Product {
  public: 
    Clothing(const std::string category, 
      const std::string name, 
      double price, 
      int qty, 
      std::string brand,
      std::string size
      );
    std::string brand_;
    std::string size_;
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
};

#endif