#include <vector>

class Solution {
  public:
    int minNumberOfHours(int initialEnergy, int initialExperience,
                         std::vector<int> &energy,
                         std::vector<int> &experience) {
        int res = 0;
        for (int i = 0; i < energy.size(); i++) {
            if (energy[i] >= initialEnergy) {
                res += energy[i] - initialEnergy + 1;
                initialEnergy += energy[i] - initialEnergy + 1;
            }

            if (experience[i] >= initialExperience) {
                res += experience[i] - initialExperience + 1;
                initialExperience += experience[i] - initialExperience + 1;
            }

            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return res;
    }
};
