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
  display += "Book name: " + name_;
  display += ", Author: " + author_;
  display += ", ISBN: " + isbn_;
  return display;
}