#include<iostream>
#include<set>
#include<sstream>
#include<algorithm>
#define MIN(n,m) ((n)>(m)?m:n)

using namespace std;

int main()
{

	string num_str;

	while (getline(cin, num_str))
	{
		istringstream ss(num_str);

		set<int> set1, set2;
		int temp;

		while (ss >> temp)
			set1.insert(temp);

		getline(cin, num_str);

		ss.str(num_str);
		ss.clear();

		while (ss >> temp)
			set2.insert(temp);

		int diff_buf[100]{0};

		int diff(set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), diff_buf) - diff_buf);

		int n(set1.size()), m(set2.size());

		if (!diff)
			cout << "A and B are disjoint\n";
		else if (diff == MIN(n, m))
		{
			if (n == m)
				cout << "A equals B\n";
			else cout << ((MIN(n, m) == n) ? "A is a proper subset of B\n" : "B is a proper subset of A\n");
		}
		else cout << "I'm confused!\n";
	}

	return 0;
}