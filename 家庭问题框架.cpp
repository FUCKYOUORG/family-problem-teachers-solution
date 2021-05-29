struct node{  //x和y是亲戚 
    int x, y;
};
int n, k;
cin >> n >> k;
node re[100];//存储k组亲戚关系 
for(int i= 0; i <k;i++){
	cin >> re[i].x >> re[i].y;//接收k组亲戚关系 
} 
int visited[100]={0}; //辅助数组，visited[1]==0表示1号成员没出现过 

for(int i=1; i <= n; i++ ){//从1号成员开始搜索，找到没出现过的成员开始广搜 
	if(visited[i] != 0) continue;//visited[i]!=0说明i号成员出现过了 
	familycount++;//家庭计数器增1 
	q.push(i);//压入队列 
	visited[i] = 1; //标记这人已经出现过 
	while(!q.empty()){//开始广搜 
		for(int j = 1; j <= k;j++){//从k个亲戚关系里面找队首元素的直系亲戚 
			找到q.front()的1个直系亲戚t 
			如果t这个亲戚没有出现过 {
				q.push(t);//压入队列等待后继搜索 
				visited[t] = 1; //标记为已出现过，下次遇到就会自动掠过 
			} 
		}
		q.pop();//找到所有直系亲戚后，这个队首元素没用了，一脚踢开，去玩吧 
	} 
}

cout << familycount; 
