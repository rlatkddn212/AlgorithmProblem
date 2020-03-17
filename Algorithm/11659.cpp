#include <iostream>
#include <vector>
using namespace std;

typedef long long int64;

template<typename Type>
class CSegmentTree
{
private:
	vector<Type> tree;
	int length;
	Type Init(const vector<int>& num, int node, int start, int end);
	Type Sum(int node, int left, int right, int start, int end);
	void Update(int node, int index, int num, int start, int end);
public:

	CSegmentTree(int n) :tree(n * 4, 0), length(n) {}
	~CSegmentTree() {}

	void SetSegment(const vector<int>& num);
	Type SumSegment(int start, int end);
	void UpdateSegement(int index, int num);
	//Type Update();
};

template<typename Type>
void CSegmentTree<Type>::SetSegment(const vector<int>& num)
{
	Init(num, 1, 0, length - 1);
}

template<typename Type>
Type CSegmentTree<Type>::SumSegment(int left, int right)
{
	return Sum(1, left, right, 0, length - 1);
}

template<typename Type>
Type CSegmentTree<Type>::Init(const vector<int>& num, int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = num[start];
	}
	return tree[node] = Init(num, node * 2, start, (start + end) / 2)
		+ Init(num, node * 2 + 1, (start + end) / 2 + 1, end);
}

template<typename Type>
Type CSegmentTree<Type>::Sum(int node, int left, int right, int start, int end)
{
	if (right < start || end < left)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	return Sum(node * 2, left, right, start, (start + end) / 2)
		+ Sum(node * 2 + 1, left, right, (start + end) / 2 + 1, end);
}

template<typename Type>
void CSegmentTree<Type>::UpdateSegement(int index, int num)
{
	Update(1, index, num, 0, length - 1);
}

template<typename Type>
void CSegmentTree<Type>::Update(int node, int index, int num, int start, int end)
{
	if (index < start || end < index)
	{
		return;
	}
	tree[node] += num;
	if (start != end)
	{
		Update(node * 2, index, num, start, (start + end) / 2);
		Update(node * 2 + 1, index, num, (start + end) / 2 + 1, end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	CSegmentTree<int64> tree(n);
	tree.SetSegment(v);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << tree.SumSegment(a - 1, b - 1) << "\n";
	}
	return 0;
}