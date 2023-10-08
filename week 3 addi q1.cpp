#include <iostream>
using namespace std;
class decimal
{
	private:
		int i=1,j=n, n, decimal=n, binary=0;
	public:
			int deci()
			{
				cout<<"decimal number : ";
				cin>>n;
			}
			int bin()
			{
				for(j=n;j>0;j=j/2)
				{
					binary = binary+(n%2)*i;
					i=i*10;
					n=n/2;
				}
				cout<<("binary= ",decimal,binary);
			}
		};
		int main()
		{
			decimal A;
			A.deci();
			A.bin();
			return 0;
		}