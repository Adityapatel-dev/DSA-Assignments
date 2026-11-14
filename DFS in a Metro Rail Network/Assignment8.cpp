#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool dfs(
    string current,
    string destination,
    map<string, vector<string>>& graph,
    set<string>& visited,
    vector<string>& path
) {
    visited.insert(current);
    path.push_back(current);

if (current == destination) {
        return true;
    }

for (string neighbour : graph[current]) {
        if (visited.find(neighbour) == visited.end()) {
            if (dfs(neighbour, destination, graph, visited, path)) {
                return true;
            }
        }
    }

path.pop_back();
    return false;
}

int main() {
    map<string, vector<string>> metro;

metro["A"] = {"B", "C"};
    metro["B"] = {"A", "D"};
    metro["C"] = {"A", "E"};
    metro["D"] = {"B", "F"};
    metro["E"] = {"C", "F"};
    metro["F"] = {"D", "E"};

string source, destination;

cout << "Enter source station: ";
    cin >> source;

cout << "Enter destination station: ";
    cin >> destination;

set<string> visited;
    vector<string> path;

if (dfs(source, destination, metro, visited, path)) {
        cout << "Path found using DFS: ";

for (string station : path) {
            cout << station << " ";
        }

cout << endl;
    } else {
        cout << "No path found.\n";
    }

return 0;
}
