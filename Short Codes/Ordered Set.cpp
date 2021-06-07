//add these lines at the top

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

//ordered set can contain duplicates like a multiset. 
//number of elements in set which are smaller than given number
#define ook order_of_key
//index of given number in the set 
#define fbo find_by_order

// Ordered Set Tree 
typedef tree<int, null_type, less_equal<int>, 
			rb_tree_tag, 
			tree_order_statistics_node_update> 
	ordered_set;

