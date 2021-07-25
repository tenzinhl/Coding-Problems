#include <bits/stdc++.h>
using namespace std;

typedef struct person {
  string name;
  int projects;
  int tasks;
} person;

static bool MyComparison(const person& a, const person& b) {
  if (a.tasks < b.tasks) {
    return true;
  } else if (b.tasks < a.tasks) {
    return false;
  } else {
    if (a.projects < b.projects) {
      return true;
    } else {
      return false;
    }
  }
}

string smartAssigning(vector<string> names, vector<bool> statuses, vector<int> projects, vector<int> tasks) {
  vector<person> people;
  for (int i = 0; i < names.size(); i++) {
    if (statuses[i] == true) {
      continue;
    }
    person temp;
    temp.name = names[i];
    temp.projects = projects[i];
    temp.tasks = tasks[i];
    people.push_back(temp);
  }
  sort(people.begin(), people.end(), MyComparison);
  return people[0].name;
}

int main() {
	return 0;
}
