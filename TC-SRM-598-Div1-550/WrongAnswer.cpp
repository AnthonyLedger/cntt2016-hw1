// WAonSystemTest
#include <string>
class FoxAndFencing{
public:
	std::string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d){
		// 1�ı�ʤ����Ϊ[0,mov1+rng1]
		// 2�ı�ʤ����Ϊ[0,mov2+rng2]
		if(d<=mov1+rng1)return"Ciel";
		// (1)������x>mov1+rng1�����ɽ�x�Ƶ�2�ı�ʤ�����⣨��Ȼ������mov1+rng1>=mov2+rng2�����������
		if(mov1+rng1+1+mov1>mov2+rng2){
			// 1.1 ���d���Ƶ�ʹ�Է�ֻ���ƽ�1�ı�ʤ�����λ�ã�ǰ����mov1>mov2����1��ʤ
			if(mov1>mov2&&mov2+rng2+1+mov2<=mov1+rng1)return"Ciel";
			// 1.2 ����ƽ��
			return"Draw";
		}
		// (2)���d�Ʋ���2�ı�ʤ���䣬1�ذ�
		if(d+mov1<=mov2+rng2)return"Liss";
		// (3)���d���Ƴ����䣬���ᱻ�Է��Ƶ�d��С��λ�ã�1�ذ�
		if(mov2>mov1)return"Liss";
		// (4)����ƽ��
		return"Draw";
	}
};
