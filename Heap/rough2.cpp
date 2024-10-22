#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
public:
    const vector<pair<int, int>> knightMoves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };

    int calculateDistance(int knightX, int knightY, int pawnX, int pawnY) {
        vector<vector<int>> distance(50, vector<int>(50, INT_MAX));
        queue<pair<int, int>> q;
        
        distance[knightX][knightY] = 0;
        q.push({knightX, knightY});
        
        while (!q.empty()) {
            auto [currentX, currentY] = q.front();
            q.pop();
            
            for (auto [dx, dy] : knightMoves) {
                int newX = currentX + dx, newY = currentY + dy;
                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && distance[newX][newY] == INT_MAX) {
                    distance[newX][newY] = distance[currentX][currentY] + 1;
                    q.push({newX, newY});
                }
            }
        }
        
        return distance[pawnX][pawnY];
    }

    int minimax(int knightX, int knightY, vector<pair<int, int>>& pawns, bool isAliceTurn) {
        if (pawns.empty()) return 0;

        MemoKey key = make_tuple(knightX, knightY, pawns);
        if (memo.find(key) != memo.end()) return memo[key];

        int bestResult = isAliceTurn ? INT_MIN : INT_MAX;

        for (int i = 0; i < pawns.size(); ++i) {
            auto [pawnX, pawnY] = pawns[i];
            
            int distance = calculateDistance(knightX, knightY, pawnX, pawnY);
            
            vector<pair<int, int>> remainingPawns = pawns;
            remainingPawns.erase(remainingPawns.begin() + i);
            
            int result = distance + minimax(pawnX, pawnY, remainingPawns, !isAliceTurn);
            
            if (isAliceTurn) {
                bestResult = max(bestResult, result);
            } else {
                bestResult = min(bestResult, result);
            }
        }

        memo[key] = bestResult;
        return bestResult;
    }

    int maxMoves(int knightX, int knightY, vector<vector<int>>& pawnPositions) {
        vector<pair<int, int>> pawns;
        for (const auto& pos : pawnPositions) {
            pawns.push_back({pos[0], pos[1]});
        }
        
        return minimax(knightX, knightY, pawns, true);
    }

private:
    // Define MemoKey as a tuple and ensure that it's hashable
    using MemoKey = tuple<int, int, vector<pair<int, int>>>;
    struct MemoKeyHash {
        size_t operator()(const MemoKey& key) const {
            auto [x, y, pawns] = key;
            size_t h = hash<int>{}(x) ^ hash<int>{}(y);
            for (const auto& p : pawns) {
                h ^= hash<int>{}(p.first) ^ hash<int>{}(p.second);
            }
            return h;
        }
    };
    unordered_map<MemoKey, int, MemoKeyHash> memo;
};

int main() {
    Solution solution;

    vector<vector<int>> pawnPositions = {{8, 3}, {1, 8}, {8, 10}, {6, 8}, {1, 5}};
    cout << "Maximum knight moves: " << solution.maxKnightMoves(0, 0, pawnPositions) << endl;

    return 0;
}
