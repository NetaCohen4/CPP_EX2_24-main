/*
    325195774
    netaco432@gmail.com
*/

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

namespace ariel {

    // Overload the output operator to print the matrix of the graph
    ostream& operator<<(ostream& os, const Graph& graph) {
        const auto& matrix = graph.graph;
        for (const auto& row : matrix) {
            os << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                os << row[i];
                if (i != row.size() - 1) {
                    os << ", ";
                }
            }
            os << "]\n";
        }
        return os;
    }

    // Overload the addition operator to add two graphs together
    Graph operator+(const Graph& lhs, const Graph& rhs) {
        Graph result;
        const auto& lhsMatrix = lhs.graph;
        const auto& rhsMatrix = rhs.graph;
        if (lhsMatrix.size() != rhsMatrix.size() || lhsMatrix[0].size() != rhsMatrix[0].size()) {
            throw std::invalid_argument("Graphs must have the same dimensions for addition.");
        }
        result.graph.resize(lhsMatrix.size(), vector<int>(lhsMatrix[0].size(), 0));
        for (size_t i = 0; i < lhsMatrix.size(); ++i) {
            for (size_t j = 0; j < lhsMatrix[0].size(); ++j) {
                result.graph[i][j] = lhsMatrix[i][j] + rhsMatrix[i][j];
            }
        }
        return result;
    }

    // Overload the multiplication operator to multiply two graphs together
    Graph operator*(const Graph& lhs, const Graph& rhs) {
        const auto& lhsMatrix = lhs.graph;
        const auto& rhsMatrix = rhs.graph;
        if (lhsMatrix[0].size() != rhsMatrix.size()) {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        Graph result;
        result.graph.resize(lhsMatrix.size(), vector<int>(rhsMatrix[0].size(), 0));
        for (size_t i = 0; i < lhsMatrix.size(); ++i) {
            for (size_t j = 0; j < rhsMatrix[0].size(); ++j) {
                for (size_t k = 0; k < lhsMatrix[0].size(); ++k) {
                    result.graph[i][j] += lhsMatrix[i][k] * rhsMatrix[k][j];
                }
            }
        }
        return result;
    }

    // Overload the multiplication operator to scale a graph by a scalar
    Graph operator*(const Graph& graph, int scalar) {
        Graph result = graph;
        for (auto& row : result.graph) {
            for (auto& value : row) {
                value *= scalar;
            }
        }
        return result;
    }

    // Overload the multiplication operator to scale a graph by a scalar (reverse order)
    Graph operator*(int scalar, const Graph& graph) {
        return graph * scalar;
    }

    // Overload the division operator to scale a graph by a scalar
    Graph operator/(const Graph& graph, int scalar) {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        Graph result = graph;
        for (auto& row : result.graph) {
            for (auto& value : row) {
                value /= scalar;
            }
        }
        return result;
    }

}
