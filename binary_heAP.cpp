#include<iostream>
using namespace std;

class biheap{
	//min-heap it is
  public:
  	//pointer to array of elements
  	int *hArr;
  	//maximum possible size of arrray
  	int msize;
  	//current size of array
  	int csize;
  	//constr creating an array in heap of arg size
  	biheap(int maxsize){
  		//this->msize=msize;
  		hArr=new int[maxsize];
  		msize=maxsize;
  		csize=0;
	  }
	int parent(int i){return (i-1)/2;	}  
  	int left(int i){return (i*2)+1; }
  	int right(int i){return (i*2)+2;}
  	
  	int getmin(){return hArr[0]; }
  	void swap(int *a,int* b){
	  	int temp=*a;
	  	*a=*b;
	  	*b=temp;
	  }
	void display(){
		//display array
		for(int i=0;i<csize;i++)
			cout<<hArr[i]<<" ";
	  		cout<<endl;
		}
	
	void insert(int value){
		//base case for heap overfloe
		if(csize==msize){cout<<"over flow";}
		else{
		
		//insert the key at the end
		hArr[csize]=value;
		csize=csize+1;
		//check it for all hiearchy with loop,fix it
			for(int i=csize-1;i>=1;i--){
				//if child<parent then swap
				display();
			if( hArr[i]<hArr[parent(i)] ){
				swap(hArr+i,hArr+parent(i)); }
		}
	}
	
	}

};
int main(){
	biheap b1(40);
	for(int i=5;i>=1;i--)
	b1.insert(i);
	b1.display();

}
















