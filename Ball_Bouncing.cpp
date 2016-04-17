	#include<GL/glut.h>

	static int flag = 0;
	
	float ball_x = 0.0;
	float ball_y = 0.0;
	float ball_z = 0.0;


	//RENDERING
	void glutInitRendering()
	{
		glEnable(GL_DEPTH_TEST);

	}

	//RESHAPING
	void reshaped(int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 0, 1, 200);
	}

	//Continuous movement of Ball
	void updateBall()
	{

		//LOGIC 
		if (!flag)
		{
			ball_y += 0.0005;
			if (ball_y > 1.0)
				flag = 1;
		}
		if (flag)
		{
			ball_y -= 0.0005;
			if (ball_y < -1)
				flag = 0;
		}
	}


	//MAIN DISPLAY FUNCTION
	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//BackGround Color set korsi
		glClearColor(0, 0,0, 0);


		//BALL draw korsi
		glPushMatrix();
			glColor3f(1, 0, 0);
			glTranslatef(ball_x, ball_y, ball_z);
			glutSolidSphere(0.1, 23, 23);
		glPopMatrix();

		//update call hobe after every millisecond
		updateBall();

		glutSwapBuffers();
	}


	//Keyboard Movements
	void move_Up()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(0, 0.5, 0); //y-er uporer dike
		glFlush();
		glutSwapBuffers();
	}

	void move_Down()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(0, -0.5, 0); //y-er nicher dike
		glFlush();
		glutSwapBuffers();
	}
	void move_Right()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(0.5, 0, 0); //x-er dan dike
		glFlush();
		glutSwapBuffers();
	}

	void move_Left()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(-0.5 , 0, 0); //x-er bam dike
		glFlush();
		glutSwapBuffers();
	}

	

	//Keyboard Work
	void mykey(unsigned char key, int x, int y)
	{

		//w=up, a= left, d=right, s=down, q=exit

		if (key == 'q' || key == 'Q')
		{
			exit(0);
		}
		if (key == 'w' || key == 'W')
		{
			move_Up();
		}
		if (key == 's' || key == 'S')
		{
			move_Down();
		}
		if (key == 'a' || key == 'A')
		{
			move_Left();
		}
		if (key == 'd' || key == 'd')
		{
			move_Right();
		}
	}



	int main(int argc, char **argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

		//Windows Size decalare korlam
		glutInitWindowSize(400, 500);

		//Title dilam
		glutCreateWindow("Ball");

		//render kora lage must
		glutInitRendering();

		//Display korlam
		glutDisplayFunc(display);

		glutIdleFunc(display);


		//Keyboard er kaj somuho
		glutKeyboardFunc(mykey);
		

		//Reshaping the ball
		glutReshapeFunc(reshaped);
		glutMainLoop();
	}