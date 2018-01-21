#include <cstdio>
bool adj_m[101][101], visited[101];
int N;
int dfs(int u)
{
	int step = 0; // u 點可到的數量(不包含其他點已經走到的!)
	for (int i = 1; i <= N; i++)
		if (adj_m[u][i] && !visited[i])
		{
			visited[i] = true;
			step += dfs(i) + 1; // (i 可以走到的) + (i 這點)
		}

	return step;
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		int T, ref[101] = {};
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &T);
			for (int j = 0; j < T; j++)
			{
				int v;
				scanf("%d", &v);
				adj_m[i][v] = true;
				ref[v]++;
			}
		}
		int ans = 0, max = 0;
		for (int i = 1; i <= N; i++)
		{
			int temp = 0;
			if (!ref[i]) // 不是任何點前置工作的點
			{
				temp = dfs(i);
				if (max < temp)
				{
					ans = i;
					max = temp;
				}

				for (int i = 0; i <= N; i++)
					visited[i] = false;
			}
		}

		printf("%d\n", ans);

		// init
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				adj_m[i][j] = false;
	}

	return 0;
}
/*
input:
8
1 6   // 6 -> 1; 先完成 6，才能做 1 
2 5 4 // 4 -> 2, 5 -> 2; 先完成 4, 5，才能做 2
0
1 3   // 3 -> 4
0
1 7
1 3
1 2
8
1 2
1 3
1 4
0
2 6 7
1 8
1 8
0
0
output:
8
1
找需要最多前置工作的點，所以把邊反過來存(e.g. 上面的 6->1 改成 1->6 ),
找可以遍歷最多的點就是答案了。(輸出點，而不是距離)
*/