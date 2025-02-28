#include<iostream>
#include<string>
 using namespace std;
 int main(){
	 string a;
	 getline(cin,a);
	 int n=a.length();
	 for(int i=0;i<n/2;i++)
	 {
		 char tem=a[i];
		 a[i]=a[n-i-1];
		 a[n-i-1]=tem;
   	 }
	 cout << a << endl;
	 system("pause");
 }