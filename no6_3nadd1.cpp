#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
unsigned long long largest;
unsigned long long smallest;
void GetSmallest(unsigned long long now,int n){
	if(n==0)
		smallest = now;
	if(n>1 && (now-1)%3==0&&((now-1)/3)%2==1&&(now-1)/3!=1)
		GetSmallest((now-1)/3,n-1);
	GetSmallest(now*2,n-1);

	

}

int main(int argc, char** argv){
	//freopen("input.txt","r",stdin);
	setbuf(stdout,NULL);

	int T;
	int test_case;


	scanf("%d",&T);
	vector<int> Ks_(T);
	for(int i=0;i<T;++i){
		cin>>Ks_[i];
	}
	for(test_case=1;test_case<=T;test_case++){
		largest = pow(2,Ks_[test_case - 1]);
		smallest = 0;
		GetSmallest(smallest,Ks_[test_case -1]);

		printf("Case #%d\n",test_case);
		cout<<smallest<<" "<<largest<<endl;
	}

	return 0;

}
