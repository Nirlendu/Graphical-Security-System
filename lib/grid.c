

void calli();
int tit=0;
void blender();

//the sequence of clicks


int x[]={160,480,480,160},y[]={120,120,360,360};
int count=0,i=0;


static void displayj(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	glColor3d(1,0,0);
	glVertex3f(-6.25,.25,-10);glVertex3f(-.25,.25,-10);
	glVertex3f(-.25,4.5,-10);
	glVertex3f(-6.25,4.5,-10);
	glColor3d(0,1,0);
	glVertex3f(.25,.25,-10);
	glVertex3f(6.25,.25,-10);
	glVertex3f(6.25,4.5,-10);
	glVertex3f(.25,4.5,-10);
	glColor3d(0,0,1);
	glVertex3f(-6.25,-4.5,-10);
	glVertex3f(-.25,-4.5,-10);
	glVertex3f(-.25,-.25,-10);
	glVertex3f(-6.25,-.25,-10);
	glColor3d(1,1,0);
	glVertex3f(.25,-4.5,-10);
	glVertex3f(6.25,-4.5,-10);
	glVertex3f(6.25,-.25,-10);
	glVertex3f(.25,-.25,-10);
	glEnd();
	glFlush();
	glutSwapBuffers();
}


static void keyj(unsigned char key, int xi, int yi)
{
	switch (key)
	{
		case 27 :
		case 'q':
			exit(0);
			break;
	}
	glutPostRedisplay();
}




static void idlej(void)
{
	glutPostRedisplay();
}




void selectFont(int newfont)
{
	font = fonts[newfont];
	glutPostRedisplay();
}




void selectMessage(int msg)
{
	switch (msg) {
		case 1:
			message = "please try again";
			break;
		case 2:
			message = "PLEASE TRY AGAIN";
			break;
		}
}





void tick(void)
{
	angle -= 2;
	glutPostRedisplay();
}





void displayx(void)
{
	int len, i;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-750, 0, 0);
	len = (int) strlen(message);
	for (i = 0; i < len; i++) {
		glutStrokeCharacter(font, message[i]);
	}
	glPopMatrix();
	glutSwapBuffers();
}






void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}




void displays(void)
{
	tit++;
	glClear(GL_COLOR_BUFFER_BIT);
	if(tit%2==0&&tit!=2)
	{
		if(count==4){
			blender();
			}	
		if(i==4&&count!=4)
			calli();
	}
}




static void resizej(int widths, int heights)
{
	const float ar = (float) widths / (float) heights;
	glViewport(0, 0, widths, heights);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity() ;
}




void click(int button,int state,int a,int b)
{
	glutDisplayFunc(display);
	if(button==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_UP)
		{
			if(a<=x[i]+160 && a>=x[i]-160 && b<=y[i]+120 && b>=y[i]-120)
			{
				count++;
			}
			i++;
			glutDisplayFunc(displays);
		}
	}
	glutPostRedisplay();
}



extern void selectp()
{
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );
	glutCreateWindow("Pattern Grid");
	glutReshapeFunc(resizej);
	glutDisplayFunc(displayj);
	glutKeyboardFunc(keyj);
	glutIdleFunc(idlej);
	glClearColor(0,0,0,0);
	glutMouseFunc(click);
	if(i==4||count==4)
		exit(0);
	glutMainLoop();
}

