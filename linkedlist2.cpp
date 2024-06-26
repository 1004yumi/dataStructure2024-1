// 202314409 김유미 
// 4주차 퀴즈 2.

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 맨 앞에 노드 삽입 
ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// 맨 앞의 노드를 삭제
ListNode* remove_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* remove(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// 노드 탐색
ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	//while (p != NULL) {
	//	if (p->data == x) return p;
	//	p = p->link;
	//}

	for (ListNode* p = head; p != NULL; p = p->link) {
		if (p->data == x) return p;
	}

	return NULL;  // 탐색 실패
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main() {
	ListNode* head = NULL;
	for (int i = 10; i < 40; i += 10) {
		head = insert_first(head, i);
		print_list(head);
	}

	int searchvalue = 30;
	ListNode* foundnode = search_list(head, searchvalue);
	if (foundnode != NULL)
		printf("리스트에서 %d을 찾았습니다.\n", foundnode->data);
	else
		printf("리스트에서 %d을 찾지 못했습니다.\n", searchvalue);

	return 0;
}

