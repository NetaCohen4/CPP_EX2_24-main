/*
    325195774
    netaco432@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph g4;
    g4.loadGraph(expectedGraph);
    CHECK((g3 == g4) == true);
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph g4;
    g4.loadGraph(expectedGraph);

    CHECK((g4 == g3) == true);
}


TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}


TEST_CASE("Test =")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    g2 = g1;
    CHECK((g1 == g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph3);
    g3 = g2;
    CHECK((g1 == g3) == true);

}

TEST_CASE("Test +")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3;
    vector<vector<int>> resultGraph = {
        {1, 2, 1},
        {2, 1, 2},
        {0, 1, 0}};
    g3.loadGraph(resultGraph);

    CHECK(((g1 + g2) == g3)  == true);
}

TEST_CASE("Test +=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    g1 += g2;
    ariel::Graph g3;
    vector<vector<int>> resultGraph = {
        {1, 2, 1},
        {2, 1, 2},
        {0, 1, 0}};
    g3.loadGraph(resultGraph);

    CHECK((g1 == g3)  == true);
}

TEST_CASE("Test -")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3;
    vector<vector<int>> resultGraph = {
        {-1, 0, -1},
        {0, -1, 0},
        {0, 1, 0}};
    g3.loadGraph(resultGraph);

    CHECK(((g1 - g2) == g3) == true);
}

TEST_CASE("Test -=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);
    g1 -= g2;
    ariel::Graph g3;
    vector<vector<int>> resultGraph = {
        {-1, 0, -1},
        {0, -1, 0},
        {0, 1, 0}};
    g3.loadGraph(resultGraph);

    CHECK((g1 == g3) == true);
}

TEST_CASE("Test ==")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph1);
    CHECK((g1 == g1) == true);
    
    ariel::Graph g2;
    g2.loadGraph(graph1);
    CHECK((g1 == g2) == true);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph3);
    CHECK((g1 == g3) == false);
}

TEST_CASE("Test !=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(graph1);
    CHECK((g1 != g1) == false);
    
    ariel::Graph g2;
    g2.loadGraph(graph1);
    CHECK((g1 != g2) == false);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph3);
    CHECK((g1 != g3) == true);
}

TEST_CASE("Test >")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);

    CHECK((g1 > g2) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph3);

    CHECK((g1 > g2) == true);

    CHECK((g1 > g1) == false);
}

TEST_CASE("Test >=")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};
    g2.loadGraph(graph2);

    CHECK((g1 >= g2) == false);

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 0, 0}};
    g2.loadGraph(graph3);

    CHECK((g1 >= g2) == true);

    CHECK((g1 >= g1) == true);
}

TEST_CASE("Test <")
{
    
}

TEST_CASE("Test <=")
{
    
}

TEST_CASE("Test ++")
{
    
}

TEST_CASE("Test --")
{
    
}

TEST_CASE("Test - (unar)")
{
    
}

TEST_CASE("Test * (by scalar)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 = g1 * 3;

    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    ariel::Graph g2;
    g2.loadGraph(expectedGraph);
    CHECK((g1 == g2) == true);

    CHECK_THROWS(g1 * 0);
}

TEST_CASE("Test *= (by scalar)")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    g1 *= 3;

    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    ariel::Graph g2;
    g2.loadGraph(expectedGraph);
    CHECK((g1 == g2) == true);

    CHECK_THROWS(g1 *= 0);
}

TEST_CASE("Test * (Graph * Graph)")
{
    
}
