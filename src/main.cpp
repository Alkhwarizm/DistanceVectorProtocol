#include <iostream>
using namespace std;

// Structs
struct Node {
    int id;
    int* neighbors;
    int** routeTable;
    int neighborCounter;
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
void printRouteTable(int** rt);
Node searchNode(int idNode);
void setEdges();
void connectNodes(Node node1, Node node2);
void addNeighbor(Node nodeCurrent, Node nodeNeighbor);
void updateRouteTable(int** rt, int nodeID, int distance, int nextHop);
void readScenarioCount();
void readAndExecuteScenarios();

// Main
int main() {
    readNodeAndEdgeCount();
    initializeNodes();
    printTest();
    setEdges();
    for (int i=0;i<nodeCount;i++) {
        printRouteTable(nodes[i].routeTable);
        cout<<endl;
    }
    readAndExecuteScenarios();
    for (int i=0;i<nodeCount;i++) {
        printRouteTable(nodes[i].routeTable);
        cout<<endl;
    }
    return 0;
}

// Function Implementaion
void readNodeAndEdgeCount() {
    cin >> nodeCount;
    cin >> edgeCount;
}

void initializeNodes(){
    nodes = new Node[nodeCount];
    for (int i = 0; i < nodeCount; ++i) {
        nodes[i].id = i+1;
        nodes[i].neighbors = new int[nodeCount];
        nodes[i].routeTable = new int*[nodeCount];
        nodes[i].neighborCounter = 0;
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

void printRouteTable(int** rt) {
    for (int i = 0; i < nodeCount ; ++i) {
        cout << rt[i][0] << " " << rt[i][1] << endl;
    }
}

Node searchNode(int idNode) {
    int i = 0;
    while ((i < nodeCount) && (nodes[i].id!=idNode)) {
        i = i + 1;
    }
    return (nodes[i]);
}

void setEdges() {
    int nodeID1;
    int nodeID2;
    for (int i = 0; i < edgeCount; i++) {
        cin >> nodeID1;
        cin >> nodeID2;
        connectNodes(searchNode(nodeID1),searchNode(nodeID2));
    }
}

void connectNodes(Node node1, Node node2) {
    addNeighbor(node1,node2);
    addNeighbor(node2,node1);
}

void addNeighbor(Node nodeCurrent, Node nodeNeighbor) {
    nodeCurrent.neighbors[nodeCurrent.neighborCounter] = nodeNeighbor.id;
    nodeCurrent.neighborCounter = nodeCurrent.neighborCounter + 1;
    updateRouteTable(nodeCurrent.routeTable, nodeNeighbor.id,1,nodeNeighbor.id);
}

void updateRouteTable(int** rt, int nodeID, int distance, int nextHop) {
    rt[nodeID-1][0] = distance;
    rt[nodeID-1][1] = nextHop;
}

void readScenarioCount() {
    cin >> scenarioCount;
}

void readAndExecuteScenarios() {
    int fromNodeIdx;
    int toNodeIdx;
    for (int i = 0; i < scenarioCount; i++) {
        cin >> fromNodeIdx;
        cin >> toNodeIdx;
        shareInformation(fromNodeIdx,toNodeIdx);
    }
}

void shareInformation(int fromNodeIdx, int toNodeIdx) {
    int** routeInformation = nodes[fromNodeIdx].routeTable;
    for (int i = 0; i<nodeCount;i++) {
        if ((i+1 != nodes[toNodeIdx].id) && (!nodes[toNodeIdx].isNeighbor(nodes[i])) && (routeInformation[i][0] > 0)) {
            if ((nodes[toNodeIdx].routeTable[i][0] == -1) || (routeInformation[i][0]+1 < nodes[toNodeIdx].routeTable[i][0])) {
                nodes[toNodeIdx].updateRouteTable(i+1,routeInformation[i][0]+1,fromNodeIdx+1);
            }
        }
    }
}

bool isNeighbor(Node currentNode, Node nodeCheck) {
    int i;
    i = 0;
    while ((i<nodeCount) && (currentNode.neighbors[i] == nodeCheck.id)) {
        i = i + 1;
    }
    return (currentNode.neighbors[i] == nodeCheck.id);
}