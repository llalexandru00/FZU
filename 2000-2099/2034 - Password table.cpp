#include <iostream>
#include <cstring>
#include <string>
#define nmax 100005
#define INF 1000000000000000000
using namespace std;

typedef long long ll;
int n, m, q, t;
string M[15][15];
string s;
int main()
{
	cin >> t;
	for (int te=1; te<=t; te++)
	{
		cin >> n >> m >> q;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> M[i][j];
		cout << "Case " << te << ":" << '\n';
		for (int i = 1; i <= q; i++)
		{
			cin >> s;
			for (int j = 0; j < s.size(); j+=2)
			{
				int col = s[j] - 'A' + 1;
				int row = s[j + 1] - '0';
				cout << M[row][col];
			}
			cout << '\n';
		}
	}
	return 0;
}