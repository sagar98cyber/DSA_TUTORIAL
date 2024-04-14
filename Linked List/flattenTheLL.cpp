class Node
{
    public : 
        int data;
        Node *next;
        Node *child;
        
        Node(int x)
        {
            data = x;
            next = NULL;
            child = NULL;
        }

        Node(int x, Node* d, bool n)
        {
            data = x;
            if(n == true)
            {
                next = d;
            }
            else{
                child = d;
            }            
        }

        Node(int x, Node* d, Node* c)
        {
            data = x;
            next = d; 
            child = c;
        }
};







int main()
{
    
    return 0;
}