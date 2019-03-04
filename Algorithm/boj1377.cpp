#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;

//��忡 ��ȣ�� �ű��.
vector<int> nodeNumber;
//������ ������Ʈ�� �и���
vector<int> sccId;
stack<int> s;
int nodeCounter;
int sccCounter;

int scc(int here) {
	int ret = nodeCounter;
	nodeNumber[here] = nodeCounter;
	nodeCounter++;
	s.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		//��������Ʈ�� ������
		int there = adj[here][i];
		//���� �߰� ���� Ʈ�� �����ϰ��
		if (nodeNumber[there] == -1) {
			//�ڸ� ��ġ�� ã�´�.
			ret = min(ret, scc(there));
		}
		//���� ������ ó�����ش�..
		else if (sccId[there] == -1) {
			ret = min(ret, nodeNumber[there]);
		}
	}
	//scc�� ��Ʈ ����� �ڸ���.
	if (nodeNumber[here] == ret) {
		while (true) {
			int t = s.top();
			s.pop();
			sccId[t] = sccCounter;
			if (t == here) {
				break;
			}
		}
		sccCounter++;
	}
	return ret;
}

vector<int> tarjan() {
	nodeCounter = 0;
	sccCounter = 0;
	nodeNumber.clear();
	sccId.clear();

	nodeNumber = vector<int>(adj.size(), -1);
	sccId = vector<int>(adj.size(), -1);
	for (int i = 0; i < adj.size(); i++) {
		if (nodeNumber[i] == -1) {
			scc(i);
		}
	}
	return sccId;
}
bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second <= b.first || b.second <= a.first;
}
//���� �׷����� �����Ѵ�.
void makeGraph(const vector<pair<int, int> >& meetings) {

	int vars = meetings.size();

	adj.clear();
	adj.resize(vars * 2);

	for (int i = 0; i < vars; i += 2) {
		int j = i + 1;

		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}

	for (int i = 0; i < vars; ++i) {
		for (int j = 0; j < i; ++j) {
			if (!disjoint(meetings[i], meetings[j])) {
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
	}
}
void printtarjan() {
	vector<int> label = tarjan();
	for (int i = 0; i < label.size(); i++) {
		cout << label[i] << endl;
	}
}

vector<int> solve2SAT() {
	int n = adj.size() / 2;
	vector<int> label = tarjan();
	//���� ������ ������Ʈ�� �ִٸ� �Ұ���
	for (int i = 0; i < 2 * n; i += 2) {
		if (label[i] == label[i + 1]) {
			return vector<int>();
		}
	}
	//���� �����Ѵ�
	vector<int> value(2 * n, -1);
	vector<pair<int, int> > order;
	//���� ������ �����
	for (int i = 0; i < 2 * n; i++) {
		order.push_back(make_pair(-label[i], i));
	}
	sort(order.begin(), order.end());


	for (int i = 0; i < 2 * n; i++) {
		//ù��° �ִ� �������� �Ѵ�.
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = vertex % 2;


		if (value[variable] != -1)continue;

		value[variable] = isTrue;
		//cout << value[variable] << " ";
	}
	return value;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<pair<int, int> > m(n * 2);

		for (int i = 0; i < n * 2; i++) {
			cin >> m[i].first >> m[i].second;
		}
		makeGraph(m);

		vector<int> solv = solve2SAT();
		if (solv.size() == 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < n * 2; i += 2) {
				if (solv[i] == 1)
					cout << m[i].first << " " << m[i].second << endl;
				else {
					cout << m[i + 1].first << " " << m[i + 1].second << endl;
				}
			}
		}

	}
	return 0;
}
