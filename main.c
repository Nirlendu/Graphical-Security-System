#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdarg.h>
#define MAXOBJS 10000
#define MAXSELECT 100
#define MAXFEED 300
#define SOLID 1
#define LINE 2
#define POINT 3
#define MESSAGE "You are authorised to use the system"
#include"lib/first_screen.c"
#include"lib/grid.c"
#include"lib/auth_user.c"
#include"lib/unauth_user.c"
#include"lib/final_triangles.c"




int main(int argc, char **argv)
{
	int submenu;
	glutInit(&argc, argv);
	glutInitWindowSize(W, H);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	myinit();glutReshapeFunc(myReshapep);
	glutDisplayFunc(displayp);
	submenu = glutCreateMenu(polygon_mode);
	glutAddMenuEntry("Filled", 1);
	glutAddMenuEntry("Outline", 2);
	glutCreateMenu(main_menu);
	glutAddMenuEntry("Quit", 666);
	glutAddSubMenu("Polygon mode", submenu);
	glutPassiveMotionFunc(passive);
	glutEntryFunc(entry);
	glutMenuStatusFunc(mstatus);
	glutMouseFunc(clickp);
	glutMainLoop();
	return 0;
}
