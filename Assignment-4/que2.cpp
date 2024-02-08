#include <GL/glut.h>
#include <iostream>
using namespace std;

void drawCircle(int xc, int yc, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    glBegin(GL_POINTS);

    while (x >= y) {
        // Plot the points in all octants
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);

        if (err <= 0) {
            err += 2*y + 1;
            y += 1;
        }

        if (err > 0) {
            err -= 2*x + 1;
            x -= 1;
        }
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
    glutCreateWindow("Midpoint Circle Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
