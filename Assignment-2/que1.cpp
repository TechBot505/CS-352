#include <GL/glut.h>
#include <math.h>
#include<iostream>

GLfloat polygonVertices[][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
GLfloat color[] = {0.0, 0.0, 1.0};

void drawPolygon(void) {
    glColor3fv(color);
    glBegin(GL_POLYGON);
    for(int i=0; i<4; i++) {
        glVertex2fv(polygonVertices[i]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clears display window
    drawPolygon();
    glFlush();
}

void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            for(int i=0; i<4; i++) {
                polygonVertices[i][1] += 0.2;
            }
            break;
        case GLUT_KEY_DOWN:
            for(int i=0; i<4; i++) {
                polygonVertices[i][1] -= 0.2;
            }
            break;
        case GLUT_KEY_LEFT:
            for(int i=0; i<4; i++) {
                polygonVertices[i][0] -= 0.2;
            }
            break;
        case GLUT_KEY_RIGHT:
            for(int i=0; i<4; i++) {
                polygonVertices[i][0] += 0.2;
            }
            break;
    }
    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        color[0] = (GLfloat)rand() / RAND_MAX;
        color[1] = (GLfloat)rand() / RAND_MAX;
        color[2] = (GLfloat)rand() / RAND_MAX;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Colored Polygon");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMouseFunc(mouseClick);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}