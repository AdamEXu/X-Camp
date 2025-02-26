#include <iostream>
#include <vector>
using namespace std;

struct Pair {
    int a;
    int b;
    Pair(int x, int y) {
        a=x;
        b=y;
    }
};

struct Circle {
    vector<Pair> pairs;
    vector<int> friends;
    Circle(vector<Pair> x, vector<int> y) {
        pairs = x;
        friends = y;
    }
};

struct Tree {
    vector<Tree *> branches;
    int value;
    Tree(vector<Tree *> a, int b) {
        branches = a;
        value = b;
    }
};

vector<Circle> merge_circles(vector<Circle> circles, int n) {
    vector<Circle> mergedcircles;
    vector<int> tempints;
    vector<Pair> temppairs;
    for (int i = 0; i < n; i++) {
        // 
    }
}

vector<Circle> circle_generator(vector<Pair> pairs, int n) {
    vector<Circle> circles;
    vector<int> tempints;
    vector<Pair> temppairs;
    for (int i = 0; i < n; i++) {
        circles.push_back(Circle(temppairs, tempints));
    }
    for (int i = 0; i < pairs.size(); i++) {
        circles[pairs[i].a].pairs.push_back(pairs[i]);
        circles[pairs[i].a].friends.push_back(pairs[i].b);
    }
    return circles;
}

int main(void) {
    // int n;
    // cin >> n;
    // vector<Pair> pairs;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int temp;
    //         cin >> temp;
    //         if (temp == 1) {
    //             pairs.push_back(Pair(i, j));
    //             cout << i << ", " << j << endl;
    //         }
    //     }
    // }
    // vector<Circle> circles = circle_generator(pairs, n);
    
}