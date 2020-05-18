#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

class car
{
public:
    int x;
    int y;
    int id;

    car(int id,int x,int y)
    {
        this->x=x;
        this->y=y;
        this->id=id;
    }
    int dist()
    {
        return x*x+y*y;
    }
    void print()
    {
        cout<<"ID :"<<id<<endl;
        cout<<"Location :"<<"("<<x<<","<<y<<")"<<endl;
    }
};
class CarCompare
{
public:
    bool operator()(car a,car b)
    {
        return a.dist()>b.dist();
    }
};
int main()
{
    int k;
    cout<<"Enter the number of nearest Cars you want to search : ";
    cin>>k;
    priority_queue<car,vector<car>,CarCompare> pq;
    int x[10]={5,6,17,18,9,11,1,3};
    int y[10]={1,-2,8,9,10,91,0,2};
    for(int i=0;i<8;i++)
    {
        car c(i,x[i],y[i]);
        pq.push(c);
    }
    while(k--)
    {
        car p=pq.top();
        p.print();
        cout<<sqrt(p.dist())<<endl<<endl;
        pq.pop();
    }
}
