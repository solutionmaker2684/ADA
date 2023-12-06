#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;
};

int findParent(int* parent, int vertex){
    if(parent[vertex] == vertex){
        return vertex;
    }

    return parent[vertex] = findParent(parent, parent[vertex]);
}

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void KruskalsAlgo(Edge* input, int noOfVertices, int noOfEdges){
    sort(input, input + noOfEdges, compare);

    int* parent = new int[noOfVertices];
    int* rank = new int[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    Edge* output = new Edge[noOfVertices - 1];

    int count = 0;
    int i = 0;
    while(count < noOfVertices - 1){
        Edge currentEdge = input[i];

        int sourceParent = findParent(parent, currentEdge.source);
        int destinationParent = findParent(parent, currentEdge.destination);

        if(sourceParent != destinationParent){
            output[count] = currentEdge;
            count++;
            if(rank[sourceParent] < rank[destinationParent]){
                parent[sourceParent] = destinationParent;
            }
            else if(rank[sourceParent] > rank[destinationParent]){
                parent[destinationParent] = sourceParent;
            }
            else{
                parent[destinationParent] = sourceParent;
                rank[sourceParent]++;
            }
        }
        i++;
    }

    for(int i = 0; i < noOfVertices - 1; i++){
        if(output[i].source < output[i].destination){
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else{
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    delete [] parent;
    delete [] rank;
    delete [] output;
}

int main(){
    int noOfVertices;
    int noOfEdges;
    cout << "Enter number of vertices : ";
    cin >> noOfVertices;
    cout << "Enter number of edges : ";
    cin >> noOfEdges;

    Edge* input = new Edge[noOfEdges];
    for(int i = 0; i < noOfEdges; i++){
        cout << "Enter data of " << i + 1 << " edge" << endl;
        cout << "Enter source : ";
        cin >> input[i].source;
        cout << "Enter destination : ";
        cin >> input[i].destination;
        cout << "Enter weight : ";
        cin >> input[i].weight;
    }

    KruskalsAlgo(input, noOfVertices, noOfEdges);

    delete [] input;

    return 0;
}