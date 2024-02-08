#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawCircle(int xc, int yc, int radius) {
    glBegin(GL_POINTS);

    float x, y;
    float theta;

    for (theta = 0; theta <= 360; theta += 0.1) {
        x = xc + radius * cos(theta);
        y = yc + radius * sin(theta);

        glVertex2i(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set color to white

    int xc, yc, radius;

    cout << "Enter the center coordinates (xc yc): ";
    cin >> xc >> yc;

    cout << "Enter the radius: ";
    cin >> radius;

    drawCircle(xc, yc, radius);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Circle Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
