#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float scale = 1.0f;

void init() {
    glClearColor(1.0, 0.7, 0.5, 1.0);  // Белый фон
    glEnable(GL_DEPTH_TEST);
}

void drawOctahedron() {

    // Рёбра октаэдра
    glColor3f(0.0, 0.0, 0.0);  // Чёрный цвет для рёбер
    glutWireOctahedron();

    // Грани октаэдра
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // Красный цвет
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);

    glColor3f(0.0, 1.0, 0.0);  // Зелёный цвет
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(0.0, 0.0, 1.0);  // Синий цвет
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);

    glColor3f(1.0, 1.0, 0.0);  // Жёлтый цвет
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, -1.0, 0.0);

    glColor3f(1.0, 0.0, 1.0);  // Фиолетовый цвет
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);

    glColor3f(0.0, 1.0, 1.0);  // Бирюзовый цвет
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(1.0, 0.5, 0.0);  // Оранжевый цвет
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, 0.0, -1.0);

    glColor3f(0.5, 0.0, 1.0);  // Фиолетовый цвет
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, -1.0, 0.0);
    glEnd();

    
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angleX, 0.0, 1.0, 0.0);
    glRotatef(angleY, 1.0, 0.0, 0.0);
    glScalef(scale, scale, scale);

    drawOctahedron();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'x':
        angleX += 5.0f;
        break;
    case 'y':
        angleY += 5.0f;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) {
            scale += 0.1f;
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN) {
            scale -= 0.1f;
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("LW3_ComputerGraphics");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
