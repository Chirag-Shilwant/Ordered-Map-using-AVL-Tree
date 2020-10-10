#include<bits/stdc++.h>
#define key_type int
#define val_type string

using ll = long long;
using namespace std;


template <class T, class U> 
class Map
{
    public:
    class node
        {
            public:
            T key;
            U value;
            ll height;
            node *left;
            node *right;
            node(T k, U v)
            {
                height = 1;
                key = k;
                value = v;
                left = NULL;
                right = NULL;
            }
        };

         node * root = NULL;
          T upperBound, lowerBound, smallclosestVal, largeclosestVal;
         T karr[10000]; 
        bool firstClose, firstClose1;
        ll n, index, nodeT=0;

        void insert(T k, U v){
            node * curr = searchUtil(root,k);
            if(curr == NULL)
                root=insertUtil(root, k, v);
            else
            {
               curr->value = v;
            }
            nodeT++;
                
        }

        void erase(T x){
            node * curr = searchUtil(root,x);
           
           if(curr != NULL)
           {
               root=removeUtil(root, x); 
                nodeT--;    
           }
           else
           {
               cout << "\nNode absent\n";
           }
           
        }

        void inorder(){
            index=0;
            inorderUtil(root);
            cout << endl;
        }

        void inorderUtil(node * head){
            if(head!=NULL)
            { 
                inorderUtil(head->left);

                cout<<head->key<<" " << head->value << endl;

                inorderUtil(head->right);
            }
            else 
                return ;
        }

         void find(T x){
            if(searchUtil(root,x)==NULL) cout << "false\n";
            
            else
                cout << "true\n";
        }
        node * searchUtil(node * head, T x){
          if(head != NULL)
           {
            T k = head->key;
            if(k == x) {
                return head;
            }
            if(k > x) {
                return searchUtil(head->left, x);
            }
            if(k < x)
              {
                 return searchUtil(head->right, x);
              }
            }
            else 
                return NULL;
        }

        ll height(node * head){
            if(head==NULL) return 0;
            return head->height;
        }

        node * rightRotation(node * head){
            node * newhead = head->left;

            head->left = newhead->right;
            
            newhead->right = head;
            
            head->height = 1+ max(height(head->left), height(head->right));
          
            newhead->height = 1+max(height(newhead->left), height(newhead->right));  
            
            return newhead;
        }

        node * leftRotation(node * head){
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(height(head->left), height(head->right));
           
            newhead->height = 1+max(height(newhead->left), height(newhead->right));
            
            return newhead;
        }

        node * insertUtil(node * head, T x, U v){
            if(head==NULL){
                n+=1;
                node * temp = new node(x, v);
                return temp;
            }

            if(x < head->key) head->left = insertUtil(head->left, x, v);

            else if(x > head->key) head->right = insertUtil(head->right, x, v);

            head->height = 1 + max(height(head->left), height(head->right));
            
            ll bal = height(head->left) - height(head->right);

            if(bal>1)
            {
                if(x < head->left->key){
                    return rightRotation(head);
                }
                else
                {
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }
            
            else if(bal<-1)
            {
                if(x > head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        node * removeUtil(node * head, T x){
            if(head==NULL) return NULL;
            if(x < head->key){
                head->left = removeUtil(head->left, x);
            }else if(x > head->key){
                head->right = removeUtil(head->right, x);
            }else{
                node * r = head->right;
                if(head->right==NULL){
                    node * l = head->left;
                    delete(head);
                    head = l;
                }else if(head->left==NULL){
                    delete(head);
                    head = r;
                }else{
                    while(r->left!=NULL) r = r->left;
                    head->key = r->key;
                    head->right = removeUtil(head->right, r->key);
                }
            }
            if(head==NULL) return head;
            head->height = 1 + max(height(head->left), height(head->right));
             
            
            ll bal = height(head->left) - height(head->right);
            if(bal>1){
                if(x > head->left->key){
                    return rightRotation(head);
                }else{
                    head->left = leftRotation(head->left);
                    return rightRotation(head);
                }
            }   
                else if(bal < -1){
                if(x < head->right->key){
                    return leftRotation(head);
                }else{
                    head->right = rightRotation(head->right);
                    return leftRotation(head);
                }
            }
            return head;
        }

        U& operator[](T k)
        {
            
             node *head = searchUtil(root, k);

            if (head == NULL)
            {
                U v{};
                insertUtil(root, k, v);
                nodeT++;
                node *curr = searchUtil(root, k);
                return curr->value;
            }

                return head->value;
        }

        ll sizee()
        {
            return nodeT;
        }

        void clearr()
        {
            inorderDel(root);
            nodeT = 0;
        }
        
        void inorderDel(node *head)
        {
            if(head == NULL) return;

            inorderDel(head->left);
            delete(head);
            inorderDel(head->right);
        }

};   



int main(){


    Map<key_type, val_type> ordered_map;
    key_type key;
    val_type value;

    ll n;
    char ch;

    do
    {

        cin >> ch;

        switch (ch)
        {

        case '1':

            cin >> key >> value;
            ordered_map.insert(key, value);
            cout << endl;
            ordered_map.inorder();
            break;

        case '2':

             cin >> key;
             ordered_map.erase(key);
             cout << endl;
             ordered_map.inorder();
            break;

        case '3':

            cin >> key;
            ordered_map.find(key);
            break;        
         
        case '4':
            cin >> key;
            cout << ordered_map[key] << endl;
            break; 

        case '5':
            cin >> key >> value;
            ordered_map[key] = value;
            cout << endl;
            ordered_map.inorder();

            break;

        case '6':
            cout << ordered_map.sizee() << endl;
            break;

        case '7':
            ordered_map.clearr();
            cout << ordered_map.sizee() << endl;
            break;

       
        default:
            break;
        }

    }while(ch!='q');

}
