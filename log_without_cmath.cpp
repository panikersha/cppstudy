#include <iostream>
using namespace std;

void reverse()
{
	int a;
	cin >> a;
	if (a == 0) return;
	else
	{
		reverse();
		cout << a<<" ";
	}
}

int log(int b, int count)
{
    int count_t = count;
    if (b/2 == 0) return count_t;
    else 
    {
        count_t = log(b/2, count_t+1);
        return count_t;
    } 
}


int main()
{
   int num = 0;
   int a = 0;
   int res = 0 ;

   cin>>num;

   for(int i=0;i<num;i++)
   {
       cin>>a;
       res = log(a,0);
       cout<<res<<endl;
   }

	return 0;
}
