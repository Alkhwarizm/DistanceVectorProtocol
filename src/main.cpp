#include <iostream>
using namespace std;

// Structs
struct Node {
    int id;
    int* neighbors;
    int** routeTable
};

// Global Variable
int nodeCount;
int edgeCount;
int scenarioCount;

Node* nodes;

// Function Declaration
void readNodeAndEdgeCount();
void printTest();
void initializeNodes();
void printRouteTable(int** rt, int node);

// Main
int main() {
    readNodeAndEdgeCount();
    initializeNodes();

    printTest();
    printRouteTable();
    return 0;
}


// Function Implementaion
void readNodeAndEdgeCount(){
    cin >> nodeCount;
    cin >> edgeCount;
}

void initializeNodes(){
    nodes = new Node[nodeCount];
    for (int i = 0; i < nodeCount; ++i) {
        nodes[i].id = i+1;
        nodes[i].routeTable = new int*[nodeCount];
        for (int j = 0; j < nodeCount; ++j) {
            nodes[i].routeTable[j] = new int[2];
            if (i == j) {
                nodes[i].routeTable[j][0] = 0;
                nodes[i].routeTable[j][1] = nodes[i].id;
            } else {
                nodes[i].routeTable[j][0] = -1;
                nodes[i].routeTable[j][1] = -1;
            }
        }
    }
}

void printTest() {
    cout << "Nodes: " << nodeCount << endl;
    cout << "Edges: " << edgeCount << endl;
}

void printRouteTable(int** rt, int node) {
    for (int i = 0; i < nodeCount ; ++i) {
        
    }
}
