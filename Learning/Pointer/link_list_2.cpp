#include<bits/stdc++.h>
using namespace std;

struct nod{
    int data;
    nod* point;

    nod(int val){
        data=val;
        point=NULL;
    }
};
void insert_back(nod* &head,int val){
    nod* n=new nod(val);
    if(head==NULL){
        head=n;
        return ;
    }

    nod* temp=head;
    while(temp->point!=NULL){
        temp=temp->point;
    }
    temp->point=n;

}
void insert_front(nod* &head,int val){
    nod * n=new nod(val);
    n->point=head;
    head=n;
}
void search(nod* &head,int val){
    nod* temp=head;
    int key=1;
    while(temp!=NULL){
        if(temp->data==val){
            cout<<"Element found at "<<key<<"\n";
            return;
        }
        temp=temp->point;
        ++key;
    }
    cout<<"Not found \n";
    return;
}
void deletion(nod* &head,int val){
    nod* temp=head;

    while(temp->point->data!=val){
        temp=temp->point;
    }

    nod* todelete=temp->point;///ith element

    temp->point=temp->point->point;///i-1 linked with i+1 element

    delete(todelete);///delate ith element
}
void delete_front(nod* &head){

    nod* todelete=head;

    head=head->point;

    delete todelete;
}
void Reverse(nod* &head){

    nod* prev=NULL;
    nod* cur=head;

    while(cur!=NULL){
        nod* next=cur->point;
        cur->point=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
}
void display(nod* &head){
    nod* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->point;
    }
    cout<<"NULL\n";
}
int main(){

    nod* head=NULL;


    insert_back(head,10);
    insert_back(head,12);
    insert_back(head,19);
    insert_back(head,7);
    display(head);

    insert_front(head,13);
    display(head);

    search(head,7);
    search(head,11);

    deletion(head,19);
    display(head);

    delete_front(head);
    display(head);

    Reverse(head);
    display(head);



    return 0;
}
