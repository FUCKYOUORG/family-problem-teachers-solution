struct node{  //x��y������ 
    int x, y;
};
int n, k;
cin >> n >> k;
node re[100];//�洢k�����ݹ�ϵ 
for(int i= 0; i <k;i++){
	cin >> re[i].x >> re[i].y;//����k�����ݹ�ϵ 
} 
int visited[100]={0}; //�������飬visited[1]==0��ʾ1�ų�Աû���ֹ� 

for(int i=1; i <= n; i++ ){//��1�ų�Ա��ʼ�������ҵ�û���ֹ��ĳ�Ա��ʼ���� 
	if(visited[i] != 0) continue;//visited[i]!=0˵��i�ų�Ա���ֹ��� 
	familycount++;//��ͥ��������1 
	q.push(i);//ѹ����� 
	visited[i] = 1; //��������Ѿ����ֹ� 
	while(!q.empty()){//��ʼ���� 
		for(int j = 1; j <= k;j++){//��k�����ݹ�ϵ�����Ҷ���Ԫ�ص�ֱϵ���� 
			�ҵ�q.front()��1��ֱϵ����t 
			���t�������û�г��ֹ� {
				q.push(t);//ѹ����еȴ�������� 
				visited[t] = 1; //���Ϊ�ѳ��ֹ����´������ͻ��Զ��ӹ� 
			} 
		}
		q.pop();//�ҵ�����ֱϵ���ݺ��������Ԫ��û���ˣ�һ���߿���ȥ��� 
	} 
}

cout << familycount; 
