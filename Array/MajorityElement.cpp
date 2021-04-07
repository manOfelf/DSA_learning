#include<bits/stdc++.h>
using namespace std;


int MajorityElement_Map(vector<int> arr){
  
    int flag = 0;
    unordered_map<int, int> m;

      int size=arr.size();
      for(int i=0;i<size;i++)
      {
          m[arr[i]]++;
      }
      for(auto it: m)
      {
          if(it.second>size/2)
          {
              flag=1;
              return it.first;
          }   
      }
      if(flag==0)
      {
          return -1;
      }
}

int MajorityElement_FrequencyCount(vector<int> arr){
  
      int res=0;
      int index=-1;
      int size=arr.size();
  
      for(int i=0;i<size;i++)
      {   
            int count=0;
            index=arr[i];
            for(int j=0;j<size;j++)
            {
                if(arr[i]==arr[j])
                count++;
            }
            if(count>res)
            {
                res=count;
                index=i;
            }
      }
  
      if(res>size/2)
      return arr[index];
      else
      return -1;
}

int main(){
  
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
   cout<<MajorityElement_FrequencyCount(arr)<<endl;
   // cout<<MajorityElement_Map(arr)<<endl;
   return 0;
}
