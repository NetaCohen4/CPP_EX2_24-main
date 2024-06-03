/*
    325195774
    netaco432@gmail.com
*/

// Graph.cpp

#include <iostream>
#include "Graph.hpp"
#include <queue>
#include <vector>
#include <stdexcept>
#include <iomanip>

namespace ariel {

    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        os << "Printing Graph . . .\n";
        for (size_t i = 0; i < graph.n; i++) {
            for (size_t j = 0; j < graph.n; j++) {
                os << std::setw(2) << graph.graph[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    void Graph::operator=(const Graph& other) {
        this->graph = other.graph;
        this->n = other.n;
    }

    Graph Graph::operator+(const Graph& other) const {
        if (this->n != other.n) {
            throw std::invalid_argument("Attempt of combining two different sized graphs");
        }
        
        vector<vector<int>> combination = this->graph;
        for (size_t i = 0; i < this->n; i++) {
            for (size_t j = 0; j < this->n; j++) {
                combination[i][j] += other.graph[i][j];
            }
        }
        Graph result;
        result.loadGraph(combination);
        result.n = this->n;
        return result;
    }

    void Graph::operator+=(const Graph& other) {

        (*this) = (*this) + other;
    }

    Graph Graph::operator-(const Graph& other) const {
        if (this->n != other.n) {
            throw std::invalid_argument("Attempt of subtracting two different sized graphs");
        }
        
        vector<vector<int>> subtraction = this->graph;
        for (size_t i = 0; i < this->n; i++) {
            for (size_t j = 0; j < this->n; j++) {
                subtraction[i][j] -= other.graph[i][j];
            }
        }
        Graph result;
        result.loadGraph(subtraction);
        result.n = this->n;
        return result;
    }

    void Graph::operator-=(const Graph& other) {
        
        (*this) = (*this) - other;
    }

    Graph Graph::operator*(const Graph& other) const {
        if (this->n != other.n) {
            throw std::invalid_argument("Attempt of multiple two different sized graphs");
        }
        Graph result;
        vector<vector<int>> multiple(this->n, vector<int>(this->n, 0));
        // Perform matrix multiplication
        for (size_t i = 0; i < this->n; ++i) {
            for (size_t j = 0; j < this->n; ++j) {
                for (size_t k = 0; k < this->n; ++k) {
                    multiple[i][j] += this->graph[i][k] * other.graph[k][j];
                }
            }
        }
        result.loadGraph(multiple);
        return result;
    }

    Graph Graph::operator*(int scalar) {
        Graph g = *this;
        for (size_t i = 0; i < this->n; i++) {
            for (size_t j =0; j < this->n; j++) {
                g.graph[i][j] *= scalar;
            }
        }
        return g;
    }

    void Graph::operator*=(int scalar) {
        
        (*this) = (*this) * scalar;
    }

    Graph Graph::operator+() {
        return *this;
    }

    Graph Graph::operator-() const{
        Graph g = *this;
        g *= (-1);
        return g;
    }

    // Pre-increment
    Graph& Graph::operator++() {
        for (size_t i = 0; i < this->n; i++) {
            for (size_t j = 0; j < this->n; j++) {
                if (this->graph[i][j]) {
                    (this->graph[i][j])++;
                }
            }
        }
        return *this;
    }

    // Post-increment
    Graph Graph::operator++(int) { 
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    // Pre-subtraction
    Graph& Graph::operator--() { 
        for (size_t i = 0; i < this->n; i++) {
            for (size_t j =0; j < this->n; j++) {
                if (this->graph[i][j]) {
                    (this->graph[i][j])--;
                }
            }
        }
        return *this;
    }

    // Post-subtraction
    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    bool Graph::operator==(const Graph& other) const {
        if (this->graph == other.graph)
            return true;
        if (!(this->graph > other.graph) && !(this->graph < other.graph))
            return true;
        return false;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator>(const Graph& other) const {

        if (this->graph == other.graph) {
            return false;
        }
        //בדיקת הכלה
        bool flag = true;
        if (other.n > this->n) {
            return false;
        }
        for (size_t i = 0; i < other.n; i++) {
            for (size_t j = 0; j < other.n; j++) {
                if (other.graph[i][j]) {
                    if (this->graph[i][j] != other.graph[i][j])
                        flag = false;
                }
                
            }
        }
        if (flag) {
            return true;
        }
        //בדיקת מספר צלעות
        if (this->get_num_of_edges() > other.get_num_of_edges()) {
            return true;
        }
        //בדיקת סדר גודל
        if (this->n > other.n) {
            return true;
        }
        return false;
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    bool Graph::operator<(const Graph& other) const {
        return (other > *this);
    }

    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }

    


    // Graphs Algorithms

    bool Graph::is_BFS_cover_all(size_t start) {

        std::vector<bool> visited(n, false);
        std::queue<int> queue;

        // Start BFS from the start vertex
        queue.push(start);
        visited[start] = true;

        while (!queue.empty()) {
            size_t currentVertex = (size_t)queue.front();
            queue.pop();

            // Visit all adjacent vertices
            for (size_t neighbor = 0; neighbor < n; neighbor++) {
                if (graph[currentVertex][neighbor])
                {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.push(neighbor);
                    }
                }
            }
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }

    vector<int> Graph::dijkstra(size_t start, vector<size_t>& parent) {

        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap for maintaining shortest distances

        parent[start] = start;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            size_t u = (size_t)pq.top().second;
            pq.pop();
            if (visited[u]) continue;
            visited[u] = true;

            for (size_t v = 0; v < n; ++v) {
                if (graph[u][v] != 0) {
                    int alt = dist[u] + graph[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        parent[v] = u; // Update predecessor of v
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        return dist;
    }


    bool Graph::dfs(size_t node, vector<bool>& visited, vector<size_t>& parent, string& cycle) {
        visited[node] = true;
        for (size_t i = 0; i < n; i++) {
            if (graph[node][i]) {
                if (visited[i]) {
                    if (i != parent[node]) {
                        size_t cur = node;
                        cycle = to_string(i);
                        while (cur != i) {
                            cycle = to_string(cur) + "->" + cycle;
                            cur = parent[cur];
                        }
                        cycle = to_string(i) + "->" + cycle;
                        return true;
                    }
                }
                else {
                    parent[i] = node;
                    if (dfs(i, visited, parent, cycle)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool Graph::Bellman_Ford_Negative_Cycle() {
        vector<int> dist(n, INF);

        // 0 as the source vertex
        dist[0] = 0;

        // Relax all edges |V| - 1 times
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t u = 0; u < n; ++u) {
                for (size_t v = 0; v < graph[u].size(); ++v) {
                    if (graph[u][v] != 0) { // 0 represents absence of edge
                        if (dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph[u][v];
                        }
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < graph[u].size(); ++v) {
                if (graph[u][v] != 0) { // 0 represents absence of edge
                    if (dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                        return true; // Negative cycle detected
                    }
                }
            }
        }

        return false; // No negative cycle detected
    }

    bool Graph::isBipartite() {

        vector<int> color(n, -1); // Initialize colors (-1: not colored, 0: color 1, 1: color 2)
        queue<size_t> q;

        for (size_t start = 0; start < n; ++start) {
            if (color[start] == -1) {
                color[start] = 0; // Assign color 1 to start node
                q.push(start);

                while (!q.empty()) {
                    size_t u = q.front();
                    q.pop();

                    for (size_t v = 0; v < n; ++v) {
                        if (graph[u][v] == 0) {
                            continue; // No edge between u and v
                        }

                        if (color[v] == -1) {
                            color[v] = 1 - color[u]; // Assign opposite color to neighbor v
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; // Found an edge between nodes of the same color (not bipartite)
                        }
                    }
                }
            }
        }

        return true; // All nodes are colored without conflicts (bipartite)
    }

}