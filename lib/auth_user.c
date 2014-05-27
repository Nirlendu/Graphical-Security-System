
void mstatus(int status, int newx, int newy)
{
	if (status == GLUT_MENU_NOT_IN_USE) {
		menu_inuse = 0;
		passive(newx, newy);
	} else {
		menu_inuse = 1;
	}
}




void main_menu(int value)
{
if (value == 666)
	exit(0);
}




void displaycc(void)
{
	static GLfloat amb[] = {0.4, 0.4, 0.4, 0.0};
	static GLfloat dif[] ={1.0, 1.0, 1.0, 0.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	amb[3] = dif[3] = cos(s) / 2.0 + 0.5;
	glMaterialfv(GL_FRONT, GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,dif);
	glPushMatrix();
	glTranslatef(-0.3, -0.3, 0.0);
	glRotatef(angle1, 1.0, 5.0, 0.0);
	glCallList(1);
	glPopMatrix();
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHT2);
	glDisable(GL_LIGHT1);
	amb[3] = dif[3] = 0.5 - cos(s * .95)/2.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT,amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,dif);
	glPushMatrix();
	glTranslatef(0.3, 0.3, 0.0);
	glRotatef(angle2, 1.0, 0.0, 5.0);
	glCallList(1);
	glPopMatrix();
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 1500, 0, 1500);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	output(200, 225, "WELCOME :)");
	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_BLEND);
	output(160, 100, "Leftclick to advance, Rightclick to exit");
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glPopAttrib();
	glMatrixMode(GL_MODELVIEW);
	glutSwapBuffers();
}

