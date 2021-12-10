#include "iostream"
#include <string>
using namespace std;
// Josephus problem same as hot potato
#define   size   10

typedef string itemtype;

struct queuetype
{ itemtype items [size];
  int front, rear;
};

typedef struct queuetype queue;

int empty(queue q)
{
        return q.front == q.rear;
}

int full(queue q)
{
        return q.front == (q.rear+1)%size;
}

void clear(queue & q)
{
        q.front = q.rear = 0;
}

void insert(queue &q , itemtype i)
{   if (!full(q))
        {  q.rear = (q.rear+1)%size;
           q.items[q.rear] = i;
    }
    else cout << "Queue is full";
}

itemtype remove (queue &q)
{   if(!empty(q))
     { q.front = (q.front+1)%size;
           return q.items[q.front];
     }
    else cout << "Queue is empty";
}

void main()
{ queue q;  
  itemtype st;
  int count, number;
  cout << "Enter number of names ===> ";
  cin >> number; // max of size -1
  clear(q);
  cout << "Enter round size is ===> ";
  cin >> count; // number of itemes removed and inserted before one is removed out
  for(int j = 0; j < number; j ++)
        { cout <<"Enter the name number "<< j+1 <<"  ==> ";
      cin >> st;
          insert(q, st);
        }

  int j = 0;
  while (number > 1)
        {  st = remove(q);
       j ++;
       if (j!=count)
                   insert(q, st);
           else
           {  number--;
              cout <<"The removed person from the list " << st << endl;
                  j = 0;
           }
         }
  st = remove(q);
  cout <<"The winner is ==>  " << st<< endl;
}

