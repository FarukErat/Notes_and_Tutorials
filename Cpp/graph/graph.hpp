#pragma once
#ifndef GRAPH
#define GRAPH

#include <iostream>
#include "DLList.hpp"
#include <unordered_map>

using namespace std;

// Class for a graph node
template<typename T>
class GraphNode {
public:
    string label;
    T value;
    DLList<pair<GraphNode<T>*, T>> neighbors; // stores neighboring nodes and their edge weights

    GraphNode(string l, T v) {
        label = l;
        value = v;
    }
};

// Class for a graph
template<typename T>
class Graph {
public:
    unordered_map<string, GraphNode<T>*> nodes; // maps labels to nodes
    bool directed;
    bool weighted;

    Graph(bool d, bool w) {
        directed = d;
        weighted = w;
    }

    // Add a node to the graph
    void addNode(string label, T value) {
        GraphNode<T>* node = new GraphNode<T>(label, value);
        nodes[label] = node;
    }

    // Add an edge between two nodes in the graph
    void addEdge(string u, string v, T weight) {
        GraphNode<T>* nodeU = getNode(u);
        GraphNode<T>* nodeV = getNode(v);
        if (nodeU && nodeV) {
            nodeU->neighbors.append(make_pair(nodeV, weight));
            if (!directed) {
                nodeV->neighbors.append(make_pair(nodeU, weight));
            }
        }
    }

    // Get the node with a given label from the graph
    GraphNode<T>* getNode(string label) {
        if (nodes.count(label)) {
            return nodes[label];
        }
        return nullptr;
    }

    // Get the number of nodes in the graph
    int size() {
        return nodes.size();
    }

    // Get the number of edges in the graph
    int numEdges() {
        int count = 0;
        for (auto& p : nodes) {
            count += p.second->neighbors.getSize();
        }
        if (!directed) {
            count /= 2; // divide by 2 for undirected graphs
        }
        return count;
    }

    // Check if the graph is connected
    bool isConnected() {
        if (nodes.empty()) {
            return true; // empty graph is connected by definition
        }
        unordered_map<string, bool> visited;
        for (auto& p : nodes) {
            visited[p.first] = false;
        }
        dfs(nodes.begin()->first, visited);
        for (auto& p : visited) {
            if (!p.second) {
                return false; // if any node was not visited, graph is disconnected
            }
        }
        return true;
    }

    // Get the density of the graph
    double density() {
        int numNodes = nodes.size();
        int numPossibleEdges = numNodes * (numNodes - 1);
        if (!directed) {
            numPossibleEdges /= 2; // divide by 2 for undirected graphs
        }
        if (numPossibleEdges == 0) {
            return 0; // prevent divide by zero error
        }
        return (double)numEdges() / numPossibleEdges;
    }

    // Get the clustering coefficient of the graph
    double clustering() {
        double sum = 0;
        for (auto& p : nodes) {
            GraphNode<T>* node = p.second;
            int numNeighbors = node->neighbors.getSize();
            if (numNeighbors >= 2) {
                int numEdges = 0;
                for (auto& n : node->neighbors) {
                    for (auto& m : n.first->neighbors) {
                        if (m.first->label == node->label) { // check if the neighboring node is the same as the current node
                            continue;
                        }
                        for (auto& k : node->neighbors) {
                            if (k.first->label == m.first->label) { // check if the neighboring node of the neighboring node is the same as the current node
                                numEdges++; // increment edge count
                            }
                        }
                    }
                }
                double denom = (numNeighbors * (numNeighbors - 1)) / 2.0;
                sum += (denom == 0 ? 0 : (double)numEdges / denom);
            }
        }
        return sum / nodes.size();
    }

private:
    // Depth-first search for checking connectivity
    void dfs(string label, unordered_map<string, bool>& visited) {
        visited[label] = true;
        GraphNode<T>* node = getNode(label);
        for (auto& n : node->neighbors) {
            if (!visited[n.first->label]) {
                dfs(n.first->label, visited);
            }
        }
    }
};

#endif // GRAPH
