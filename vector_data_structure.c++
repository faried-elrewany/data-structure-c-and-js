
#include <bits/stdc++.h>
using namespace std;
#define mb make_pair
#define em emplace_back
#define fx(x) fixed<<setprecision(x)
#define sz(s) (int)(s.size())
#define endl "\n"
#define M  100000000
#define INF  0x3f3f3f3f3f3f3f3fLL
#define All(x)	x.begin(), x.end()
#define trav(a,x)   for(  auto &a :x)
typedef long long   ll;
typedef long double ld;
typedef vector<int> vi;
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
class vecData{
  private:
  int size=0;
  int *arr=nullptr;
  int capacity=size+20;
  public:
  vecData(int len){
    size=len;
      arr=new int[capacity] { };
  }
  ~vecData(){
    delete [] arr;
      arr = nullptr;
  }
  int getSize(){
    int x=size;
      cout<<"size is: "<<x<<endl;
        return x;
  }
  int getCapacity(){
    int x=capacity;
      cout<<"capacity is : "<<capacity<<endl;
        return x;
  }
  bool isEmpty(){
    return (size==0 ? true:false);
  }
  int set(int idx, int value)
  {
    assert(0 <=idx or idx <size);
    arr[idx]=value;
    return 0;
  }
  int get(int idx){
    assert(idx>=0 && idx<size);
    cout<<"value of index: "<<idx <<" = "<<arr[idx]<<endl;
    return arr[idx];
  }
  int findIdx(int value){
    for(int i=0;i< size;++i)
      if (arr[i]==value)
      { cout<<"the index of value:  "<<value<<" is :"<<i;
       return i;
      }
      
    
    return -1;
  }
  void expandCapacity(){
    capacity*=2;

    int *arr2=new int[capacity] { };
      for(int i{00};i<size;++i)
        arr2[i]=arr[i];
    
      swap(arr,arr2);
        delete[] arr2;
  }
  void pushBack(int val){

      if(size <capacity)
        arr[size]=val,++size;

      else 
        expandCapacity();
  }
  void print(){

   for(int i{0};i<size;++i)
      cout<<arr[i]<<" ";

   cout<<endl;

  } 
  void insertIn(int pos,int val){
    if (size== capacity)
      expandCapacity();

    for(int i{size-1};i>=pos;--i )
        arr[i+1]=arr[i];

      arr[pos]=val;
        ++size;


      // ------------explanation------------- 
      // insert in index 7 value 10 
      // first check the size
      // arr 1 2 3 4 5 6 7 8 9 
      // shift all elements to the right of the new value 
      // loop from right to the input index  
      // arr= 1 2 3 4 5 6 7 8 8 9 
      // arr= 1 2 3 4 5 6 8 8 9 
      //then put in  given index 7  value 10
      //arr 1 2 3 4 5 6 7 10 8 9
      // increase the size 
  }

  void rotateRight(){
    print();
    int x=arr[size-1];
    for(int i{size-1};i>=0;--i)
    {
      if(i>0)
      arr[i]=arr[i-1];
    }
    arr[0]=x;
    print();
  }
  void rotateLift(){
    print();
    int x=arr[0];
    int *arr2=new int [capacity]{ };

   for(int i{1};i<=size;++i)
   {
    arr2[i-1]=arr[i];
   }
   swap(arr, arr2);
   delete[] arr2;
    arr[size-1]=x;
    print();

  }
int deletePos(int pos){
 int *arr2=new int[size] {};
 for(int i{pos};i<size;++i)
 {
  arr2[i]=arr[i+1];
 }
 for(int i{0};i<pos;++i)
 {
  arr2[i]=arr[i];
 }
 swap(arr,arr2);
 delete []arr2;
 --size;
 print();
}
};
int main(){
vecData obj(7);

for(int i{0};i<obj.getSize();++i)
  obj.set(i,i*2);

obj.print();
obj.insertIn(2,10);
obj.print();
obj.findIdx(6);
obj.getSize();
obj.isEmpty();
obj.pushBack(99);
obj.print();
obj.getCapacity();
obj.get(5);
obj.deletePos(5);

}