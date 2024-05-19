/*
    325195774
    netaco432@gmail.com
*/

// Graph.hpp

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

const int INF = std::numeric_limits<int>::max(); // Infinity for dijkstra

namespace ariel {

    class Graph {
    private:

        vector<vector<int>> graph;
        size_t n;

    public:
        // Constructor
        Graph(){}

        // Destructor
        ~Graph(){}

        size_t getSize() {
            return n;
        }

        // Function to load graph data from file
        void loadGraph(std::vector<std::vector<int>> matrix) {
            size_t numRows = matrix.size();
            if (numRows == 0) // If the matrix has no rows, it's not a square matrix
                throw std::invalid_argument("Invalid graph: Empty matrix"); // Throw an exception if the matrix is empty
            size_t numCols = matrix[0].size(); // Assuming all rows have same number of columns
            if (numRows != numCols)
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            for (size_t i = 0; (i < numRows) && (i<numCols); i++) {
                //if (graph[i][i]) {
                //    throw std::invalid_argument("Invalid graph: A vertex can't have an edge to itself.");
                //}
            }
            graph = matrix;
            n = graph.size();
            
        }

        // Function to print the graph
        void printGraph(){
            int e_count = 0;
            for (const auto& row : graph) {
                for (int value : row) {
                    if (value != 0) {
                        e_count++;
                    }
                }
            }
            std::cout << "Graph with " <<  graph.size() << " vertices and " << e_count << " edges.\n";
        }

        // Operator functions:
        // Overload the output operator to print the matrix of the graph
        friend ostream& operator<<(ostream& os, const Graph& graph);

        void operator=(const Graph other);

        // Overload the addition operator to add two graphs together
        Graph operator+(const Graph& other) const;

        void operator+=(const Graph other) const;

        Graph operator-(const Graph& other) const;

        void operator-=(const Graph& other) const;

        // Pre-increment
        Graph& operator++();
        
        // Post-increment
        Graph operator++(int);

        // Pre-reduction
        Graph& operator--();
        
        // Post-reduction
        Graph operator--(int);

        Graph operator*(int);

        Graph operator*(const Graph& other) const;
/*
        // Overload the multiplication operator to multiply two graphs together
        friend Graph operator*(const Graph& lhs, const Graph& rhs);

        // Overload the multiplication operator to scale a graph by a scalar
        friend Graph operator*(const Graph& graph, int scalar);

        // Overload the multiplication operator to scale a graph by a scalar (reverse order)
        friend Graph operator*(int scalar, const Graph& graph);

        // Overload the division operator to scale a graph by a scalar
        friend Graph operator/(const Graph& graph, int scalar);

        // *= operator overload
        Graph& operator*=(int scalar) {
            for (auto& row : graph) {
                for (int& value : row) {
                    value *= scalar;
                }
            }
            return *this;
        }
        */


        bool is_BFS_cover_all(size_t start);

        vector<int> dijkstra(size_t start, vector<size_t>& predecessors);

        bool dfs(size_t node, vector<bool>& visited, vector<size_t>& parent, string& cycle);

        bool Bellman_Ford_Negative_Cycle();

        bool isBipartite();

    };

}


#endif // GRAPH_HPP