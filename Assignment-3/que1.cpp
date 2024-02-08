#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xIncrement = static_cast<float>(dx) / steps;
    float yIncrement = static_cast<float>(dy) / steps;

    float x = x1, y = y1;

    drawPixel(round(x), round(y));

    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        drawPixel(round(x), round(y));
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    int x1, y1, x2, y2;

    cout << "Enter the first endpoint (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter the second endpoint (x2 y2): ";
    cin >> x2 >> y2;

    drawLineDDA(x1, y1, x2, y2);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}