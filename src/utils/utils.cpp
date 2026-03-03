#include "utils.hpp"
#include "../list/list.hpp"
#include <iostream>
#include <string>

#define list lists::list

using namespace lists;
namespace list_utils {

bool is_debugging = true;

void debug_log(std::string s) {
  if (is_debugging)
    std::cout << "[DEBUG] " << s << std::endl;
}

int get_max(list *beg) {
  int   max = beg->info;
  list *t = beg->next;

  while (t != NULL) {
    if (max < t->info)
      max = t->info;
    t = t->next;
  }

  return max;
}

bool is_symmetric(list *beg) {
  list *l = beg;
  list *r = beg;

  while (r->next != NULL)
    r = r->next;

  while (l != r) {
    if (l->info != r->info)
      return 0;
    l = l->next;
    r = r->prev;
  }

  return 1;
}

long long solve_equasion(list *beg) {
  long long res = 0;
  list     *l = beg;
  list     *r = beg;
  while (r->next != NULL)
    r = r->next;
  do {
    res += l->info * r->info;
    l = l->next;
    r = r->prev;
  } while (l != NULL);
  return res;
}

int get_last_even(list *beg) {
  list *r = beg;
  while (r->next != NULL)
    r = r->next;
  while (r != NULL) {
    if (r->info % 2 == 0)
      return r->info;
    r = r->prev;
  }
  return 0;
}

void replace_4(list *beg) {
  list *t = beg;
  int   last_even = get_last_even(beg);

  while (t != NULL) {
    if (t->info % 10 == 5)
      t->info = last_even;
    t = t->next;
  }
}

int get_max_5(list *beg) {
  list *l = beg;
  list *r = beg;
  while (r->next != NULL) {
    r = r->next;
  }

  int max = l->info * r->info;

  do {
    r = r->prev;
    l = l->next;
    int t = l->info * r->info;
    if (t > max)
      max = t;

  } while (r != l);

  return max;
}

void print_reverse(list *beg) {
  list *r = beg;
  while (r->next != NULL)
    r = r->next;
  std::cout << "reversed list: ";
  while (r != NULL) {
    std::cout << r->info << " ";
    r = r->prev;
  }
  std::cout << std::endl;
}

bool is_prime(int n) {
  for (int i = 2; i * i < n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

void remove_prime_between_even(list *beg) {
  list *cur = beg->next;
  while (cur->next != NULL) {
    if (is_prime(cur->info) && cur->prev->info % 2 == 0 &&
        cur->next->info % 2 == 0) {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
    }
    cur = cur->next;
  }
  debug_log("removed prime nums that are between even nums");
}

bool is_there_0(list *t) {
  int n = t->info;
  while (n) {
    if (n % 10 == 0)
      return true;
    n /= 10;
  }
  return false;
}

void remove_all_mod5_before_no_0(list *beg) {
  list *prev = beg;
  while (prev->next != NULL) {
    if (prev->next->info % 5 == 0 && !is_there_0(prev)) {
      prev->next = prev->next->next;
      prev->next->prev = prev;
    } else {
      prev = prev->next;
    }
  }
}

bool is_sorted(list *beg) {
  list *t = beg;

  while (t->next != NULL)
    t = t->next;

  while (t->prev != NULL) {
    if (t->prev->info > t->info)
      return 0;
    t = t->prev;
  }
  return 1;
}

bool is_ideal(list *item) {
  int t = item->info;
  int sm = 0;
  for (int i = 1; i < t / 2 + 1; ++i) {
    if (!(t % i))
      sm += i;
  }
  return sm == t;
}

bool are_ideal(list *beg) {
  list *t = beg;
  while (t != NULL) {
    if (!is_ideal(t))
      return 0;
    t = t->next;
  }
  return 1;
}

void remove(list *l) {
  if (l->prev != NULL)
    l->prev->next = l->next;
  if (l->next != NULL)
    l->next->prev = l->prev;

  // if (l->next != NULL) l = l->next;
  // if (l->prev != NULL) l = l->prev;
}

void remove_ideal(list *beg) {
  list *t = beg;
  while (t != NULL) {
    if (is_ideal(t))
      remove(t);
    t = t->next;
  }
}

void remove_not_ideal(list **beg) {
  while (!is_ideal(*beg)) {
    (*beg)->next->prev = NULL;
    *beg = (*beg)->next;
  }
  list *t = *beg;
  while (t != NULL) {
    if (!is_ideal(t)) {
      remove(t);
      debug_log(std::to_string(t->info));
    }
    t = t->next;
  }
}

void push_back(list **beg, list *item) {
  list *t = *beg;
  while (t->next != NULL) {
    debug_log("Processing push...");
    t = t->next;
  }
  t->next = item;
  t->next->prev = t;
}

void push_next(list **beg, list *item) {
  item->next = (*beg)->next;
  (*beg)->next = item;
  (*beg)->next->prev = *beg;
}

list *make_node(int info) {
  list *res = new list;
  res->next = nullptr;
  res->prev = nullptr;
  res->info = info;
  return res;
}

list *make_without_nonideal(list *beg) {
  if (beg == nullptr)
    return nullptr;

  list *current = beg;
  list *new_head = nullptr;

  while (current != nullptr) {
    if (is_ideal(current)) {
      // debug_log(std::to_string(current->info));
      list *newNode = make_node(current->info);

      if (new_head == nullptr) {
        new_head = newNode;
      } else {
        push_next(&new_head, newNode);
        new_head = new_head->next;
      }
    }
    current = current->next;
  }

  if (new_head == nullptr)
    return nullptr;

  while (new_head->prev != nullptr) {
    new_head = new_head->prev;
  }

  return new_head;
}

} // namespace list_utils
