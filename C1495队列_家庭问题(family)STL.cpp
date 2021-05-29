/*
题目描述

有 n 个人，编号为 1,2,……n，另外还知道存在 K 个关系。一个关系的表达为二元组（α，β）形式，表示α，β为同一家庭的成员。
当 n，k 和 k 个关系给出之后，求出其中共有多少个家庭、最大的家庭中有多少人？例如：n＝6，k＝3，三个关系为（1,2），(1,3)，(4,5)
   此时，6 个人组成三个家庭，即：｛1,2,3｝为一个家庭，｛4,5｝为一个家庭，｛6｝单独为一个家庭，第一个家庭的人数为最多。

输入
文件的第一行为 n,k 二个整数（1≤n≤100）（用空格分隔）
接下来的 k 行，每行二个整数（用空格分隔）表示关系

输出
二个整数（分别表示家庭个数和最大家庭人数）

样例输入
6 3
1 2
1 3
4 5

样例输出
3 3
*/
#include<iostream>
#include<queue> 
using namespace std;
struct relation{ //a和b是亲戚关系 
	int a, b; 
};
int search(int x, relation re);//寻找对应的亲戚,返回0表示没找到 

int main(){
	int n, k, tmp;
	int familyCount = 0; //记录当前搜索家庭的人数 
	int familyMax = 0; //记录最大家庭人数
	int familyTotal = 0; //家庭数量 
	relation relations[1000]; //记录k个亲戚关系 
	bool visited[101] = {0}; //辅助数组，记录哪些人已经搜索过 
	queue<int> q;
    cin >> n >> k;
	for(int i = 1; i <= k; i++){
	    cin >> relations[i].a  >> relations[i].b;
	}
	for(int x = 1; x <= n; x++){ //从1号成员开始搜索，每一轮循环搜索一个家庭 
		//跳过已搜索人员
		if(visited[x]){
			continue;
		}
		familyTotal++; // 家庭数量增1 
		q.push(x); //家庭第一个成员加入队列 
		visited[x] = true;
		familyCount = 1;		
		while(!q.empty()){  //如果当前队列已空，说明当前家庭已经搜索完毕
			//从k个亲戚关系里面寻找队首这个人的亲戚tmp，并入队尾后继处理 
	        for(int i = 1; i <= k; i++){
	        	tmp = search(q.front(), relations[i]);
	        	if(tmp != 0 && !visited[tmp]){ //找到一个亲戚，并且这个亲戚还没被搜索过 ，则…… 
	        		q.push(tmp);  //将这个亲戚入队，放到队尾 
	        		familyCount++; //家庭人数增1 
	        		visited[tmp] = true;//标记这个人已经搜索过 
				}
			}
			q.pop();//把队首这人出队，准备处理队列中下一个人的亲戚关系 
		}
		//记录最大家庭人数 
		if(familyCount > familyMax){
			familyMax = familyCount;
		}
	}	
	cout << familyTotal << " " << familyMax;
	return 0; 
}
//寻找对应的亲戚
int search(int x, relation re){
	if(x == re.a){
		return re.b;
	}else if(x == re.b){
		return re.a;
	}
	return 0;
}
	
