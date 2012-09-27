#include <GLUT/GLUT.h>
#include <gflags/gflags.h>
#include <glog/logging.h>


void Render(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBegin(GL_TRIANGLES);

  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2f(0.0f, 0.5f);

  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2f(-0.5f, -0.5f);

  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2f(0.5f, -0.5f);

  glEnd();
  glutSwapBuffers();
}


void HandleKeyboard(unsigned char c, int x, int y) {
  if (c == 27) {
    exit(0);
  }
}


void HandleMouse(int button, int state, int x, int y) {
  if (button == GLUT_RIGHT_BUTTON) {
    exit(0);
  }
}


int main(int argc, char* argv[]) {
  google::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = false;
  google::InitGoogleLogging(argv[0]);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 500);
  glutCreateWindow("GLUTtony");

  glutDisplayFunc(Render);
  glutKeyboardFunc(HandleKeyboard);
  glutMouseFunc(HandleMouse);

  glutMainLoop();
}
