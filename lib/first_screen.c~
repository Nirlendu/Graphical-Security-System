#define BUFSIZE 512
#define TORUS 1
#define TETRAHEDRON 2
#define ICOSAHEDRON 3


#include"../include/first_screen.h"

//all global variables

GLfloat light0_ambient[] = {0.2, 0.2, 0.2, 1.0};
GLfloat light0_diffuse[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light1_diffuse[] = {1.0, 0.0, 0.0, 1.0};
GLfloat light1_position[] ={1.0, 1.0, 1.0, 0.0};
GLfloat light2_diffuse[] = {0.0, 1.0, 0.0, 1.0};
GLfloat light2_position[] = {-1.0, -1.0, 1.0, 0.0};
float s = 0.0;
GLfloat angle1 = 0.0, angle2 = 0.0;
void *font = GLUT_STROKE_ROMAN;
void *fonts[] ={GLUT_STROKE_ROMAN, GLUT_STROKE_MONO_ROMAN};
char defaultMessage[] = "You are not AUTHORISED !!";
char *message = defaultMessage;
int angle = 0;
GLuint selectBuff[BUFSIZE];
int W = 500, H = 500;
GLfloat xp, yp;
int locating = 0;
int theObject = 0;
int menu_inuse = 0;
int mouse_state = 0;
char *objectNames[] ={"Nothing", "Torus", "Tetrahedron", "Icosahedron"};





void output(GLfloat xp, GLfloat yp, char *format,...)
{
	va_list args;
	char buffer[200], *p;
	va_start(args, format);
	vsprintf(buffer, format, args);
	va_end(args);
	glPushMatrix();glTranslatef(xp, yp, 0);
	for (p = buffer; *p; p++)
	glutStrokeCharacter(GLUT_STROKE_ROMAN,*p);
	glPopMatrix();
}




void myinit(void)
{
	GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glSelectBuffer(BUFSIZE, selectBuff);
	glNewList(TORUS, GL_COMPILE);
	glutSolidTorus(0.275, 0.85, 10, 15);
	glEndList();
	glNewList(TETRAHEDRON, GL_COMPILE);
	glutSolidTetrahedron();
	glEndList();
	glNewList(ICOSAHEDRON, GL_COMPILE);
	glutSolidIcosahedron();
	glEndList();
}




void highlightBegin(void)
{
	static GLfloat red[4] ={1.0, 0.0, 0.0, 1.0};
	glPushAttrib(GL_LIGHTING_BIT | GL_CURRENT_BIT);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red);
	glColor3f(1.0, 0.0, 0.0);
}



void highlightEnd(void)
{
	glPopAttrib();
}




void drawp(void)
{
	glPushMatrix();
	glScalef(1.3, 1.3, 1.3);
	glRotatef(20.0,1.0, 0.0, 0.0);
	glLoadName(2);
	glPushMatrix();
	if (theObject == 2)
	highlightBegin();
	glTranslatef(-0.75, -0.5, 0.0);
	glRotatef(270.0,1.0, 0.0, 0.0);
	glCallList(TETRAHEDRON);
	if (theObject == 2)
	highlightEnd();
	glPopMatrix();
	glLoadName(1);
	glPushMatrix();
	if (theObject == 1)
	highlightBegin();
	glTranslatef(-0.75, 0.5, 0.0);
	glRotatef(90.0,1.0, 0.0, 0.0);
	glCallList(TORUS);
	if (theObject == 1)
	highlightEnd();
	glPopMatrix();
	glLoadName(3);
	glPushMatrix();
	if (theObject == 3)
	highlightBegin();
	glTranslatef(0.75, 0.0, -1.0);
	glCallList(ICOSAHEDRON);
	if (theObject == 3)
	highlightEnd();
	glPopMatrix();
	glPopMatrix();
}





void myortho(void)
{
	if (W <= H)
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat) H / (GLfloat) W,2.5 * (GLfloat) H / (GLfloat) W, -10.0, 10.0);
	else
	glOrtho(-2.5 * (GLfloat) W / (GLfloat) H,2.5 * (GLfloat) W / (GLfloat) H, -2.5, 2.5, -10.0, 10.0);
}




void processHits(GLint hits, GLuint buffer[])
{
	GLuint depth = 0;
	unsigned int i, getThisName;
	GLuint names, *ptr;
	GLuint newObject;
	ptr = (GLuint *) buffer;
	newObject = 0;
	for (i = 0; i < hits; i++) {
		getThisName = 0;
		names = *ptr;
		ptr++;
		if (*ptr <= depth) {
			depth = *ptr;
			getThisName = 1;
			}
		ptr++;
		if (*ptr <= depth) {
			depth = *ptr;
			getThisName = 1;
			}
		ptr++;
		if (!getThisName)
			newObject = *ptr;
		ptr += names;
	}
	if (theObject != newObject) {
		theObject = newObject;
		glutPostRedisplay();
	}
}


void locate(int value)
{
	GLint viewport[4];
	GLint hits;
	if (locating) {
		if (mouse_state == GLUT_ENTERED) {
			(void) glRenderMode(GL_SELECT);
			glInitNames();
			glPushName(-1);
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			viewport[0] = 0;
			viewport[1] = 0;
			viewport[2] = W;
			viewport[3] = H;
			gluPickMatrix(xp, H - yp, 5.0, 5.0, viewport);
			myortho();
			glMatrixMode(GL_MODELVIEW);
			drawp();
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
			hits = glRenderMode(GL_RENDER);
		}else {
			hits = 0;
		}
		processHits(hits, selectBuff);
	}
	locating = 0;
}




void passive(int newx, int newy)
{
	xp = newx;
	yp = newy;
	if (!locating) {
		locating = 1;
		glutTimerFunc(1, locate, 0);
	}
}





void entry(int state)
{
	mouse_state = state;
		if (!menu_inuse) {
			if (state == GLUT_LEFT) {
				if (theObject != 0) {
					theObject = 0;
					glutPostRedisplay();
				}
			}
		}
}



void displayp(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawp();
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LINE_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 3000, 0, 3000);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	output(80, 2800, "Leftclick to advance, Rightclick to exit");
	output(80, 100, "Located:%s.", objectNames[theObject]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
	glutSwapBuffers();
}



void myReshapep(int w, int h)
{
	W = w;
	H = h;
	glViewport(0, 0, W, H);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	myortho();
	glMatrixMode(GL_MODELVIEW);
}


void polygon_mode(int value)
{
	switch (value) {
		case 1:
			glEnable(GL_LIGHTING);
			glDisable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glPolygonMode(GL_FRONT_AND_BACK,
			GL_FILL);
			break;
		case 2:
			glDisable(GL_LIGHTING);
			glColor3f(1.0, 1.0, 1.0);
			glPolygonMode(GL_FRONT_AND_BACK,
			GL_LINE);
			glEnable(GL_LINE_SMOOTH);
			glEnable(GL_BLEND);
			glDisable(GL_DEPTH_TEST);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			break;
	}
	glutPostRedisplay();
}



