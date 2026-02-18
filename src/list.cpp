#include <iostream>

namespace lists { 

struct list {
  long long info;
  list *next;

  list() = default;
};

list *make_list() {
  list *beg = new list;
  list *r, *p;
  long long x;
  std::cin >> x;
  beg->info = x;
  p = beg;
  std::cin >> x;

  while (x != 0) {
    r = new list;
    r->info = x;
    r->next = NULL;
    p->next = r;
    p = r;
    std::cin >> x;
  }
  return beg;
}

void print_list(list *beg) {
  list *p = beg;
  while (p != NULL) {
    std::cout << p->info << " ";
    p = p->next;
  }
}

list *del(list *&beg, int k) {
  list *p = beg;
  list *r;
  while (p->next != NULL) {
    if (p->next->info == k) {
      r = p->next;
      if (r->next != NULL) {
        p->next = r->next;
        delete[] r;
      } else {
        p->next = NULL;
        delete[] r;
        break;
      }
    }
    p = p->next;
  }
  if (beg->info == k) {
    p = beg;
    beg = beg->next;
    delete[] p;
  }
  return beg;
}

list *vst(list *&beg, int k, int z) {
  list *p = beg;
  list *r;
  while (p != NULL) {
    if (p->info == k) {
      r = new (list);
      r->info = z;
      if (p->next != NULL) {
        r->next = p->next;
        p->next = r;
      } else {
        r->next = NULL;
        p->next = r;
      }
    }
    p = p->next;
  }
  return beg;
}

long long sum_list(list *beg) {
  long long sum = 0;
  list *current = beg;
  while (current->next != NULL) {
    sum += current->info;
    current = current->next;
    if (current->next == NULL) {
      sum += current->info;
    }
  }
  return sum;
}

int count_list(list *beg) {
  int i = 0;
  list *current = beg;
  while (current->next != NULL) {
    ++i;
    current = current->next;
    if (current->next == NULL)
      ++i;
  }
  return i;
}

bool is_list_sorted(list *beg) {
  list *current = beg->next;
  list *prev = beg;
  while (prev->next != NULL) {
    if (prev->info >= current->info)
      return false;
    prev = current;
    current = current->next;
  }
  return true;
}

long long find_min_list(list* beg) {
  list* cur = beg;
  long long min = cur->info;
  while (cur != NULL) {
    if (cur->info < min) min = cur->info ;
    cur = cur->next;
  }
  return min;
}

} // namespace lists
