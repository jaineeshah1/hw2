#include "util.h"
#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty,
  const std::string brand, const std::string size) :
    Product(category, name, price, qty)
{
  brand_ = brand;
  size_ = size;
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
  display += name_ + "\n";
  display += "Size: " + size_ + " Brand: " + brand_;
  display += std::to_string(price_) + " " + std::to_string(qty_) + " left.";
  return display;
}
void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" 
    << qty_ << brand_ << std::endl;
}