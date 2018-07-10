#pragma once
#include<iostream>
using namespace std;
template <class T>
class Stack
{
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Top(T &x) const = 0;
	virtual bool Push(T x) = 0;
	virtual bool Pop() = 0;
	virtual void Clear() = 0;
	virtual bool Botton(T &x) = 0;
};
template <class T>
class SeqStack : public Stack<T>
{
public:
	SeqStack(int mSize)
	{
		maxTop = mSize - 1;
		s = new T[mSize];
		top = -1;
	}
	~SeqStack() { delete[]s; }
	void Clear() { top = -1; }
	bool IsEmpty()const { return (top == -1); }
	bool IsFull()const
	{
		return(top == maxTop);
	}
	bool Top(T &x)const //����ջ��Ԫ�� 
	{
		if (IsEmpty())
		{
			cout << "Empty!" << endl;
			return false;
		}
		x = s[top];
		return true;
	}
	bool Push(T x)  //��ջ������Ԫ��x
	{
		if (IsFull())
		{
			cout << "Overflow" << endl;
			return false;
		}
		s[++top] = x;
		return true;
	}
	bool Pop()  //ɾ��ջ��Ԫ�� 
	{
		if (IsEmpty())
		{
			cout << "UnderFlow" << endl;
			return false;
		}
		top--;
		return true;
	}
	bool Botton(T &x)
	{
		if (IsEmpty())
		{
			cout << "Empty!" << endl;
			return false;
		}
		x = s[0];
		return true;
	}
private:
	int top;
	int maxTop;
	T *s;
};

/******************************************************************
*******************************************************************/
template <class T>
class Queue
{
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual bool Front(T &x) const = 0;
	virtual bool EnQueue(T x) = 0;
	virtual bool DeQueue() = 0;
	virtual void Clear() = 0;
	virtual int Length() = 0;
};
template <class T>
class SeqQueue :public Queue<T>
{
public:
	SeqQueue(int mSize)
	{
		maxSize = mSize;
		q = new T[maxSize];
		front = rear = 0;
	}
	~SeqQueue() { delete[]q; };
	bool IsEmpty() const { return front == rear; }
	bool IsFull() const { return (rear + 1) % maxSize == front; }
	bool Front(T &x) const //��x�з��ض�ͷԪ��
	{
		if (IsEmpty())  //�ն��д���
		{
			cout << "Empty" << endl;
			return false;
		}
		x = q[(front + 1) % maxSize];
		return true;
	}
	bool EnQueue(T x)  //�ڶ�β����Ԫ��
	{
		if (IsFull()) //�������
		{
			cout << "Full" << endl; return false;
		}
		q[rear = (rear + 1) % maxSize] = x;
		return true;
	}
	bool DeQueue()  //ɾ����ͷԪ��
	{
		if (IsEmpty())
		{
			cout << "UnderFlow." << endl;
			return false;
		}
		front = (front + 1) % maxSize;//ѭ����1
		return true;
	}
	void Clear() { front = rear = 0; }
	int Length()
	{
		if (rear>front)
			return (rear - front);
		else
			return (rear + maxSize - front);
	}
	void showLineNode(int x) {
		cout << q[x] << endl;
	}
private:
	int front, rear;
	int maxSize;
	T *q;
};
/*
*************��ʽ�洢ѭ������****************
*/
typedef int ElemType;
typedef struct  qnode
{
	ElemType data;
	struct qnode * next;
}DataNode;
typedef struct
{
	DataNode *front;
	DataNode *rear;
}LinkQuNode;

/*******����********************/
template <class T>
struct QNode
{
	T data;
	QNode * next;
	QNode()
	{
		next = NULL;
	}
	QNode(T Data)
	{
		next = NULL;
		data = Data;
	}
	int Length()
	{
		QNode *CurNode = this;
		int counter = 0;
		while (CurNode->next != NULL)
		{
			++counter;
			CurNode = CurNode->next;
		}
		return counter;
	}
	void AddData(T newdata)
	{
		QNode *q = new QNode;
		q->data = newdata;
		this->next = q;
	}
	void Insert(QNode *&preNode, T dataInsert)
	{
		QNode *Insert = new QNode;
		Insert->data = dataInsert;
		Insert->next = preNode->next;
		preNode->next = Insert;
	}
	void DelNode(QNode *&preNode)
	{
		QNode *temp = preNode->next;
		preNode->next = temp->next;
		delete temp;

	}
};