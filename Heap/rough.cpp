class Solution: 
    def findMaximumScore(self, nums: List[int]) -> int: 
        n = len(nums) 
        ans = 0 
        last_index = 0 
        l = nums[0] 
 
        for i in range(1, n): 
            if nums[i] > l: 
                ans += l * (i - last_index) 
                l = nums[i] 
                last_index = i 
 
        ans += l * (n - 1 - last_index) 
        return ans
third answer

from collections import deque 
 
class Solution: 
    def maxMoves(self, kx, ky, positions): 
        self.DIRECTIONS = [(2, 1), (2, -1), (-2, 1), (-2, -1), 
                           (1, 2), (1, -2), (-1, 2), (-1, -2)] 
        self.numPawns = len(positions) 
        self.memo = [[-1] * (1 << self.numPawns) for _ in range(self.numPawns + 1)] 
        self.dist = [[0] * (self.numPawns + 1) for _ in range(self.numPawns + 1)] 
        self.distances(kx, ky, positions) 
        return self.maxx(0, positions, 0, True) 
 
    def distances(self, kx, ky, positions): 
        for i in range(self.numPawns): 
            self.dist[0][i + 1] = self.bfs(kx, ky, positions[i][0], positions[i][1]) 
            self.dist[i + 1][0] = self.dist[0][i + 1] 
 
        for i in range(self.numPawns): 
            for j in range(i + 1, self.numPawns): 
                d = self.bfs(positions[i][0], positions[i][1], positions[j][0], positions[j][1]) 
                self.dist[i + 1][j + 1] = d 
                self.dist[j + 1][i + 1] = d 
 
    def maxx(self, knightPos, positions, capturedMask, isAliceTurn): 
        if self.memo[knightPos][capturedMask] != -1: 
            return self.memo[knightPos][capturedMask] 
         
        bestMoves = float('-inf') if isAliceTurn else float('inf') 
        anyMovePossible = False 
         
        for i in range(self.numPawns): 
            if capturedMask & (1 << i): 
                continue 
             
            anyMovePossible = True 
            newMask = capturedMask | (1 << i) 
            moves = self.dist[knightPos][i + 1] 
            nextMoves = self.maxx(i + 1, positions, newMask, not isAliceTurn) 
             
            if isAliceTurn: 
                bestMoves = max(bestMoves, moves + nextMoves) 
            else: 
                bestMoves = min(bestMoves, moves + nextMoves) 
         
        if not anyMovePossible: 
            return 0 
         
        self.memo[knightPos][capturedMask] = bestMoves 
        return bestMoves 
 
    def bfs(self, kx, ky, tx, ty): 
        if kx == tx and ky == ty: 
            return 0 
         
        queue = deque([(kx, ky, 0)]) 
        visited = [[False] * 50 for _ in range(50)] 
        visited[kx][ky] = True 
         
        while queue: 
            x, y, moves = queue.popleft() 
            for dx, dy in self.DIRECTIONS: 
                nx, ny = x + dx, y + dy 
                if nx == tx and ny == ty: 
                    return moves + 1 
                if 0 <= nx < 50 and 0 <= ny < 50 and not visited[nx][ny]: 
                    visited[nx][ny] = True 
                    queue.append((nx, ny, moves + 1)) 
         
        return -1 