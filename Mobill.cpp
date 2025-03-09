#include <GL/glut.h>
#include <cmath>

float posX = 0.0f;      
float angle = 0.0f;     

void drawCircle(float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawMobil() {
    glPushMatrix();               
    glTranslatef(posX, 0.0f, 0.0f); 

    // Badan utama mobil 
    glColor3f(0.2f, 0.2f, 0.8f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, 0.1f);    
        glVertex2f(-0.6f, 0.3f);    
        glVertex2f(-0.3f, 0.6f);    
        glVertex2f(0.2f, 0.6f);     
        glVertex2f(0.4f, 0.4f);     
        glVertex2f(0.75f, 0.3f);    
        glVertex2f(0.75f, 0.1f);   
    glEnd();
    
    //  Kaca Mobil
    glColor3f(1.0f, 1.0f, 1.0f); 
    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, 0.55f);  
        glVertex2f(-0.3f, 0.38f);  
        glVertex2f(0.30f, 0.38f);  
        glVertex2f(0.15f, 0.55f);  
    glEnd();

    // Roda kiri
    glPushMatrix();
        glTranslatef(-0.35f, 0.1f, 0.0f);  
        glRotatef(angle, 0.0f, 0.0f, 1.0f);  
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(0.15f);
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
        glTranslatef(0.43f, 0.1f, 0.0f);   
        glRotatef(angle, 0.0f, 0.0f, 1.0f);  
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(0.15f);
    glPopMatrix();

    glPopMatrix();  
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMobil();
    glutSwapBuffers();
}

void update(int value) {
    posX += 0.005f;      
    angle -= 5.0f;        

    if (posX > 1.5f) posX = -1.5f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); 
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.0, 1.0);     
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 2D");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

