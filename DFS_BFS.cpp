#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int curNode, vector<vector<int>> &path, vector<bool> &visit){
    printf("%d ", curNode);
    visit[curNode] = true;
    for (int i = 0; i < path[curNode].size(); i++){
        if (!visit[path[curNode][i]]) DFS(path[curNode][i], path, visit);
    }
}

void DFS_settig(int Node_count, int start, vector<vector<int>> &path){
    vector<bool> visit(Node_count, 0);
    visit[start] = true;

    cout << "DFS: ";
    DFS(start, path, visit);
    cout << "\n";
}

void BFS(int Node_count, int start, vector<vector<int>> &path){
    queue<int> q;
    q.push(start);
    
    vector<bool> visit(Node_count, 0);
    visit[start] = true;

    cout << "BFS: ";
    int curNode = start;
    while(!q.empty()){
        curNode = q.front(); q.pop();
        visit[curNode] = true;
        printf("%d ", curNode);

        for (int i = 0; i < path[curNode].size(); i++){
            if(!visit[path[curNode][i]]){
                q.push(path[curNode][i]);
                visit[path[curNode][i]] = true;
            }
        }
    }
    cout << "\n";
}

int main(){
    int Node_count, path_count, start;
    cin >> Node_count >> path_count >> start;
    
    vector<vector<int>> path(Node_count, vector<int>(0, 0));
    
    int a, b;
    for (int i = 0; i < path_count; i++){
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    
    DFS_settig(Node_count, start, path);
    BFS(Node_count, start, path);
}