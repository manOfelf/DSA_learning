// T.C : O(logn)
// S.C : O(1)

#include <bits/stdc++.h>
using namespace std;

//finding last occurence
int Last(vector<int>arr, int element){
  
	int l=0,r=arr.size()-1,last=-1;
      while(l<=r)
      {
          int mid=(l+r)/2;
          if(arr[mid]<element)
            l=mid+1;
          else if(arr[mid]>element)
            r=mid-1;
          else
          {
            last=mid;
            l=mid+1;
          }
      }
	return last;
}

//finding first occurence
int First(vector<int>arr, int element){
  
	    int l=0,r=arr.size()-1,first=-1;
      while(l<=r)
      {
          int mid=(l+r)/2;
          if(arr[mid]<element)
            l=mid+1;
          else if(arr[mid]>element)
            r=mid-1;
          else
          {
            first=mid;
            r=mid-1;
          }
      }
	return first;
}

int Occurence(vector<int> arr, int element)
{
	int l=0,r=arr.size()-1;
  
	int count=Last(arr,element)-First(arr,element)+1;

	//return count of the occurence of given element.
	if(count==1)
	return 0;
	else
	return count;
}

int main() {
  
      int n,element;
      vector<int> arr;    
      cin>>n>>element;
      for(int i=0;i<n;i++){
        
        int tem;
        cin>>tem;
        arr.push_back(tem);
      }
	    cout<<Occurence(arr,element)<<endl;
  
	return 0;
}



