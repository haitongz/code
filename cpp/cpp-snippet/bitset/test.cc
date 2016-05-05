#include<iostream>
#include<string>
#include<vector>
#include<sys/time.h>
using namespace std;
const long  N=1000000000;
unsigned char bytes_array[N];
unsigned char * bytes_array_dynamic;
struct timeval start,endd;
void startTimer()
{
    gettimeofday(&start,NULL);
}
void stopTimer()
{
    gettimeofday(&endd,NULL);
}
int getMs()
{
    return  (endd.tv_sec - start.tv_sec)*1000 + (endd.tv_usec-start.tv_usec)/1000;
}
int main()
{
    long i;

    startTimer();
    vector<unsigned char> v(N);
    v.reserve(N);
    for(i=0;i<N;i++)
        v.push_back(12);
    stopTimer();
    cout<<getMs()<<endl;

    startTimer();
    for(i=0;i<N;i++)
        bytes_array[i]=12;
    stopTimer();
    cout<<getMs()<<endl;

    startTimer();
    bytes_array_dynamic = (unsigned char *)malloc(sizeof(unsigned char)*N);
    for(i=0;i<N;i++)
        bytes_array_dynamic[i] = 12;
    stopTimer();
    cout<<getMs()<<endl;

    return 0;
}
