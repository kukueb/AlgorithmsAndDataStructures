#ifndef UTILS_H
#define UTILS_H

#include "../list/list.hpp"

namespace list_utils {

int          get_max(lists::list *);
bool         is_symmetric(lists::list *);
long long    solve_equasion(lists::list *);
void         replace_4(lists::list *);
int          get_max_5(lists::list *);
void         print_reverse(lists::list *);
void         remove_prime_between_even(lists::list *);
bool         is_sorted(lists::list *);
bool         is_ideal(lists::list *);
bool         are_ideal(lists::list *);
void         remove(lists::list *);
void         remove_ideal(lists::list *);
void         remove_not_ideal(lists::list **);
void         push_back(lists::list *);
lists::list *make_without_nonideal(lists::list *);
void         push_back(lists::list **, lists::list *);
void         push_next(lists::list **, lists::list *);

}; // namespace list_utils

#endif
