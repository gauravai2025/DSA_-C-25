#include<bits/stdc++.h>
using namespace std;


void build_segment_tree( vector<int> &arr,int idx,int l,int r,vector<long long int>&seg_tree){
    // base case single element

    if(l==r){
       seg_tree[idx]=arr[l]; 
       return;
    }

    int mid=(l+r)/2;

     build_segment_tree(arr,2*idx+1,l,mid,seg_tree);
     build_segment_tree(arr,2*idx+2,mid+1,r,seg_tree);

     seg_tree[idx]=seg_tree[2*idx+1]+seg_tree[2*idx+2];
}

void update_segment_tree( int val,int i,int idx,int l,int r,vector<long long int>&seg_tree){
    // reach the leaf node to update the value

    if(l==r){
       seg_tree[idx]=val; 
        return;
    }

    int mid=(l+r)/2;

    if(i<=mid)
     update_segment_tree(val,i,2*idx+1,l,mid,seg_tree);
     else
     update_segment_tree(val,i,2*idx+2,mid+1,r,seg_tree);

     seg_tree[idx]=seg_tree[2*idx+1]+seg_tree[2*idx+2];
}


long long int query_segment_tree( int x,int y,int idx,int l,int r,vector<long long int>&seg_tree){

// no overlap
    if(l>y || r<x){
      
    return 0;
    }
      
      // complete overlap
      
    if(l>=x && r<=y){
     return seg_tree[idx];
    }

    // partial overlap

    else{ 
  int mid=(l+r)/2;
 return query_segment_tree(x,y,2*idx+1,l,mid,seg_tree)+query_segment_tree(x,y,2*idx+2,mid+1,r,seg_tree);

    }   
}
 
int main()
{

 int size;
 cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array: ";

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    vector<long long int> seg_tree(4*size,0);

    build_segment_tree(arr,0,0,size-1,seg_tree);
    vector<long long int>ans;
    
    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;

    cout<<"enter query in  format 1 for update and 2 for query:";
    int type,val,i,l,r;
      
      while(q--){
        cin>>type;

        if(type==1){
          cin>>i>>val; 
          i--;
          update_segment_tree(val,i,0,0,size-1,seg_tree); 
        }

        else{
          cin>>l>>r;
          l--;r--;
        ans.push_back(query_segment_tree(l,r,0,0,size-1,seg_tree));

        }
      }

cout<<endl;
      cout<<"The sum of the given range after query processed is: \n";

        for(auto i:ans){
            cout<<i<<" ";
        }
    

    return 0;
}