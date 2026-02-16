#include <iostream>

using namespace std;

struct list {
  long long info;
  list *next;

  list() = default;
};

list *make_list() {
  list *beg = new list;
  list *r, *p;
  long long x;
  cin >> x;
  beg->info = x;
  p = beg;
  cin >> x;

  while (x != 0) {
    r = new list;
    r->info = x;
    r->next = NULL;
    p->next = r;
    p = r;
    cin >> x;
  }
  return beg;
}

void print(list *beg) {
  list *p = beg;
  while (p != NULL) {
    cout << p->info << " ";
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
    if (current->next == NULL)
      ++i;
  }
  return i;
}

bool is_sorted(list *beg) {
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

int main() {
  list *beg = make_list();
  print(beg);
  cout << "\nSUM: " << sum_list(beg) << endl;
  cout << "\nIs sorted = " << (is_sorted(beg) ? "true" : "false") << "\n";
  return 0;
}
