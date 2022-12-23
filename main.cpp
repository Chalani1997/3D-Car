#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


/* GLUT callback Handlers */
float theta1 = 0.0;
float theta2 = 0.0;
float theta3 = 0.0;
float drive = 0.0;



static void resize(int width, int height)
{

    const float ar = (float) width / (float) height;

    glViewport(5, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(20.0, 20.0, 20.0,        // - eye point
              1.0, 0.0, 0.0,        // - center point
              0.0, 1.0, 0.0);       // - up axis
}

void initGL()
{

    glClearColor(0.6f, 0.7f, 0.9f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1000.0, 1000.0, -1000.0, 1000.0, -1000.0, 1000.0);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    glRotatef(theta1, 1.0, 0.0, 0.0);
    glRotatef(theta2, 0.0, 1.0, 0.0);

    //vehicle body
    glPushMatrix();

        glTranslatef(drive,4.0f,0.0f);

        glPushMatrix();

        glColor3f(0.1,0.0,0.75);
        glScalef(10.0f,3.0f,6.0f);
        glutSolidCube (1.0);

        /*glTranslatef(drive,1.0f,0.0f);

        glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glutSolidSphere(0.8,5,5);

        glScalef(5.0f,3.0f,6.0f);


        glPopMatrix();*/

        glPopMatrix();



        //vehicle tires
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
            glPushMatrix();
            glTranslatef(5.0f,-2.0f,3.5f);
            glRotatef(theta3, 0.0, 0.0, 1.0);
            glScalef(1.2f,1.2f,1.0f);
            glutWireTorus(0.7,0.7,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(5.0f,-2.0f,-3.5f);
            glRotatef(theta3, 0.0, 0.0, 1.0);
            glScalef(1.2f,1.2f,1.0f);
            glutWireTorus(0.7,0.7,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-5.0f,-2.0f,3.5f);
            glRotatef(theta3, 0.0, 0.0, 1.0);
            glScalef(1.2f,1.2f,1.0f);
            glutWireTorus(0.7,0.7,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-5.0f,-2.0f,-3.5f);
            glRotatef(theta3, 0.0, 0.0, 1.0);
            glScalef(1.2f,1.2f,1.0f);
            glutWireTorus(0.7,0.7,15.0,15.0);
            glPopMatrix();


        glPopMatrix();
    glPopMatrix();


    glPopMatrix();


        glPushMatrix();
        glTranslatef(-5.0f,-2.0f,-3.5f);
        glColor3f(0.8,0.5,0.0);
        glScalef(10.0f,3.0f,6.0f);
        glutSolidCube (1.0);
        glPopMatrix();


    //arcs

            glPushMatrix();

            glColor3f(0.8,0.4,0.1);
            glTranslatef(-120.0f,+2.0f,-3.5f);
            glRotatef(90, 0.0, 1.0, 0.0);
            glScalef(10.0f,10.0f,-2.0f);
            glutWireTorus(0.5,1.5,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-60.0f,+2.0f,-3.5f);
            glRotatef(-90.0, 0.0, 1.0, 0.0);
            glScalef(10.0f,10.0f,-2.0f);
            glutWireTorus(0.5,1.5,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.0f,+2.0f,-3.5f);
            glRotatef(-90.0, 0.0, 1.0, 0.0);
            glScalef(10.0f,10.0f,-2.0f);
            glutWireTorus(0.5,1.5,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-150.0f,+2.0f,-3.5f);
            glRotatef(-90.0, 0.0, 1.0, 0.0);
            glScalef(10.0f,10.0f,-2.0f);
            glutWireTorus(0.5,1.5,15.0,15.0);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-30.0f,+2.0f,-3.5f);
            glRotatef(90, 0.0, 1.0, 0.0);
            glScalef(10.0f,10.0f,-2.0f);
            glutWireTorus(0.5,1.5,15.0,15.0);
            glPopMatrix();


    glBegin(GL_QUADS);

//a green surroundings
    glPushMatrix();
	glTranslatef(-5.0f,2.0f,-3.5f);
  glColor3f(0.0,1.0,0.0);
  glVertex3f(-200,0.1,-100);
  glVertex3f(-200,0.1,0);
  glVertex3f(200,0.1,0);
  glVertex3f(200,0.1,-100);



   //a green surroundings

  glColor3f(0,1,0);
  glVertex3f(-200,0.1,1);
  glVertex3f(-200,0.1,100);
  glVertex3f(200,0.1,100);
  glVertex3f(200,0.1,1);


    glPopMatrix();


    glPushMatrix();
    glRotatef(theta3, 0.0, 1.0, 0.0);
	glTranslatef(-5.0f,-2.0f,-3.5f);
  glColor3f(0,1,0);
  glVertex3f(-100,0.1,-100);
  glVertex3f(-100,0.1,0);
  //glVertex3f(10void drawTire()0,0.1,0);
  glVertex3f(100,0.1,-100);

  //a long road

  glColor3f(0.7,0.7,0.7);
  glVertex3f(-200,0,1.0);
  glVertex3f(-200,3.0,1.0);
  glVertex3f(200,3,1.0);
  glVertex3f(200,0,1.0);

   glEnd();

    glPopMatrix();



    glutSwapBuffers();
}


void static drawRoad(){


    }



static void idle(void)
{
    glutPostRedisplay();
}

void camMovement(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_RIGHT:
        theta1 += 5;
        if (theta1 > 360)
            theta1 = 0.0;
        break;
    case GLUT_KEY_LEFT:
        theta1 -= 5;
        if (theta1 > 360)
            theta1 = 0.0;
        break;
    case GLUT_KEY_DOWN:
        theta2 += 5;
        if (theta2 > 360)
            theta2 = 0.0;
        break;
    case GLUT_KEY_UP:
        theta2 -= 5;
        if (theta2 > 360)
            theta2 = 0.0;
        break;
    }
    glutPostRedisplay();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;

        case 'w':
            theta3 += 5;
            drive -= 1;
            break;

        case 's':
            theta3 -= 5;
            drive += 1;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D_CAR");

    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(resize);
    glutSpecialFunc(camMovement);
    glutKeyboardFunc(key);
    glutDisplayFunc(display);
    drawRoad();
    glutIdleFunc(idle);


    initGL();
    glutMainLoop();

    return EXIT_SUCCESS;
}
