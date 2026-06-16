#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "base64.hpp"

namespace afrilang::runtime::game3d {

struct Texture3d {
    GLuint id = 0;
    int width = 0;
    int height = 0;
};

struct ObjVertex {
    float x = 0;
    float y = 0;
    float z = 0;
    float u = 0;
    float v = 0;
    float nx = 0;
    float ny = 1;
    float nz = 0;
};

struct ObjModel {
    std::vector<ObjVertex> triangles;
    std::vector<std::vector<float>> animTimes;
    std::vector<std::vector<float>> animRotY;
};

struct LevelObject {
    std::string type;
    std::string asset;
    double x = 0;
    double y = 0;
    double z = 0;
    double scale = 1;
    double rotY = 0;
};

struct ModelAnimPlayback {
    int animIndex = 0;
    double timeSec = 0;
    bool playing = false;
    bool loop = true;
};

struct RigidBody {
    double px = 0;
    double py = 0;
    double pz = 0;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double radius = 0.5;
    double hx = 0.5;
    double hy = 0.5;
    double hz = 0.5;
    double restitution = 0.55;
    double friction = 0.92;
    bool isBox = false;
    bool active = true;
};

struct Particle {
    double x = 0;
    double y = 0;
    double z = 0;
    double vx = 0;
    double vy = 0;
    double vz = 0;
    double life = 0;
    double maxLife = 1;
    double r = 255;
    double g = 220;
    double b = 120;
    double size = 0.12;
};

struct LightingState {
    bool enabled = false;
    float ambient[3]{0.22f, 0.24f, 0.30f};
    float sunDir[3]{-0.35f, -1.0f, -0.25f};
    float sunColor[3]{1.0f, 0.96f, 0.88f};
};

struct FogState {
    bool enabled = false;
    float color[3]{0.55f, 0.62f, 0.72f};
    float start = 18.0f;
    float end = 90.0f;
};

struct SkyboxState {
    GLuint faces[6]{};
    bool loaded[6]{};
};

struct ShaderInfo {
    GLuint program = 0;
};

struct Game3dContext {
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    bool open = false;
    int windowW = 960;
    int windowH = 600;
    bool keys[SDL_NUM_SCANCODES]{};
    bool pressed[SDL_NUM_SCANCODES]{};
    int mouseX = 0;
    int mouseY = 0;
    bool clickThisFrame = false;
    bool mouseDown = false;
    bool mousePressed = false;
    Uint32 lastFrameTicks = 0;
    double frameDeltaMs = 16.0;
    double camX = 0;
    double camY = 4;
    double camZ = 14;
    double camYaw = 0;
    double camPitch = -12;
    double sceneRotY = 0;
    bool imgInited = false;
    double windX = 0;
    double windY = 0;
    double windZ = 0;
    double animTimeMs = 0;
    double followSmooth = 0.12;
    std::string followTarget;
    GLdouble lastModelView[16]{};
    GLdouble lastProjection[16]{};
    GLint lastViewport[4]{};
    std::unordered_map<std::string, Texture3d> textures;
    std::unordered_map<std::string, ObjModel> models;
    std::unordered_map<std::string, ShaderInfo> shaders;
    std::unordered_map<std::string, RigidBody> bodies;
    std::vector<std::string> bodyOrder;
    std::vector<Particle> particles;
    LightingState lighting;
    FogState fog;
    SkyboxState skybox;
    std::unordered_map<std::string, ModelAnimPlayback> modelAnims;
    std::vector<LevelObject> levelObjects;
    bool editMode = false;
    double lastGroundX = 0;
    double lastGroundY = 0;
    double lastGroundZ = 0;
    bool lastGroundHit = false;
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

inline void releaseGpuAssets() {
    Game3dContext& ctx = context();
    for (auto& [_, tex] : ctx.textures) {
        if (tex.id) glDeleteTextures(1, &tex.id);
    }
    ctx.textures.clear();
    ctx.models.clear();
    for (auto& [_, sh] : ctx.shaders) {
        if (sh.program) glDeleteProgram(sh.program);
    }
    ctx.shaders.clear();
    for (int i = 0; i < 6; ++i) {
        if (ctx.skybox.faces[i]) glDeleteTextures(1, &ctx.skybox.faces[i]);
        ctx.skybox.faces[i] = 0;
        ctx.skybox.loaded[i] = false;
    }
    ctx.bodies.clear();
    ctx.bodyOrder.clear();
    ctx.particles.clear();
    ctx.modelAnims.clear();
    ctx.levelObjects.clear();
    if (ctx.imgInited) {
        IMG_Quit();
        ctx.imgInited = false;
    }
}

inline void closeWindow() {
    Game3dContext& ctx = context();
    releaseGpuAssets();
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
    ctx.mousePressed = false;
    ctx.clickThisFrame = false;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            ctx.open = false;
        } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            ctx.mouseDown = true;
            ctx.mousePressed = true;
            ctx.clickThisFrame = true;
            ctx.mouseX = event.button.x;
            ctx.mouseY = event.button.y;
        } else if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
            ctx.mouseDown = false;
        } else if (event.type == SDL_MOUSEMOTION) {
            ctx.mouseX = event.motion.x;
            ctx.mouseY = event.motion.y;
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
    ctx.animTimeMs += ctx.frameDeltaMs;
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

inline double mouseX() {
    return static_cast<double>(context().mouseX);
}

inline double mouseY() {
    return static_cast<double>(context().mouseY);
}

inline bool isMouseDown() {
    return context().mouseDown;
}

inline bool wasMousePressed() {
    return context().mousePressed;
}

inline bool wasMouseClicked() {
    return context().clickThisFrame;
}

inline void clearScreen(double r, double g, double b) {
    glClearColor(static_cast<GLfloat>(r / 255.0),
                 static_cast<GLfloat>(g / 255.0),
                 static_cast<GLfloat>(b / 255.0),
                 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

inline void drawSkyGradient(double topR, double topG, double topB,
                            double botR, double botG, double botB) {
    glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glBegin(GL_QUADS);
    glColor3f(static_cast<GLfloat>(topR / 255.0),
              static_cast<GLfloat>(topG / 255.0),
              static_cast<GLfloat>(topB / 255.0));
    glVertex3f(-1.0f, 1.0f, -0.999f);
    glVertex3f(1.0f, 1.0f, -0.999f);
    glColor3f(static_cast<GLfloat>(botR / 255.0),
              static_cast<GLfloat>(botG / 255.0),
              static_cast<GLfloat>(botB / 255.0));
    glVertex3f(1.0f, -1.0f, -0.999f);
    glVertex3f(-1.0f, -1.0f, -0.999f);
    glEnd();
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopAttrib();
}

inline void setCamera(double x, double y, double z, double yaw, double pitch) {
    Game3dContext& ctx = context();
    ctx.camX = x;
    ctx.camY = y;
    ctx.camZ = z;
    ctx.camYaw = yaw;
    ctx.camPitch = pitch;
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

    glGetDoublev(GL_MODELVIEW_MATRIX, ctx.lastModelView);
    glGetDoublev(GL_PROJECTION_MATRIX, ctx.lastProjection);
    glGetIntegerv(GL_VIEWPORT, ctx.lastViewport);
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

inline void ensureImageLoader() {
    Game3dContext& ctx = context();
    if (!ctx.imgInited) {
        ctx.imgInited = (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != 0;
    }
}

inline bool loadTexture3d(const std::string& name, const std::string& path) {
    ensureImageLoader();
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) return false;

    GLuint texId = 0;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    const GLenum format = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0,
                 format, GL_UNSIGNED_BYTE, surface->pixels);

    const int w = surface->w;
    const int h = surface->h;
    SDL_FreeSurface(surface);

    Game3dContext& ctx = context();
    auto it = ctx.textures.find(name);
    if (it != ctx.textures.end() && it->second.id) {
        glDeleteTextures(1, &it->second.id);
    }
    ctx.textures[name] = Texture3d{texId, w, h};
    glEnable(GL_TEXTURE_2D);
    return true;
}

inline bool hasTexture3d(const std::string& name) {
    const auto it = context().textures.find(name);
    return it != context().textures.end() && it->second.id != 0;
}

inline void bindTexture3d(const std::string& name) {
    const auto it = context().textures.find(name);
    if (it == context().textures.end() || !it->second.id) return;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, it->second.id);
    glColor3f(1, 1, 1);
}

inline void unbindTexture3d() {
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

inline void drawPlaneTextured(double y, double halfSize, const std::string& textureName) {
    if (!hasTexture3d(textureName)) {
        drawPlane(y, halfSize, 60, 80, 60);
        return;
    }
    const GLfloat hs = static_cast<GLfloat>(halfSize);
    const GLfloat cy = static_cast<GLfloat>(y);
    bindTexture3d(textureName);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-hs, cy, -hs);
    glTexCoord2f(8, 0); glVertex3f(hs, cy, -hs);
    glTexCoord2f(8, 8); glVertex3f(hs, cy, hs);
    glTexCoord2f(0, 8); glVertex3f(-hs, cy, hs);
    glEnd();
    unbindTexture3d();
}

inline void drawCubeTextured(double x, double y, double z, double size,
                             const std::string& textureName) {
    if (!hasTexture3d(textureName)) {
        drawCube(x, y, z, size, 180, 180, 180);
        return;
    }
    const GLfloat s = static_cast<GLfloat>(size * 0.5);
    bindTexture3d(textureName);
    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
    glBegin(GL_QUADS);
    auto face = [&](float y0, float y1, float z0, float z1, float x0, float x1) {
        glTexCoord2f(0, 0); glVertex3f(x0, y0, z0);
        glTexCoord2f(1, 0); glVertex3f(x1, y0, z0);
        glTexCoord2f(1, 1); glVertex3f(x1, y1, z1);
        glTexCoord2f(0, 1); glVertex3f(x0, y1, z1);
    };
    face(s, s, -s, s, -s, s);
    face(-s, -s, -s, s, -s, s);
    face(-s, -s, s, s, -s, s);
    face(-s, -s, -s, s, s, s);
    face(-s, -s, -s, s, -s, -s);
    face(-s, -s, s, s, s, s);
    glEnd();
    glPopMatrix();
    unbindTexture3d();
}

inline int parseObjIndex(const std::string& token, int currentSize) {
    std::size_t slash = token.find('/');
    const std::string num = slash == std::string::npos ? token : token.substr(0, slash);
    int idx = std::stoi(num);
    if (idx < 0) idx = currentSize + idx + 1;
    return idx - 1;
}

inline void computeTriangleNormal(ObjVertex& a, ObjVertex& b, ObjVertex& c) {
    const float ax = b.x - a.x;
    const float ay = b.y - a.y;
    const float az = b.z - a.z;
    const float bx = c.x - a.x;
    const float by = c.y - a.y;
    const float bz = c.z - a.z;
    const float nx = ay * bz - az * by;
    const float ny = az * bx - ax * bz;
    const float nz = ax * by - ay * bx;
    const float len = std::sqrt(nx * nx + ny * ny + nz * nz);
    if (len < 0.0001f) return;
    a.nx = b.nx = c.nx = nx / len;
    a.ny = b.ny = c.ny = ny / len;
    a.nz = b.nz = c.nz = nz / len;
}

inline bool loadModel(const std::string& name, const std::string& path) {
    std::ifstream file(path);
    if (!file) return false;

    std::vector<float> positions;
    std::vector<float> uvs;
    std::vector<float> normals;
    ObjModel model;

  std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        std::string tag;
        iss >> tag;
        if (tag == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            positions.push_back(x);
            positions.push_back(y);
            positions.push_back(z);
        } else if (tag == "vt") {
            float u, v;
            iss >> u >> v;
            uvs.push_back(u);
            uvs.push_back(1.0f - v);
        } else if (tag == "vn") {
            float nx, ny, nz;
            iss >> nx >> ny >> nz;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);
        } else if (tag == "f") {
            std::vector<std::string> parts;
            std::string part;
            while (iss >> part) parts.push_back(part);
            if (parts.size() < 3) continue;
            auto corner = [&](const std::string& tok) {
                ObjVertex vert;
                const int vi = parseObjIndex(tok, static_cast<int>(positions.size() / 3));
                vert.x = positions[static_cast<std::size_t>(vi * 3 + 0)];
                vert.y = positions[static_cast<std::size_t>(vi * 3 + 1)];
                vert.z = positions[static_cast<std::size_t>(vi * 3 + 2)];
                const std::size_t slash = tok.find('/');
                if (slash != std::string::npos) {
                    const std::size_t slash2 = tok.find('/', slash + 1);
                    const std::string uvTok = slash2 == std::string::npos
                        ? tok.substr(slash + 1)
                        : tok.substr(slash + 1, slash2 - slash - 1);
                    if (!uvTok.empty()) {
                        const int ti = parseObjIndex(uvTok, static_cast<int>(uvs.size() / 2));
                        vert.u = uvs[static_cast<std::size_t>(ti * 2 + 0)];
                        vert.v = uvs[static_cast<std::size_t>(ti * 2 + 1)];
                    }
                    if (slash2 != std::string::npos) {
                        const std::string nTok = tok.substr(slash2 + 1);
                        if (!nTok.empty() && !normals.empty()) {
                            const int ni = parseObjIndex(nTok, static_cast<int>(normals.size() / 3));
                            vert.nx = normals[static_cast<std::size_t>(ni * 3 + 0)];
                            vert.ny = normals[static_cast<std::size_t>(ni * 3 + 1)];
                            vert.nz = normals[static_cast<std::size_t>(ni * 3 + 2)];
                        }
                    }
                }
                return vert;
            };
            const ObjVertex a0 = corner(parts[0]);
            for (std::size_t i = 1; i + 1 < parts.size(); ++i) {
                ObjVertex a = a0;
                ObjVertex b = corner(parts[i]);
                ObjVertex c = corner(parts[i + 1]);
                if (normals.empty()) computeTriangleNormal(a, b, c);
                model.triangles.push_back(a);
                model.triangles.push_back(b);
                model.triangles.push_back(c);
            }
        }
    }

    if (model.triangles.empty()) return false;
    context().models[name] = std::move(model);
    return true;
}

inline bool hasModel(const std::string& name) {
    const auto it = context().models.find(name);
    return it != context().models.end() && !it->second.triangles.empty();
}

inline void drawModel(const std::string& name, double x, double y, double z,
                      double scale, double rotY, const std::string& textureName) {
    const auto it = context().models.find(name);
    if (it == context().models.end()) return;
    const bool textured = !textureName.empty() && hasTexture3d(textureName);
    if (textured) bindTexture3d(textureName);
    else glColor3f(0.85f, 0.85f, 0.9f);

    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
  glRotatef(static_cast<GLfloat>(rotY), 0, 1, 0);
    glScalef(static_cast<GLfloat>(scale), static_cast<GLfloat>(scale),
             static_cast<GLfloat>(scale));

    glBegin(GL_TRIANGLES);
    for (const ObjVertex& v : it->second.triangles) {
        if (textured) glTexCoord2f(v.u, v.v);
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
    glPopMatrix();

    if (textured) unbindTexture3d();
}

inline void drawModelColored(const std::string& name, double x, double y, double z,
                             double scale, double rotY, double r, double g, double b) {
    const auto it = context().models.find(name);
    if (it == context().models.end()) return;
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));
    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
    glRotatef(static_cast<GLfloat>(rotY), 0, 1, 0);
    glScalef(static_cast<GLfloat>(scale), static_cast<GLfloat>(scale),
             static_cast<GLfloat>(scale));
    glBegin(GL_TRIANGLES);
    for (const ObjVertex& v : it->second.triangles) {
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
    glPopMatrix();
}

inline void addBodyToOrder(const std::string& name) {
    std::vector<std::string>& order = context().bodyOrder;
    if (std::find(order.begin(), order.end(), name) == order.end()) {
        order.push_back(name);
    }
}

inline void createBody(const std::string& name, double x, double y, double z, double radius) {
    RigidBody body;
    body.px = x;
    body.py = y;
    body.pz = z;
    body.radius = radius;
    addBodyToOrder(name);
    context().bodies[name] = body;
}

inline bool hasBody(const std::string& name) {
    return context().bodies.count(name) > 0;
}

inline void setBodyVelocity(const std::string& name, double vx, double vy, double vz) {
    auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    it->second.vx = vx;
    it->second.vy = vy;
    it->second.vz = vz;
}

inline void setBodyPosition(const std::string& name, double x, double y, double z) {
    auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    it->second.px = x;
    it->second.py = y;
    it->second.pz = z;
}

inline double bodyX(const std::string& name) {
    const auto it = context().bodies.find(name);
    return it == context().bodies.end() ? 0 : it->second.px;
}

inline double bodyY(const std::string& name) {
    const auto it = context().bodies.find(name);
    return it == context().bodies.end() ? 0 : it->second.py;
}

inline double bodyZ(const std::string& name) {
    const auto it = context().bodies.find(name);
    return it == context().bodies.end() ? 0 : it->second.pz;
}

inline void applyImpulse(const std::string& name, double ix, double iy, double iz) {
    auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    it->second.vx += ix;
    it->second.vy += iy;
    it->second.vz += iz;
}

inline void resolveGround(RigidBody& body, double groundY) {
    if (body.py - body.radius < groundY) {
        body.py = groundY + body.radius;
        if (body.vy < 0) body.vy = -body.vy * body.restitution;
        body.vx *= 0.98;
        body.vz *= 0.98;
    }
}

inline void resolveSpherePair(RigidBody& a, RigidBody& b) {
    const double dx = b.px - a.px;
    const double dy = b.py - a.py;
    const double dz = b.pz - a.pz;
    const double distSq = dx * dx + dy * dy + dz * dz;
    const double minDist = a.radius + b.radius;
    if (distSq <= 0.0001 || distSq >= minDist * minDist) return;
    const double dist = std::sqrt(distSq);
    const double nx = dx / dist;
    const double ny = dy / dist;
    const double nz = dz / dist;
    const double overlap = minDist - dist;
    a.px -= nx * overlap * 0.5;
    a.py -= ny * overlap * 0.5;
    a.pz -= nz * overlap * 0.5;
    b.px += nx * overlap * 0.5;
    b.py += ny * overlap * 0.5;
    b.pz += nz * overlap * 0.5;
    const double rvx = b.vx - a.vx;
    const double rvy = b.vy - a.vy;
    const double rvz = b.vz - a.vz;
    const double vn = rvx * nx + rvy * ny + rvz * nz;
    if (vn > 0) return;
    const double e = (a.restitution + b.restitution) * 0.5;
    const double impulse = -(1 + e) * vn / 2.0;
    a.vx -= impulse * nx;
    a.vy -= impulse * ny;
    a.vz -= impulse * nz;
    b.vx += impulse * nx;
    b.vy += impulse * ny;
    b.vz += impulse * nz;
}

inline void stepPhysics(double deltaMs, double gravity) {
    const double dt = deltaMs / 1000.0;
    Game3dContext& ctx = context();
    for (auto& [_, body] : ctx.bodies) {
        if (!body.active) continue;
        body.vy += gravity * dt;
        body.px += body.vx * dt;
        body.py += body.vy * dt;
        body.pz += body.vz * dt;
        resolveGround(body, 0);
    }
    std::vector<RigidBody*> list;
    list.reserve(ctx.bodies.size());
    for (auto& [_, body] : ctx.bodies) {
        if (body.active) list.push_back(&body);
    }
    for (std::size_t i = 0; i < list.size(); ++i) {
        for (std::size_t j = i + 1; j < list.size(); ++j) {
            resolveSpherePair(*list[i], *list[j]);
        }
    }
}

inline void removeBody(const std::string& name) {
    Game3dContext& ctx = context();
    ctx.bodies.erase(name);
    auto& order = ctx.bodyOrder;
    order.erase(std::remove(order.begin(), order.end(), name), order.end());
}

inline void enableLighting(bool on) {
    context().lighting.enabled = on;
}

inline void setAmbientLight(double r, double g, double b) {
    LightingState& l = context().lighting;
    l.ambient[0] = static_cast<float>(r / 255.0);
    l.ambient[1] = static_cast<float>(g / 255.0);
    l.ambient[2] = static_cast<float>(b / 255.0);
}

inline void setSunLight(double dx, double dy, double dz, double r, double g, double b) {
    LightingState& l = context().lighting;
    const double len = std::sqrt(dx * dx + dy * dy + dz * dz);
    if (len > 0.0001) {
        l.sunDir[0] = static_cast<float>(dx / len);
        l.sunDir[1] = static_cast<float>(dy / len);
        l.sunDir[2] = static_cast<float>(dz / len);
    }
    l.sunColor[0] = static_cast<float>(r / 255.0);
    l.sunColor[1] = static_cast<float>(g / 255.0);
    l.sunColor[2] = static_cast<float>(b / 255.0);
}

inline void applyLighting() {
    const LightingState& l = context().lighting;
    if (!l.enabled) {
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_COLOR_MATERIAL);
        return;
    }
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, l.ambient);
    const GLfloat pos[4]{-l.sunDir[0], -l.sunDir[1], -l.sunDir[2], 0.0f};
    const GLfloat diff[4]{l.sunColor[0], l.sunColor[1], l.sunColor[2], 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
}

inline void setFog(bool enabled, double r, double g, double b, double startDist, double endDist) {
    FogState& f = context().fog;
    f.enabled = enabled;
    f.color[0] = static_cast<float>(r / 255.0);
    f.color[1] = static_cast<float>(g / 255.0);
    f.color[2] = static_cast<float>(b / 255.0);
    f.start = static_cast<float>(startDist);
    f.end = static_cast<float>(endDist);
}

inline void applyFog() {
    const FogState& f = context().fog;
    if (!f.enabled) {
        glDisable(GL_FOG);
        return;
    }
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogfv(GL_FOG_COLOR, f.color);
    glFogf(GL_FOG_START, f.start);
    glFogf(GL_FOG_END, f.end);
}

inline void setWind(double x, double y, double z) {
    Game3dContext& ctx = context();
    ctx.windX = x;
    ctx.windY = y;
    ctx.windZ = z;
}

inline void followBody(const std::string& name, double height, double distance, double smooth) {
    Game3dContext& ctx = context();
    ctx.followTarget = name;
    ctx.followSmooth = smooth <= 0 ? 1.0 : smooth;
    const auto it = ctx.bodies.find(name);
    if (it == ctx.bodies.end()) return;
    const double tx = it->second.px;
    const double ty = it->second.py + height;
    const double tz = it->second.pz + distance;
    const double t = ctx.followSmooth;
    ctx.camX += (tx - ctx.camX) * t;
    ctx.camY += (ty - ctx.camY) * t;
    ctx.camZ += (tz - ctx.camZ) * t;
    const double dx = it->second.px - ctx.camX;
    const double dy = it->second.py - ctx.camY;
    const double dz = it->second.pz - ctx.camZ;
    ctx.camYaw = std::atan2(dx, -dz) * 180.0 / 3.141592653589793;
    ctx.camPitch = std::atan2(dy, std::sqrt(dx * dx + dz * dz)) * 180.0 / 3.141592653589793;
}

inline void createBoxBody(const std::string& name, double x, double y, double z,
                          double hx, double hy, double hz) {
    RigidBody body;
    body.px = x;
    body.py = y;
    body.pz = z;
    body.hx = hx;
    body.hy = hy;
    body.hz = hz;
    body.isBox = true;
    body.radius = std::max({hx, hy, hz});
    addBodyToOrder(name);
    context().bodies[name] = body;
}

inline void setBodyFriction(const std::string& name, double friction) {
    auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    it->second.friction = friction;
}

inline void setBodyRestitution(const std::string& name, double restitution) {
    auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    it->second.restitution = restitution;
}

inline void drawBox(double x, double y, double z, double sx, double sy, double sz,
                    double r, double g, double b) {
    const GLfloat hx = static_cast<GLfloat>(sx * 0.5);
    const GLfloat hy = static_cast<GLfloat>(sy * 0.5);
    const GLfloat hz = static_cast<GLfloat>(sz * 0.5);
    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
    glColor3f(static_cast<GLfloat>(r / 255.0),
              static_cast<GLfloat>(g / 255.0),
              static_cast<GLfloat>(b / 255.0));
    glBegin(GL_QUADS);
    auto quad = [](float ax, float ay, float az,
                   float bx, float by, float bz,
                   float cx, float cy, float cz,
                   float dx, float dy, float dz,
                   float nx, float ny, float nz) {
        glNormal3f(nx, ny, nz);
        glVertex3f(ax, ay, az);
        glVertex3f(bx, by, bz);
        glVertex3f(cx, cy, cz);
        glVertex3f(dx, dy, dz);
    };
    quad(-hx, -hy, hz, hx, -hy, hz, hx, hy, hz, -hx, hy, hz, 0, 0, 1);
    quad(hx, -hy, -hz, -hx, -hy, -hz, -hx, hy, -hz, hx, hy, -hz, 0, 0, -1);
    quad(-hx, hy, hz, hx, hy, hz, hx, hy, -hz, -hx, hy, -hz, 0, 1, 0);
    quad(-hx, -hy, -hz, hx, -hy, -hz, hx, -hy, hz, -hx, -hy, hz, 0, -1, 0);
    quad(-hx, -hy, -hz, -hx, -hy, hz, -hx, hy, hz, -hx, hy, -hz, -1, 0, 0);
    quad(hx, -hy, hz, hx, -hy, -hz, hx, hy, -hz, hx, hy, hz, 1, 0, 0);
    glEnd();
    glPopMatrix();
}

inline void drawBody(const std::string& name) {
    const auto it = context().bodies.find(name);
    if (it == context().bodies.end()) return;
    const RigidBody& b = it->second;
    if (b.isBox) {
        drawBox(b.px, b.py, b.pz, b.hx * 2, b.hy * 2, b.hz * 2, 180, 140, 90);
    } else {
        drawSphere(b.px, b.py, b.pz, b.radius, 100, 200, 255);
    }
}

inline void emitBurst(double x, double y, double z, double count, double speed) {
    Game3dContext& ctx = context();
    const int n = std::max(1, static_cast<int>(count));
    for (int i = 0; i < n; ++i) {
        Particle p;
        p.x = x;
        p.y = y;
        p.z = z;
        const double a = (i * 2.399963) + ctx.animTimeMs * 0.001;
        p.vx = std::cos(a) * speed;
        p.vy = speed * 0.8;
        p.vz = std::sin(a) * speed;
        p.life = 0;
        p.maxLife = 900 + (i % 5) * 120;
        p.r = 255;
        p.g = 180 + (i % 3) * 20;
        p.b = 80;
        p.size = 0.08 + (i % 4) * 0.03;
        ctx.particles.push_back(p);
    }
}

inline void updateParticles(double deltaMs) {
    Game3dContext& ctx = context();
    const double dt = deltaMs / 1000.0;
    std::vector<Particle> alive;
    alive.reserve(ctx.particles.size());
    for (Particle p : ctx.particles) {
        p.life += deltaMs;
        if (p.life >= p.maxLife) continue;
        p.vy -= 6.0 * dt;
        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.z += p.vz * dt;
        if (p.y < 0.05) {
            p.y = 0.05;
            p.vy = -p.vy * 0.35;
            p.vx *= 0.7;
            p.vz *= 0.7;
        }
        alive.push_back(p);
    }
    ctx.particles = std::move(alive);
}

inline void drawParticles() {
    for (const Particle& p : context().particles) {
        const double t = 1.0 - (p.life / p.maxLife);
        const double alpha = t;
        drawSphere(p.x, p.y, p.z, p.size * alpha,
                   p.r, p.g * alpha, p.b * alpha);
    }
}

inline void resolveBoxGround(RigidBody& body, double groundY) {
    if (!body.isBox) return;
    if (body.py - body.hy < groundY) {
        body.py = groundY + body.hy;
        if (body.vy < 0) body.vy = -body.vy * body.restitution;
        body.vx *= body.friction;
        body.vz *= body.friction;
    }
}

#include "game3d_advanced.inl.hpp"

inline void stepPhysicsEx(double deltaMs, double gravity) {
    const double dt = deltaMs / 1000.0;
    Game3dContext& ctx = context();
    for (auto& [_, body] : ctx.bodies) {
        if (!body.active) continue;
        body.vx += ctx.windX * dt;
        body.vy += (gravity + ctx.windY) * dt;
        body.vz += ctx.windZ * dt;
        body.px += body.vx * dt;
        body.py += body.vy * dt;
        body.pz += body.vz * dt;
        if (body.isBox) resolveBoxGround(body, 0);
        else resolveGround(body, 0);
    }
    std::vector<RigidBody*> list;
    for (auto& [_, body] : ctx.bodies) {
        if (body.active) list.push_back(&body);
    }
    for (std::size_t i = 0; i < list.size(); ++i) {
        for (std::size_t j = i + 1; j < list.size(); ++j) {
            RigidBody& a = *list[i];
            RigidBody& b = *list[j];
            if (a.isBox && b.isBox) resolveBoxBox(a, b);
            else if (!a.isBox && !b.isBox) resolveSpherePair(a, b);
            else if (!a.isBox && b.isBox) resolveSphereBox(a, b);
            else resolveSphereBox(b, a);
        }
    }
}

inline void drawModelLit(const std::string& name, double x, double y, double z,
                         double scale, double rotY, const std::string& textureName) {
    const auto it = context().models.find(name);
    if (it == context().models.end()) return;
    const bool textured = !textureName.empty() && hasTexture3d(textureName);
    if (textured) bindTexture3d(textureName);

    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
    glRotatef(static_cast<GLfloat>(rotY), 0, 1, 0);
    glScalef(static_cast<GLfloat>(scale), static_cast<GLfloat>(scale),
             static_cast<GLfloat>(scale));

    glBegin(GL_TRIANGLES);
    for (const ObjVertex& v : it->second.triangles) {
        glNormal3f(v.nx, v.ny, v.nz);
        if (textured) glTexCoord2f(v.u, v.v);
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
    glPopMatrix();
    if (textured) unbindTexture3d();
}

inline void drawGltf(const std::string& name, double x, double y, double z,
                     double scale, double rotY) {
    drawModelColored(name, x, y, z, scale, rotY, 200, 220, 255);
}

inline void drawGltfLit(const std::string& name, double x, double y, double z,
                        double scale, double rotY, const std::string& textureName) {
    drawModelLit(name, x, y, z, scale, rotY, textureName);
}

inline bool rayFromScreen(double sx, double sy,
                          double& ox, double& oy, double& oz,
                          double& dx, double& dy, double& dz) {
    Game3dContext& ctx = context();
    const GLdouble* MV = ctx.lastModelView;
    const GLdouble* PR = ctx.lastProjection;
    const GLint* VP = ctx.lastViewport;
    if (VP[2] <= 0 || VP[3] <= 0) return false;

    const GLdouble x = sx;
    const GLdouble y = static_cast<GLdouble>(VP[3]) - sy;

    GLdouble nx, ny, nz;
    GLdouble fx, fy, fz;
    if (gluUnProject(x, y, 0.0, MV, PR, VP, &nx, &ny, &nz) == GL_FALSE) return false;
    if (gluUnProject(x, y, 1.0, MV, PR, VP, &fx, &fy, &fz) == GL_FALSE) return false;

    ox = nx; oy = ny; oz = nz;
    dx = fx - nx; dy = fy - ny; dz = fz - nz;
    const double len = std::sqrt(dx * dx + dy * dy + dz * dz);
    if (len < 1e-9) return false;
    dx /= len; dy /= len; dz /= len;
    return true;
}

inline bool raySphereHit(double ox, double oy, double oz,
                         double dx, double dy, double dz,
                         double cx, double cy, double cz, double radius,
                         double& tHit) {
    const double lx = cx - ox;
    const double ly = cy - oy;
    const double lz = cz - oz;
    const double tca = lx * dx + ly * dy + lz * dz;
    if (tca < 0) return false;
    const double d2 = (lx * lx + ly * ly + lz * lz) - tca * tca;
    const double r2 = radius * radius;
    if (d2 > r2) return false;
    const double thc = std::sqrt(std::max(0.0, r2 - d2));
    const double t0 = tca - thc;
    const double t1 = tca + thc;
    tHit = t0 > 0 ? t0 : t1;
    return tHit > 0;
}

inline double pickBody(double screenX, double screenY) {
    double ox, oy, oz, dx, dy, dz;
    if (!rayFromScreen(screenX, screenY, ox, oy, oz, dx, dy, dz)) return -1;

    Game3dContext& ctx = context();
    double bestT = 1e18;
    int bestIndex = -1;
    for (int i = 0; i < static_cast<int>(ctx.bodyOrder.size()); ++i) {
        const std::string& name = ctx.bodyOrder[static_cast<std::size_t>(i)];
        const auto it = ctx.bodies.find(name);
        if (it == ctx.bodies.end() || !it->second.active) continue;
        const RigidBody& body = it->second;
        double t = 0;
        bool hit = false;
        if (body.isBox) {
            hit = rayAabbHit(ox, oy, oz, dx, dy, dz,
                             body.px, body.py, body.pz, body.hx, body.hy, body.hz, t);
        } else {
            hit = raySphereHit(ox, oy, oz, dx, dy, dz,
                               body.px, body.py, body.pz, body.radius, t);
        }
        if (hit && t < bestT) {
            bestT = t;
            bestIndex = i;
        }
    }
    return static_cast<double>(bestIndex);
}

inline std::string pickBodyName(double screenX, double screenY) {
    const double idx = pickBody(screenX, screenY);
    if (idx < 0) return "";
    const int i = static_cast<int>(idx);
    const Game3dContext& ctx = context();
    if (i < 0 || i >= static_cast<int>(ctx.bodyOrder.size())) return "";
    return ctx.bodyOrder[static_cast<std::size_t>(i)];
}

} // namespace afrilang::runtime::game3d
