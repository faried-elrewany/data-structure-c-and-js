#include <iostream>
#include <cassert>
#include<vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct node{
  int data{};
  node *next{};
  node(int data): data(data) {}
};
void print(node *head){
 while(head !=nullptr)
 {
    cout<<head->data<<" ";
    head=head->next;
 }
 cout<<endl;
}
void print2(node*head)
{
  if(!head)return;
  cout<<head->data<<" ";
  print2(head->next);
}
void print_reverse(node *head){
  if(!head)return;
  print_reverse(head->next);
  cout<<head->data<<" ";
}

class linkedlist{

private:
node *head{};
node*tail{};
int length = 0;	
// all node data 
vector<node*> debug_data;

void debug_add_node(node*node){
  debug_data.emplace_back(node);
}

void debud_remove_node(node*node){
  auto it=find(debug_data.begin(),debug_data.end(),node);
  if(it==debug_data.end())
    	cout << "Node does not exist"<<endl;
  else{
    debug_data.erase(it);
    cout<<"node removed successfully";
  }
}

public:

	linkedlist() {}
  // to avoid memory leak 
	linkedlist(const linkedlist&) = delete;
	linkedlist &operator=(const linkedlist &another) = delete;

void debug_print_address(){

  node*cur=head;
  while(cur){
    cout<<cur<<" , "<<cur->data<<endl;
    cur=cur->next;
  }

  cout<<endl;
}

void debug_print_node(node*node,bool is_seperate=false){

  if(is_seperate)
    cout<<"sep: ";
  
  // if no node return other wise print its data
  if(node==nullptr){
    cout<<"nullptr"<<endl;
    return;
  }

  // print data of this node and the next to it 
  cout<<node->data<<" ";

  if(node->next==nullptr)
    cout<<"X";
  else
    cout<<node->next->data;

  if(node==head)
    cout<<" HEAD"<<endl; 
  else if(node==tail)
    cout<<" TAIL"<<endl;
  else 
    cout<<endl;

}
string debug_to_string(){
  if(!length)
    return "";
  string data="";
  node*cur=head;
  while(cur){
    data+=to_string(cur->data);
    if(cur->next)
      data+=" ";
    cur=cur->next;
  }
  cout<<data<<endl;
  return data;
  
}
void print(){
  node *temp_head=head;
  while(temp_head!=nullptr)
  {
    // cout<<temp_head->data<<" ";
    debug_print_node(temp_head);
    temp_head=temp_head->next;

  }
  cout<<endl;
}


	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}
  void delete_node(node *node)
  {
    // remove this node from debug_data vector first 
    debud_remove_node(node);
    // decrease length;
    --length;
    // delete node from the list
    delete node;
  }
  void delete_front(){
    if(!length)
      return;
    node* cur=head->next;
    delete_node(head);
    cur=head;   
  }

  void add_node(node* node) {
    // add this node to debug_data vector first 
		debug_add_node(node);
		++length;
	}
  void insert_end(int value){
    // create new node with new value 
  node *item=new node(value);
  // if the list is empty 
  add_node(item);

  if(!head)
    head=tail=item;
    else{
      tail->next=item;
      tail=item;
    };
}

void insert_front(int value) {
   // create new node with new value 
		node* item = new node(value);
		add_node(item);

		item->next = head;
		head = item;

		if(length == 1)
			tail = head;
	}
  node* get_nth(int n) {
    // 1 based
		int cnt = 0;
		for (node* cur = head; cur; cur = cur->next)
			if (++cnt == n)
				return cur;

		return nullptr;
	}
};
int main() {
//  node *node1=new node(13);
//  node *node2=new node(14);
//  node *node3=new node(15);
//  node *node4=new node(16);
//  node1->next=node2;
//  node2->next=node3;
//  node3->next=node4;
//  node4->next=nullptr;
//  cout<<node1->data<<" "<<node1->next->data<<endl;
// node* node=node1;
// print_reverse(node);
// cout<<endl;
linkedlist list;
list.insert_end(10);
list.insert_end(11);
list.insert_end(12);
list.insert_end(13);
list.insert_end(14);
list.print();

cout<<" ***************"<<endl;
list.debug_print_address();
cout<<" ***************"<<endl;
list.debug_to_string();
cout<<" ***************"<<endl;
cout<<list.get_nth(2)->data;
	return 0;
}