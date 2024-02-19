#include <GL/glut.h>
#include <iostream>
#include <cmath>

int sides = 4;
float vertices[6][2];

// Draws the polygon using the vertices
void drawPolygon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; ++i) {
        glVertex2fv(vertices[i]);
    }
    glEnd();
}

// Function to perform translation: Adds the tx and ty values to original vertices coordinates to translate the polygon
void translate(float tx, float ty) {
    for (int i = 0; i < sides; ++i) {
        vertices[i][0] += tx;
        vertices[i][1] += ty;
    }
}

// Function to perform rotation: FInds the centroid of polygon and then rotate every vertex about the centroid
void rotate(float angle) {
    float radians = angle * 3.14159 / 180.0;
    float centerX = 0.0, centerY = 0.0;

    // Calculate the centroid of the polygon
    for (int i = 0; i < sides; ++i) {
        centerX += vertices[i][0];
        centerY += vertices[i][1];
    }
    centerX /= sides;
    centerY /= sides;

    // Rotate each vertex around the centroid
    for (int i = 0; i < sides; ++i) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        vertices[i][0] = centerX + (x - centerX) * cos(radians) - (y - centerY) * sin(radians);
        vertices[i][1] = centerY + (x - centerX) * sin(radians) + (y - centerY) * cos(radians);
    }
}

// Function to perform scaling: MUltiply each vertex values with sx and sy to scale the polygon
void scale(float sx, float sy) {
    for (int i = 0; i < sides; ++i) {
        vertices[i][0] *= sx;
        vertices[i][1] *= sy;
    }
}

// Function to perform shear: Adds the shx * y and shy * x to the original vertices coordinates to shear the polygon
void shear(float shx, float shy) {
    for (int i = 0; i < sides; ++i) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        vertices[i][0] = x + shx * y;
        vertices[i][1] = y + shy * x;
    }
}

// Function to perform reflection: Negates the x coordinate of each vertex to reflect the polygon
void reflect() {
    for (int i = 0; i < sides; ++i) {
        vertices[i][0] = -vertices[i][0];
    }
}

// Display function to display the polygon
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    drawPolygon();

    glutSwapBuffers();
}

// Menu function: Opens a menu with folowing options upon right click on the output screen
void menu(int option) {
    switch (option) {
        case 1: translate(2.0, 2.0); break;
        case 2: rotate(30.0); break;
        case 3: scale(1.5, 1.5); break;
        case 4: shear(0.5, 0.0); break;
        case 5: reflect(); break;
        case 6: exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("2D Transformations");

    // Initialize the polygon vertices with some values
    for (int i = 0; i < sides; ++i) {
        float angle = i * 2.0 * 3.14159 / sides;
        vertices[i][0] = 2.0 * cos(angle);
        vertices[i][1] = 2.0 * sin(angle);
    }

    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    // Create a menu for transformation operations
    glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Shear", 4);
    glutAddMenuEntry("Reflect", 5);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Setting right click to oprn the options menu

    glutDisplayFunc(display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutMainLoop();

    return 0;
}
