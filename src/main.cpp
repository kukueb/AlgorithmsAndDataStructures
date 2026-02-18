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

int* count_two_lists(list* l1, list* l2) {
  int* arr = new int[2];
  arr[0] = count_list(l1);
  arr[1] = count_list(l2);
  return arr;
}

int count_sum(list* beg) {
  int sm = 0;
  int info = beg->info;
  while (info) {
    sm += info%10;
    info /= 10;
  }
  return sm;
}

void insert_min(list* beg) {
  int min = find_min_list(beg);
  list* cur = beg;
  list* next = beg->next;
  while (next != NULL) {
    if (count_sum(next) % 2 == 0) {
      list* t = new list;
      t->info = min;
      t->next = next;
      cur->next = t;
    }
    cur = next;
    next = next->next;
  }
}

int main() {
  list *beg1 = make_list();
  // cout << count_list(beg1);
  // list *beg2 = make_list();
  //
  // print_list(beg);
  // cout << "\n";
  //
  // cout << "\nSUM: " << sum_list(beg) << endl;
  // cout << "\nIs sorted = " << (is_list_sorted(beg) ? "true" : "false") << "\n";
  //
  // remove_positive_next_div2(beg);
  // print_list(beg);
  
  // int* arr = count_two_lists(beg1, beg2);
  // for (int i = 0; i < 2; ++i) {
  //   cout << "arr " << i+1 << ": " << arr[i] << "\n";
  // }

  insert_min(beg1);
  print_list(beg1);
  cout << "\n";
  return 0;
}
