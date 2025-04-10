

struct SINHVIEN
{
    string MSSV;
    string HOTEN;
    float DTB;
    char LoaiTN;
} typedef SV;

char XepLoai(SV & sv)
{
    if(sv.DTB >= 9)
        return 'X';
    else if(sv.DTB >= 8)
        return 'G';
    else if(sv.DTB >= 7)
        return 'K';
    else if(sv.DTB >=5)
        return 'T';
    return 'Y';
}


struct Node
{
    SV data;
    Node * pNext;
};

class LinkList
{
    private :
        Node *head = nullptr,*tail = nullptr;
    public :
        Node* CreateNode(SV & data)
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

        void AddToTail(SV & data)
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
        void AddToHead(SV & data)
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

void XepLoaiSV(LinkList & ll)
{
    Node *temp = ll.GetHead();
    while(temp != nullptr)
    {
        temp->data.LoaiTN = XepLoai(temp->data);
        temp = temp->pNext;
    }

}

void XoaLoaiYeu(LinkList & ll)
{
    Node * temp = ll.GetHead();
    while(temp != nullptr)
    {
        if(temp == ll.GetHead() && temp->data.LoaiTN == 'Y')
        {
            Node * toDeleteNode = temp;
            ll.SetHead(toDeleteNode->pNext);
            delete toDeleteNode;
        }
        else if(temp->pNext == nullptr)
        {
            ll.SetTail(temp);
            if(temp->data.LoaiTN == 'Y')
            {
                Node * toDeleteNode = temp;
                temp->pNext = nullptr;
                delete toDeleteNode;
            }
        }
        else if(temp->pNext->data.LoaiTN == 'Y')
        {
            Node * toDeleteNode = temp->pNext;
            temp->pNext = toDeleteNode->pNext;
            delete toDeleteNode;
        }
        temp = temp->pNext;
    }
}
