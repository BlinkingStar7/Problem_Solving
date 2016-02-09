#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

map<int, int> lazer;

int main(int argc, const char * argv[]) {

int h = 0, ans=0;
char in;
bool check = false;


while(scanf("%c", &in) != EOF){

    if(in == '('){
        h++;
        check = true;
    }
    else if(check){
        check = false;
        h--;

        for(int i=0; i< h; i++) lazer[i]++;
    }
    else{
        h--;

        ans += lazer[h]+1;
        lazer[h] = 0;

    }
}

cout<<ans;

return 0;
}
