#include "util.h"
#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty,
  const std::string author, const std::string isbn) :
    Product(category, name, price, qty)
{
  author_ = author;
  isbn_ = isbn;
}
std::set<std::string> Book::keywords() const {
  std::set<std::string> set_keywords;

  std::set<std::string> set_keywords_author;
  set_keywords_author = parseStringToWords(author_);
  
  std::set<std::string> set_keywords_name;
  set_keywords_name = parseStringToWords(name_);

  set_keywords = setUnion(set_keywords_author, set_keywords_name);
  set_keywords.insert(isbn_);

  return set_keywords;
}
std::string Book::displayString() const {
  std::string display = "";
  display += name_ + "\n";
  display += "Author: " + author_ + " ISBN: " + isbn_;
  display += std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return display;
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" 
    << qty_ << isbn_ << author_ << std::endl;
}