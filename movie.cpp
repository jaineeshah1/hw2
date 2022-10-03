#include "util.h"
#include "movie.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty,
  const std::string genre, const std::string rating) :
    Product(category, name, price, qty)
{
  genre_ = genre;
  rating_ = rating;
}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> set_keywords;
  set_keywords = parseStringToWords(name_);
  set_keywords.insert(genre_);

  return set_keywords;
}
std::string Movie::displayString() const {
  std::string display = "";
  display += "Movie name: " + name_;
  display += ", Genre: " + genre_;
  display += ", Rating: " + rating_;
  return display;
}