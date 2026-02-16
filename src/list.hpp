#ifndef LIST_HPP
#define LIST_HPP

namespace lists {
struct list;
list *make_list();
void print_list(list *beg);
list *del(list *&beg, int k);
list *vst(list *&beg, int k, int z);
long long sum_list(list *beg);
int count_list(list *beg);
bool is_list_sorted(list *beg);

} // namespace lists

#endif
