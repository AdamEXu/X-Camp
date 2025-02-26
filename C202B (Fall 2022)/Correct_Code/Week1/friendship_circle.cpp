#include <iostream>
#include <vector>
using namespace std;

int idvals = 0;

struct Friend {
    int val; 
    int circle;
    Friend(int v) : val(v), circle(-1) {}
};

struct Circle {
    int id;
    vector<int> nodes;
    Circle() : id(idvals++) {}
    Circle(int i) : id(i) {}
};

vector<Friend> friends;
vector<Circle> circles;

void mergecircles(int circlea_id, int circleb_id) {
    return;
}

void checkcircles(int a, int b) {
    if (friends[a].circle == friends[b].circle) {
        return;
    }
    if (friends[a].circle == -1 && friends[b].circle != -1) {
        friends[a].circle = friends[b].circle;
        circles[friends[b].circle].nodes.push_back(a);
        return;
    }
    if (friends[a].circle != -1 && friends[b].circle == -1) {
        friends[b].circle = friends[a].circle;
        circles[friends[a].circle].nodes.push_back(b);
        return;
    }
    if (friends[a].circle != -1 && friends[b].circle != -1) {
        mergecircles(friends[a].circle, friends[b].circle);
        return;
    }
    if (friends[a].circle == -1 && friends[b].circle == -1) {
        Circle newcircle = Circle();
        newcircle.nodes.push_back(a);
        newcircle.nodes.push_back(b);
        circles.push_back(newcircle);
        friends[a].circle = newcircle.id;
        friends[b].circle = newcircle.id;
        return;
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        friends.push_back(Friend(i));
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        checkcircles(a, b);
    }
    for (int i = 0; i < circles.size(); i++) {
        cout << circles[i].id << " ";
        for (int j = 0; j < circles[i].nodes.size(); j++) {
            cout << circles[i].nodes[j] << " ";
        }
        cout << endl;
    }
}