/*
��Ŀ����

�� n ���ˣ����Ϊ 1,2,����n�����⻹֪������ K ����ϵ��һ����ϵ�ı��Ϊ��Ԫ�飨�����£���ʽ����ʾ������Ϊͬһ��ͥ�ĳ�Ա��
�� n��k �� k ����ϵ����֮��������й��ж��ٸ���ͥ�����ļ�ͥ���ж����ˣ����磺n��6��k��3��������ϵΪ��1,2����(1,3)��(4,5)
   ��ʱ��6 �������������ͥ��������1,2,3��Ϊһ����ͥ����4,5��Ϊһ����ͥ����6������Ϊһ����ͥ����һ����ͥ������Ϊ��ࡣ

����
�ļ��ĵ�һ��Ϊ n,k ����������1��n��100�����ÿո�ָ���
�������� k �У�ÿ�ж����������ÿո�ָ�����ʾ��ϵ

���
�����������ֱ��ʾ��ͥ����������ͥ������

��������
6 3
1 2
1 3
4 5

�������
3 3
*/
#include<iostream>
#include<queue> 
using namespace std;
struct relation{ //a��b�����ݹ�ϵ 
	int a, b; 
};
int search(int x, relation re);//Ѱ�Ҷ�Ӧ������,����0��ʾû�ҵ� 

int main(){
	int n, k, tmp;
	int familyCount = 0; //��¼��ǰ������ͥ������ 
	int familyMax = 0; //��¼����ͥ����
	int familyTotal = 0; //��ͥ���� 
	relation relations[1000]; //��¼k�����ݹ�ϵ 
	bool visited[101] = {0}; //�������飬��¼��Щ���Ѿ������� 
	queue<int> q;
    cin >> n >> k;
	for(int i = 1; i <= k; i++){
	    cin >> relations[i].a  >> relations[i].b;
	}
	for(int x = 1; x <= n; x++){ //��1�ų�Ա��ʼ������ÿһ��ѭ������һ����ͥ 
		//������������Ա
		if(visited[x]){
			continue;
		}
		familyTotal++; // ��ͥ������1 
		q.push(x); //��ͥ��һ����Ա������� 
		visited[x] = true;
		familyCount = 1;		
		while(!q.empty()){  //�����ǰ�����ѿգ�˵����ǰ��ͥ�Ѿ��������
			//��k�����ݹ�ϵ����Ѱ�Ҷ�������˵�����tmp�������β��̴��� 
	        for(int i = 1; i <= k; i++){
	        	tmp = search(q.front(), relations[i]);
	        	if(tmp != 0 && !visited[tmp]){ //�ҵ�һ�����ݣ�����������ݻ�û�������� ���򡭡� 
	        		q.push(tmp);  //�����������ӣ��ŵ���β 
	        		familyCount++; //��ͥ������1 
	        		visited[tmp] = true;//���������Ѿ������� 
				}
			}
			q.pop();//�Ѷ������˳��ӣ�׼�������������һ���˵����ݹ�ϵ 
		}
		//��¼����ͥ���� 
		if(familyCount > familyMax){
			familyMax = familyCount;
		}
	}	
	cout << familyTotal << " " << familyMax;
	return 0; 
}
//Ѱ�Ҷ�Ӧ������
int search(int x, relation re){
	if(x == re.a){
		return re.b;
	}else if(x == re.b){
		return re.a;
	}
	return 0;
}
	
