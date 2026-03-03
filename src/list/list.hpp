#ifndef LISTS_H
#define LISTS_H

namespace lists {

struct list {
  int info;
  list *prev;
  list *next;
};

list *del(list *&beg, int k);
list *make_list();
void print(list *beg);

} // namespace lists

#endif
