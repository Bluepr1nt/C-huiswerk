#include <stdio.h>
#include <stdlib.h>
include "Header.h"

void main(){
	
}

List *List_create(){
	return calloc(1, sizeof(List));
}

void llist_show(List *list){
	LIST_FOREACH(list, first, next, cur){
		printf(cur->value);
	}
}

int llist_excist(List *list, void *item){
	LIST_FOREACH(list, first, next, cur){
		if(cur->value == item){
			printf("Item excists");
			return cur->count;
		}
	}
}

void llist_remove(){
	
}

void llist_add(List *list, void *value){
	ListNode *node = calloc(1, sizeof(ListNode));
	check_mem(node);
	node->value = value;
	
	if(list->last == NULL){
		list->first = node;
		list->last = node;
	} else{
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}
	list->count++;
	
	error: return;
}

void *List_remove(List *list, ListNode *node){
	void *result = NULL;
	check(list->first && list->last, "List is empty");
	check(node, "Node can't be NULL");
	
	if(node == list->first && node == list->last){
		list->first = NULL;
		list->last = NULL;
	} else if(node == list->first){
		list->first = node->next;
		check(list->first != NULL, "Invalid list: First = NULL");
		list->first->prev = NULL;
	} else if(node == list->last){
		list->last = node->prev;
		check(list->last != NULL, "Invalid list: Next = NULL");
		list->last->next = NULL;
	} else{
		ListNode *after = node->next;
		ListNode *before = node->prev;
		after->prev = before;
		before->next = after;
	}
	
	list->count--;
	result = node->value;
	free(node);
	
	error: return result;
}

void llist_clear(List *list){
	LIST_FOREACH(list, first, next, cur){
		if(cur->prev){
			free(cur->prev);
		}
	}
	free(list->last);
	free(list);
}

int llist_nrItems(List *list){
	if(list->last->count != NULL){
		return list->last->count;
	} else{
		return 0;
	}
}