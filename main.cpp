/**Group_no 17

1.Name:Tanvir Ahmed
ID:2016-1-60-010
section:2
2.Towhiduzzaman
ID:2016-1-60-031
section:2
3.MD. Saim Shadman Mukib
ID:2015-1-60-188
section:1
4.Azmain Iktidar
ID:2016-1-60-063
section:2

**/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))
#define sqrt2 (sqrt(2))

typedef struct point
{
	double x,y,z;
}Point;

bool drawAxes = true;
float tyreAngle = 0;

float quadAngle = 0;
float boxAngle = 0;
float boxScaleFactor = .95;
float tyreScaleFactor = .2;
float tinyBoxAngle = 0;
float background = 0;
int m=150;
int n=-150;
int q=1;
 int i=0;
float Angle=0;
int bb=0;
Point pos, u, r, l;

void displayAxes()
{
	if(drawAxes)
	{
		glBegin(GL_LINES);
		{
		    glColor3f(1.0, 0, 0);

			glVertex3f( 500,0,0); // a point on pos x axis
			glVertex3f(-500,0,0); // a point on neg x axis

			glColor3f(0, 1.0, 0);

			glVertex3f(0,-500,0); // a point on pos y axis
			glVertex3f(0, 500,0); // a point on neg y axis

			glColor3f(0, 0, 1.0);

			glVertex3f(0,0, 500);  // a point on pos z axis
			glVertex3f(0,0,-500);   // a point on neg z axis
		}
		glEnd();
	}
}


void displaysearch()
{

		glBegin(GL_LINES);
		{




			glColor3f(1.0, 0, 0);
            //upper therr

			glVertex3f(0,0,20); // a point on pos y axis
			glVertex3f(0,1000,70); // a point on neg y axis
            glVertex3f(5,0,20); // a point on pos y axis
            glVertex3f(5,1000,70); // a point on neg y axis
            glVertex3f(-5,0,20); // a point on pos y axis
            glVertex3f(-5,1000,70); // a point on neg y axis

            //bottom


            glVertex3f(-5,0,-20); // a point on pos y axis
			glVertex3f(-5,1000,-70); // a point on neg y axisd
            glVertex3f(0,0,-20); // a point on pos y axis
			glVertex3f(0,1000,-70); // a point on neg y axisd
            glVertex3f(5,0,-20); // a point on pos y axis
			glVertex3f(5,1000,-70); // a point on neg y axisd

			//Right


            glVertex3f(-15,0,10); // a point on pos y axis
			glVertex3f(-20,1000,10); // a point on neg y axisd
			 glVertex3f(-15,0,5); // a point on pos y axis
			glVertex3f(-20,1000,5); // a point on neg y axisd
            glVertex3f(-15,0,1); // a point on pos y axis
			glVertex3f(-20,1000,1); // a point on neg y axisd

			//left


            glVertex3f(15,0,10); // a point on pos y axis
            glVertex3f(20,1000,10); // a point on neg y axisd
            glVertex3f(15,0,5); // a point on pos y axis
			glVertex3f(20,1000,5); // a point on neg y axisd
            glVertex3f(15,0,1); // a point on pos y axis
			glVertex3f(20,1000,1); // a point on neg y axisd
			 glPopMatrix();
		}
		glEnd();
  glLineWidth(3.0f);

}



Point func(Point vect, Point perp, int dir)
{
    double c = cos(pi/180);
    double s = dir * sin(pi/180);
    Point point;
    point.x = c * vect.x + s * perp.x;
    point.y = c * vect.y + s * perp.y;
    point.z = c * vect.z + s * perp.z;
    c = sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
    point.x /= c;
    point.y /= c;
    point.z /= c;
    return point;
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){
		case '1': {
            Point l1 = func(l, r, -1);
            r = func(r, l, 1);
            l = l1;
            break;
		}
		case '2': {
            Point l1 = func(l, r, 1);
            r = func(r, l, -1);
            l = l1;
            break;
		}

		case '3': {
            Point u1 = func(u, l, -1);
            l = func(l, u, 1);
            u = u1;
            break;
        }
        case '4': {
            Point u1 = func(u, l, 1);
            l = func(l, u, -1);
            u = u1;
            break;
        }
        case '5': {
            Point r1 = func(r, u, -1);
            u = func(u, r, 1);
            r = r1;
            break;
        }
        case '6':{
            Point r1 = func(r, u, 1);
            u = func(u, r, -1);
            r = r1;
            break;
        }
        case '7':{
            boxScaleFactor+=0.10;
            tyreScaleFactor += 0.10;
            break;
        }
        case '8':{
            boxScaleFactor-=0.10;
            tyreScaleFactor -= 0.10;
            break;
        }
           case '9':{

            glRotatef(Angle,0,0,q);
            Angle=Angle+10;
            break;
        }
		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN: // down arrow
		    {
		        pos.x=pos.x+20;
		       // quadAngle += 5;
		        printf("Quad Angle %f\n", quadAngle);
		        break;
		    }

		case GLUT_KEY_UP:   // up arrow
		    {
                pos.x= pos.x-20;
		       // quadAngle -= 5;
		        printf("Quad Angle %f\n", quadAngle);
		        break;
		    }

		case GLUT_KEY_RIGHT:    // right arrow
		    {
		          pos.y= pos.y+20;
                Point l1 = func(l, r, 1);
            r = func(r, l, -1);
		       // boxAngle += 5;
		        printf("Box Angle %f\n", boxAngle);
		        break;
		    }

		case GLUT_KEY_LEFT:     // left arrow
		    {
		         pos.y= pos.y-20;
		       // boxAngle -= 5;
		        printf("Box Angle %f\n", boxAngle);
		        break;
		    }

		case GLUT_KEY_PAGE_UP:
		    {
		        pos.z=pos.z+20;
                //boxScaleFactor += 0.2;
                break;
		    }

		case GLUT_KEY_PAGE_DOWN:
		    {
		            pos.z=pos.z-20;
		        //boxScaleFactor -= 0.2;
                break;
		    }

		case GLUT_KEY_HOME:
		    {

		        tyreAngle += 5;
                n=n-5;
                glTranslatef(0,n,0);
                m=m-5;
                glTranslatef(0,m,0);
                bb=bb-5;
                glTranslatef(0, bb,30);

                break;


		    }

        case GLUT_KEY_END:
            {

                tyreAngle -= 5;
                m=m+5;
                glTranslatef(0,m,0);
                n=n+5;
                glTranslatef(0,n,0);
                bb=bb+5;
                glTranslatef(0, bb,30);
                break;
            }

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN) // 2 times?? in ONE click? -- solution is checking DOWN or UP
            {
                drawAxes=false;
                printf("Mouse Left Button Clicked\n");
			}
			else if(state == GLUT_UP)
            {
                 drawAxes=true;
                printf("Mouse Left Button Released\n");
            }
            break;
		default:
			break;
	}
}

void displayTyre(float tyreRadius, float tyreWidth)
{
    int tyreSlices = 36;
    float sliceWidth = (2 * M_PI * tyreRadius) / tyreSlices;
    float sliceAngle = 360 / tyreSlices;

    float halfTyreWidth = tyreWidth / 2, quartTyreWidth = halfTyreWidth / 2;
    float halfSliceWidth = sliceWidth / 2;


    glBegin(GL_QUADS);
    {
   glColor3f(255,255,255);
        glVertex3f(halfTyreWidth, tyreRadius, 0);
        glVertex3f(-halfTyreWidth, tyreRadius, 0);
        glColor3f(1,0,0);
        glVertex3f(-halfTyreWidth, -tyreRadius, 0);
        glVertex3f(halfTyreWidth, -tyreRadius, 0);
    }
    glEnd();


    glBegin(GL_QUADS);
    {  glColor3f(255,255,255);
        glVertex3f(halfTyreWidth, 0, tyreRadius);
        glVertex3f(halfTyreWidth, 0, -tyreRadius);
           glColor3f(1,0,0);
        glVertex3f(-halfTyreWidth, 0, -tyreRadius);
        glVertex3f(-halfTyreWidth, 0, tyreRadius);
    }
    glEnd();



    for(int i=0; i<tyreSlices; i++)
    {
        glPushMatrix();
        glRotatef(sliceAngle*i, 1, 0, 0);
        glTranslatef(0, tyreRadius, 0);

        glBegin(GL_QUADS);
        {
                glColor3f(255,255,255);
            glVertex3f(halfTyreWidth, 0, halfSliceWidth);
            glVertex3f(halfTyreWidth, 0, -halfSliceWidth);

            glColor3f(1,0,0);
            glVertex3f(-halfTyreWidth, 0, -halfSliceWidth);
            glVertex3f(-halfTyreWidth, 0, halfSliceWidth);

        }
        glEnd();

        glPopMatrix();
    }
}

void displayQuad(float quadWidth, float quadLength) // width along x axis, length along z axis
{
    float halfQuadWidth = quadWidth / 2, halfQuadLength = quadLength / 2;

    glBegin(GL_QUADS);
    {
        /** Solid Fill Quad **/

        glColor3f(1, 1, 0);

        glVertex3f(halfQuadWidth, 0, halfQuadLength);
        glVertex3f(halfQuadWidth, 0, -halfQuadLength);
        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
        glVertex3f(-halfQuadWidth, 0, halfQuadLength);

        /** Gradient Fill Quad **/


        glColor3f(1, 1, 0);

        glVertex3f(halfQuadWidth, 0, halfQuadLength);
        glVertex3f(halfQuadWidth, 0, -halfQuadLength);

        glColor3f(0, 1, 1);

        glVertex3f(-halfQuadWidth, 0, -halfQuadLength);
        glVertex3f(-halfQuadWidth, 0, halfQuadLength);

    }
    glEnd();
}

void displayBox(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(0,1,1);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);

        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);


    glColor3f(0.32,0.15,0.066);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);



        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
    }
    glEnd();
}


void displayBox1(float boxLength, float boxWidth, float boxHeight) // length -> x axis, width -> yaxis, height -> z axis
{
    float halfBoxLength = boxLength / 2, halfBoxWidth = boxWidth / 2, halfBoxHeight = boxHeight / 2;
    glBegin(GL_QUADS);
    {
        glColor3f(82,244,244);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth+50, -halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth+50, -halfBoxHeight);

        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth-50, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth-50, -halfBoxHeight);


        glColor3f(0,1,1);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);

        glColor3f(0,0,1);

        glVertex3f(halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, halfBoxHeight);


        glVertex3f(halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, halfBoxWidth, -halfBoxHeight);
        glVertex3f(-halfBoxLength, -halfBoxWidth, -halfBoxHeight);
        glVertex3f(halfBoxLength, -halfBoxWidth, -halfBoxHeight);
    }
    glEnd();
}




void displayScene()
{
    //Primitive Object dimensions

    float quadLength = 160, quadWidth = 65;
    float largeBoxLength = 150, largeBoxWidth = 450, largeBoxHeight = 30;
    float smallBoxLength = 20, smallBoxWidth = 20, smallBoxHeight = 80;
    float tinyBoxLength = 10, tinyBoxWidth = 10, tinyBoxHeight = 10;
    float tyreRadius = 100, tyreWidth = 40;


    /** Principal Axes **/

    displayAxes();

    /**/

    /** Quad **/
    /** Quad **/
    glPushMatrix();
    glTranslatef(0,m,50);
    glRotatef(quadAngle+50, 1, 0, 0); // rotates with respect to x axis
  // glRotatef(quadAngle-20, 0, 1, 0); // rotates with respect to y axis
   // glRotatef(quadAngle-50, 0, 0, 1); // rotates with respect to z axis
   // displayQuad(quadLength, quadWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-175,50);
    glRotatef(quadAngle-50, 1, 0, 0); // rotates with respect to x axis
  // glRotatef(quadAngle-20, 0, 1, 0); // rotates with respect to y axis
   // glRotatef(quadAngle-50, 0, 0, 1); // rotates with respect to z axis
  //  displayQuad(quadLength, quadWidth);
    glPopMatrix();




    /**/

    /** Single Box **/

    glTranslatef(0, 0, 0); // rotation applied first, translation applied second
    glRotatef(boxAngle, 1, 0, 0); // rotates with respect to x axis
   // glRotatef(boxAngle, 0, 1, 0); // rotates with respect to y axis
  //  glRotatef(boxAngle, 0, 0, 1); // roytates with respect to z axis
    glTranslatef(0,20,20);    // translation applied first, rotation applied second
   // displayBox(150,50, 30);
    glPopMatrix();
    /**/

    /** Double Box Stack **/

    glPushMatrix();
    glRotatef(boxAngle, 0, 0, 1); // rotation applied to both boxes
    glTranslatef(0, bb,40); // translation applied to both boxes
    glVertex3d(0,50,0);
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    displayBox1(largeBoxLength, largeBoxWidth-200, largeBoxHeight+20); // large box
    glPopMatrix();

    glPushMatrix();
    glRotatef(boxAngle, 1, 0, 0);   // rotation applied only on the small box
    glTranslatef(0,120,40); // places the small box on top of the large box
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    // small box
    glPopMatrix();


    /** Double Box Stack - Push Pop Matrix **/


 //  glRotatef(boxAngle, 0, 0, 1); // rotation applied to both boxes

  //  glPushMatrix(); // saves the matrix just before scaling, to prevent scale effect to anything other than the large box
  //  glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor); // without push-pop, scale will be applied to both boxes
   // displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
  //  glPopMatrix();

  //  glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
  //  displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight); // small box



    /** Tyre **/

   // glRotatef(tyreAngle, 1, 0, 0); // roates the tyre w.r.t x axis
   // glRotatef(tyreAngle, 0, 1, 0); // roates the tyre w.r.t y axis
  //  glRotatef(tyreAngle, 0, 0, 1); // roates the tyre w.r.t z axis
   //  glPushMatrix();
   // displayTyre(tyreRadius, tyreWidth);
 //  glPopMatrix();

    /** Tyre Double Box Stack **/

    glPushMatrix();
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
  //  displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, bb, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
   // displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight); // small box
    glPopMatrix();


   // glPushMatrix();
   // glTranslatef(0, 0, tyreRadius+smallBoxHeight+(largeBoxHeight/2)); // places the tyre on top of both boxes
    //glRotatef(tyreAngle, 1, 0, 0); // check what happens to the tyre after exchanging the order of translation and roation
    //glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    //displayTyre(tyreRadius, tyreWidth);
   // glPopMatrix();
    glPushMatrix();
    glTranslatef(75, n, -15);
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
    glRotatef(tyreAngle, 1, 0, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-75, n, -15);
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
     glRotatef(tyreAngle, 1, 0, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(75,m, -15);
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
     glRotatef(tyreAngle, 1, 0, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-75, m, -15);
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
     glRotatef(tyreAngle, 1, 0, 0);
    displayTyre(tyreRadius, tyreWidth);
    glPopMatrix();


    /** Animate Function **/
    glPushMatrix();
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    glTranslatef(0,bb,0);
    displayBox(largeBoxLength, largeBoxWidth, largeBoxHeight); // large box
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, (smallBoxHeight/2) + (largeBoxHeight/2)); // places the small box on top of the large box
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
     glTranslatef(0,bb,0);
    displayBox(smallBoxLength, smallBoxWidth, smallBoxHeight+50); // small box
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,tyreRadius+smallBoxHeight+(largeBoxHeight/2)); // places the tyre on top of both boxes
  //  glRotatef(tyreAngle, 1, 0, 0); // check what happens to the tyre after exchanging the order of translation and roation
    glScalef(tyreScaleFactor, tyreScaleFactor, tyreScaleFactor);
  //  displayTyre(tyreRadius, tyreWidth); // tyre
    glPopMatrix();

    glPushMatrix();
   // glRotatef(tinyBoxAngle, 0, 0, 1); // angle is updated in animate function

    glTranslatef(0, 0, 140);
    glScalef(boxScaleFactor, boxScaleFactor, boxScaleFactor);
    glTranslatef(0,bb,0);
    glRotatef(Angle,0,0,q);
    displaysearch();
    displayBox(tinyBoxLength+30, tinyBoxWidth+30, tinyBoxHeight+40);
    glPopMatrix();
}

void display(){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(background, background, background,0);	//sets background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // sets the current matrix to identity
    gluLookAt(pos.x, pos.y, pos.z, pos.x+l.x, pos.y+l.y, pos.z+l.z, u.x, u.y, u.z); // sets camera position and direction

    displayScene();

	glutSwapBuffers();
}



void animate(){
    tinyBoxAngle += 0.05;
	glutPostRedisplay();
}

void init(){
    glClearColor(background, background, background,0); 	//sets background color

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity(); // sets the current matrix to identity
    gluPerspective(80,	1,	1,	1000.0);

	// to understand the following values, read the specification pdf
    double d = 1 / sqrt2;
    pos = {300, 300, 150};
    u = {0, 0, 1};
    r = {-d, d, 0};
    l = {-d, -d, 0};
    //Tanvir Ahmed


}

void subMenu(int id)
{
    if(id == 3)
    {
        background = 1;
    }
    else if(id == 4)
    {
        background = 0;
    }
}

void mainMenu(int id)
{
    if(id == 1)
    {
        drawAxes = true;
    }
    else if(id == 2)
    {
        drawAxes = false;
    }
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color
	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	int subMenuNo = glutCreateMenu(subMenu);
    glutAddMenuEntry("White", 3);
	glutAddMenuEntry("Black", 4);

    glutCreateMenu(mainMenu);
	glutAddMenuEntry("Axes On", 1);
	glutAddMenuEntry("Axes Off", 2);
	glutAddSubMenu("Background", subMenuNo);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();		//The main loop of OpenGL, this function never returns

	return 0;
