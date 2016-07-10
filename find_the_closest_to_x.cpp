/* Given a sorted array of floats, find the index of the number closest to x: */
/* Example: {1.2, 2.5, 9.3} x = 5, return 1 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    int num;
    cin>>num;
    vector<double> numbers(num, 0);
    for(int i=0; i<num; ++i)
        cin>>numbers[i];
    double x;
    cin>>x;
    double min = INT_MAX;
    int res = 0;
    for(int i=0; i<numbers.size(); ++i) {
        double diff = abs(numbers[i] - x);
        if(diff < min) {
            min = diff;
            res = i;
        }
    }
    cout<<"index is "<<res<<endl;
    return 0;
}
