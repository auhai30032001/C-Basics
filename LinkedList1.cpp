#include<iostream>
#include<string>

using namespace std;

class SinhVien
{
    private:
    string Fullname;
    string id;
    SinhVien  *pNext;
    public:
    friend class List;
};
class List
{
   private:
   SinhVien *pHead;
   SinhVien *pTail;
   public:
   void CreateList(List &l);
   SinhVien *CreateSV(string Fullname, string id);
   void InsertBegin(List &l, SinhVien *p);
   void InsertLast(List &l, SinhVien *p);
   void DeleteBegin(List &l);
   void DeleteLast(List &l);
   void DeletePos(List &l, string Fullname);
   void Output(List l);
   void Update(List &l, SinhVien *p);
   void Menu(List &l);
};

void List ::CreateList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

SinhVien* List::CreateSV(string Fullname, string id)
{
    SinhVien *p = new SinhVien;
    if(p == NULL){
    return NULL;
    }
    p->Fullname = Fullname;
    p->id = id;
    p->pNext = NULL;
    return p;
}

void List ::InsertBegin(List &l, SinhVien *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void List ::InsertLast(List &l, SinhVien *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail ->pNext = p;
        l.pTail = p;
    }
}

void List::DeleteBegin(List &l)
{
    if(l.pHead == NULL)
    return;
    SinhVien *p = l.pHead;
    l.pHead = l.pHead ->pNext;
    delete p;
}

void List ::DeleteLast(List &l)
{
    if(l.pHead == NULL)
    return;
    if(l.pHead ->pNext == NULL)
    {
        DeleteBegin(l);
    return;
    }
    for(SinhVien *k = l.pHead ; k != NULL; k = k->pNext)
    {
        if(k->pNext == l.pTail)
        {
            delete l.pTail;
            k->pNext == NULL;
            l.pTail = k;
            return;
        }
    }
}

void List ::DeletePos(List &l, string Fullname)
{
    if(l.pHead == NULL)
    return;
    if(l.pHead ->Fullname == Fullname)
    DeleteBegin(l);
    return;
    if(l.pTail ->Fullname == Fullname)
    DeleteLast(l);

    SinhVien *g = new SinhVien;
    for(SinhVien *k = l.pHead ; k != NULL; k = k->pNext)
    {
        if(k->Fullname == Fullname)
        {
            g ->pNext = k->pNext;
            delete k;
            return;
        }
        g = k;
    }
}

void List::Update(List &l, SinhVien *p)
{
    string Name;
    fflush(stdin);
    cout<<"Input name to update :";
    getline(cin,Name);
    for(SinhVien *k = l.pHead; k != NULL; k = k ->pNext)
    {
        if(Name == k->Fullname)
        {
            fflush(stdin);
            cout<<"Input name :";
            getline(cin,p->Fullname);
            k->Fullname = p->Fullname;
            cout<<"Input ID";
            getline(cin,p->id);
            k->id = p->id;
        }
    }
}


void List::Output(List l)
{
    for(SinhVien *k = l.pHead; k != NULL; k = k ->pNext)
    {
        cout<<"\nFull Name :"<<k->Fullname<<endl;
        cout<<"\nID :"<<k->id<<endl;
    }
}

void List::Menu(List &l)
{
    int x;
    while(true)
    {
        system("cls");
        cout<<"\n-----------------Menu-----------------"<<endl;
        cout<<"\n\t1.Insert Begin "<<endl;
        cout<<"\n\t2.Insert End "<<endl;
        cout<<"\n\t3.Delete Begin "<<endl;
        cout<<"\n\t4.Delete Last "<<endl;
        cout<<"\n\t5.Delete Position"<<endl;
        cout<<"\n\t6.Update "<<endl;
        cout<<"\n\t7.Output List"<<endl;
        cout<<"\n\t0.Exit program"<<endl;
        cout<<"\n----------------End-------------------"<<endl;
        cout<<"Input your choice \t";
        cin>>x;
        if(x < 0 || x > 7)
        {
            cout<<"Input your choice again!"<<endl;
        }
        if(x == 1)
        {
            string Fullname;
            string id;
            fflush(stdin);
            cout<<"Input name ";
            getline(cin,Fullname);
            cout<<"Input ID ";
            getline(cin,id);
            SinhVien *p = CreateSV(Fullname,id);
            InsertBegin(l,p);
        }
        else if(x==2)
        {
            string Fullname;
            string id;
            cout<<"Input name ";
            fflush(stdin);
            getline(cin,Fullname);
            cout<<"Input ID";
            fflush(stdin);
            getline(cin,id);
            SinhVien *p = CreateSV( Fullname, id);
            InsertLast(l,p);
        }
        else if(x==3)
        {
            DeleteBegin(l);
        }
        else if(x==4)
        {
            DeleteLast(l);
        }
        else if(x==5)
        {
            string Fullname;
            cout<<"Input name to delete ";
            fflush(stdin);
            getline(cin,Fullname);
            DeletePos(l,Fullname);
        }
        else if(x==6)
        {
            SinhVien *p = new SinhVien;
            Update(l,p);
        }
        else if(x==7)
        {
        	system("cls");
            cout<<"\n\t----------Your List-----------"<<endl;
            Output(l);
            system("pause");
        }
        else
        {
            break;
        }
        
    }
}




int main()
{
    List l;
    l.CreateList(l);
    l.Menu(l);
    system("pause");
    return 0;
}


    




