// Set or map 쓰지 않고 기능 구현하기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root ,int data){
    if(root == nullptr){
        root = new Node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if( data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    
    return root;
}

bool search(Node* root, int data){
    if(root == nullptr){
        return false;
    }

    else if (root->data == data){
        return true;
    }

    else if (data < root->data){
        return search(root->left, data);
    }

    else{
        return search(root->right, data);
    }
}

vector<int> sum(vector<int> A, vector<int> B){
    Node* root;
    root = nullptr;
    for(int i=0; i<A.size(); i++){ root = insert(root, A[i]); }

    vector<int> temp = A;
    for(int i=0; i<B.size(); i++){
        if(search(root, B[i]) == false){
            temp.push_back(B[i]);
        }
    }
    return temp;
}

vector<int> complement(vector<int> A, vector<int> B){
    Node* root;
    root = nullptr;
    for(int i=0; i<B.size(); i++){ root = insert(root, B[i]); }

    vector<int> temp;
    for(int i=0; i<A.size(); i++){
        if(search(root, A[i]) == false){
            temp.push_back(A[i]);
        }
    }

    return temp;
}

vector<int> intersect(vector<int> A, vector<int> B){
    Node* root;
    root = nullptr;
    for(int i=0; i<A.size(); i++){ root = insert(root, A[i]); }

    vector<int> temp;
    for(int i=0; i<B.size(); i++){
        if(search(root, B[i]) == true){
            temp.push_back(B[i]);
        }
    }
    return temp;
}

vector<int> solution(vector<int> arrayA, vector<int> arrayB){
    vector<int> answer;
    sort(arrayA.begin(), arrayA.end());
    arrayA.erase(unique(arrayA.begin(), arrayA.end()), arrayA.end());

    sort(arrayB.begin(), arrayB.end());
    arrayB.erase(unique(arrayB.begin(), arrayB.end()), arrayB.end());
    answer.push_back(arrayA.size());
    answer.push_back(arrayB.size());

    vector<int> resultSum = sum(arrayA, arrayB);
    vector<int> resultComplement = complement(arrayA, arrayB);
    vector<int> resultIntersect = intersect(arrayA, arrayB);

    answer.push_back(resultSum.size());
    answer.push_back(resultComplement.size());
    answer.push_back(resultIntersect.size());
    return answer;
}

int main(){
    vector<int> a, b;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    b.push_back(0);
    b.push_back(3);
    b.push_back(5);
    vector<int> result = solution(a, b);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}