#include <iostream>
#include <cstring>
using namespace std; 

template<typename T>
//the array should hold elements of any type, and should be able to have any number of dimensions
class multiDimensionalArr
{
private:
	T *p;
	int row;	
	int col;
	int dimension;
public:
	multiDimensionalArr()					//constructor
	{
		cout<<"Enter number of dimensions for array: "<<endl;
		cin>>dimension;
		cout<<"Enter rows: "<<endl;
		cin>>row;
		cout<<"Enter columns: "<<endl;
		cin>>col;
		p=new T[row*col*dimension];
		for(int i=0;i<dimension*row*col;i++)
		{
			p[i]=i;
		}
	}

	void set(int i,int j,int k,T a)			//setter or mutator to set value
	{
		p[(i-1)*row*col+j*col+k]=a;
	}

	T get(int i,int j,int k)				//getter or accessor to return value
	{
		return p[(i-1)*row*col+j*col+k];
	}

	~multiDimensionalArr()					//destructor
	{
		delete []p;
	}

	void printMatrix()						//function for printing data in matrix/table form
	{            
		for(int i=0;i<dimension;i++)
		{	
			cout<<"Matrix "<<i+1<<endl;
			for(int j=0;j<row;j++)
			{
				for(int k=0;k<col;k++)
				{
					cout<<p[i*row*col+j*col+k]<<"  ";
					cout<<endl;
				}
			}
		}
	}

	void printLinear()					   //function for printing linear 1D array as present in memory
	{        
		int size=dimension*row*col;
		for(int i=0;i<size;i++)
		{
			cout<<p[i];
			cout<<" ";
		}
	}
};


//Template specialization
template< >
class multiDimensionalArr<char>
{
	char **p;
	int row;
	int col;
	int dimension;
public:
	multiDimensionalArr()								//constructor
	{
		cout<<"Enter number of dimensions for array: "<<endl;
		cin>>dimension;
		cout<<"Enter rows: "<<endl;
		cin>>row;
		cout<<"Enter columns: "<<endl;
		cin>>col;
		p=new char*[row*col*dimension];
		for(int i=0;i<dimension*row*col;i++)
			p[i]= '\0';
	}

	void set(int i,int j,int k,char* a)					//setter or mutator to set value
	{
		int l=strlen(a);								//length of coming array
		p[(i-1)*row*col+j*col+k]=new char[l+1];			//row major order
		strcpy(p[(i-1)*row*col+j*col+k],a);
	}

	char* get(int i,int j,int k)						//getter or accessor to return value
	{
		if(p[(i-1)*row*col+j*col+k]!='\0')				//till it is not ending
		{
			int l=strlen(p[(i-1)*row*col+j*col+k]);
			char* temp=new char[l+1];
			strcpy(temp,p[(i-1)*row*col+j*col+k]);
			return temp;
		}
		else
			return "No data";
	}
	~multiDimensionalArr()								//destructor
	{
		for(int i=0;i<dimension*row*col;i++)
			delete []p[i];
		delete []p;
	}

	void printLinear()									 //function for printing linear 1D array as present in memory
	{                
		for(int i=0;i<dimension*row*col;i++)
		{
			if(p[i]!='\0')
			{
				int s=strlen(p[i]);
				char *d=new char[s+1];
				strcpy(d,p[i]);
				cout<<d;
				cout<<"  ";
				delete []d;
			}
			else 
				cout<<"0  ";
		}
	}


	void printMatrix()									//function for printing data in table/matrices form 
	{					
		for(int i=0;i<dimension;i++)
		{	
			cout<<"Matrix "<<i+1<<endl;
			for(int j=0;j<row;j++)
			{
				for(int k=0;k<col;k++)
				{
					if(p[i*row*col+j*col+k]!='\0')
					{
						cout<<"(";
						int s=strlen(p[i*row*col+j*col+k]);
						char* d=new char[s+1];
						strcpy(d,p[i*row*col+j*col+k]);
						cout<<d;
						cout<<")";
						delete []d;
						cout<<" ";
					}
					else
						cout<<"0 ";
				}	
				cout<<endl;
			}
		}
	}
};