#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;


int FindMinSubarray(const vector<int> &my_arr,int s)
{
	int min=0;
	int sum=0;
	int front;
	queue<int> min_array;
	for(size_t i=0;i<my_arr.size();++i){
		min_array.push(my_arr[i]);
		sum+=my_arr[i];
		while(sum>=s){	
			front = min_array.front();
			min_array.pop();
			sum-=front;
			if(sum>=s&&min_array.size()<min){
				min = min_array.size();
			
			}
		}
	}
	
	return min;
}

int main(int argc, char** argv){
	//freopen("sample.txt","r",stdin);
	setbuf(stdout,NULL);
	//
	
	int T;
	int test_case;

	scanf("%d", &T);
	for(test_case = 1;test_case <=T;test_case++){
		int n;
		int s;
		cin >> n>>s;
		vector<int> my_arr(n);
		for(int i=0;i<n;++i)
			cin >> my_arr[i];
		int result = FindMinSubarray(my_arr,s);


		printf("#testcase%d\n",test_case);
		//print answer
		printf("%d\n",result);
	
	}
	return 0;
}

