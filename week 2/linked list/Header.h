struct ListNode;
typedef struct ListNode{
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List{
	int count;
	ListNode *first;
	ListNode *last;
} List;

#define LIST_FOREACH(list, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = list->S; _node != NULL; V = _node = _node->M)

#endif

void llist_clear(List *list);
List *List_create();