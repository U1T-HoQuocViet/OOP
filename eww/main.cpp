#include "sort.cpp"
//#include "linklist.cpp"

 using namespace std;

struct Node
{
    unsigned int data;
    Node * pNext;
};

class LinkList
{
    private :
        Node *head = nullptr,*tail = nullptr;
    public :
        Node* CreateNode(unsigned int data)
        {
            Node *a = new Node;
            a->data = data;
            return a;
        }

        Node* GetHead()
        {
            return head;
        }
        void SetHead(Node * a)
        {
            head = a;
        }
        void SetTail(Node * a)
        {
            tail = a;
        }

        void AddToTail(unsigned int data)
        {
            Node * temp = CreateNode(data);
            if(head == nullptr || tail == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->pNext = temp;
            }
        }
        void AddToHead(unsigned int data)
        {
            Node * temp = CreateNode(data);
            if(head == nullptr || tail == nullptr)
            {
                head = temp;
                tail = temp;
                temp->pNext = nullptr;
            }
            else
            {
                temp->pNext = head;
                head = temp;
            }
        }
};
void NhapDS(LinkList & ll)
{
    int a;
    while(cin>>a && a != -1)
    {
        if(a >= 0)
            ll.AddToTail(a);
    }
}

void TinhToan(LinkList & ll)
{
    unsigned Sum = 0 ,maxI =0,minU = 1e11 ,n =0;
    Node *temp = ll.GetHead();
    while(temp != nullptr)
    {
        if(temp->data < minU)
            minU = temp->data;
        if(temp->data < minU)
            minU = temp->data;
        Sum += temp->data;
        n++;
        temp = temp->pNext;
    }
    cout<<"min :"<<minU<<endl;
    cout<<"max :"<<minU<<endl;
    cout<<"avr :"<<Sum/n<<endl;
}

int main()
{
//    SV a{"1233" ,"Ho Quoc Viet" ,1.1};
//    SV b{"1133" ,"Ho Quo Viet" ,1.1};
//    SV c{"1033" ,"Ho Quc Viet" ,11.1};
//
//    LinkList ll;
//    ll.AddToHead(a);
//    ll.AddToHead(b);
//    ll.AddToHead(c);
//
//    XepLoaiSV(ll);
//    XoaLoaiYeu(ll);
//
//    Node * temp = ll.GetHead();
//    while(temp != nullptr)
//    {
//        cout<<temp->data.HOTEN<<" ";
//        temp = temp->pNext;
//    }

}
