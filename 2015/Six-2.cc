typedef struct BNode {
	int weight;
	struct BNode *left;
	struct BNode *right;
};

// �ݹ�������ö�������洢�Ĺ�������ֵ���㷨
// 

int compute(BNode *root, int depth) {
	if (root->left == NULL && root->right == NULL) {
		return depth * weight;
	}
	else {
		return compute(root->left, depth + 1) + compute(root->right, depth + 1);
	}
}
