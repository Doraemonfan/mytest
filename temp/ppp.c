#include <GL/glut.h>

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

void onDisplay();
void onUpdate();
void onKeyboard(unsigned char key, int x, int y);

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("SolarSystem at dora");
	glutDisplayFunc(onDisplay);
	glutIdleFunc(onUpdate);
	glutKeyboardFunc(onKeyboard);

	glutMainLoop();

	return 0;
}
