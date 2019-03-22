#include <iostream>
#include <math.h>
#define modulor 1000000007
using namespace std;

long long facto(const long long& n)
{
    if(n < 1)
    {
        return 1;
    }
    
    if(n == 1)
    {
        return 1;
    }
    return ((n%modulor)*(facto(n-1)%modulor))%modulor;
}

long long choose(const int& n, int m)
{
    if(m == 0)
        return 1;
    if(m*2 > n)
        m = n-m;
    long long result = n;
    for(int i = 2; i <=m; ++i)
    {
        result = (result*(n-i+1))%modulor;
        result /= i;
    }
    return result;
}

long long togetherCouple(const int& t, const int& N, const int& M)
{
    return ((facto(2*(N-t))*(facto(t)*choose(2*N-t, t))%modulor)%modulor*(int)(pow(2, t))%modulor)%modulor;
}

int countTheWays(const int& N, const int& M)
{
    int totalp = 0;
    for(int i = M; i >= 0; --i)
    {
        totalp += pow(-1, i)*togetherCouple(i, N, M)*choose(M, i);
        cout << totalp << " " << i << endl;
    }
    return totalp;
}

int main()
{
    int T, N, M;
    cin >> T;
    for(int i = 1; i <= T; ++i)
    {
        cin >> N >> M;
        cout << "Case #" << i << ": " << countTheWays(N, M) << endl;
    }
    return 0;
}
