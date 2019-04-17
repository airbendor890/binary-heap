#include<iostream>
using namespace std;
/*-its a complete array(so we acn use array)
	-either max heap or mean heap
array Implementation
root=arr[0]
parent node:arr[i-1/2]
left child:arr[2i+1]
right child:arr[2i+2]
functions:
1.getMin()
2.extractMin()
3.decreaseKey()
4.insert
5.delete()
6.display()
7.minHeapify()
*/
class binaryHeap{
	public:
		//pointer to array of elements
		int* hArr;
		//maximum posiible size of array
		int mSize;
		//current size of array
		int cSize;
		//constructor
		binaryHeap(int maxSize){
			mSize=maxSize;
			hArr=new int[mSize];
			cSize=0;
		}
		void swap(int *a,int *b){
			int temp=*a;
			*a=*b;
			*b=temp;
		}
		int parent(int i){
			return (i-1)/2;
		}
		int leftChild(int i){
			return (2*i)+1;
		}
		int  rightChild
		(int i){
			return (2*i)+2;
		}
		int getMin(){
			return hArr[0];
		}
		void insert(int value){
			//base case
			if(cSize==mSize){
				cout<<"heap overflow"<<endl;
				return;
			}
			//insert the new key at the end
			int i=cSize++;
			hArr[i]=value;
			//check it if it breaks heap property and fix it
			//check it for all hiearchy
			while(i!=0 && hArr[parent(i)]>hArr[i]){
				swap(&hArr[i],&hArr[parent(i)]);
				i=parent(i);
			}
		} 
		
		int extractMin(){
			if(cSize<=0)return INT_MAX;
			if(cSize==1){
				return hArr[0];
				cSize--;
			}
			//store the minimum value and remove it from heap
			int root=hArr[0];
			hArr[0]=hArr[cSize-1];
			cSize--;
			minHeapify(0);
			return root;
		}
		
		void decreaseKey(int i,int new_val){
			//algorithm for what happens when one reduce the value of an element 
			//indexed at i to a new_value.you can assume new_value to be less than
			//present value of the element
			hArr[i]=new_val;
			while(i!=0 && hArr[parent(i)]>hArr[i]){
				swap(&hArr[parent(i)],&hArr[i]);
				i=parent(i);
			}
		}
		void deleteKeyAt(int i){
			//decrease the value to INT_MIN
			decreaseKey(i,INT_MIN);
			//call extractMin()s
			extractMin();
		}
		void minHeapify(int i){
			int l=leftChild(i); 
			int r=rightChild(i);
			int smallest=i;
			if(l<cSize && hArr[l]<hArr[i])
				smallest=l;
			if(r<cSize && hArr[r]<hArr[smallest])
				smallest=r;
			if(smallest!=i)
			{	swap(&hArr[i],&hArr[smallest]);
				minHeapify(smallest);
			}
		 }
	
	
	
	
	
	
	
	
	
};
int main(){
	cout<< INT_MIN<<endl;
}

