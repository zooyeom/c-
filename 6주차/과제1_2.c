#include <stdio.h>
#include <math.h>

struct point{
    int x;
    int y;
};

double dist(struct point p1, struct point p2){
    double distance;
    distance=sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    return distance;
}

int main(){
    struct point p1={10,20};
    struct point p2;
    double d;
    
    p1.x=20;
    p2.x=30;
    p2.y=40;
    
    printf("p1.x=%d , p1.y=%d\n",p1.x,p1.y);
    printf("p2.x=%d , p2.y=%d\n",p2.x,p2.y);
    d=dist(p1,p2);
    printf("p1과 p2의 거리는: %lf\n",d);
}
