typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

void Diff(LinkList &L1, LinkList L2) {
	LNode *p = L1->next, *q = L2->next, pre = L1;
	while (p != NULL) {
		while (q != NULL) {
			if (p->data == q->data) {
				pre->next = p->next;
				free(p);
				p = pre->next;
			}
			else {
				q = q->next;
			}
		}
		pre = p;
		p = p->next;
	}
}

