#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<math.h>
#include <corecrt_math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void drawCircle(float cx, float cy, float r, int num_segments)
{
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    float theta = 3.1415926 / float(num_segments);
    float tangetial_factor = tanf(theta);

    float radial_factor = cosf(theta);

    float x = r;

    float y = 0;
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);

        float tx = -y;
        float ty = x;

        x += tx * tangetial_factor;
        y += ty * tangetial_factor;

        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

int main(void)
{
    GLFWwindow* window;


    if (!glfwInit())
    {
        return -1;
    }


    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Semi Circle", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();




    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        drawCircle(250, 250, 100, 360);

        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}