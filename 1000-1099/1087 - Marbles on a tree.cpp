#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
vector <int> V[100005];
int B[100005], Viz[100005];
int tot;
int Tata[100005];

pair<vector<int>, vector<int> > DFS(int x)
{
	pair<vector<int>, vector<int> > DP;
	for (int i = 0; i < V[x].size(); i++)
	{
		pair<vector<int>, vector<int> > y = DFS(V[x][i]);
		for (int j = 0; j < y.first.size(); j++)
			DP.first.push_back(y.first[j]+1);
		for (int j = 0; j < y.second.size(); j++)
			DP.second.push_back(y.second[j]+1);
	}
	if (B[x] == 0)
		DP.second.push_back(0);
	if (B[x] > 1)
		for (int i=1; i<=B[x]-1; i++)
			DP.first.push_back(0);
	sort(DP.first.begin(), DP.first.end());
	sort(DP.second.begin(), DP.second.end());
	while (DP.first.size() && DP.second.size())
	{
		tot += DP.first[DP.first.size()-1] + DP.second[DP.second.size()-1];
		DP.first.pop_back();
		DP.second.pop_back();
	}
	return DP;
}

int main()
{
	int n = 1;
	while (n != 0)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++)
		{
			int x, nr, y;
			cin >> x;
			cin >> B[x];
			cin >> nr;
			for (int j = 1; j <= nr; j++)
			{
				cin >> y;
				Tata[y] = 1;
				V[x].push_back(y);
			}
		}
		int tata;
		for (int i = 1; i <= n; i++)
			if (Tata[i] == 0)
				tata = i;
		tot = 0;
		DFS(tata);
		cout << tot << '\n';
		for (int i = 1; i <= n; i++)
			V[i].clear();
		memset(Viz, 0, sizeof(Viz));
	}
}