#include "util.h"
#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty,
  const std::string brand) :
    Product(category, name, price, qty)
{
  brand_ = brand;
}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> set_keywords;

  std::set<std::string> set_keywords_brand;
  set_keywords_brand = parseStringToWords(brand_);
  
  std::set<std::string> set_keywords_name;
  set_keywords_name = parseStringToWords(name_);

  set_keywords = setUnion(set_keywords_brand, set_keywords_name);

  return set_keywords;
}
std::string Clothing::displayString() const {
  std::string display = "";
  display += "Clothing name: " + name_;
  display += ", Brand: " + brand_;
  return display;
}