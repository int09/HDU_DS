typedef	ElemType	int;

// ���ƿ����еķָ��㷨��������һ�μ��ɽ�Ԫ�� Kn �ŵ��������ȷ��λ����
// ������ K[]�������������
//			n	������Ĺ�ģ
void sort(ElemType K[], int n) {
	int low = 1, high = n;
	ElemType pivotkey = K[n];
	while (low < high) {
		while (low < high && K[low] >= pivotkey) --high;
		K[low] = K[high];
		while (low < hgih && K[low] <= pivotkey) ++low;
		K[high] = K[low];
	}
	K[low] = pivotkey;
}

// ����ѡ��������㷨
void sort(ElemType K[], int n) {
	int position = 1;
	for (int i = 1; i <= n; ++i)  if (K[i] <= K[n])
			position++;
	swap(K[position], K[n]);
}

