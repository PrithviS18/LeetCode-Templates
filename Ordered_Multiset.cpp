#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
struct OrderedMultiset {
    tree<
        pair<T,int>,
        null_type,
        less<pair<T,int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > os;

    int uid = 0; 

    void insert(T x) {
        os.insert({x, uid++});
    }

    void erase_one(T x) {
        auto it = os.lower_bound({x, -1});  // first occurrence
        if (it != os.end() && it->first == x) {
            os.erase(it);
        }
    }

    int order_of_key(T x) {
        return os.order_of_key({x, -1});
    }

    // get k-th smallest — 0 indexed
    T kth(int k) {
        return os.find_by_order(k)->first;
    }

    int size() {
        return os.size();
    }
};

/*
OrderedMultiset<int> ms;

ms.insert(5);
ms.insert(5);
ms.insert(1);
ms.insert(10);

cout << ms.size();                  // 4

cout << ms.order_of_key(5) << "\n"; // 1 (only 1 < 5)

cout << ms.kth(0) << "\n";          // 1
cout << ms.kth(1) << "\n";          // 5
cout << ms.kth(2) << "\n";          // 5
ms.erase_one(10);
*/
