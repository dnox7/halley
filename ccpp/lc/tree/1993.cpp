#include <queue>
#include <vector>

class LockingTree {
  private:
    std::vector<int> parent;
    std::vector<std::vector<int>> adj;
    std::vector<int> locked;

  public:
    LockingTree(std::vector<int> &parent) {
        this->parent = parent;
        int n = parent.size();
        locked.resize(n);
        adj.resize(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) adj[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (locked[num] != 0) return false;
        locked[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (locked[num] != user) return false;
        locked[num] = 0;
        return true;
    }

    bool upgrade(int num, int user) {
        int ancestor = num;
        while (ancestor != -1) {
            if (locked[ancestor] != 0) return false;
            ancestor = this->parent[ancestor];
        }

        bool isUpgradable = false;
        std::queue<int> q;
        q.push(num);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int curr = q.front();
                q.pop();
                if (curr != num && locked[curr] != 0) {
                    isUpgradable = true;
                }
                locked[curr] = 0;
                for (int child : adj[curr]) q.push(child);
            }
        }

        if (isUpgradable) {
            locked[num] = user;
            return true;
        }
        return false;
    }
};
