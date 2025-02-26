#include <iostream>
#include <stdio.h>
using namespace std;

int n, l, t, ans[10005], maxans;
int main(void) {
    scanf("%d", &n);
    for (int i=1; i <= n; i++) {
        scanf("%d%d",&i,&l);
        int tmp=0;
        while(scanf("%d", &t) && t) {
            tmp=max(ans[t],tmp);
        }
        ans[i] = tmp+l;
        maxans=max(maxans,ans[i]);
    }
    printf("%d\n", maxans);
    return 0;
}