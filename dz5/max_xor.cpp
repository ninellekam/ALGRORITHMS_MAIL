
#include <bitset>
#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;
 
typedef long long unsigned int llu;
 
struct  Node {
    int         subtree_size;
    Node        *left;
    Node        *right;
};
 
typedef class NininoDerevo {
public:
    NininoDerevo() {
         root = new Node({0, 0, 0});
    }
 
    void    insert(llu a) {
        bitset<32>  bit_a(a);
        Node    *cur_node(root);
        
        for(int i = 32; i >= 0; --i) {
            cur_node->subtree_size++;
            if (bit_a[i - 1] == 0) {
                if (!cur_node->left)
                    cur_node->left = new Node({0, 0, 0});
                cur_node = cur_node->left;
            }
            else {
                if (!cur_node->right)
                    cur_node->right = new Node({0, 0, 0});
                cur_node = cur_node->right;
            }
        }
    }
    
    llu     search(llu a) {
        bitset<32>  bit_a(a);
        bitset<32>  res(0);
        Node        *cur_node(root);
        
        if (root->subtree_size == 0) {
            return (-1);
        }
        
        for (int i = 32; i >= 0; --i) {
            if (bit_a[i - 1] == 0) {
                if (cur_node->right && cur_node->right->subtree_size != 0) {
                    cur_node = cur_node->right;
                    res[i - 1] = 1;
                }
                else {
                    cur_node = cur_node->left;
                    res[i - 1] = 0;
                }
            }
            else {
                if (cur_node->left && cur_node->left->subtree_size != 0) {
                    cur_node = cur_node->left;
                    res[i - 1] = 0;
                }
                else {
                    cur_node = cur_node->right;
                    res[i - 1] = 1;
                }
            }
        }
        return (res.to_ullong());
    }
    
    void    erase(llu a) {
        bitset<32>  bit_a(a);
        Node        *cur_node(root);
        
        for (int i = 32; i >= 0; --i) {
            cur_node->subtree_size--;
            if (bit_a[i - 1] == 1)
                cur_node = cur_node->right;
            else
                cur_node = cur_node->left;
        }
    }
private:
    Node    *root;
} nd;
 
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    int         N, command;
    llu         arg;
    nd          derevo;
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> command >> arg;
        if (command == 1 ) {
            derevo.insert(arg);
        }
        else if (command == 2 ) {
            derevo.erase(arg);
        }
        else {
            printf("%llu\n", derevo.search(arg));
        }
    } 
    return 0;
}
