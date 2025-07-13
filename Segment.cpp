#include <bits/stdc++.h>
using namespace std;

class Segmentree
{
public:
  vector<int> Segment;
  Segmentree(int n)
  {
    Segment.resize(2*n);
  }
  void Build(vector<int> &arr, int idx, int left, int right)
  {
    if (left == right)
    {
      Segment[idx] = arr[left];
      return;
    }
    int mid = (left + right) / 2;
    Build(arr, 2 * idx + 1, left, mid);
    Build(arr, 2 * idx + 2, mid + 1, right);
    Segment[idx] = Segment[2 * idx + 1] + Segment[2 * idx + 2];
  }
  int querry(int idx, int left, int right, int start, int end)
  {
    if (start > right || end < left)
    {
      return 0;

    }
    if (left >= start && right <= end)
    {
      return Segment[idx];
    }
    int mid = (left + right) / 2;
    int leftsum = querry(2 * idx + 1, left, mid, start, end);
    int rightsum = querry(2 * idx + 2, mid + 1, right, start, end);
    return leftsum + rightsum;
  }
  void Build2(vector<int>&arr,int idx, int left, int right){
    if(left==right){
      Segment[idx]=arr[left];
      return;
    }
    int mid=(left+right)/2;
    Build2(arr,2*idx+1,left,mid);
    Build2(arr,2*idx+2,mid+1,right);
    Segment[idx] = min(Segment[2 * idx + 1], Segment[2 * idx + 2]);
  }
  int querry2(int idx,int start, int end, int left, int right){
    if(start>right || end<left){
      return 0;
    }
    if(left>=start && right<=end){
      return Segment[idx];
    }
    int left=querry2(2*idx+1,start,end,left,mid);
    int right=querry2(2*idx+2,start,end,mid+1,right);
    return min(left,right);
  }
  void update2(int idx, int left,int right, int pos,int val){
    if(left==right){
      Segment[idx]%=val;
      return;
    }
    int mid=(left+right)/2;
    if(pos<=mid){
      update2(2*idx+1,left,mid,pos,val);
    }else{
      update2(2*idx+2,mid+1,right,pos,val);
    }
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  Segmentree s(n);
  s.Build(arr, 0, 0, n - 1);
  cout << s.querry(0, 0, n - 1, 0, n - 1) << endl;
  s.update(0, 0, n - 1, 0, 5);
  return 0;
}
