
/************************************************************************************

File: 			ScreenSaver.c

Description:	A complete OpenGL program that draws a K on the screen.

Author:			Surya Kashyap 

*************************************************************************************/


/* include the library header files */
#include <freeglut.h>

//variables for window size
GLint windowHeight = 500;
GLint windowWidth = 500;

//variables for mouse clicks
GLint mouseClicked = 0;
GLint sparksButtonClicked = 0;
GLint sparkleButtonClicked = 0;
GLint morphButtonClicked = 0;
GLfloat mouseX, mouseY;

//first polygon points
GLfloat A1[2] = { -0.3,0.6 }, A2[2] = { -0.1,0.6 }, A3[2] = { -0.1, -0.2 }, A4[2] = { -0.3, -0.2 };
//second polygon points
GLfloat B1[2] = { 0.2,0.6 }, B2[2] = { 0.3,0.5 }, B3[2] = { -0.1,0.2 }, B4[2] = { -0.1,0.4 };
//third polygon points
GLfloat C1[2] = { 0.3, -0.1 }, C2[2] = { 0.2, -0.2 }, C3[2] = { -0.1,0.0 }, C4[2] = { -0.1, 0.2 };

GLfloat P1[2] = { -0.9, 1.0 };
GLfloat P2[2] = { -0.9, 0.9 };
GLfloat X1[2] = { -0.9, 1.0 };
GLfloat X2[2] = { -0.9, 0.9 };
GLfloat Q1[2] = { -1.0, 0.95 };
GLfloat Q2[2] = { -0.8, 0.95 };
GLfloat Y1[2] = { -1.0, 0.95 };
GLfloat Y2[2] = { -0.8, 0.95 };
GLfloat R1[2] = { -1.0, 1.0 };
GLfloat V1[2] = { -1.0, 1.0 };
GLfloat R2[2] = { -0.8, 0.9 };
GLfloat V2[2] = { -0.8, 0.9 };
GLfloat S1[2] = { -0.8, 1.0 };
GLfloat W1[2] = { -0.8, 1.0 };
GLfloat S2[2] = { -1.0, 0.9 };
GLfloat W2[2] = { -1.0, 0.9 };

//interpolation
GLfloat sparkleInterp = 0.0;

GLfloat morphInterp = 0.0;

GLint count = 0;




/************************************************************************

Function:		initializeGL

Description:	Initializes the OpenGL rendering context for display.

*************************************************************************/
void initializeGL(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glColor3f(1.0f, 1.0f, 1.0f);

	// set the dot size to be 4 by 4 pixels
	glPointSize(4.0);

	// set to projection mode
	glMatrixMode(GL_PROJECTION);

	// load the identity matrix
	glLoadIdentity();

	// set the shade model
	glShadeModel(GL_SMOOTH);

	//enable smooth line-drawing 
	glEnable(GL_LINE_SMOOTH);
}

void myIdle(void)
{
	if (mouseClicked)
	{
		if (sparkleButtonClicked)
		{
			sparkleInterp += 0.0005;
		}
		else
		{
			sparkleInterp = 0.0;
		}
	}

	if (mouseClicked)
	{
		if (morphButtonClicked)
		{
			morphInterp += 0.00009;
		}
		else
		{
			morphInterp = 0.0;
		}
	}


	if (morphInterp >= 1.0)
	{
		morphInterp = 1.0;
	}

	//loop the sparkle in a pattern
	if (sparkleInterp >= 1.0)
	{
		if (count == 0)
		{
			P1[0] = X1[0], P1[1] = X1[1], P2[0] = X2[0], P2[1] = X2[1];
			Q1[0] = Y1[0], Q1[1] = Y1[1], Q2[0] = Y2[0], Q2[1] = Y2[1];
			R1[0] = V1[0], R1[1] = V1[1], R2[0] = V2[0], R2[1] = V2[1];
			S1[0] = W1[0], S1[1] = W1[1], S2[0] = W2[0], S2[1] = W2[1];

			X1[0] = 0.9, X1[1] = 1.0, X2[0] = 0.9, X2[1] = 0.9;
			Y1[0] = 1.0, Y1[1] = 0.95, Y2[0] = 0.8, Y2[1] = 0.95;
			V1[0] = 1.0, V1[1] = 1.0, V2[0] = 0.8, V2[1] = 0.9;
			W1[0] = 0.8, W1[1] = 1.0, W2[0] = 1.0, W2[1] = 0.9;
			count++;
		}
		else if (count == 1)
		{
			P1[0] = X1[0], P1[1] = X1[1], P2[0] = X2[0], P2[1] = X2[1];
			Q1[0] = Y1[0], Q1[1] = Y1[1], Q2[0] = Y2[0], Q2[1] = Y2[1];
			R1[0] = V1[0], R1[1] = V1[1], R2[0] = V2[0], R2[1] = V2[1];
			S1[0] = W1[0], S1[1] = W1[1], S2[0] = W2[0], S2[1] = W2[1];

			X1[0] = -0.9, X1[1] = -0.8, X2[0] = -0.9, X2[1] = -0.7;
			Y1[0] = -1.0, Y1[1] = -0.75, Y2[0] = -0.8, Y2[1] = -0.75;
			V1[0] = -1.0, V1[1] = -0.8, V2[0] = -0.8, V2[1] = -0.7;
			W1[0] = -0.8, W1[1] = -0.8, W2[0] = -1.0, W2[1] = -0.7;
			count++;
		}
		else if (count == 2)
		{
			P1[0] = X1[0], P1[1] = X1[1], P2[0] = X2[0], P2[1] = X2[1];
			Q1[0] = Y1[0], Q1[1] = Y1[1], Q2[0] = Y2[0], Q2[1] = Y2[1];
			R1[0] = V1[0], R1[1] = V1[1], R2[0] = V2[0], R2[1] = V2[1];
			S1[0] = W1[0], S1[1] = W1[1], S2[0] = W2[0], S2[1] = W2[1];

			X1[0] = 0.9, X1[1] = -0.8, X2[0] = 0.9, X2[1] = -0.7;
			Y1[0] = 1.0, Y1[1] = -0.75, Y2[0] = 0.8, Y2[1] = -0.75;
			V1[0] = 1.0, V1[1] = -0.8, V2[0] = 0.8, V2[1] = -0.7;
			W1[0] = 0.8, W1[1] = -0.8, W2[0] = 1.0, W2[1] = -0.7;
			count++;
		}
		else if (count == 3)
		{
			P1[0] = X1[0], P1[1] = X1[1], P2[0] = X2[0], P2[1] = X2[1];
			Q1[0] = Y1[0], Q1[1] = Y1[1], Q2[0] = Y2[0], Q2[1] = Y2[1];
			R1[0] = V1[0], R1[1] = V1[1], R2[0] = V2[0], R2[1] = V2[1];
			S1[0] = W1[0], S1[1] = W1[1], S2[0] = W2[0], S2[1] = W2[1];

			X1[0] = -0.9, X1[1] = 1.0, X2[0] = -0.9, X2[1] = 0.9;
			Y1[0] = -1.0, Y1[1] = 0.95, Y2[0] = -0.8, Y2[1] = 0.95;
			V1[0] = -1.0, V1[1] = 1.0, V2[0] = -0.8, V2[1] = 0.9;
			W1[0] = -0.8, W1[1] = 1.0, W2[0] = -1.0, W2[1] = 0.9;

			count = 0;
		}

		sparkleInterp = 0.0;
	}

	//force GLUT to draw the display again
	glutPostRedisplay();
}


/************************************************************************

Function:		display

Description:	Draws a K.

*************************************************************************/
void display(void)
{
	// clear the screen 
	glClear(GL_COLOR_BUFFER_BIT);
	// draw the first polygon
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f((1 - morphInterp) * A1[0] + morphInterp * -0.15, (1 - morphInterp) * A1[1] + morphInterp * 0.3);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f((1 - morphInterp) * A2[0] + morphInterp * 0.0, (1 - morphInterp) * A2[1] + morphInterp * 0.2);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f((1 - morphInterp) * A3[0] + morphInterp * -0.2, (1 - morphInterp) * A3[1] + morphInterp * -0.1);
	glColor3f(0.0, 1.0, 1.0);
	glVertex2f((1 - morphInterp) * A4[0] + morphInterp * -0.3, (1 - morphInterp) * A4[1] + morphInterp * 0.0);
	glEnd();

	//draw the second polygon
	glBegin(GL_POLYGON);
	glVertex2f((1 - morphInterp) * B1[0] + morphInterp * 0.1, (1 - morphInterp) * B1[1] + morphInterp * 0.5);
	glVertex2f((1 - morphInterp) * B2[0] + morphInterp * 0.2, (1 - morphInterp) * B2[1] + morphInterp * 0.4);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2f((1 - morphInterp) * B3[0] + morphInterp * -0.1, (1 - morphInterp) * B3[1] + morphInterp * 0.2);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f((1 - morphInterp) * B4[0] + morphInterp * -0.2, (1 - morphInterp) * B4[1] + morphInterp * 0.3);
	glEnd();

	//draw the last polygon
	glBegin(GL_POLYGON);
	glVertex2f((1 - morphInterp) * C1[0] + morphInterp * -0.2, (1 - morphInterp) * C1[1] + morphInterp * 0.0);
	glVertex2f((1 - morphInterp) * C2[0] + morphInterp * -0.1, (1 - morphInterp) * C2[1] + morphInterp * -0.1);
	glVertex2f((1 - morphInterp) * C3[0] + morphInterp * -0.4, (1 - morphInterp) * C3[1] + morphInterp * -0.3);
	glVertex2f((1 - morphInterp) * C4[0] + morphInterp * -0.3, (1 - morphInterp) * C4[1] + morphInterp * -0.2);
	glEnd();

	//draw the sparkle
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f((1 - sparkleInterp) * P1[0] + sparkleInterp * X1[0], (1 - sparkleInterp) * P1[1] + sparkleInterp * X1[1]);
	glVertex2f((1 - sparkleInterp) * P2[0] + sparkleInterp * X2[0], (1 - sparkleInterp) * P2[1] + sparkleInterp * X2[1]);

	glVertex2f((1 - sparkleInterp) * Q1[0] + sparkleInterp * Y1[0], (1 - sparkleInterp) * Q1[1] + sparkleInterp * Y1[1]);
	glVertex2f((1 - sparkleInterp) * Q2[0] + sparkleInterp * Y2[0], (1 - sparkleInterp) * Q2[1] + sparkleInterp * Y2[1]);

	glVertex2f((1 - sparkleInterp) * R1[0] + sparkleInterp * V1[0], (1 - sparkleInterp) * R1[1] + sparkleInterp * V1[1]);
	glVertex2f((1 - sparkleInterp) * R2[0] + sparkleInterp * V2[0], (1 - sparkleInterp) * R2[1] + sparkleInterp * V2[1]);

	glVertex2f((1 - sparkleInterp) * S1[0] + sparkleInterp * W1[0], (1 - sparkleInterp) * S1[1] + sparkleInterp * W1[1]);
	glVertex2f((1 - sparkleInterp) * S2[0] + sparkleInterp * W2[0], (1 - sparkleInterp) * S2[1] + sparkleInterp * W2[1]);
	glEnd();

	//draw the bottom bar
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(-1.0, -0.8);
	glVertex2f(1.0, -0.8);
	glVertex2f(1.0, -1.0);
	glVertex2f(-1.0, -1.0);
	glEnd();

	//draw the first button
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.9, -0.85);
	glVertex2f(-0.6, -0.85);
	glVertex2f(-0.6, -0.95);
	glVertex2f(-0.9, -0.95);
	glEnd();

	//draw the second button
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.2, -0.85);
	glVertex2f(0.2, -0.85);
	glVertex2f(0.2, -0.95);
	glVertex2f(-0.2, -0.95);
	glEnd();

	//draw the third button
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.9, -0.85);
	glVertex2f(0.6, -0.85);
	glVertex2f(0.6, -0.95);
	glVertex2f(0.9, -0.95);
	glEnd();

	//set color for button text
	glColor3f(1.0, 1.0, 1.0);

	//first button text
	GLfloat fXPos = -0.85;
	char fButton[] = { 'S','P', 'A', 'R', 'K', 'S' };
	for (int i = 0; i < 6; i++)
	{
		glRasterPos2f(fXPos, -0.925);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, fButton[i]);
		fXPos += 0.03;
	}

	//second button text
	GLfloat sXPos = -0.15;
	char sButton[] = { 'S','P', 'A', 'R', 'K', 'L', 'E' };
	for (int i = 0; i < 7; i++)
	{
		glRasterPos2f(sXPos, -0.925);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, sButton[i]);
		sXPos += 0.03;
	}

	//third button text
	GLfloat tXPos = 0.65;
	char tButton[] = { 'M','O', 'R', 'P', 'H' };
	for (int i = 0; i < 5; i++)
	{
		glRasterPos2f(tXPos, -0.925);
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, tButton[i]);
		tXPos += 0.03;
	}

	if (mouseClicked)
	{
		glBegin(GL_POINTS);

		// draw the vertex at that point
		glVertex2f(mouseX, mouseY);

		glEnd();
	}
	// switch to the other buffer
	glutSwapBuffers();
}


/************************************************************************

Function:		myMouse

Description:	Handles mouse clicks and hovers

*************************************************************************/
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseClicked = 1;
		// convert x from Mouse coordinates to OpenGL coordinates
		mouseX = (GLfloat)x / (GLfloat)windowWidth;
		mouseX = mouseX * 2.0f - 1.0f;

		// convert y from Mouse coordinates to OpenGL coordinates
		mouseY = (GLfloat)windowHeight - (GLfloat)y;  // first invert mouse Y position
		mouseY = mouseY / (GLfloat)windowHeight;
		mouseY = mouseY * 2.0f - 1.0f;

		if (mouseX >= -0.2 && mouseX <= 0.2 && mouseY <= -0.85 && mouseY >= -0.95)
		{
			if (sparkleButtonClicked)
			{
				sparkleButtonClicked = 0;
			}
			else
			{
				sparkleButtonClicked = 1;
			}
		}

		if (mouseX >= 0.6 && mouseX <= 0.9 && mouseY <= -0.85 && mouseY >= -0.95)
		{
			if (morphButtonClicked)
			{
				morphButtonClicked = 0;
			}
			else
			{
				morphButtonClicked = 1;
			}
		}
		glutPostRedisplay();

	}
}

/************************************************************************

Function:		main

Description:	Sets up the openGL rendering context and the windowing
system, then begins the display loop.

*************************************************************************/
void main(int argc, char** argv)
{
	// initialize the toolkit
	glutInit(&argc, argv);
	// set display mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// set window size
	glutInitWindowSize(windowWidth, windowHeight);
	// open the screen window
	glutCreateWindow("Assignment 1");
	// register redraw function
	glutDisplayFunc(display);
	//idle function
	glutIdleFunc(myIdle);
	// mouse function
	glutMouseFunc(myMouse);
	//initialize the rendering context
	initializeGL();
	// go into a perpetual loop
	glutMainLoop();
}
