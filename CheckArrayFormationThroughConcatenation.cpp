#include<vector>
using namespace std;

static class CheckArrayFormationThroughConcatenation {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        vector<int> pv(101, -1);
        for (int i = 0; i < pieces.size(); i++) {
            pv[pieces[i][0]] = i;
        }

        int ai,pj;
        ai = 0;

        while(ai < arr.size()) {
            int pi = pv[arr[ai]];
            pj = 0;
            if (pi == -1)
                return false;

            while (pj < pieces[pi].size()) {
                if (arr[ai++] != pieces[pi][pj++])
                    return false;
                
            }

        }
        return true;
    }
};