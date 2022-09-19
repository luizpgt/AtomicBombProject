#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int main(){
 
ios_base::sync_with_stdio(false);  
cin.tie(NULL); // flushes cout  
 
    long n;
    cin >> n;
 
   int arr[n];
   int index = 0;
 
   if(n == 1)
   {
   	cout << 1 << endl;
   	return 0;
   }
   else if(n == 2 or n == 3)
   {
   	cout << "NO SOLUTION";
   	return 0;
   }
   else{
   	 for(long i = 1 ;i <= n ; i++)
   	 {
   	 	if(i%2==0)
   	 	{
   	 		cout << i << " ";
   	 	}
   	 	else{
             arr[index++] = i;
   	 	}
   	 }
 
   }
   for(int i=0;i<index;i++)
   {
   	cout << arr[i] << " ";
   }
    
 
 
 
}
