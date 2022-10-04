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
  display += name_ + "\n";
  display += "Genre: " + genre_ + " Rating: " + rating_;
  display += std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return display;
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" 
    << qty_ << genre_ << rating_ << std::endl;
}