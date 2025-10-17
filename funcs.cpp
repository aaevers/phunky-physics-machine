#include <string>
#include <iostream>
#include <vector>
#include <cmath>

void mainMenu();
void kinematic();
void projMotion();

using namespace std;


void mainMenu(){

    int choice;

    cout << "-------Main Menu-------" << endl;
    cout << "1. Kinematics" << endl;
    cout << "2. Projectile Motion" << endl;
    cout << "Enter Selection: ";

    cin >> choice;

    cout << endl;

    switch(choice){
        case 1: kinematic();
        case 2: projMotion();
    }

}


void kinematic(){

    double vi;
    double vf;
    double t;
    double a;
    double deltaXY;
    int counter = 0;
    int i;

    cout << "Please list Vi, Vf, t, a(x/y), Δ(x/y). If unknown type 0." << endl;
    cout << "Vi: ";
    cin >> vi;
    cout << "Vf: ";
    cin >> vf;
    cout << "t: ";
    cin >> t;
    cout << "a(x/y): ";
    cin >> a;
    cout << "Δ(x/y): ";
    cin >> deltaXY;

    if(vi == 0){
        counter++;
    }
    else if(vf == 0){
        counter++;
    }
    else if(t == 0){
        counter++;
    }
    else if(a == 0){
        counter++;
    }
    else if(deltaXY == 0){
        counter++;
    }

    if(counter >= 3){
        cout << "I need at least 3 non zero values, try again." << endl;
        kinematic();
    }

    if((vi != 0) && (vf != 0) && (t != 0)){
        a = (vf - vi) / t;
    }
    else if((vi != 0) && (vf != 0) && (a != 0)){
        t = (vf - vi) / a;
    }
    else if((vi != 0) && (vf != 0) && (deltaXY != 0)){
        t = deltaXY / (0.5 * (vi + vf));
    }
    else if((t != 0) && (vf != 0) && (deltaXY != 0)){
        vi = (deltaXY / (0.5 * t)) - vf;
    }
    else if((t != 0) && (vf != 0) && (a != 0)){
        vi = vf - (a * t);
    }
    else if((t != 0) && (a != 0) && (deltaXY != 0)){
        vi = (deltaXY / t) - (0.5 * a * t);
    }
    else if((vi != 0) && (t != 0) && (a != 0)){
        vf = vi + (a * t);
    }
    else if((vi != 0) && (a != 0) && (deltaXY != 0)){
        vf = sqrt(pow(vi, 2) + (2 * a * deltaXY));
    }
    else if((vi != 0) && (t != 0) && (deltaXY != 0)){
        a = (deltaXY - (vi * t)) / (0.5 * (pow(t, 2)));
    }

    if(vi == 0){
        vi = vf - (a * t);
    }
    else if(vf == 0){
        vf = vi + (a * t);
    }
    else if(t == 0){
        t = (vf - vi) / a;
    }
    else if(a == 0){
        a = (vf - vi) / t;
    }
    else if(deltaXY == 0){
        deltaXY = 0.5 * (vi + vf) * t;
    }

    cout << endl << "--------------" << endl << endl;
    cout << "Vi: " << vi << endl;
    cout << "Vf: " << vf << endl;
    cout << "t: " << t << endl;
    cout << "a(x/y): " << a << endl;
    cout << "Δ(x/y): " << deltaXY << endl;

}


void projMotion(){

}