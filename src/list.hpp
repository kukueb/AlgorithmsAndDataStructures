#ifndef LIST_HPP
#define LIST_HPP

namespace lists {

struct list {
  long long info;
  list* next;
  list() = default;
};
list *make_list();
void print_list(list *beg);
list *del(list *&beg, int k);
list *vst(list *&beg, int k, int z);
long long sum_list(list *beg);
int count_list(list *beg);
bool is_list_sorted(list *beg);
long long find_min_list(list* beg);

} // namespace lists

#endif
