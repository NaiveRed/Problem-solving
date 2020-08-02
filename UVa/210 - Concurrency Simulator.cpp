#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

struct Program
{
  vector<string> statement{32};
  int pos, run_pos;
  void init()
  {
    run_pos = pos = 0;
  }
  bool read()
  {
    getline(cin, statement[pos]);
    return statement[pos++].size() != 3;
  }

  const string &advance()
  {
    return statement[run_pos++];
  }

} programs[1024];
int exe_time[5], tq;
deque<int> ready_q, block_q;
// assignments to a variable in one program affect the value
// that might be printed by a different program.
// All variables are initially set to zero.
int vars[26];
bool is_lock;
int execute(int pid, const string &statement)
{
  int ch_pos = statement.find(" ");
  if (ch_pos != -1)
  {
    if (ch_pos == 1) // assignment
    {
      vars[statement[0] - 'a'] = stoi(statement.substr(4));
      return 0;
    }
    else // print
    {
      cout << pid + 1 << ": " << vars[statement[statement.size() - 1] - 'a'] << '\n';
      return 1;
    }
  }
  else
  {
    if (statement[0] == 'l') // lock
    {
      if (is_lock)
        return -1;

      is_lock = true;
      return 2;
    }
    else if (statement[0] == 'u')
    {
      is_lock = false;
      return 3; //unlock
    }
    else
      return 4; // end
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int Case, n;
  cin >> Case;
  while (Case--)
  {
    // Init
    ready_q.clear();
    block_q.clear();
    is_lock = false;
    for (int &i : vars)
      i = 0;

    cin >> n;
    for (int i = 0; i < 5; ++i)
      cin >> exe_time[i];
    cin >> tq;
    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
      programs[i].init();
      while (programs[i].read())
        ;
      ready_q.push_back(i);
    }

    // Execute
    while (!ready_q.empty())
    {
      int time = tq, pid = ready_q.front();
      ready_q.pop_front();
      while (true)
      {
        int ret = execute(pid, programs[pid].advance());

        if (ret == -1)
        {
          // lock failed:
          // placed at the end of the blocked queue
          block_q.push_back(pid);
          --programs[pid].run_pos;
          break;
        }
        else if (ret == 3 && !block_q.empty())
        {
          // unlock:
          // any program at the head of the blocked queue
          // is moved to the head of the ready queue
          ready_q.push_front(block_q.front());
          block_q.pop_front();
        }
        else if (ret == 4)
          break;

        time -= exe_time[ret];
        // Time expires
        if (time <= 0)
        {
          ready_q.push_back(pid);
          break;
        }
      }
    }

    if (Case)
      cout << '\n';
  }

  return 0;
}