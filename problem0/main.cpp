#include <iostream>
#include<string>
using namespace std;
int main()
{

    int Size;
    cout<<"enter the Size of the sentence;"<<endl;
    cin>>Size;


    char* arr = new char [Size];
    cout<<"please enter the sentence\n";
    for(int i=0;i<Size;i++)
        cin>>arr[i];



    if(arr[0]>='a'&&arr[0]<='z')
        {
            arr[0]-=32;


            for(int i=1;i<Size;i++)
                if(arr[i]>='A'&&arr[i]<='Z')
                {
                    arr[i]+=32;
                }

            for(int i=0;i<Size;i++)
                cout<<arr[i]<<endl;
        }
    else
    {
        for(int i=1;i<Size;i++)
            if(arr[i]>='A'&&arr[i]<='Z')
            {
                arr[i]+=32;
            }

            for(int i=0;i<Size;i++)
                cout<<arr[i]<<endl;
    }




}
