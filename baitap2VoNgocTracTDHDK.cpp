#include<iostream>
using namespace std;
class ArrayList{
	// thuoc tinh cua doi tuong
	private:
		int *element = new int[100000];// luu mang du lieu
		int current; // chi so phan tu hien tai
		int last;// chi so phan tu cuoi cung
	public:
		ArrayList(); // ham khoi tao
		bool isEmpty(); // kiem tra danh sach rong
		bool isFull(); // kiem tra danh sach day
		int length(); // do dai danh sach
		void append(int x);//them cuoi
		void insert(int x, int pos); // them bat ki
		void remove(int pos);//xoa phan tu
		void print();
};
ArrayList::ArrayList(){
	last=-1;
}
int ArrayList::length(){
	return last+1;
} 
bool ArrayList::isEmpty(){
	if(last==-1)
		return true;
	else
		return false;
}
void ArrayList::append(int x){
	if(last<100){
		element[last+1]=x;
		last=last+1;
	}
	else
		cout<<"List is full";
}
void ArrayList::print(){
	cout<<endl;
	for(int i=0;i<=last;i++)
		cout<<element[i]<<"\t";
}
bool ArrayList::isFull(){
	return (last<100)?false:true;	
}
void ArrayList::insert(int x, int pos){
	if(isFull())
		cout<<"list is full";
	else{
		last=last+1;
		for(int i=last;i>pos;i--){
			element[i]= element[i-1];
		}
		element[pos]=x;
	}
}
void ArrayList::remove(int pos){
	for(int i=pos;i<last;i++)
		element[i]=element[i+1];
	last=last-1;
}
int main(){
	ArrayList list;
    list.length();
    cout<<"Length is: "<<list.length()<<endl;
    list.isEmpty();
    if ( list.isEmpty() == true){
    cout<<"List is empty!"<<endl;
    } else cout << "List is not empty!";
	list.append(5);
	list.append(10);
	list.append(15);
	list.append(20); 
    list.length();
    cout<<"Length is: "<<list.length()<<endl;
    list.print();
    list.insert(15,2);
    cout<<"\nSau khi them la: "<<endl;
    list.print();
    cout<<"\nSau khi xoa la: "<<endl;
    list.remove(2);
    list.print();
}