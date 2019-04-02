#include<bits/stdc++.h>
using namespace std;
vector<char>Char;
vector<int>Freq;
struct Node{
	char data;
	int freq;
	Node *left, *right;
	Node(char data, int freq){
		this->left=this->right=NULL;
		this->data = data; 
        this->freq = freq; 
	}
};
struct compare{
	bool operator()(Node* A, Node* B){
	return A->freq>B->freq;
}
};

void printCodes(struct Node* root, string str) 
{ 
    if (!root) 
        return; 
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 

void HuffmanCodes(int size){
	struct Node *left, *right, *top; 
	priority_queue<Node*, vector<Node*>, compare> minHeap; 
	for (int i = 0; i < size; ++i) 
        minHeap.push(new Node(Char[i], Freq[i])); 
    while (minHeap.size() != 1) { 
        left = minHeap.top(); 
        minHeap.pop(); 
        right = minHeap.top(); 
        minHeap.pop(); 
        top = new Node('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 

    printCodes(minHeap.top(), ""); 

}





int main(){
	int n;
	cout<<"Enter the number of symbols: ";
	cin>>n;
	Char.resize(n);
	Freq.resize(n);
	cout<<"Enter the symbols: ";
	for(int i=0;i<n;i++){
		cin>>Char[i];
	}
	cout<<"Enter the frequencies: ";
	for(int i=0;i<n;i++){
		cin>>Freq[i];
	}

	HuffmanCodes(n);



	return 0;
}