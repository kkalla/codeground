#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>


using namespace std;

int main(int argc,char** argv){

	setbuf(stdout,NULL);

	int TC;
	int test_case;

	scanf("%d",&TC);
	for(test_case=1;test_case<=TC;test_case++){
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		int max =0;
		for(int i=0;i<N;i++){
			if(arr[i]+N-i>max)
				max = arr[i]+N-i;
		}
		int count =0;
		for(int i=0;i<N;i++){
			if(arr[i]+N-i>=max)
				count++;
		}




		printf("Case #%d\n",test_case);
		cout<<count<<endl;
	}

	return 0;
}

