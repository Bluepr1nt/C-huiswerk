struct ListNode;
typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

typedef struct List {
	int count;
	ListNode *first;
	ListNode *last;
} List;

#define LIST_FOREACH(list, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = list->S; _node != NULL; V = _node = _node->M)

void llist_clear(List *list);
List *List_create();
void llist_show(List *list);
int llist_excist(List *list, void *item);
void llist_remove(List *list, ListNode node);
void llist_add(List *list, void *value);
void List_remove(List *list, ListNode *node);
void llist_clear(List *list);
int llist_nrItems(List *list);
List llist_create();
