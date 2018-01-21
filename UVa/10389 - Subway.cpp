#include <cstdio>
#include <sstream>
#include <utility>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> Stop;

struct Node
{
	int id;
	double cost; //minute
	Node(int _id, double _cost) : id(_id), cost(_cost) {}
	bool operator<(const Node &a) const { return cost > a.cost; }
};
inline double get_dist(Stop &a, Stop &b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main()
{
	const double speed[2] = { 10000.0 / 60, 40000.0 / 60 };
	map<Stop, int> stop_to_id;
	Stop id_to_stop[205];
	vector<int> adj_list[205];
	int Case;
	scanf("%d", &Case);

	while (Case--)
	{
		Stop start, goal;
		scanf("%d%d%d%d", &start.first, &start.second, &goal.first, &goal.second);
		stop_to_id[start] = 1;
		stop_to_id[goal] = 2;
		id_to_stop[1] = start;
		id_to_stop[2] = goal;
		int id = 3;
		char str[10000];
		getchar();
		// subway station
		while (fgets(str, 10000, stdin) && str[0] != '\n')
		{
			istringstream ss(str);
			int x, y, now, last = -1;
			while (ss >> x >> y)
			{
				if (x < 0)
					break;
				Stop n(x, y);
				if (stop_to_id.count(n))
					now = stop_to_id[n];
				else
				{
					now = stop_to_id[n] = id;
					id++;
				}

				id_to_stop[now] = n;
				if (last != -1)
				{
					adj_list[now].push_back(last);
					adj_list[last].push_back(now);
				}

				last = now;
			}
		}

		//dijkstra
		bool visited[205] = {};
		double d[205]; //best minute
		for (int i = 0; i < id; i++)
			d[i] = 1e9;
		d[1] = 0;
		priority_queue<Node> PQ;
		PQ.push(Node(1, 0));
		while (!PQ.empty())
		{
			int now_id = 0;
			while (!PQ.empty() && visited[now_id = PQ.top().id])
				PQ.pop();

			if (!now_id || now_id == 2) // 2 is goal id
				break;

			visited[now_id] = true;
			Stop now = id_to_stop[now_id];

			//subway
			for (int next_id : adj_list[now_id])
			{
				Stop next = id_to_stop[next_id];
				if (!visited[next_id])
				{
					double cost = d[now_id] + get_dist(now, next) / speed[1];
					if (cost < d[next_id])
					{
						d[next_id] = cost;
						PQ.push(Node(next_id, d[next_id]));
					}
				}
			}
			//walk
			for (int next_id = 2; next_id < id; next_id++)
			{
				Stop next = id_to_stop[next_id];
				if (!visited[next_id])
				{
					double cost = d[now_id] + get_dist(now, next) / speed[0];
					if (cost < d[next_id])
					{
						d[next_id] = cost;
						PQ.push(Node(next_id, d[next_id]));
					}
				}
			}
		}

		printf("%d\n", (int)(d[2]+0.5));
		if (Case)
			putchar('\n');
		
		//init
		stop_to_id.clear();
		for (int i = 0; i < id; i++)
			adj_list[i].clear();
	}

	return 0;
}
