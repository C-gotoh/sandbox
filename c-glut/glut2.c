#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int vertices = 6;

uint time = 0;

double pi = 3.141592653589793;

float height = 3.0;

int colmod;

int rotate = 0;

void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

    glLineWidth(10);

    int i;
    double factor = 2*pi/vertices;

    glColor3f (0.0, 0.0, 0.0);

    // Draw Sandwatch

    //draw bottom
    glBegin(GL_POLYGON);
        for (i=0; i< vertices; i++) {
            glVertex3f (sin(factor*i), cos(factor*i), -height);
        }
    glEnd();

    //draw top

    glBegin(GL_POLYGON);
        for (i=0; i< vertices; i++) {
            glVertex3f (sin(factor*i), cos(factor*i), height);
        }
    glEnd();

    //draw top pillar

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f (0.0, 0.0, 0.0);
        for (i=0; i< vertices+1; i++) {
            if (colmod % 2 == 0) {
            glColor3f (0.0, 1.0, 0.0);
            }
            else {
            glColor3f (0.0, 0.7, 0.0);
            }
            glVertex3f (sin(factor*i), cos(factor*i), height);
            colmod++;
        }
    glEnd();

    //draw bottom pillar
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f (0.0, 0.0, 0.0);
        for (i=0; i< vertices+1; i++) {
            if (colmod % 2 == 0) {
            glColor3f (1.0, 0.0, 1.0);
            }
            else {
            glColor3f (1.0, 0.0, 0.7);
            }
            glVertex3f (sin(factor*i), cos(factor*i), -height);
            colmod++;
        }
    glEnd();
    // //Draw Sandwatch
    if (rotate==1)
        glRotatef(0.1f, 0.0f, 0.0f, 1.0f);
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

static void Key(unsigned char key, int x, int y)
{
    //printf("%c\n", key);
    switch (key) {
        case ' ':
            rotate = (rotate+1)%2; break;
        case '+':
            vertices++; break;
        case '4':
            vertices++; break;
        case '-':
            vertices--; break;
        case '5':
            vertices--; break;
        case 27:
            exit(0); 
    }
    if (vertices <3)
        vertices = 3;
    else if (vertices>50)
        vertices = 50;
    glutPostRedisplay();
}
static void Special(int special, int x, int y){
  switch (special) {
    case 100:
        //printf("Pfeil nach links\n"); 
        glRotatef(5.0f, 0.0f, 1.0f, 0.0f);
        break;
    case 101:
        //printf("Pfeil nach oben\n");
        glRotatef(5.0f, 1.0f, 0.0f, 0.0f); 
        break;
    case 102:
        //printf("Pfeil nach rechts\n"); 
        glRotatef(5.0f, 0.0f, -1.0f, 0.0f);
        break;
    case 103:
        //printf("Pfeil nach unten\n");
        glRotatef(5.0f, -1.0f, 0.0f, 0.0f); 
        break;

  }
}

int main(int argc, char **argv){
    GLenum type;
    type = GLUT_SINGLE;

    glutInit(&argc, argv);

    glutInitDisplayMode(type);

    glutInitWindowPosition(50, 50);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Hello GLUUUT");

    init ();

    glutDisplayFunc(display);

    glutKeyboardFunc(Key);

    glutSpecialFunc(Special);

    glutIdleFunc(display);

    glutMainLoop();

    return 0;
}