#include <iostream>  
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

float spaceshipX = 0.0f;
float spaceshipY = -0.8f;
float angle = 0.0f;

struct Star {
    float x, y;
    bool collected;
};

std::vector<Star> stars;
int starsCollected = 0;
const int totalStars = 5;

void generateStars() {
    srand(time(0));
    for (int i = 0; i < totalStars; ++i) {
        Star star;
        star.x = (float(rand()) / RAND_MAX) * 2.0f - 1.0f;
        star.y = (float(rand()) / RAND_MAX) * 2.0f - 1.0f;
        star.collected = false;
        stars.push_back(star);
    }
}

void drawStar(float x, float y) {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    glVertex2f(x + 0.02f, y + 0.02f);
    glVertex2f(x - 0.02f, y + 0.02f);
    glVertex2f(x - 0.02f, y - 0.02f);
    glVertex2f(x + 0.02f, y - 0.02f);
    glEnd();
}

void drawSpaceship() {
    glPushMatrix();
    glTranslatef(spaceshipX, spaceshipY, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.05f, -0.05f);
    glVertex2f(0.05f, -0.05f);
    glVertex2f(0.0f, 0.1f);
    glEnd();
    glPopMatrix();
}

void drawPlanet(float x, float y, float radius, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.1415926f * float(i) / float(100);
        float dx = cos(angle) * radius;
        float dy = sin(angle) * radius;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    for (float x = -1.0f; x < 1.0f; x += 0.05f) {
        for (float y = -1.0f; y < 1.0f; y += 0.05f) {
            glVertex2f(x, y);
        }
    }
    glEnd();

    drawPlanet(0.0f, 0.6f, 0.1f, 1.0f, 0.0f, 0.0f);
    drawPlanet(0.5f, 0.5f, 0.07f, 0.0f, 0.0f, 1.0f);

    float orbitX = 0.3f * cos(angle);
    float orbitY = 0.3f * sin(angle);
    drawPlanet(orbitX, orbitY, 0.05f, 1.0f, 1.0f, 0.0f);

    for (const auto& star : stars) {
        if (!star.collected) {
            drawStar(star.x, star.y);
        }
    }

    drawSpaceship();
}

bool checkCollision(float x1, float y1, float x2, float y2, float radius) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) < radius;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        spaceshipX -= 0.01f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        spaceshipX += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        spaceshipY += 0.01f;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        spaceshipY -= 0.01f;
}

void update() {
    angle += 0.01f;
    if (angle > 2 * 3.1415926f) {
        angle -= 2 * 3.1415926f;
    }

    for (auto& star : stars) {
        if (!star.collected && checkCollision(spaceshipX, spaceshipY, star.x, star.y, 0.1f)) {
            star.collected = true;
            starsCollected++;
            std::cout << "Estrelas Coletadas: " << starsCollected << std::endl;
        }
    }
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Jogo Espacial com Objetivo - Coletar Estrelas", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    generateStars();

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        update();
        renderScene();
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (starsCollected == totalStars) {
            break;
        }
    }

    glfwTerminate();
    return 0;
}
