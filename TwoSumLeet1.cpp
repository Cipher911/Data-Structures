#include<iostream>
using namespace std;
int main()
{
	int n,tar;
	cout<<"Enter the size of the araay"<<endl;
	cin>>n;
	cout<<endl;
    int nums[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int k=0;k<n;k++)
    {
    	cin>>nums[k];
	}
    cout<<"Enter Target no.";
    cin>>tar;
    cout<<endl;
    int a,b,c,d;
    

    for(int i=0;i<n;i++)
    {
    	int flag =0;
        for(int j=0;j<n;j++)
        {
        	
            //cout<<i<<j<<endl;
            if(i!=j)
            {
            	//cout<<nums[i]<<" "<<nums[j]<<endl;
            	c=i;d=j;
            	a=nums[i];b=nums[j];
            	//cout<<a+b<<endl;
            	if(a+b==tar)
                    {
                    	flag=1;
                        //cout<<"hello"<<endl;
                        break;
                    }
            }
            
            
            
        }
        if(flag==1)
            {
            	break;
			}
    }
    cout<<"["<<c<<","<<d<<"]"<<endl;
}
