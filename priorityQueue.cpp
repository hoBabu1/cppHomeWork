#include <iostream>
#include <queue>
using namespace std;
void queueInsert(queue<int> &q, int value)
{
    q.push(value);
    cout << "Inserted " << value << " into the queue." << endl;
}
void queueDelete(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue is empty. Cannot delete element." << endl;
        return;
    }
    int deletedValue = q.front();
    q.pop();
    cout << "Deleted " << deletedValue << " from the queue." << endl;
}
void priorityQueueInsert(priority_queue<int> &pq, int value)
{
    pq.push(value);
    cout << "Inserted " << value << " into the priority queue." << endl;
}
void priorityQueueDelete(priority_queue<int> &pq)
{
    if (pq.empty())
    {
        cout << "Priority queue is empty. Cannot delete element." << endl;
        return;
    }
    int deletedValue = pq.top();
    pq.pop();
    cout << "Deleted " << deletedValue << " from the priority queue." << endl;
}
int main()
{
    queue<int> q;
    priority_queue<int> pq;
    queueInsert(q, 10);
    queueInsert(q, 20);
    cout << endl;
    priorityQueueInsert(pq, 30);
    priorityQueueDelete(pq);
    priorityQueueDelete(pq);
    return 0;
}
