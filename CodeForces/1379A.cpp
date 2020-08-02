#include <bits/stdc++.h>
//#define DEBUG
#define MULTICASE
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define dbg(x) cerr << #x " = " << x << endl;
#define CASET  \
  int ___T;    \
  cin >> ___T; \
  for (int _t = 1; _t <= ___T; ++_t)
using namespace std;

string target = "abacaba", caba = "caba", abac = "abac";
inline void solve()
{
  int n, pos;
  string s;
  cin >> n >> s;
  pos = s.find(target);
  if (pos != string::npos)
  {
    if (s.find(target, pos + 1) != string::npos)
      cout << "No\n";
    else
    {
      cout << "Yes\n";
      for (char c : s)
        cout << (c != '?' ? c : 'x');
      cout << '\n';
    }
  }
  else
  {
    pos = 0;
    for (int i = 0; i < n; ++i)
    {
      if (s[i] == target[pos] || s[i] == '?')
      {
        if (++pos == 7) // Done
        {
          if (i + 4 < n && s.substr(i + 1, 4) == caba)
            pos = 3;
          else if (i - 10 >= 0 && s.substr(i - 10, 4) == abac)
            pos = 3;
          else
          {
            s.replace(i - 6, 7, target);
            break;
          }
        }
      }
      else
        pos = 0;
    }

    if (pos == 7)
    {
      cout << "Yes\n";
      for (char c : s)
        cout << (c != '?' ? c : 'x');
      cout << '\n';
    }
    else
      cout << "No\n";
  }
}
int main()
{
  IOS
#ifdef DEBUG
      freopen("problem.in", "r", stdin);
  freopen("problem.out", "w", stdout);
  clock_t _t_start = clock();
#endif

#ifdef MULTICASE
  CASET
  {
    solve();
  }
#else
  {
    solve();
  }
#endif

#ifdef DEBUG
  fprintf(stderr, "\nRuntime: %.10f s\n", (double)(clock() - _t_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}
