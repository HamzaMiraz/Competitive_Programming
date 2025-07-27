#include<bits/stdc++.h>
using namespace std;

struct nod{
    int data;
    struct nod* point;
};
int main(){
    struct nod* a=NULL;
    struct nod* b=NULL;
    nod* c=NULL;

    a=new nod;///(nod*)malloc(sizeof (nod));or (struct nod*)malloc(sizeof (struct nod));
    b=(nod*)malloc(sizeof (nod));
    c=(struct nod*)malloc(sizeof (struct nod));


    a->data=10;
    b->data=20;
    c->data=30;
    a->point=b;
    b->point=c;
    c->point=NULL;


    while(a!=NULL){
        cout<<a->data<<"->";
        a=a->point;

        if(a==NULL)cout<<"NULL\n";
    }

    return 0;
}
