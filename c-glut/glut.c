#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

/*  draw white polygon (rectangle) with corners at
 *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f (0.25, 0.25, 0.0);
        glVertex3f (0.75, 0.25, 0.0);
        glVertex3f (0.75, 0.75, 0.0);
        glVertex3f (0.25, 0.75, 0.0);
    glEnd();

/*  don't wait!  
 *  start processing buffered OpenGL routines 
 */
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

static void Key(unsigned char key, int x, int y)
{
    printf("%c\n", key);
    switch (key) {
        case 27:
            exit(0); 
    }
}
static void Special(int special, int x, int y)
{
  switch (special) {
    case 100:
        printf("Pfeil nach links\n"); 
        break;
    case 101:
        printf("Pfeil nach oben\n"); 
        break;
    case 102:
        printf("Pfeil nach rechts\n"); 
        break;
    case 103:
        printf("Pfeil nach unten\n"); 
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

    glutMainLoop();

    return 0;
}