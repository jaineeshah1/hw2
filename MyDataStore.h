#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <iostream>

class MyDataStore: public DataStore {
  public: 
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
  
  private:
    std::vector<Product*> products;
    std::vector<User*> users;
};

#endif