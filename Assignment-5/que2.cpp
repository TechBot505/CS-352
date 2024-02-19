#include <GL/glut.h>
#include <cmath>
#include <iostream>

int windowHeight = 600;
int windowWidth = 800;

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;

    int stepX = (x1 < x2) ? 1 : -1;
    int stepY = (y1 < y2) ? 1 : -1;

    int d = 2 * dy - dx;

    if (dx >= dy) {
        while (x != x2) {
            setPixel(x, y);

            if (d >= 0) {
                y += stepY;
                d -= 2 * dx;
            }

            x += stepX;
            d += 2 * dy;
        }
    } else {
        while (y != y2) {
            setPixel(x, y);

            if (d >= 0) {
                x += stepX;
                d -= 2 * dy;
            }

            y += stepY;
            d += 2 * dx;
        }
    }
}

void drawCircle(int centerX, int centerY, int radius) {
    int x = 0, y = radius;
    int d = 1 - radius;

    while (x <= y) {
        setPixel(centerX + x, centerY + y);
        setPixel(centerX - x, centerY + y);
        setPixel(centerX + x, centerY - y);
        setPixel(centerX - x, centerY - y);
        setPixel(centerX + y, centerY + x);
        setPixel(centerX - y, centerY + x);
        setPixel(centerX + y, centerY - x);
        setPixel(centerX - y, centerY - x);

        x++;

        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
    }
}

void drawBus() {

    glColor3f(0.5, 0.5, 0.5);
    drawLine(100, 100, 700, 100);
    drawLine(100, 100, 100, 260); 
    drawLine(700, 100, 700, 260); 
    drawLine(100, 260, 700, 260); 

    drawLine(300, 100, 300, 200);
    drawLine(300, 200, 360, 200);
    drawLine(360, 100, 360, 200);

    drawLine(400, 200, 460, 200);
    drawLine(400, 140, 460, 140);
    drawLine(400, 140, 400, 200);
    drawLine(460, 140, 460, 200);

    drawLine(500, 200, 560, 200);
    drawLine(500, 140, 560, 140);
    drawLine(500, 140, 500, 200);
    drawLine(560, 140, 560, 200);

    glColor3f(0.5, 0.5, 0.5);
    drawCircle(200, 100, 45);
    drawCircle(600, 100, 45);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawBus();
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Car Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
