//......Merge Sort by Linonymous....//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

#define read(x) freopen(x,"r",stdin)
#define write(x) freopen(x,"w",stdout)
#define REP(i,n) for( i=0;i<(n);i++)
#define FOR(i,a,b) for( i=(a);i<=(b);i++)
#define FORD(i,a,b) for( i=(a);i>=(b);i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ins insert

typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;

int ans[100];
int arr[100];
void Merge(int low1,int high1,int low2,int high2){
	int i=low1,j=low2,k=0;
	while(i<=high1 && j<=high2){
		if(arr[i]<arr[j]){
			ans[k]=arr[i];
			i++;k++;
		}
		else{
			ans[k]=arr[j];
			j++;k++;
		}
	}	
	if(i<=high1){
		while(i<=high1){
			ans[k]=arr[i];i++;k++;
		}
	}	
	else if(j<=high2){
		while(j<=high2){
			ans[k]=arr[j];j++;k++;
		}
	}
	for(i=low1,j=0;i<=high2&&j<k;i++,j++)
		arr[i]=ans[j];
}

void MergeSort(int low,int high){
	if(low>=high) //Base COndition
		return;
	int mid=(low+high)/2;
	MergeSort(low,mid);
	MergeSort(mid+1,high);	
	Merge(low,mid,mid+1,high);
}

int main(){
	int n,i;
	cin>>n;
	REP(i,n){
		cin>>arr[i];
	}
	MergeSort(0,n-1);
	REP(i,n){
		cout<<arr[i]<<" ";
	}
    return 0;
}
