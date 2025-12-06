#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

/*
ordered_set<int> s;

s.insert(5);
s.insert(1);
s.insert(10);

cout << s.order_of_key(5);      // 1  (only 1 element < 5)
cout << *s.find_by_order(0);    // 1  (0th smallest)
cout << *s.find_by_order(2);    // 10
s.erase(10);
*/
