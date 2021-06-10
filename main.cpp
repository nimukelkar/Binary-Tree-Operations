#include <iostream>
#include<stack>

using namespace std;

int cl=0;
int ci=0;
class node{

private:
    int data;
     node* left;
     node* right;
 public:
    friend class tree;
     //void create();




};
class tree{
public:
    node* root;
    tree()
    {
        root=NULL;

    }
    void create();
     void inorder(node* );
     void preorder(node* );
     void postorder(node* );
     int height(node* );
     void mirror(node* );
     void dpre(node*);
     void iterativepreorder();
     void iterativeinorder();
     void iterativepostorder();
     void dummyin()

     {
         inorder(root);

     }
     void dummypre()
     {
         preorder(root);
     }
     void dummypost()
     {
         postorder(root);
     }
     int dummyheight()
     {
         int h=height(root);
         return h;
     }
     void dummymirror()
     {
         mirror(root);
         cout<<"Inorder of the tree, after mirroring is"<<endl;
         inorder(root);
     }
     void dpre()
     {
         preorder(root);
     }
     void treecopy(node* &cpy,node* &orig);
     tree operator=(tree);
     /*void preorder();
    void postorder();

     int height();

     void mirror();*/

};

void tree:: create()
{
     node* p=new node;
     node* q=new  node;
    cout<<"Enter the data of the tree node"<<endl;
    cin>>p->data;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        cout<<"Root node has been successfully inserted"<<endl;
    }
    else{
        int flag=0;
        char ch;
        q=root;


        do {
                cout<<"Do you wish to insert to the left or to the right enter l or r?"<<endl;
        cin>>ch;

        if(ch=='l')
        {
            if(q->left==NULL)
            {
                q->left=p;
                cout<<p->data<<" Has been successfully inserted at left"<<endl;
                flag=1;

            }
            else
            {
                q=q->left;
            }
        }
        else{
                if(q->right==NULL)
            {
                q->right=p;
                cout<<p->data<<" Has been successfully inserted at right"<<endl;
                flag=1;

            }
            else
            {
                q=q->right;
            }

        }
        } while(flag==0);

    }

}
void tree::inorder(node* root)
{
    if(root!=NULL){
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
    }
}
void tree:: preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<endl;
        if((root->left==NULL) &&(root->right==NULL))
        cl++;
    else
        ci++;
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::postorder( node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}


int tree:: height(node* root)
{
    int h1,h2;
    if(root==NULL)
        return 0;
    if((root->left==NULL) && (root->right==NULL))
        return 0;
    h1=height(root->left);
    h2=height(root->right);
    if(h1>h2)
        return h1+1;
    else
        return h2+1;
}

void tree:: mirror(node* root)
{
    if(root!=NULL)
    {
        mirror(root->left);
        mirror(root->right);
        node* temp=new  node;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        //cout<<root->data<<endl;
    }
}
void tree::iterativepreorder()
{
    node* p=new node;
    stack<node*>s1;
    p=root;
    while(1)
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            s1.push(p);
            p=p->left;
        }
            if(s1.empty())
                break;
            else{
                p=s1.top();
                s1.pop();
                p=p->right;
            }

        }
    }
    void tree::iterativeinorder()
{
    node* p=new node;
    p=root;
    stack<node* >s1;
    while(1)
    {
        while(p!=NULL)
        {
            s1.push(p);
            p=p->left;
        }
        if(s1.empty())
            break;
        else
        {
            p=s1.top();
            s1.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}
void tree::iterativepostorder()
{
    node* p=new node;
    p=root;
    stack<node* >s1;
    while(1)
    {
        while(p!=NULL)
        {
            s1.push(p);
            p=p->left;
        }
        if(s1.empty())
            break;

            if(s1.top()->right==NULL)
            {
                p=s1.top();
                s1.pop();
                cout<<p->data<<" ";
            }
            while(s1.top()->right==p)
            {
                p=s1.top();
                cout<<p->data<<" ";
                s1.pop();
                if(s1.empty())
                    break;
            }


        if(!s1.empty())
        {
            p=s1.top()->right;

        }
        else
            p=NULL;
    }
}
tree tree::operator=(tree origtree)
{
    treecopy(root,origtree.root);
    return *this;
}
void tree::treecopy(node* &cpy,node* &orig)
{
   cpy=orig;
   if(orig->left)
   {
       treecopy(cpy->left,orig->left);
   }
   if(orig->right)
   {
       treecopy(cpy->right,orig->right);
   }
}




int main()
{
    int h;
   //node* root=NULL;
   node* left=NULL;
   node* right=NULL;
   tree t;
   //int h;
    char ch='y';
    while(ch=='y')
    {
        int choice;
        cout<<"Enter 1 to create a binary  tree.\n2.To print inorder r\n3.To print inorder non recursively\n4.To print preorder r\n5.To print preorder non recursively\n6.To print postorder r\n7.To find iterative postorder.\n8.To find the height of tree.\n9.To find no. of leaf and intermediate nodes\n10.To find the mirror image of tree.\n11.To copy the tree."<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            t.create();
            break;
        case 2:
            t.dummyin();
            break;
        case 3:
            t.iterativeinorder();
            cout<<endl;
            break;
       case 4:
            t.dummypre();
            break;
       case 5:
            t.iterativepreorder();
            cout<<endl;
            break;

        case 6:
            t.dummypost();
            break;
        case 7:
            t.iterativepostorder();
            break;

        case 8:
             h=t.dummyheight();
             cout<<"The height of the tree is"<<h<<endl;

            break;

       case 9:
            t.dpre();
            cout<<"The number of leaf nodes are "<<cl<<endl;
            cout<<"The number of intermediate nodes are "<<ci<<endl;
            break;
        case 10:
            t.dummymirror();
            break;
        case 11:
            tree t2;
            //t1.create();
            t2=t;
            cout<<"Both of the trees are"<<endl;
            //t1.iterativeinorder();
            t.iterativeinorder();
            t2.iterativeinorder();






        }
        cout<<"Do you wish to continue y or n?"<<endl;
        cin>>ch;
    }
    return 0;

}
