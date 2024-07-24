#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort the cuts in descending order
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        
        int h = 0, v = 0;
        int hPieces = 1, vPieces = 1;
        int totalCost = 0;
        
        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] > verticalCut[v]) {
                totalCost += horizontalCut[h] * vPieces;
                hPieces++;
                h++;
            } else {
                totalCost += verticalCut[v] * hPieces;
                vPieces++;
                v++;
            }
        }
        
        
        while (h < horizontalCut.size()) {
            totalCost += horizontalCut[h] * vPieces;
            h++;
        }
        
        // Add remaining vertical cuts
        while (v < verticalCut.size()) {
            totalCost += verticalCut[v] * hPieces;
            v++;
        }
        
        return totalCost;
    }
}; 