#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int* distance, bool* visited, int noOfVertices){
    int minVertex = -1;
    for(int i = 0; i < noOfVertices; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void DijkstrasAlgorithm(int** edges, int noOfVertices){
    int* distance = new int[noOfVertices];
    bool* visited = new bool[noOfVertices];
    for(int i = 0; i < noOfVertices; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[0] = 0;

    for(int i = 0; i < noOfVertices - 1; i++){
        int minVertex = findMinVertex(distance, visited, noOfVertices);

        visited[minVertex] = true;

        for(int j = 0; j < noOfVertices; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int currentDistance = distance[minVertex] + edges[minVertex][j];
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
        cout << "Enter vertices of " << i + 1 << " edge : ";
        cin >> first >> second;
        cout << "Enter weight : ";
        cin >> weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }

    DijkstrasAlgorithm(edges, noOfVertices);

    for(int i = 0; i < noOfVertices; i++){
        delete [] edges[i];
    }
    delete [] edges;

    return 0;
}