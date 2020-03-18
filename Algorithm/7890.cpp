/**
 * https://en.wikipedia.org/wiki/K-d_tree
 * kd 트리를 이용한 최근접 이웃 탐색
 */
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <map>
#include <unordered_map>
#include <math.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define int64 long long 

struct Node
{
	pair<int64, int64> pos;
	Node* left;
	Node* right;
};

class KdTree
{
public:
	KdTree(vector<pair<int64, int64>> v)
	{
		root = init(v, 0, v.size(), 0);
	}

	~KdTree()
	{
		destroy(root);
	}

	void destroy(Node* node)
	{
		if (node == nullptr) return;
		if (node->left != nullptr) destroy(node->left);
		if (node->right != nullptr) destroy(node->right);
		delete node;

		node = nullptr;
	}

	Node* init(vector<pair<int64, int64>>& v, int a, int b, int depth)
	{
		if (b - a == 0) return nullptr;
		if (b - a == 1)
		{
			Node* newNode = new Node();
			newNode->pos = v[a];
			newNode->left = nullptr;
			newNode->right = nullptr;

			return newNode;
		}

		// x 축 정렬
		if (depth % 2 == 0)
		{
			sort(v.begin() + a, v.begin() + b, [](pair<int64, int64>& a, pair<int64, int64>& b) {
				return a.first < b.first;
			});
		}
		// y 축 정렬
		else
		{
			sort(v.begin() + a, v.begin() + b, [](pair<int64, int64>& a, pair<int64, int64>& b) {
				return a.second < b.second;
			});
		}

		pair<int64, int64> pos = v[a + (b - a) / 2];
		Node* newNode = new Node();
		newNode->pos = pos;
		newNode->left = init(v, a, a + (b - a) / 2, depth + 1);
		newNode->right = init(v, a + (b - a) / 2 + 1, b, depth + 1);

		return newNode;
	}

	void print(Node* node)
	{
		if (node == nullptr) return;
		printf("{ %lld, %lld }\n", node->pos.first, node->pos.second);
		print(node->left);
		print(node->right);
	}

	void print()
	{
		print(root);
	}

	void nn(Node* node, int64& best, pair<int64, int64>& p, int depth)
	{
		if (node == nullptr)return;
		//printf("{ %lld, %lld }\n", node->pos.first, node->pos.second);
		if (node->pos != p)
		{
			long long len = (node->pos.first - p.first) * (node->pos.first - p.first) + (node->pos.second - p.second) * (node->pos.second - p.second);
			best = min(len, best);
		}

		if (depth % 2 == 0)
		{
			if (p.first <= node->pos.first)
			{
				nn(node->left, best, p, depth + 1);
				if (node->pos.first - p.first <= sqrt(best))
				{
					nn(node->right, best, p, depth + 1);
				}
			}
			else
			{
				nn(node->right, best, p, depth + 1);
				if ((p.first - node->pos.first) <= sqrt(best))
				{
					nn(node->left, best, p, depth + 1);
				}
			}
		}
		else
		{
			if (p.second <= node->pos.second)
			{
				nn(node->left, best, p, depth + 1);
				if (node->pos.second - p.second <= sqrt(best))
				{
					nn(node->right, best, p, depth + 1);
				}
			}
			else
			{
				nn(node->right, best, p, depth + 1);
				if (p.second - node->pos.second <= sqrt(best))
				{
					nn(node->left, best, p, depth + 1);
				}
			}
		}

	}

	int64 nn(pair<int64, int64>& p)
	{
		int64 best = numeric_limits<int64>::max();
		nn(root, best, p, 0);
		return best;
	}

private:
	Node* root;
};

int main()
{
	int t;
	cin >> t;

	for (int tc = 0; tc < t; ++tc)
	{
		int n;
		cin >> n;
		vector<pair<int64, int64>> v;
		for (int i = 0; i < n; ++i)
		{
			int64 a;
			int64 b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		KdTree kdTree(v);
		//kdTree.print();

		for (int i = 0; i < v.size(); ++i)
		{
			cout << kdTree.nn(v[i]) << "\n";
		}
	}

	return 0;
}