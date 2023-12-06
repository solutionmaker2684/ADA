#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
    string data;
    int freq;
    Node* left;
    Node* right;

    Node(string data, int freq){
        this->data = data;
        this-> freq = freq;
        left = NULL;
        right = NULL;
    }
};

class comparator{
    public:
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

void print(Node* root, string temp){
    if(root -> left == NULL && root -> right == NULL){
        cout << "Encoding for " << root -> data << " is " << temp << endl;
        return;
    }

    print(root -> left, temp + '0');
    print(root -> right, temp + '1');
}

int main(){
    int noOfChar;
    cout << "Enter number of characters : ";
    cin >> noOfChar;
    
    vector<Node*> nodesVector;
    cout << "Enter character and its frequency" << endl;
    for(int i = 0; i < noOfChar; i++){
        string tempChar;
        cin >> tempChar;
        int freqTemp;
        cin >> freqTemp;
        Node* tempNode = new Node(tempChar, freqTemp);
        nodesVector.push_back(tempNode);
    }

    priority_queue<Node*, vector<Node*>, comparator> minHeap;
    for(int i = 0; i < noOfChar; i++){
        minHeap.push(nodesVector[i]);
    }

    while(minHeap.size() > 1){
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node(left -> data + right -> data, left -> freq + right -> freq);
        newNode -> left = left;
        newNode -> right = right;
        minHeap.push(newNode);
    }

    Node* root = minHeap.top();
    minHeap.pop();

    string temp = "";

    print(root, temp);

    return 0;
}