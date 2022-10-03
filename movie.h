#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"
#include <iostream>

class Movie: public Product {
  public: 
    Movie(const std::string category, 
      const std::string name, 
      double price, 
      int qty, 
      std::string genre,
      std::string rating
      );
    std::string genre_;
    std::string rating_;
    std::set<std::string> keywords() const;
    std::string displayString() const;
};

#endif