#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;
const int ALPHA_SIZE=26;

struct Trie{
	struct Trie * child[ALPHA_SIZE];
	bool isComplete;
	int child_count;
};

struct Trie * getNode(void){
	struct Trie * pNode = new Trie;

	pNode->isComplete = false;
	pNode->child_count = 0;

	for(int i = 0; i< ALPHA_SIZE; i++)
		pNode->child[i] = NULL;

	return pNode;
}


void insert(struct Trie * root, string key){
	struct Trie * pCrawl = root;

	for(int i = 0; i < key.length(); i++){

		int index = key[i]-'a';

		if(!pCrawl->child[index])
			pCrawl->child[index] = getNode();

		pCrawl = pCrawl->child[index];
		pCrawl->child_count = pCrawl->child_count + 1;
		//cout<<key[i]<<" "<<pCrawl->child_count<<endl;
	}

	pCrawl->isComplete = true;
}

int search(struct Trie * root, string key){
	struct Trie * pCrawl = root;
    
	for(int i = 0 ; i< key.length(); i++){
		int index = key[i] - 'a';
		
		if(!pCrawl->child[index])
			return 0;
		pCrawl = pCrawl->child[index];
		//cout<<key[i]<<" "<<pCrawl->child_count<<" "<<pCrawl<<endl;		
	}
	//cout<<pCrawl;
	if(pCrawl != NULL){
		return pCrawl->child_count;
	}
	return 0;
}

int main(){
    int n;
    cin >> n;
    
    struct Trie *root = getNode();

    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;

        if(op.compare("add") == 0)
        	insert(root, contact);
        else
        	cout<<search(root, contact)<<endl;
    }
    return 0;
}
