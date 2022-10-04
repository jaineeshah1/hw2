#include "MyDataStore.h"
#include "util.h"

void MyDataStore::addProduct(Product* p) {
  products.push_back(p);
}
void MyDataStore::addUser(User* u) {
  users.push_back(u);
}
std::set<std::string> convertToSet(std::vector<std::string>& v)
{
    std::set<std::string> s;
     for (std::string x : v) {
        s.insert(x);
    }
 
    return s;
}
bool in_array(const std::string &value, const std::vector<std::string> &array)
{
    return std::find(array.begin(), array.end(), value) != array.end();
}
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::vector<Product*> result;
  std::set<std::string> set_terms = convertToSet(terms);
  if (type == 0) { // AND
    for (unsigned int i = 0; i < products.size(); i++) {
      Product* p = products[i];
      std::set<std::string> keywords = p->keywords();
      if (setIntersection(set_terms, keywords).size() == set_terms.size()) {
        result.push_back(p);
      }
    }
  }
  else {
    for (unsigned int i = 0; i < products.size(); i++) {
      Product* p = products[i];
      std::set<std::string> keywords = p->keywords();
      if (setIntersection(set_terms, keywords).size() > 0) {
        result.push_back(p);
      }
    }
  }
  return result;
}
void MyDataStore::dump(std::ostream& ofile) {
  for (unsigned int i = 0; i < products.size(); i++) {
    Product* p = products[i];
    p->dump(ofile);
  }
}

