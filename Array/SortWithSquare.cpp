vector<int> Solution::solve(vector<int> &A) {
    vector<int>B;
    if(A.size()==1){
        B.push_back(A[0]*A[0]);
        return B;
    }
    
    long long mn=INT_MAX,j;
    for(int i=0;i<A.size();i++){
        if(abs(A[i]*A[i])<mn){
            j=i;
            mn=abs(A[i]*A[i]);
        }
        
    }
    int l=j,r=j+1;
    while(l>=0 && r<A.size()){
        if(A[l]*A[l]>A[r]*A[r])
        {
            B.push_back(A[r]*A[r]);
            r++;
        }
        else if(A[l]*A[l]<A[r]*A[r]){
            B.push_back(A[l]*A[l]);
            l--;
        }
        else{
             B.push_back(A[r]*A[r]);
             B.push_back(A[l]*A[l]);
             r++;
             l--;
        }
    }
    if(r<=A.size()-1){
        while(r<=A.size()-1){
            B.push_back(A[r]*A[r]);
            r++;
        }
    }
    if(l>=0){
        while(l>=0){
            B.push_back(A[l]*A[l]);
            l--;
        }
    }
    return B;
    
}
