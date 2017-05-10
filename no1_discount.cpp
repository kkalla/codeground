#include <cstdio>
#include <iostream>
#include <climits>

using namespace std;

int minDistance(int dist[],bool sptset[]){
	int min = INT_MAX, min_index;

	for(int i=0;i<sptset.size();++i){
		if(sptset[i]==false && dist[i]<=min)
			min=dist[i],min_index = i;
	}
	return min_index
}

int Dijkstra(bool** graph,int** cost,int s, int e){
	int size = graph[0].max_size();
	int dist[size];
	bool sptset[size];

	for(int i=0; i<size;++i)
		dist[i]=INT_MAX,sptset[i]=false;
	dist[s]=0;

	for(int count=0;count<size-1;count++){
		int u=minDistance(dist,sptset);
		sptset[u]=true;
		for(int v=0;v<size;v++){
			if(!sptset[v] && graph[u][v] && dist[u] != INT_MAX
					&& dist[u]+cost[u][v]<dist[v])
				dist[v] = dist[u]+cost[u][v];
		}
	}

	return dist[e];

}


int main(int argc, char** argv) {
		
		freopen("sample_input.txt", "r", stdin);
		setbuf(stdout, NULL);
		
		
	int T;
	int test_case;
		//
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for(test_case = 1; test_case <= T; test_case++) {
		int stations;
		int num_rails;
		int discount;
		int result =0;
		int s;
		int e;
		int c;
		//create empty graph
		bool** graph;
		int** cost;
		graph = new boll*[stations];
		cost = new int*[stations];
		for(int i=0;i<stations;++i){
			graph[i]=new bool[stations]={false};
			cost[i]=new int[stations]={INT_MAX};
		}
		cin >> station >> num_rails >> discount;
		//input initial values to graph and cost
		for(int i=0;i<num_rails;++i){
			cin>>s>>e>>c;
			graph[s][e] = graph[e][s]=true;
			cost[s][e] = cost[e][s]=c;
		}
		int p;
		cin >> p;
		for(int i=0;i<p; ++i){
			cin >> s >> e;
			if(graph[s][e] && cost[s][e]>discount)
				result++;
			else if(graph[s][e]==false){
				int total_cost = Dijkstra(graph,cost,s,e);
				if(total_cost>discount)
					result++;
			}
		}





		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다
		printf("Case #%d\n", test_case);
		printf("%d\n",result);
		}
	return 0;
}
