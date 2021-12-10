#include<iostream>
#include<string>
#define MAX 100
using namespace std;

template <typename T>
class stack
{
	T stackArr[MAX];
	int top;
	public:
	stack(){
		top = -1;
	}
	bool isFull();
	bool isEmpty();
	void push(T data);
	void pop();
	int topPos();
	T operator [](int index);
	T topEle();	
};

template <typename T>
T stack<T>::topEle()
{
	return stackArr[top];
}

template <typename T>
int stack<T>::topPos()
{
	return top;
}

template <typename T>
T stack<T>::operator [](int index)
{
	return stackArr[index];
}

template <typename T>
bool stack<T>::isFull()
{
	if (top>=MAX)
		return 1;
	else
		return 0;
	
}

template <typename T>
bool stack<T>::isEmpty()
{
	if (top==-1)
		return 1;
	else
		return 0;	
}

template <typename T>
void stack<T>::push(T data)
{
	if (isFull())
		cout<<"Stack is Full"<<endl;
	else
	{
		top++;
		stackArr[top] = data;
		
	}
}

template <typename T>
void stack<T>::pop() {
   if(isEmpty())
   cout<<"Stack empty"<<endl;
   else {
    
    	top--;
   }
}

int main()
{
	stack<int> s1;
	stack<int> s2;

	
	int n, num;
	
	cout<<"Enter how many elements you want to enter in stack: ";
	cin>>n;
	
	for (int i=0; i<n; i++)
	{
		cout<<"Enter element: ";
		cin>>num;
		s1.push(num);
	}
	while(!s1.isEmpty())
	{
		int temp = s1.topEle();
		s1.pop();
		while(!s2.isEmpty() and s2.topEle()<temp)
		{
			s1.push((s2.topEle()));
			s2.pop();
		}
		s2.push(temp);
//		cout<<"s1.top: "<<s1.topEle()<<endl;
//		cout<<"s2.top : "<<s2.topEle()<<endl;
	}
	cout<<"Sorted stack: ";
	for (int i=0; i<n; i++)
	{
		cout<<s2.topEle()<<" ";
		s2.pop();
	}
	return 0;
}
