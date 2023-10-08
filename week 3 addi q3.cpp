#include<iostream>
#include<conio.h>
using namespace std;
class Cube
{
	private:
		int i,n;
		public:
			Cube()
	        {
	        	i=1;
	        	n=0;
	        }
	        Cube(int p, int q)
	        {
	        	i=p;
	        	n=q;
			}
			void display()
			{
				cout<<"enter the number :"<<endl;
				cin>>n;
				for(i=1; i<=n; i++)
				{
							cout<<" The cube of "<<i<<"is = "<<(i*i*i)<<endl;
					
				}
			}
			~Cube()
			{
				cout<<" clear :"<<endl;
			}
		};
int main()
   {
   	int p,q;
	Cube obj(p,q);
	obj.display();
	getch();
}