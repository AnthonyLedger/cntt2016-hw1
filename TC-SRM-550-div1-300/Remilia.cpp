#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;
 
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())
 
 
class RotatingBot
{
public:
    int minArea(vector <int> moves);
};
 
int RotatingBot::minArea(vector <int> moves)
{
    int minx = 0;
    int maxx = 0;
    int miny = 0;
    int maxy = 0;
    int N = SZ(moves);
 
    int dx = 1;
    int dy = 0;
    int x = 0;
    int y = 0;
	// ģ�����ߣ����³�������ı߽�
    for (int i = 0; i < N; i++)
    {
        int M = moves[i];
        x += M * dx;
        y += M * dy;
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
        int t = dy;
        dy = dx;
        dx = -t;
    }
	// �߽��СҪ��
    if (maxx - minx > 100 || maxy - miny > 100)
        return -1;
 
    x = -minx;
    y = -miny;
    dx = 1;
    dy = 0;
    maxx -= minx;
    maxy -= miny;
    int SX = maxx + 1;
    int SY = maxy + 1;
    vector<vector<bool> > done(SX, vector<bool>(SY, false));
    done[x][y] = true;

	// ��������һ�߿����Ƿ���� 
    for (int i = 0; i < N; i++)
    {
        int M = moves[i];
        for (int j = 0; j < M; j++)
        {
            x += dx;
            y += dy;
			// �߳��߽�
            if (x > maxx || x < 0 || y > maxy || y < 0)
                return -1;
			// �����ص�
            if (done[x][y])
                return -1;
            done[x][y] = true;
        }
		// �յ㲻�ڱ߽���
        if (i != N - 1)
        {
            int tx = x + dx;
            int ty = y + dy;
            if (tx >= 0 && tx <= maxx && ty >= 0 && ty <= maxy && !done[tx][ty])
                return -1;
        }
        int t = dy;
        dy = dx;
        dx = -t;
    }
    return SX * SY;
}