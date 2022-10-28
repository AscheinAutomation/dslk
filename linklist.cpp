#include<iostream>
using namespace std;
//dinh nghia 1 node
struct Node{
	int data;
	Node *next;
};
typedef struct Node* node;

struct List{
	//thuoc tinh
	node head;
	node tail;
	//phuong thuc
	List();
	node createNode(int x);
	void addFirst(int x);
	void addLast(int x);
	void insert(int x, int pos);
	void removeFirst();
	void removeLast();
	void remove(int pos);
	void print();
};
List::List(){
	head=tail=NULL;
}
node List::createNode(int x){
	node p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
void List::addFirst(int x){
	node p=createNode(x);
	if(head==NULL)
		head=tail=p;
	else{
		p->next=head;
		head=p;
	}
}
void List::print(){
	for(node i=head;i!=NULL;i=i->next){
		cout<<i->data<<"\t";
	}
}
void List::addLast(int x){
	node p=createNode(x);
	if(head==NULL)
		head=tail=p;
	else{
		tail->next=p;
		tail=p;
	}
}
int main(){
	List l;
	l.addFirst(5);// l = 5 
	l.addFirst(10);// l = 10 5
	l.addFirst(15);// l = 15 10 5
	l.addFirst(20);// l = 20 15 10 5
	l.addLast(100); //l = 20 15 10 5 100
	l.addFirst(1);
	l.addLast(2);
	l.addFirst(3);
	l.print();
}