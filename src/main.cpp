#include "list.hpp"
#include <iostream>

using namespace std;
using namespace lists;

void remove_positive_next_div2(list *&beg) {
  list* current = beg->next;
  list* prev = beg;
  while (current != NULL) {
    if (!((current->info % 2 == 0) && (prev->info > 0))) {
      prev = current;
      current = current->next;
    }
    else {
      prev->next = current != NULL ? current->next : NULL;
      current = current != NULL ? current->next : NULL;
    }
  }

}

int main() {
  list *beg = make_list();
  print_list(beg);
  cout << "\n";
  // cout << "\nSUM: " << sum_list(beg) << endl;
  // cout << "\nIs sorted = " << (is_list_sorted(beg) ? "true" : "false") << "\n";
  remove_positive_next_div2(beg);
  print_list(beg);
  cout << "\n";
  return 0;
}
