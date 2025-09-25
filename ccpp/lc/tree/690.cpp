#include <unordered_map>
#include <vector>

class Employee {
  public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

class Solution {
    std::unordered_map<int, std::pair<Employee *, int>> m;

  public:
    int getImportance(std::vector<Employee *> employees, int id) {
        for (const auto &e : employees) m[e->id] = {e, e->importance};
        solve(id);
        return m[id].second;
    }

    void solve(int id) {
        for (const int &subId : m[id].first->subordinates) {
            solve(subId);
            m[id].second += m[subId].second;
        }
    }
};
