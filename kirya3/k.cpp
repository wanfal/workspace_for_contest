#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <climits>

int main()
{
    std::string pathStr;
    std::cin >> pathStr;
    int maxOffset = 201;
    int size = maxOffset*2;
    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
    std::vector<std::vector<std::set<std::pair<int,int>>>> neighs(size, std::vector<std::set<std::pair<int,int>>>(size));

    std::pair<int, int> start = {maxOffset, maxOffset};
    std::pair<int, int> curr = start;
    std::pair<int, int> prev;
    visited[start.first][start.second] = true;
    for(int i=0;i<pathStr.size();i++){
        char dir = pathStr[i];
        prev = curr;
        if(dir=='N') curr.second++;
        else if(dir=='S') curr.second--;
        else if(dir=='W') curr.first--;
        else if(dir=='E') curr.first++;
        visited[curr.first][curr.second] = true;
        neighs[prev.first][prev.second].insert(curr);
        neighs[curr.first][curr.second].insert(prev);
    }
    std::pair<int, int> end = curr;
    
    long long inf = LLONG_MAX/2;
    std::vector<std::vector<long long>> dist(size, std::vector<long long>(size, inf));
    std::queue<std::pair<int,int>> q;

    dist[end.first][end.second] = 0;
    q.push(end);

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    char dirs[4] = {'N', 'E', 'S', 'W'};
    int nx, ny;
    bool isTupik, isEnd, isStart;
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();

        for(int d=0;d<4;d++){
            nx = cx + dx[d];
            ny = cy + dy[d];
            if(nx<0 || nx>=size || ny<0 || ny>=size) continue;
            if(neighs[cx][cy].count({nx, ny}) == 0) continue;

            isStart = (nx == start.first  && ny == start.second);
            isEnd = (nx == end.first && ny == end.second);
            isTupik = neighs[nx][ny].size()==1 && !isStart && !isEnd;
            if(dist[nx][ny]!=inf || isTupik) continue;

            dist[nx][ny] = dist[cx][cy]+1;
            q.push({nx, ny});
        }
    }

    std::string answer;
    int currX = end.first, currY = end.second;

    while(!(currX==start.first && currY==start.second)){
        for(int d=0;d<4;d++){
            nx = currX + dx[d];
            ny = currY + dy[d];
            if(nx<0 || nx>=size || ny<0 || ny>=size) continue;
            if(neighs[currX][currY].count({nx, ny})==0) continue;
            if(dist[nx][ny] == dist[currX][currY]+1){
                answer += dirs[d];
                currX = nx;
                currY = ny;
                break;
            }
        }
    }

    std::cout << answer << '\n';
    return 0;
}
