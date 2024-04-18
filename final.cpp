#include<iostream>
#include <fstream>
#include<ctime>
#include <iomanip>
#include<string>
#include <string.h>
using namespace std;

//LLQueue implementation
class NodeS{
	public:
		int index;
		string data;
		NodeS *next;
		NodeS()
		{
			index = -1;
			data = '\0';
			next = NULL;
		}
		NodeS(string data,int index)
		{
			this->index = index;
			this->data = data;
			next = NULL;
		}
};

class SimpleLLQueue{
	public:
	NodeS *front,*rear;
		SimpleLLQueue()
		{
			front = NULL;
			rear = NULL;
		}

		void Enqueue(string x,int index)
        {
			NodeS *temp = new NodeS(x,index);

            //LLQueue is empty
			if(front == NULL)
			{
				front = temp;
				rear = temp;
			}

            //Not empty
			else
			{
				rear->next = temp;
				rear = temp;
			}
		}

		void Dequeue()
		{
			//LLQueue is empty
			if(front == NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}
            
            //LLQueue has one element
			if(front == rear)
			{
				front = rear = NULL;
			}

			else
			{
				front = front->next;
			}
		}
        
		int Dequeueret()
		{
			int index = -1;
			//empty 
            if(front == NULL)
			{
				return index;
			}

            //one element
	        else if(front == rear)
			{
				index = front->index;
				front = NULL;
                rear = NULL;
			}
            
			else
			{
				index = front->index;
				front = front->next;
			}
			
            return index;
		}

		void Display(){
			
			if(front == NULL)
			{
				cout<<"Underflow"<<endl;
				return;
			}

			NodeS *temp = front;
			
            while(temp)
			{
				cout<<temp->data<< "  " << temp->index << endl;
				temp = temp->next;
			}
		}
};

class ll
{
    public:
    NodeS* first;
    ll()
    {
        first = NULL;
    }


    ll(string data,int index)
    {
        NodeS* temp;
        temp = new NodeS(data,index);
        first = temp;
    }


    void remove(string data)
    {
        NodeS* temp;
        temp = first;
        if(temp->data == data)
        {
            first = first->next;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                if(temp->next->data == data)
                {
                    temp->next = temp->next->next;
                    return;
                }
                temp = temp->next;
            }
        }
        
        
    }

    void enter(string data,int index)
    {
        NodeS* temp;
        temp = new NodeS(data,index);
        if(first == NULL)
        {
            // cout<<"Null hai ya nai "<<endl;
            first = temp;
        }
        else
        {
            cout<<"ll ke root main abhi ye hai "<<first->data<<endl;
            temp->next = first;
            first = temp;
            cout<<"kitni dafa "<<endl;
        }
    }

    void removeall()
    {
        first = NULL;
    }

    ll* filereader()
    {
            ll* history;
            history = new ll;
            ifstream inner;
            inner.open("history.txt");
            string var;
            int x;
            inner >> x;
            getline(inner,var);
            while(!inner.eof())
            {
                history->enter(var,x);
                inner >> x;
                getline(inner,var);
            }
            inner.close();
            return history;
    }
    
    void filewriter(string data,int x)
    {
        //writes index into history file
        ofstream outer;
        outer.open("history.txt",ios::app);
        outer << x << "  " << data <<endl;
        outer.clear();
        outer.close();
    }
    
    void filewriternew()
    {
        //new record into history
        ofstream outer;
        outer.open("history.txt");
        NodeS* temp;
        temp = first;
        while(temp != NULL)
        {
            outer << temp->index << "  " << temp->data << endl;
            temp = temp->next;
        }
        outer.clear();
        outer.close();
    }
    
    void viewhistory()
    {
        NodeS* temp;
        temp = first;
        while(temp != NULL)
        {
            cout << temp->index << "  " << temp->data << endl;
            temp = temp->next;
        }
    }
};

class Node
{
 	public:
	  	string data;
        int index;
	 	Node* left;
	 	Node* right;
        int height;
	 	Node()  // constructor
	 	{
	 		this->left = NULL;
	 		this->right = NULL;
            this->height = 0;
	 	}
	 	Node(string data,int index) // constructor with value
	 	{
	 		this->left = NULL;
	 		this->right = NULL;
	 		this->data = data;
            this->index = index;
            this->height = 0;
		}
 };
 
 class AVL
 {
 	public:
 		Node* root;
 		AVL()  // constructor
 		{
 			root = NULL;
		}
		AVL(string data,int index)  // constructor with value
 		{
 			Node* temp;
 			temp = new Node(data,index);
 			root = temp;
		}
		int heightret(Node *N) 
        {
            if (N == NULL)
            {
                return -1;
            }
            return N->height;
        }
        int max(int a, int b) 
        {
            if(a>b)
            {
                return a;
            }
            else
            {
                return b;
            }
        }

        Node *rightRotate(Node *y) 
        {
            Node *x = y->left;
            if(y->left->right == NULL)
            {
                x->right = y;
                y->left = NULL;
                return x;
            }
            Node *T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(heightret(y->left),heightret(y->right)) + 1;
            x->height = max(heightret(x->left),heightret(x->right)) + 1;
            
            return x;
        }
        
        Node *leftRotate(Node *y) 
        {
            Node *x = y->right;
            if(y->right->left == NULL)
            {
                x->left = y;
                y->right = NULL;
                return x;
            }
            Node *T2 = x->left;
            x->left = y;
            y->right = T2;
            y->height = max(heightret(y->left),heightret(y->right)) + 1;
            x->height = max(heightret(x->left),heightret(x->right)) + 1;
            
            return x;
        }
        
        int getBalanceFactor(Node *N) 
        {
            if (N == NULL)
            {
                return 0;
            }
            return heightret(N->left) - heightret(N->right);
        }
        
        //inserts into avl based on data
        Node *insertNode(Node *node,string data,int index) 
        {
            if (node == NULL)
            {
                Node* temp;
                temp = new Node(data,index);
                return temp;
            }
            else if (data < node->data)
            {
                node->left = insertNode(node->left,data,index);
            }
            else if (data >= node->data)
            {
                node->right = insertNode(node->right, data,index);
            }
            else
            {
                return node;
            }
            
            node->height = 1 + max(heightret(node->left), heightret(node->right));
            int balanceFactor = getBalanceFactor(node);
            
            if (balanceFactor > 1) 
            {
                if (data < node->left->data)
                {
                   return rightRotate(node);
                } 
                else if (data > node->left->data) 
                {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            
            if (balanceFactor < -1) 
            {
                if (data > node->right->data) 
                {
                   return leftRotate(node);
                } 
                else if (data < node->right->data)
                {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }
            return node;
        }
        
        //inserts serials into avl based on data
        void insert(string data,int index)
        {
            root = insertNode(root,data,index);
        }
        
        void inorder(Node *root)
        {
            if(root)
            {
                inorder(root->left);
                cout<<root->data<< "  " <<  root->height <<endl;
                inorder(root->right);
            }
        }
        
        void preorder(Node *root)
        {
            if(root)
            {
                cout<<root->data<<endl;
                inorder(root->left);
                inorder(root->right);
            }
        }
        void out()
        {
            inorder(root);
            //preorder(root);
        }
        
        void search(ll* history)
        {
            clock_t time_req;
            string data;
            cout << "Enter the Name of the page you want to search for" << endl;
            getline(cin,data);
            SimpleLLQueue* l1;
            l1 = new SimpleLLQueue;
            time_req = clock();
            // cout<<"\n\nroot: "<<root<<" data: "<<root->data<<endl;
            l1 = BSTsearch(root,data,l1);
            //cout<<"LL ka display ye aarha "<<endl;
            l1->Display();//gives data and index  of QUEUE LL
            int returned;
            // ll* history;
            // history = new ll();
            if(l1->front != NULL)
            {
                history->enter(l1->front->data,l1->front->index);
                //writes index into history file 
                history->filewriter(l1->front->data,l1->front->index);
            }
            
            //returns index of data
            returned = l1->Dequeueret();
            //name not found in file(not found in LLQueue)
            if(returned == -1)
            {
                cout << "Not Found";
            }
            
            //found
            while(returned != -1)
            {
            	//opens file according to index like for e.g 99.txt 
                int filenum;
                int ind;
                filenum = returned/10000;
                //ind ko dekhna
                ind = returned%10000;
                if(ind == 0)
                {
                    ind = 10000;
                    filenum--;
                }
                string filename = to_string(filenum);
                filename+= ".txt";
                ifstream inner;
                string line;
                inner.open(filename);
                
				for(int x = 1; x <= ind; x++ )
                {
                    getline(inner,line);
                }
                cout << line << endl;
                if(l1->front != NULL)
                {
                	//connects the ll with the 
                    history->enter(l1->front->data,l1->front->index);
                    history->filewriter(l1->front->data,l1->front->index);
                }
                returned = l1->Dequeueret();
            }
            time_req = clock() - time_req;
            cout<<"Time: ";
			cout << setprecision(10) << fixed << (long double)time_req/CLOCKS_PER_SEC<< " Secs" <<endl;
        }
        
        //incognito search,incognito doesnt store history
        void search()
        {
            clock_t time_req;
            string data;
            cout << "Enter the Name of the page you want to search for" << endl;
            getline(cin,data);
            SimpleLLQueue* l1;
            l1 = new SimpleLLQueue;
            time_req = clock();
            l1 = BSTsearch(root,data,l1);
            int returned;
            returned = l1->Dequeueret();
            if(returned == -1)
            {
                cout << "Not Found";
            }
            
            //same process as search
            while(returned != -1)
            {
                int filenum;
                int ind;
                filenum = returned/10000;
                ind = returned%10000;
                if(ind == 0)
                {
                    ind = 10000;
                    filenum--;
                }
                string filename = to_string(filenum);
                filename+= ".txt";
                ifstream inner;
                string line;
                inner.open(filename);
                for(int x = 1; x <= ind; x++ )
                {
                    getline(inner,line);
                }
                cout << line << endl;
                returned = l1->Dequeueret();
            }
            time_req = clock() - time_req;
            cout<<"Time: ";
			cout << setprecision(10) << fixed << (long double)time_req/CLOCKS_PER_SEC<< " Secs" <<endl;
        }
        
        //searches data and add serial's txt data into LLQueue
        SimpleLLQueue* BSTsearch(Node* temp,string data,SimpleLLQueue* l1)
        {
            if(temp == NULL)
            {
                //cout<<"is main aya"<<endl;
                return l1;
            }
            
            else if(temp->data == data)
            {
                l1->Enqueue(temp->data,temp->index);
                l1 = BSTsearch(temp->right,data,l1);
                l1 =  BSTsearch(temp->left,data,l1);
            }
            
            else if(temp->data > data)
            {
                return BSTsearch(temp->left,data,l1);
            }
            
            else if(temp->data < data)
            {
                return BSTsearch(temp->right,data,l1);
            }
            
            
            return l1;
        }
        
        AVL* filereader()
        {
            clock_t time_req;
            AVL* av2;
            av2 = new AVL;
            ifstream inner;
            inner.open("serials.txt");
            string var;
            int x = 1;
            time_req = clock();
            while(!inner.eof())
            {
            	
                getline(inner,var);
                //cout<<"hello i am under the water:   "<<var<<endl<<endl;
				//serials se data is entered into avl tree                
                av2->insert(var,x);
                x++;
                //this will lead to g to be root   
            }


            cout<<"x"<<x<<endl;//1000006
            inner.close();
            time_req = clock() - time_req;
            cout<<"Time: ";
            cout << setprecision(10) << fixed << (long double)time_req/CLOCKS_PER_SEC<< " Secs" <<endl;
            ofstream outer;
            outer.open("size.txt");
            outer << x-1 << endl;//1000005
            outer.close();
            return av2;
        }
        
        void addnew()
        {
            //adds new record to txt 100
            int x;
            ifstream inner;
            inner.open("size.txt");
            inner >> x;//1000003(when mod with 10000 this will give 100 always)
            //this will create new file i.e 100.txt
            inner.close();
            string entered;
            cout << "Enter the Title" << endl;
            getline(cin,entered);
            insert(entered,x);
            ofstream outer;
            outer.open("serials.txt",ios::app);
            outer << entered << endl;
            outer.clear();
            int filenum;
            int ind;
            filenum = x/10000;
            ind = x%10000;
            if(ind == 0)
            {
               ind = 10000;
               filenum--;
            }
            string filename = to_string(filenum);
            filename+= ".txt";
            string line;
            outer.close();
            outer.clear();
            fflush(stdin);
            outer.open(filename,ios::app);
            cout << "Enter the Data to be entered" << endl;
            getline(cin,entered);
            outer << entered << endl;
            outer.close();
            outer.clear();
            x++;
            fflush(stdin);
            outer.open("size.txt");
            outer << x << endl;
            outer.close();
        }
        
        void removerec()
        {

            string entered;
            cout << "Enter the Title to be deleted" << endl;
            getline(cin,entered);
            SimpleLLQueue* l1;
            l1 = new SimpleLLQueue;
            l1 = BSTsearch(root,entered,l1);
            int returned;
            returned = l1->Dequeueret();
            if(returned == -1)
            {
                cout << "Not Found";
            }
            while(returned != -1)
            {
                int filenum;
                int ind;
                filenum = returned/10000;
                ind = returned%10000;
                if(ind == 0)
                {
                    ind = 10000;
                    filenum--;
                }
                string filename = to_string(filenum);
                filename+= ".txt";
                ifstream inner;
                string line;
                inner.open(filename);
                string arr[10000];
                int x = 0;
                while(!inner.eof())
                {
                    getline(inner,arr[x]);
                    x++;
                }
                arr[ind-1] = "Deleted";
                inner.clear();
                inner.close();

                ofstream outer;
                outer.open(filename);
                for(int y = 0; y < x-1; y++ )
                {
                    outer << arr[y] << endl;
                }
                outer.clear();
                outer.close();
                returned = l1->Dequeueret();
            }
        }
 };



int main()
{   
    system("cls");
    char string1[] = "\n\t\t ----- I.B.U SEARCH ENGINE -----\n";
    for(int i=0;i<strlen(string1);i++){
            cout<<string1[i];
            for(int j=0;j<10000;j++){
                for(int k=0;k<10000;k++){

                }
            }
    }
    
	int option=1;
    
	AVL* av1;
    
	ll* history;
    
	history = history->filereader();
    //cout<<"history first:"<<history->first->data<<endl;
    
	av1 = av1->filereader();
    
	//cout<<"AVL :"<<av1->root->data<<"index "<<av1->root->index<<endl; //Gleneagles Medical Centre   
    
	
	while(option != 6){
        cout<<"\n\t\t\t   _____";								// Prints menu.
	    cout<<"\n\n\t\t\t     Main Menu";
	    cout<<"\n\t\t\t   _____";		
	    cout<<"\n\n1. Search \n2. Add a new record \n3. Remove a record \n4. Incognito\n5. View History\n6. Exit";
	    cout<<"_______";
	    cout<<"\n\nEnter your choice: ";
        cin>>option;
        fflush(stdin);
        
		switch(option)
        {

            case 1:
                av1->search(history);
                break;
            case 2:
                av1->addnew();
                break;
            case 3:
                av1->removerec();
                break;
            case 4:
                av1->search();
                break;
            case 5:
                history->viewhistory();
                char choice;
                cout << "Do you want to delete anything from history Y|N" << endl;
                cin >> choice;
                if(choice == 'Y' ||choice == 'y')
                {
                    cout << "Do you want to delete Entire history y|N" << endl;
                    cin >> choice;
                    if(choice == 'Y' ||choice == 'y')
                    {
                        history->removeall();
                    }
                    else
                    {
                        string data;
                        cout << "Enter the Name that you want to delete" << endl;
                        fflush(stdin);
                        getline(cin,data);
                        cout << data << endl;
                        history->remove(data);
                    }
                    history->filewriternew();
                }
                break;

            case 6:
                exit(0);
                break;
            default:
                cout<<"Please enter a valid choice";
                break;
        }
    }
    return 0;
}