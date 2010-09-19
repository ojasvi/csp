#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include<stdio.h>

#define PI 3.1415926535898
float p_a=-3.0,p_b=1.0;
float pa=0,pb=0;
static GLfloat spin = 0.0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void init(void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3d(1,0,0);

GLint circle_points = 100;
double angle;
//glutSolidSphere(0.075, 50, 50);
glPushMatrix();

glBegin(GL_POLYGON);
  glColor3f(0.5,0.5,0.5);

/*for (int i = 0; i < circle_points; i++) {
angle = 2*PI*i/circle_points;*/
//}
glVertex2f(-2.575,-2.575);

glVertex2f(-2.575,2.575);
glVertex2f(2.575,2.575);
glVertex2f(2.575,-2.575);
glEnd();
glRectf(2.575,2.575,-2.575,-2.575);
 glPopMatrix();
    glPushMatrix();
 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1.0, 1.0, 2.0, 100.0);
    glColor3d(0.2,0.8,0.0);
 glTranslated(pa,pb,-6);
 glutSolidSphere(0.105, 50, 50);
 glPopMatrix();

//if(p<0.51)
{
    

pa+=p_a;
pb+=p_b;
}
 if(pa>2.5)
 {
     p_a=-0.0555;
 }
 else if(pa<-2.5)
 {
     p_a=0.0555;
 }
if(pb>2.5)
 {
     p_b=-0.0255;
 }
 else if(pb<-2.5)
 {
     p_b=0.0255;
 }
//else p=0.0;


glutSwapBuffers();
glutPostRedisplay();

}
/*void spinDisplay(void)
{
spin = spin + 2.0;
if (spin > 360.0)
spin = spin - 360.0;
glutPostRedisplay();
}
 */
static void idle(void)
{
   glutPostRedisplay();
}
void reshape(int width, int height)
{
const float ar = (float) width / (float) height;

   /* glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
*/
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

}
void mouse(int button, int state, int x, int y)
{
switch (button) {
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN)
//glutIdleFunc(spinDisplay);
break;
case GLUT_MIDDLE_BUTTON:
if (state == GLUT_DOWN)
glutIdleFunc(NULL);
break;
default:
break;
}
}
/*
* Request double buffer display mode.
* Register mouse input callback functions
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
//init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
//glutIdleFunc(idle);
 glClearColor(1,1,1,1);
glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

   glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
   glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

glutMainLoop();
return EXIT_SUCCESS;
}

