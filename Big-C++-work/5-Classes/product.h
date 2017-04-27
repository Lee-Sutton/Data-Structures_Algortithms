#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product{
 public:
  // Constructs product with score 0 and price 1
  Product();

  // Reads in the product object
  void read();

  // Compares two products
  // @param b the object to compare with this object
  // @return true if this object is better than b
  bool is_better_than(Product b) const;

  // Prints the product object
  void print() const;

 private:
  string name;
  double price;
  int score;
  
};

#endif
