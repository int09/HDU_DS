#define MaxSize 100

typedef	struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
	char data;
	int distance;					// ����ӵľ���������
	struct ArcNode *firstarc;
};

typedef struct ALGraph {
	int n, e;
	VNode adjlist[MaxSize];
};



// ���ڷ��� BFS �㷨
int visit[MaxSize];
int Queue[MaxSize];

void BFS(ALGraph *G, int v0, int len) {
	int front = 0, rear = 0;
	Visit(v0), visit[v0] = 1;
	rear = (rear + 1) % MaxSize;
	Queue[rear] = v0;
	while (front != rear) {
		front = (front + 1) % MaxSize;
		int w = Queue[front];
		ArcNode *p = G->adjlist[w].firstarc;
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {
				// Ϊ��һ�����ľ����һ
				G->adjlist[p->adjvex].distance = G->adjlist[w].distance + 1;
				Visit(p->adjvex), visit[p->adjvex];
				rear = (rear + 1) % MaxSize;
				Queue[rear] = p->adjvex;
				if (G->adjlist[p->adjvex].distance == len)
					cout << G->adjlist[p->adjvex].data << endl;
			}
			p = p->nextarc;
		}
	}
}

