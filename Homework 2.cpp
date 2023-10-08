#include <iostream>
#include <math.h>

#define INFINITY 999

using namespace std;

class Graph{

private:
	int adjMatrix[50][50]; 
	int predecessor[50], distance[50];
	bool mark[50];    //keep track of visited node
	int source;
	int V;//total number of vertices
	int density;
	int densityArray[30];

public:
	void readNodeInfo();

	void initialize();

	int unmarkedNode();
	
	void calcDist();
	
	void output();
	void printPath(int);
};


void Graph::readNodeInfo(){
	cout << "Enter the number of vertices of the graph (should be (0 - 50] ):\n";
	cin >> V;
	cout << "\nEnter the amount of node density (enter 20 for %20 and 40 for %40):\n";
	cin >> density;

	for (int i = 0; i < (int)round(V * density / 100); i++) {
		densityArray[i] = rand() % V;
	}
    
	cout << "\nThe costs for Edges are being generated randomly for a graph with " << V << " nodes.\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adjMatrix[i][j] = rand() % 10; //INFINITY;
			adjMatrix[j][i] = adjMatrix[i][j];

			if (*find(densityArray, densityArray + (int)round(V * density / 100), j) == j) {
				adjMatrix[i][j] = INFINITY;
				adjMatrix[j][i] = adjMatrix[i][j];
			}

			if (i == j) {
				adjMatrix[i][j] = 0;
			}
		}
	}

	// print out the generated cost matrix
	cout << "\nThe randomly generated edge cost matrix is:\n\n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// get the source vertex as input from the user
	cout << "\nEnter the source vertex (must be within [0 - " << V << ") ):\n";
	cin >> source;
	cout << endl;

	while ((source < 0) | (source > V - 1)) {
		cout << "Source vertex should be between 0 and " << V - 1 << endl;
		cout << "Enter the source vertex again\n";
		cin >> source;
		cout << endl;
	}

	cout << "The shortest paths (if existing) from the selected source to all other nodes are:\n";
	cout << "==========================================\n";
	cout << "Source" << "..Path" << "..Destination" << "->Total path cost\n";
	cout << "==========================================\n";
}


void Graph::initialize(){
	//
	// Function initialize initializes all the data members at the begining of
	// the execution. The distance between source to source is zero and all other
	// distances between source and vertices are infinity. The mark is initialized
	// to false and predecessor is initialized to -1


	for (int i = 0; i<V; i++) {
		mark[i] = false;
		predecessor[i] = -1;
		distance[i] = INFINITY;
	}
	distance[source] = 0;
}


int Graph::unmarkedNode(){
	//
	// Function unmarkedNode returns the node which is nearest from the
	// Predecessor marked node. If the node is alreadNodeInfoy marked as visited, then it search
	// for another node.
	//

	int minDistance = INFINITY;
	int closestUnmarkedNode;
	for (int i = 0; i<V; i++) {
		if ((!mark[i]) & (minDistance >= distance[i])) {
			minDistance = distance[i];
			closestUnmarkedNode = i;
		}
	}
	return closestUnmarkedNode;
}


void Graph::calcDist(){
	//
	// Function calcDist calculates the minimum distances from the source node to
	// Other nodes.
	//

	initialize();
	int minDistance = INFINITY;
	int closestUnmarkedNode;
	int count = 0;
	while (count < V) {
		closestUnmarkedNode = unmarkedNode();
		mark[closestUnmarkedNode] = true;
		for (int i = 0; i<V; i++) {
			if ((!mark[i]) & (adjMatrix[closestUnmarkedNode][i]>0)) {
				if (distance[i] > distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i]) {
					distance[i] = distance[closestUnmarkedNode] + adjMatrix[closestUnmarkedNode][i];
					predecessor[i] = closestUnmarkedNode;
				}
			}
		}
		count++;
	}
}


void Graph::printPath(int node){
	//
	// Function printPath prints the results (path).
	//

	if (node == source)
		cout << node << "..";
	else if (predecessor[node] == -1)
		cout << "No path from source to " << node << " ";
	else {
		printPath(predecessor[node]);
		cout << node << "..";
	}
}


void Graph::output(){
	//
	// Function output prints the results with help from function printPath.
	//

	for (int i = 0; i<V; i++) {
		if (i == source)
			cout << source << ".." << source;
		else
			printPath(i);
		cout << "->" << distance[i] << endl;
	}
}


int main(){
	// initialize a graph
	Graph G;
	G.readNodeInfo();
	G.calcDist();
	G.output();

	// these cin.get(); are for users with MS Visual Studio.
	// they will keep the console window open for the user to see the results.
	cin.get();

	cin.get();

	return 0;
}