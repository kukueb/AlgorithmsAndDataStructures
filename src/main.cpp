#include "list.hpp"
#include <iostream>

using namespace std;
using namespace lists;

int main() {
  list *beg = make_list();
  print_list(beg);
  cout << "\nSUM: " << sum_list(beg) << endl;
  cout << "\nIs sorted = " << (is_list_sorted(beg) ? "true" : "false") << "\n";
  return 0;
}
