#include <GL/glut.h>
#include <math.h>
#include<iostream>

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION); // Set projection parameters
    gluOrtho2D(0, 300, 0, 300);
}

void drawHouse(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clears display window

    glColor3f(0.0, 1.0, 0.0);

    // Draw a triangle(House Roof)
    glBegin(GL_TRIANGLES);
    glVertex2i(80, 150);
    glVertex2i(162, 240);
    glVertex2i(245, 150);
    glEnd();

    // Main Body
    glColor3f(1.0, 1.0, 1.0);

    // Draw a rectangle
    glBegin(GL_POLYGON);

    glVertex2i(100, 50);
    glVertex2i(225, 50);

    glVertex2i(225, 125);
    glVertex2i(100, 125);

    glVertex2i(225, 50);
    glVertex2i(225, 150);

    glVertex2i(100, 150);
    glVertex2i(100, 50);

    glEnd();

    glColor3f(1.0, 1.0, 0.0);

    // Draw a rectangle
    glBegin(GL_POLYGON);

    glVertex2i(150, 50);
    glVertex2i(175, 50);

    glVertex2i(175, 50);
    glVertex2i(175, 125);

    glVertex2i(175, 125);
    glVertex2i(150, 125);

    glVertex2i(150, 125);
    glVertex2i(150, 50);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    // Draw a rectangle
    glBegin(GL_POLYGON);

    glVertex2i(115, 90);
    glVertex2i(140, 90);

    glVertex2i(140, 90);
    glVertex2i(140, 125);

    glVertex2i(140, 125);
    glVertex2i(115, 125);

    glVertex2i(115, 125);
    glVertex2i(115, 90);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    // Draw a rectangle
    glBegin(GL_POLYGON);

    glVertex2i(185, 90);
    glVertex2i(210, 90);

    glVertex2i(210, 90);
    glVertex2i(210, 125);

    glVertex2i(210, 125);
    glVertex2i(185, 125);

    glVertex2i(185, 125);
    glVertex2i(185, 90);

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(300, 50);
    glutCreateWindow("A House");
    init();
    glutDisplayFunc(drawHouse);
    glutMainLoop();
    return 0;
}