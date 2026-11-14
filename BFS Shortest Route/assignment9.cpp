#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    map<string, vector<string>> roads;

roads["Home"] = {"Market", "School"};
    roads["Market"] = {"Home", "Office"};
    roads["School"] = {"Home", "Office"};
    roads["Office"] = {"Market", "School", "Mall"};
    roads["Mall"] = {"Office"};

string source, destination;

cout << "Enter starting location: ";
    cin >> source;

cout << "Enter destination: ";
    cin >> destination;

queue<string> q;
    set<string> visited;
    map<string, string> parent;

q.push(source);
    visited.insert(source);

while (!q.empty()) {
        string current = q.front();
        q.pop();

for (string neighbour : roads[current]) {
            if (visited.find(neighbour) == visited.end()) {
                visited.insert(neighbour);
                parent[neighbour] = current;
                q.push(neighbour);
            }
        }
    }

if (visited.find(destination) == visited.end()) {
        cout << "No route found.\n";
        return 0;
    }

vector<string> route;
    string current = destination;

while (current != source) {
        route.push_back(current);
        current = parent[current];
    }

route.push_back(source);
    reverse(route.begin(), route.end());

cout << "Shortest route: ";

for (string location : route) {
        cout << location << " ";
    }

cout << "\nNumber of edges: " << route.size() - 1 << endl;

return 0;
}
