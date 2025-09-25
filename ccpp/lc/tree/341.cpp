#include <queue>
#include <vector>

class NestedInteger {
  public:
    bool isInteger() const;
    int getInteger() const;
    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator {
    std::queue<int> q;

  public:
    NestedIterator(std::vector<NestedInteger> &nestedList) {
        build(nestedList);
    }

    void build(const std::vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for (int i = 0; i < n; ++i) {
            if (nestedList[i].isInteger()) q.push(nestedList[i].getInteger());
            else build(nestedList[i].getList());
        }
    }

    int next() {
        int val = q.front();
        q.pop();
        return val;
    }

    bool hasNext() {
        return !q.empty();
    }
};
