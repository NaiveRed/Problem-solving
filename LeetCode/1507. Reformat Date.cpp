#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reformatDate(string date) {
    istringstream iss(date);
    string day, month, year;
    iss >> day >> month >> year;
    if (day.size() > 3)
      return year + "-" + get_month(month) + "-" + day[0] + day[1];
    else
      return year + "-" + get_month(month) + "-0" + day[0];
  }
  inline string get_month(string& s) {
    if (s == "Jan")
      return "01";
    else if (s == "Feb")
      return "02";
    else if (s == "Mar")
      return "03";
    else if (s == "Apr")
      return "04";
    else if (s == "May")
      return "05";
    else if (s == "Jun")
      return "06";
    else if (s == "Jul")
      return "07";
    else if (s == "Aug")
      return "08";
    else if (s == "Sep")
      return "09";
    else if (s == "Oct")
      return "10";
    else if (s == "Nov")
      return "11";
    else
      return "12";
  }
};
