#include "list/list.hpp"
#include "utils/utils.hpp"
#include <iostream>

using namespace lists;
using namespace std;
using namespace list_utils;

int main() {
  list *beg = make_list();
  print(beg);

  if (!is_sorted(beg)) {
    // remove_not_ideal(&beg);

    list *new_beg;
    new_beg = make_without_nonideal(new_beg);
    print(new_beg);
    // print(beg);
  }

  return 0;
}
