#include <iostream>

using namespace std;
namespace lists {

struct list {
  int info;
  list *prev;
  list *next;
};

void print(list *beg) {
  list *p = beg;
  cout << "list: ";
  while (p != NULL) {
    cout << p->info << " ";
    p = p->next;
  }
  cout << endl;
  ;
}

list *make_list() {
  list *beg = new (list);
  list *r, *p;
  int x;
  cin >> x;
  beg->info = x;
  p = beg;
  while (x != 0) {
    cin >> x;
    if (x == 0)
      break;
    r = new (list);
    r->info = x;
    r->next = NULL;
    p->next = r;
    r->prev = p;
    p = r;
  }
  return beg;
}

list *del(list *&beg, int k) {
  list *p = beg->next;
  list *r;
  while (p != NULL) {
    if (p->info == k) {
      if (p->next != NULL) {
        r = p;
        p->next->prev = p->prev;
        p->prev->next = p->next;
        delete[] r;
      } else {
        p->prev->next = NULL;
        delete[] p;
        break;
      }
    }
    p = p->next;
  }
  if (beg->info == k) {
    p = beg;
    beg = beg->next;
    beg->prev = NULL;
    delete[] p;
  }
  return beg;
}

} // namespace lists
