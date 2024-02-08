#include <GL/glut.h>
#include <math.h>
#include<iostream>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 150, 0, 500);
}

void drawTree(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Tree Stem
    glColor3b(140, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(70, 100);
    glVertex2d(70, 160);
    glVertex2d(90, 160);
    glVertex2d(90, 100);
    glEnd();

    // Leaf-1 (bottom)
    glColor3b(0, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2d(20, 160);
    glVertex2d(140, 160);
    glVertex2d(80, 230);
    glEnd();

    // Leaf-2
    glColor3b(0, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2d(30, 200);
    glVertex2d(130, 200);
    glVertex2d(80, 270);
    glEnd();

    // Leaf-3 (top)
    glColor3b(0, 115, 0);
    glBegin(GL_POLYGON);
    glVertex2d(40, 250);
    glVertex2d(120, 250);
    glVertex2d(80, 320);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A Tree");
    init();
    glutDisplayFunc(drawTree);
    glutMainLoop();
    return 0;
}

// void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
//     glBegin(GL_POLYGON);
//     glVertex2f(cx, cy);
//     for(int i=0; i<=360; i++) {
//         float angle = i*3.1416 / 180;
//         float x = rx*cos(angle);
//         float y = ry*sin(angle);
//         glVertex2f((x+cx), (y+cy));
//     }
//     glEnd();
// }