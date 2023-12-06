#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int findMinVertex(int* weights, bool* visited, int noOfVerties){
    int minVertex = -1;
    for(int i = 0; i < noOfVerties; i++){
        if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void PrimsAlgorithm(int** edges, int noOfVertices){
    int* parent = new int[noOfVertices];
    int* weights = new int[noOfVertices];
    bool* visited = new bool[noOfVertices];

    for(int i = 0; i < noOfVertices; i++){
        weights[i] = INT_MAX;
        visited[i] = false;
    }

    parent[0] = -1;
    weights[0] = 0;

    for(int i = 0; i < noOfVertices - 1; i++){
        int minVertex = findMinVertex(weights, visited, noOfVertices);

        visited[minVertex] = true;

        for(int j = 0; j < noOfVertices; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i < noOfVertices; i++){
        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weights[i] << endl;
    }

    delete [] parent;
    delete [] weights;
    delete [] visited;
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
        int first;
        int second;
        int weight;
        cout << "Enter vertices of " << i + 1 << " edges : ";
        cin >> first >> second;
        cout << "Enter weight : ";
        cin >> weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }

    PrimsAlgorithm(edges, noOfVertices);

    for(int i = 0; i < noOfVertices; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}