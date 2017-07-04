#include <iostream>
#include <list>
using namespace std;

struct node
{
    node* l=NULL;
    node* r=NULL;
    string c;
    int f;
}*h=NULL;

list<node*> q;
//list<node*> :: iterator it= q.begin();

void huff_code(node* h){
  if(h->l!=NULL)
    {
        h->l->c =h->c+"0";
        huff_code(h->l);
    }

  if(h->l==NULL && h->r==NULL )
    cout<<h->f<<": "<<h->c <<endl;

  if(h->r!=NULL)
    {
        h->r->c =h->c+"1";
        huff_code(h->r);
    }
}

void insert()
{  int a,b;
   node* t = new node();

   a=q.front()->f;
   t->l=q.front();
   q.pop_front();

   b=q.front()->f;
   t->r=q.front();
   q.pop_front();

   t->f = a+b;
   q.push_back(t);
}
bool comparator(node* s1, node* s2)
{
    return (s1->f < s2->f);
}

int main()
{  int n;
   cout<<"Enter no. of elements: ";
   cin>>n;
   cout<<"Enter the data: "<<endl;

   for(int i=0; i<n; i++)
   {
       node* p = new node();
       cin>>p->f;
       q.push_back(p);
   }
   q.sort(comparator);

   //for(it=q.begin(); it!=q.end(); it++)
    //cout<<(*it)->f<<" ";
   for(int i =1; i<n; i++)
   {
     insert();
     q.sort(comparator);
   }
 h = q.front();
 h->c = "";
 huff_code(h);
}
