#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define NO return "Impossible"
#define YES return "Possible"
using namespace std;
struct FoxAndChess
{
	string ableToMove(string begin, string target)
	{
		int n=begin.size();
		int i,j=0;
		for(i=0;i<n;i++)
		{
			if(target[i]=='.') continue;
			while(j<n&&begin[j]=='.') j++;
			if(j==n) NO;//���������Բ��� 
			if(target[i]!=begin[j]) NO;//��������Բ��� 
			if(target[i]=='L'&&j<i) NO;
			if(target[i]=='R'&&j>i) NO;//����λ�öԲ��� 
			j++;
		}
		for(i=j;i<n;i++)
		if(begin[i]!='.') NO;//���������Բ��� 
		YES;//ȫ�� 
	}
};