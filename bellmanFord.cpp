#include <iostream>
#include <climits>
using namespace std;

void BellmanFord(int** edges, int noOfVertices){
    int* distance = new int[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for(int i = 0; i < noOfVertices; i++){
        for(int j = 0; j < noOfVertices; j++){
            if(edges[i][j] != 0){
                int currentDistance = distance[i] + edges[i][j];
                if(currentDistance < distance[j]){
                    distance[j] = currentDistance;
                }
            }
        }
    }
    
    for(int i = 0; i < noOfVertices; i++){
        cout << i << " " << distance[i] << endl;
    }

    delete [] distance;
}

int main(){
    int noOfVertices;
    int noOfEdges;

    cout << "Enter number of vertices : ";
    cin >> noOfVertices;
    cout << "Enter number of edges : ";
    cin >> noOfEdges;

    int** edges = new int*[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        edges[i] = new int[noOfVertices];
        for(int j = 0; j < noOfVertices; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < noOfEdges; i++){
        int source;
        int destination;
        int weight;
        cout << "Enter  of source and destination " << i + 1 << " edge : ";
        cin >> source >> destination;
        cout << "Enter weight : ";
        cin >> weight;
        edges[source][destination] = weight;
    }

    BellmanFord(edges, noOfVertices);

    for(int i = 0; i < noOfVertices; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}