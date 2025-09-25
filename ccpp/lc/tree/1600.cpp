#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class ThroneInheritance {
  public:
    ThroneInheritance(std::string kingName) {
        this->kingName = kingName;
    }

    void birth(std::string parentName, std::string childName) {
        children[parentName].push_back(childName);
    }

    void death(std::string name) {
        deaths.insert(name);
    }

    std::vector<std::string> getInheritanceOrder() {
        std::vector<std::string> res;
        this->dfs(this->kingName, res);
        return res;
    }

  private:
    std::string kingName;
    std::unordered_map<std::string, std::vector<std::string>> children;
    std::unordered_set<std::string> deaths;

    void dfs(std::string curr, std::vector<std::string> &order) {
        if (!deaths.count(curr)) order.push_back(curr);
        for (std::string &child : children[curr]) dfs(child, order);
    }
};
