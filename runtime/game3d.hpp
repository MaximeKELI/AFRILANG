#pragma once

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <cmath>
#include <string>

namespace afrilang::runtime::game3d {

struct Game3dContext {
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    bool open = false;
    int windowW = 960;
    int windowH = 600;
    bool keys[SDL_NUM_SCANCODES]{};
    bool pressed[SDL_NUM_SCANCODES]{};
    Uint32 lastFrameTicks = 0;
    double frameDeltaMs = 16.0;
    double camX = 0;
    double camY = 4;
    double camZ = 14;
    double camYaw = 0;
    double camPitch = -12;
    double sceneRotY = 0;
};

inline Game3dContext& context() {
    static Game3dContext ctx;
    return ctx;
}

inline SDL_Scancode scancodeFromName(const std::string& key) {
    if (key == "Left" || key == "ArrowLeft") return SDL_SCANCODE_LEFT;
    if (key == "Right" || key == "ArrowRight") return SDL_SCANCODE_RIGHT;
    if (key == "Up" || key == "ArrowUp") return SDL_SCANCODE_UP;
    if (key == "Down" || key == "ArrowDown") return SDL_SCANCODE_DOWN;
    if (key == "W" || key == "w") return SDL_SCANCODE_W;
    if (key == "A" || key == "a") return SDL_SCANCODE_A;
    if (key == "S" || key == "s") return SDL_SCANCODE_S;
    if (key == "D" || key == "d") return SDL_SCANCODE_D;
    if (key == "Q" || key == "q") return SDL_SCANCODE_Q;
    if (key == "E" || key == "e") return SDL_SCANCODE_E;
    if (key == "Space" || key == " ") return SDL_SCANCODE_SPACE;
    if (key == "Escape" || key == "Esc") return SDL_SCANCODE_ESCAPE;
    if (key == "R" || key == "r") return SDL_SCANCODE_R;
    return SDL_SCANCODE_UNKNOWN;
}

inline void openWindow(const std::string& title, double width, double height) {
    Game3dContext& ctx = context();
    if (ctx.open) return;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) return;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    const int w = static_cast<int>(width);
    const int h = static_cast<int>(height);
    ctx.windowW = w;
    ctx.windowH = h;

    ctx.window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w,
        h,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (!ctx.window) {
        SDL_Quit();
        return;
    }

    ctx.glContext = SDL_GL_CreateContext(ctx.window);
    if (!ctx.glContext) {
        SDL_DestroyWindow(ctx.window);
        ctx.window = nullptr;
        SDL_Quit();
        return;
    }

    SDL_GL_SetSwapInterval(1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    ctx.open = true;
}

inline void closeWindow() {
    Game3dContext& ctx = context();
    if (ctx.glContext) {
        SDL_GL_DeleteContext(ctx.glContext);
        ctx.glContext = nullptr;
    }
    if (ctx.window) {
        SDL_DestroyWindow(ctx.window);
        ctx.window = nullptr;
    }
    ctx.open = false;
    SDL_Quit();
}

inline void shutdown() {
    closeWindow();
}

inline bool isOpen() {
    return context().open;
}

inline void pollEvents() {
    Game3dContext& ctx = context();
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        ctx.pressed[i] = false;
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            ctx.open = false;
        } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            const SDL_Scancode sc = event.key.keysym.scancode;
            if (sc >= 0 && sc < SDL_NUM_SCANCODES) {
                ctx.keys[sc] = true;
                ctx.pressed[sc] = true;
            }
        } else if (event.type == SDL_KEYUP) {
            const SDL_Scancode sc = event.key.keysym.scancode;
            if (sc >= 0 && sc < SDL_NUM_SCANCODES) {
                ctx.keys[sc] = false;
            }
        }
    }
}

inline void beginFrame() {
    Game3dContext& ctx = context();
    const Uint32 now = SDL_GetTicks();
    if (ctx.lastFrameTicks > 0) {
        ctx.frameDeltaMs = static_cast<double>(now - ctx.lastFrameTicks);
    }
    ctx.lastFrameTicks = now;
    pollEvents();
}

inline double deltaMs() {
    return context().frameDeltaMs;
}

inline void showFrame() {
    Game3dContext& ctx = context();
    if (!ctx.window) return;
    SDL_GL_SwapWindow(ctx.window);
}

inline double windowWidth() {
    return static_cast<double>(context().windowW);
}

inline double windowHeight() {
    return static_cast<double>(context().windowH);
}

inline bool isKeyDown(const std::string& key) {
    Game3dContext& ctx = context();
    const SDL_Scancode sc = scancodeFromName(key);
    if (sc == SDL_SCANCODE_UNKNOWN) return false;
    return ctx.keys[sc];
}

inline bool wasKeyPressed(const std::string& key) {
    Game3dContext& ctx = context();
    const SDL_Scancode sc = scancodeFromName(key);
    if (sc == SDL_SCANCODE_UNKNOWN) return false;
    return ctx.pressed[sc];
}

inline void clear(double r, double g, double b) {
    glClearColor(static_cast<GLfloat>(r / 255.0),
                 static_cast<GLfloat>(g / 255.0),
                 static_cast<GLfloat>(b / 255.0),
                 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

inline void setCamera(double x, double y, double z, double yaw, double pitch) {
    Game3dContext& ctx = context();
    ctx.camX = x;
    ctx.camY = y;
    ctx.camZ = z;
    ctx.camYaw = yaw;
    ctx.camPitch = pitch;
}

inline void cameraPos(double& x, double& y, double& z) {
    const Game3dContext& ctx = context();
    x = ctx.camX;
    y = ctx.camY;
    z = ctx.camZ;
}

inline void applyCamera() {
    Game3dContext& ctx = context();
    const double aspect = ctx.windowH > 0
        ? static_cast<double>(ctx.windowW) / static_cast<double>(ctx.windowH)
        : 1.0;

    glViewport(0, 0, ctx.windowW, ctx.windowH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 0.1, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    const double yawRad = ctx.camYaw * 3.141592653589793 / 180.0;
    const double pitchRad = ctx.camPitch * 3.141592653589793 / 180.0;
    const double lookX = ctx.camX + std::sin(yawRad) * std::cos(pitchRad);
    const double lookY = ctx.camY + std::sin(pitchRad);
    const double lookZ = ctx.camZ - std::cos(yawRad) * std::cos(pitchRad);

    gluLookAt(ctx.camX, ctx.camY, ctx.camZ, lookX, lookY, lookZ, 0, 1, 0);
}

inline void updateFlyCamera(double moveSpeed, double turnSpeed) {
    Game3dContext& ctx = context();
    const double yawRad = ctx.camYaw * 3.141592653589793 / 180.0;
    const double forwardX = std::sin(yawRad);
    const double forwardZ = -std::cos(yawRad);
    const double rightX = std::cos(yawRad);
    const double rightZ = std::sin(yawRad);

    if (isKeyDown("W")) {
        ctx.camX += forwardX * moveSpeed;
        ctx.camZ += forwardZ * moveSpeed;
    }
    if (isKeyDown("S")) {
        ctx.camX -= forwardX * moveSpeed;
        ctx.camZ -= forwardZ * moveSpeed;
    }
    if (isKeyDown("A")) {
        ctx.camX -= rightX * moveSpeed;
        ctx.camZ -= rightZ * moveSpeed;
    }
    if (isKeyDown("D")) {
        ctx.camX += rightX * moveSpeed;
        ctx.camZ += rightZ * moveSpeed;
    }
    if (isKeyDown("E") || isKeyDown("Space")) {
        ctx.camY += moveSpeed;
    }
    if (isKeyDown("Q")) {
        ctx.camY -= moveSpeed;
    }
    if (isKeyDown("Left")) ctx.camYaw -= turnSpeed;
    if (isKeyDown("Right")) ctx.camYaw += turnSpeed;
    if (isKeyDown("Up")) ctx.camPitch += turnSpeed;
    if (isKeyDown("Down")) ctx.camPitch -= turnSpeed;

    if (ctx.camPitch > 89) ctx.camPitch = 89;
    if (ctx.camPitch < -89) ctx.camPitch = -89;
}

inline void setSceneRotation(double angleY) {
    context().sceneRotY = angleY;
}

inline void rotateScene(double angleY) {
    glRotatef(static_cast<GLfloat>(angleY), 0.0f, 1.0f, 0.0f);
}

inline void applySceneRotation() {
    rotateScene(context().sceneRotY);
}

inline void drawCube(double x, double y, double z, double size,
                     double r, double g, double b) {
    const GLfloat s = static_cast<GLfloat>(size * 0.5);
    const GLfloat cx = static_cast<GLfloat>(x);
    const GLfloat cy = static_cast<GLfloat>(y);
    const GLfloat cz = static_cast<GLfloat>(z);
    glPushMatrix();
    glTranslatef(cx, cy, cz);
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));

    glBegin(GL_QUADS);
    // Top
    glVertex3f(-s, s, -s); glVertex3f(-s, s, s);
    glVertex3f(s, s, s); glVertex3f(s, s, -s);
    // Bottom
    glColor3f(static_cast<GLfloat>(r * 0.6 / 255.0),
              static_cast<GLfloat>(g * 0.6 / 255.0),
              static_cast<GLfloat>(b * 0.6 / 255.0));
    glVertex3f(-s, -s, -s); glVertex3f(s, -s, -s);
    glVertex3f(s, -s, s); glVertex3f(-s, -s, s);
    // Front
    glColor3f(static_cast<GLfloat>(r * 0.85 / 255.0),
              static_cast<GLfloat>(g * 0.85 / 255.0),
              static_cast<GLfloat>(b * 0.85 / 255.0));
    glVertex3f(-s, -s, s); glVertex3f(s, -s, s);
    glVertex3f(s, s, s); glVertex3f(-s, s, s);
    // Back
    glColor3f(static_cast<GLfloat>(r * 0.7 / 255.0),
              static_cast<GLfloat>(g * 0.7 / 255.0),
              static_cast<GLfloat>(b * 0.7 / 255.0));
    glVertex3f(-s, -s, -s); glVertex3f(-s, s, -s);
    glVertex3f(s, s, -s); glVertex3f(s, -s, -s);
    // Left
    glColor3f(static_cast<GLfloat>(r * 0.75 / 255.0),
              static_cast<GLfloat>(g * 0.75 / 255.0),
              static_cast<GLfloat>(b * 0.75 / 255.0));
    glVertex3f(-s, -s, -s); glVertex3f(-s, -s, s);
    glVertex3f(-s, s, s); glVertex3f(-s, s, -s);
    // Right
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));
    glVertex3f(s, -s, -s); glVertex3f(s, s, -s);
    glVertex3f(s, s, s); glVertex3f(s, -s, s);
    glEnd();
    glPopMatrix();
}

inline void drawPlane(double y, double halfSize, double r, double g, double b) {
    const GLfloat hs = static_cast<GLfloat>(halfSize);
    const GLfloat cy = static_cast<GLfloat>(y);
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));
    glBegin(GL_QUADS);
    glVertex3f(-hs, cy, -hs);
    glVertex3f(hs, cy, -hs);
    glVertex3f(hs, cy, hs);
    glVertex3f(-hs, cy, hs);
    glEnd();
}

inline void drawGrid(double y, double halfSize, double divisions) {
    const int div = std::max(1, static_cast<int>(divisions));
    const GLfloat hs = static_cast<GLfloat>(halfSize);
    const GLfloat cy = static_cast<GLfloat>(y);
    const GLfloat step = (2.0f * hs) / static_cast<GLfloat>(div);

    glBegin(GL_LINES);
    for (int i = 0; i <= div; ++i) {
        const GLfloat p = -hs + step * static_cast<GLfloat>(i);
        const bool major = (i % 5) == 0;
        if (major) glColor3f(0.45f, 0.5f, 0.58f);
        else glColor3f(0.28f, 0.32f, 0.38f);
        glVertex3f(-hs, cy, p);
        glVertex3f(hs, cy, p);
        glVertex3f(p, cy, -hs);
        glVertex3f(p, cy, hs);
    }
    glEnd();
}

inline void drawAxis(double size) {
    const GLfloat s = static_cast<GLfloat>(size);
    glBegin(GL_LINES);
    glColor3f(1, 0.2f, 0.2f); glVertex3f(0, 0, 0); glVertex3f(s, 0, 0);
    glColor3f(0.2f, 1, 0.3f); glVertex3f(0, 0, 0); glVertex3f(0, s, 0);
    glColor3f(0.3f, 0.5f, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, s);
    glEnd();
}

inline void drawSphere(double x, double y, double z, double radius,
                       double r, double g, double b) {
    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x),
                   static_cast<GLfloat>(y),
                   static_cast<GLfloat>(z));
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));
    GLUquadric* quad = gluNewQuadric();
    gluSphere(quad, radius, 16, 16);
    gluDeleteQuadric(quad);
    glPopMatrix();
}

} // namespace afrilang::runtime::game3d
