#include <GL/glut.h>
#include <iostream>
using namespace std;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);

    int p = 2 * dy - dx;

    int x, y;

    // Determine the order of endpoints
    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    drawPixel(x, y);

    while (x < x2) {
        x++;

        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }

        drawPixel(x, y);
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

    drawLineBresenham(x1, y1, x2, y2);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}