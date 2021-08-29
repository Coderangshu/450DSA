// To understand the Huffman Encoding/Decoding : https://youtu.be/uDS8AkTAcIU
// A Huffman tree node
struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left, *right;
    
    MinHeapNode(char data, int freq){
        this->left = this->right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode*a, MinHeapNode*b){
        return a->freq > b->freq;
    }
};class Solution
{
	public:
	    
	    // Prints huffman codes from the root of Huffman Tree in preorder
        void getCodes(struct MinHeapNode* root, string str, vector<string> &ans){
            if (!root) return;
            
            if (root->data != '$') ans.push_back(str);//cout<<root->data<<" : "<<str<<endl;
          
            getCodes(root->left, str + "0",ans);
            getCodes(root->right, str + "1",ans);
        }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    
		    // to store the left, right and the sum of left and right in top
		    // to be pushed back into the min heap
		    struct MinHeapNode *left, *right, *top;
		    
		    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
            for (int i=0;i<N;i++) minHeap.push(new MinHeapNode(S[i], f[i]));
            
            while(minHeap.size()!=1){
                // Extract the two minimum freq items from min heap
                left = minHeap.top();
                minHeap.pop();
                right = minHeap.top();
                minHeap.pop();
                
                // keeping first occuring character in left
                // if freq of both left and right are same
                if(left->freq==right->freq){
                    if(left->data!='$' or right->data!='$')
                        if(left->data!='$') swap(left,right);
                    else if(left->data>right->data) swap(left,right);
                }
          
                // Create a new internal node with frequency equal to the sum
                // of the two nodes frequencies. Make the two extracted node
                // as left and right children of this new node. Add this node
                // to the min heap '$' is a special value for internal node's data
                top = new MinHeapNode('$', left->freq + right->freq);
                top->left = left;
                top->right = right;
          
                minHeap.push(top);
            }
            
            vector<string> ans;
            getCodes(minHeap.top(),"",ans);
            return ans;
		}
};
