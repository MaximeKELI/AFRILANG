#pragma once

#include "ui.hpp"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang::runtime::game2d {

struct SpriteInfo {
    SDL_Texture* texture = nullptr;
    int width = 0;
    int height = 0;
};

struct SpriteSheetInfo {
    SDL_Texture* texture = nullptr;
    int width = 0;
    int height = 0;
    int frameW = 0;
    int frameH = 0;
    int cols = 0;
    int rows = 0;
};

struct GridConfig {
    int cols = 0;
    int rows = 0;
    int viewCols = 0;
    int viewRows = 0;
    int cellSize = 28;
    int padX = 32;
    int padY = 88;
};

struct Game2dContext {
    GridConfig grid;
    std::unordered_map<std::string, double> timers;
    std::unordered_map<std::string, SpriteInfo> sprites;
    std::unordered_map<std::string, Mix_Chunk*> sounds;
    std::unordered_map<std::string, Mix_Music*> music;
    std::unordered_map<std::string, SpriteSheetInfo> sheets;
    double highScore = 0;
    double animTimeMs = 0;
    double pendingDx = 1;
    double pendingDy = 0;
    double camX = 0;
    double camY = 0;
    bool audioReady = false;
};

inline Game2dContext& context() {
    static Game2dContext ctx;
    return ctx;
}

inline void configureGrid(double cols, double rows, double cellSize, double padX, double padY) {
    Game2dContext& ctx = context();
    ctx.grid.cols = static_cast<int>(cols);
    ctx.grid.rows = static_cast<int>(rows);
    ctx.grid.cellSize = static_cast<int>(cellSize);
    ctx.grid.padX = static_cast<int>(padX);
    ctx.grid.padY = static_cast<int>(padY);
}

inline void configureViewport(double viewCols, double viewRows) {
    Game2dContext& ctx = context();
    ctx.grid.viewCols = static_cast<int>(viewCols);
    ctx.grid.viewRows = static_cast<int>(viewRows);
}

inline int visibleCols() {
    const GridConfig& g = context().grid;
    return g.viewCols > 0 ? g.viewCols : g.cols;
}

inline int visibleRows() {
    const GridConfig& g = context().grid;
    return g.viewRows > 0 ? g.viewRows : g.rows;
}

inline double gridWindowWidth() {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padX * 2 + visibleCols() * g.cellSize);
}

inline double gridWindowHeight() {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padY + visibleRows() * g.cellSize + 40);
}

inline double cellWorldX(double col) {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padX + static_cast<int>(col) * g.cellSize);
}

inline double cellWorldY(double row) {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padY + static_cast<int>(row) * g.cellSize);
}

inline double cellPx(double col) {
    return cellWorldX(col) - context().camX;
}

inline double cellPy(double row) {
    return cellWorldY(row) - context().camY;
}

inline double cellInnerSize() {
    return static_cast<double>(context().grid.cellSize - 2);
}

inline bool isBorderCell(double col, double row) {
    const GridConfig& g = context().grid;
    const int c = static_cast<int>(col);
    const int r = static_cast<int>(row);
    return c <= 0 || r <= 0 || c >= g.cols - 1 || r >= g.rows - 1;
}

inline void fillCell(double col, double row, double r, double g, double b) {
    const int inset = 1;
    const double size = cellInnerSize();
    ui::fillRect(cellPx(col) + inset, cellPy(row) + inset, size, size, r, g, b);
}

inline void drawCell(double col, double row, double r, double g, double b) {
    const double size = static_cast<double>(context().grid.cellSize);
    ui::drawRect(cellPx(col), cellPy(row), size, size, r, g, b);
}

inline void fillBoard(double r, double g, double b) {
    const GridConfig& gr = context().grid;
    ui::fillRect(cellPx(0), cellPy(0),
                 static_cast<double>(gr.cols * gr.cellSize),
                 static_cast<double>(gr.rows * gr.cellSize),
                 r, g, b);
}

inline void drawWalls(double r, double g, double b) {
    const GridConfig& gr = context().grid;
    for (int y = 0; y < gr.rows; ++y) {
        for (int x = 0; x < gr.cols; ++x) {
            if (isBorderCell(static_cast<double>(x), static_cast<double>(y))) {
                fillCell(static_cast<double>(x), static_cast<double>(y), r, g, b);
            }
        }
    }
}

inline void drawGridLines(double r, double g, double b) {
    const GridConfig& gr = context().grid;
    const double x0 = cellPx(0);
    const double y0 = cellPy(0);
    const double w = static_cast<double>(gr.cols * gr.cellSize);
    const double h = static_cast<double>(gr.rows * gr.cellSize);
    for (int i = 0; i <= gr.cols; ++i) {
        const double x = x0 + static_cast<double>(i * gr.cellSize);
        ui::drawRect(x, y0, 1, h, r, g, b);
    }
    for (int j = 0; j <= gr.rows; ++j) {
        const double y = y0 + static_cast<double>(j * gr.cellSize);
        ui::drawRect(x0, y, w, 1, r, g, b);
    }
}

inline void fillCircle(double x, double y, double radius, double r, double g, double b) {
    ui::UiContext& u = ui::context();
    if (!u.renderer) return;
    SDL_SetRenderDrawColor(u.renderer,
                           static_cast<Uint8>(r),
                           static_cast<Uint8>(g),
                           static_cast<Uint8>(b),
                           255);
    const int cx = static_cast<int>(x);
    const int cy = static_cast<int>(y);
    const int rad = std::max(1, static_cast<int>(radius));
    for (int dy = -rad; dy <= rad; ++dy) {
        for (int dx = -rad; dx <= rad; ++dx) {
            if (dx * dx + dy * dy <= rad * rad) {
                SDL_RenderDrawPoint(u.renderer, cx + dx, cy + dy);
            }
        }
    }
}

inline void fillCircleSolid(double x, double y, double radius, double r, double g, double b) {
    ui::UiContext& u = ui::context();
    if (!u.renderer) return;
    const double sx = x - context().camX;
    const double sy = y - context().camY;
    SDL_SetRenderDrawColor(u.renderer,
                           static_cast<Uint8>(r),
                           static_cast<Uint8>(g),
                           static_cast<Uint8>(b),
                           255);
    const int cx = static_cast<int>(sx);
    const int cy = static_cast<int>(sy);
    const int rad = std::max(1, static_cast<int>(radius));
    for (int dy = -rad; dy <= rad; ++dy) {
        const int span = static_cast<int>(std::sqrt(static_cast<double>(rad * rad - dy * dy)));
        SDL_Rect row{cx - span, cy + dy, span * 2 + 1, 1};
        SDL_RenderFillRect(u.renderer, &row);
    }
}

inline bool everyMs(const std::string& name, double deltaMs, double intervalMs) {
    if (intervalMs <= 0) return true;
    Game2dContext& ctx = context();
    ctx.animTimeMs += deltaMs;
    ctx.timers[name] += deltaMs;
    if (ctx.timers[name] >= intervalMs) {
        ctx.timers[name] -= intervalMs;
        return true;
    }
    return false;
}

inline void resetTimer(const std::string& name) {
    context().timers[name] = 0;
}

inline double animTimeMs() {
    return context().animTimeMs;
}

inline double pulse01(double periodMs) {
    if (periodMs <= 0) return 1.0;
    const double t = context().animTimeMs / periodMs;
    return 0.5 + 0.5 * std::sin(t * 6.283185307179586);
}

inline double lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

inline void updateDirection(double curDx, double curDy) {
    using ui::isKeyDown;
    double ndx = curDx;
    double ndy = curDy;

    const bool left = isKeyDown("Left") || isKeyDown("A") || isKeyDown("a");
    const bool right = isKeyDown("Right") || isKeyDown("D") || isKeyDown("d");
    const bool up = isKeyDown("Up") || isKeyDown("W") || isKeyDown("w");
    const bool down = isKeyDown("Down") || isKeyDown("S") || isKeyDown("s");

    if (left && curDx != 1) {
        ndx = -1;
        ndy = 0;
    } else if (right && curDx != -1) {
        ndx = 1;
        ndy = 0;
    } else if (up && curDy != 1) {
        ndx = 0;
        ndy = -1;
    } else if (down && curDy != -1) {
        ndx = 0;
        ndy = 1;
    }

    Game2dContext& ctx = context();
    ctx.pendingDx = ndx;
    ctx.pendingDy = ndy;
}

inline double inputDirX() {
    return context().pendingDx;
}

inline double inputDirY() {
    return context().pendingDy;
}

inline bool gridHas(const std::vector<double>& xs,
                    const std::vector<double>& ys,
                    double count,
                    double gx,
                    double gy) {
    const int n = static_cast<int>(count);
    for (int i = 0; i < n && i < static_cast<int>(xs.size()) && i < static_cast<int>(ys.size()); ++i) {
        if (xs[static_cast<std::size_t>(i)] == gx && ys[static_cast<std::size_t>(i)] == gy) {
            return true;
        }
    }
    return false;
}

inline double rgb(double r, double g, double b) {
    const auto c = [](double v) {
        return static_cast<long long>(v < 0 ? 0 : (v > 255 ? 255 : v));
    };
    return static_cast<double>(c(r) * 65536 + c(g) * 256 + c(b));
}

inline double redOf(double packed) {
    return static_cast<double>(static_cast<long long>(packed) / 65536 % 256);
}

inline double greenOf(double packed) {
    return static_cast<double>(static_cast<long long>(packed) / 256 % 256);
}

inline double blueOf(double packed) {
    return static_cast<double>(static_cast<long long>(packed) % 256);
}

inline void fillCellRgb(double col, double row, double packed) {
    fillCell(col, row, redOf(packed), greenOf(packed), blueOf(packed));
}

inline void drawCenteredText(const std::string& text, double y, double size,
                             double r, double g, double b) {
    const double approxW = static_cast<double>(text.size()) * size * 0.55;
    const double x = (ui::windowWidth() - approxW) / 2.0;
    ui::drawTextColor(text, x, y, size, r, g, b);
}

inline void drawHud(const std::string& text, double x, double y, double size,
                    double r, double g, double b) {
    ui::drawTextColor(text, x, y, size, r, g, b);
}

inline double highScore() {
    return context().highScore;
}

inline void updateHighScore(double score) {
    if (score > context().highScore) context().highScore = score;
}

inline double moveIntervalForScore(double score, double baseMs, double minMs) {
    const double interval = baseMs - score * 3.0;
    return interval < minMs ? minMs : interval;
}

inline void setCamera(double x, double y) {
    context().camX = x;
    context().camY = y;
}

inline double cameraX() {
    return context().camX;
}

inline double cameraY() {
    return context().camY;
}

inline void followCamera(double targetX, double targetY, double smooth) {
    Game2dContext& ctx = context();
    const double viewW = ui::windowWidth();
    const double viewH = ui::windowHeight();
    const double targetCamX = targetX - viewW / 2.0;
    const double targetCamY = targetY - viewH / 2.0;
    const double t = smooth <= 0 ? 1.0 : std::min(1.0, smooth);
    ctx.camX += (targetCamX - ctx.camX) * t;
    ctx.camY += (targetCamY - ctx.camY) * t;

    const GridConfig& g = ctx.grid;
    const double maxCamX = std::max(0.0,
        static_cast<double>(g.padX * 2 + g.cols * g.cellSize) - viewW);
    const double maxCamY = std::max(0.0,
        static_cast<double>(g.padY + g.rows * g.cellSize + 40) - viewH);
    if (ctx.camX < 0) ctx.camX = 0;
    if (ctx.camY < 0) ctx.camY = 0;
    if (ctx.camX > maxCamX) ctx.camX = maxCamX;
    if (ctx.camY > maxCamY) ctx.camY = maxCamY;
}

inline void ensureAudio() {
    Game2dContext& ctx = context();
    if (ctx.audioReady) return;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == 0) {
        ctx.audioReady = true;
    }
}

inline bool loadMusic(const std::string& name, const std::string& path) {
    ensureAudio();
    if (!context().audioReady) return false;
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    if (!music) return false;
    Game2dContext& ctx = context();
    auto it = ctx.music.find(name);
    if (it != ctx.music.end() && it->second) {
        Mix_FreeMusic(it->second);
    }
    ctx.music[name] = music;
    return true;
}

inline bool playMusic(const std::string& name, double loops) {
    const auto it = context().music.find(name);
    if (it == context().music.end() || !it->second) return false;
    const int lp = static_cast<int>(loops);
    return Mix_PlayMusic(it->second, lp) == 0;
}

inline void stopMusic() {
    if (!context().audioReady) return;
    Mix_HaltMusic();
}

inline void setMusicVolume(double volume0to128) {
    const int vol = static_cast<int>(std::max(0.0, std::min(128.0, volume0to128)));
    Mix_VolumeMusic(vol);
}

inline bool loadSprite(const std::string& name, const std::string& path) {
    ui::UiContext& u = ui::context();
    if (!u.renderer) return false;
    static bool imgInited = false;
    if (!imgInited) {
        imgInited = (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != 0;
    }
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) return false;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(u.renderer, surface);
    const int w = surface->w;
    const int h = surface->h;
    SDL_FreeSurface(surface);
    if (!texture) return false;

    Game2dContext& ctx = context();
    auto it = ctx.sprites.find(name);
    if (it != ctx.sprites.end() && it->second.texture) {
        SDL_DestroyTexture(it->second.texture);
    }
    ctx.sprites[name] = SpriteInfo{texture, w, h};
    return true;
}

inline bool hasSprite(const std::string& name) {
    const auto it = context().sprites.find(name);
    return it != context().sprites.end() && it->second.texture != nullptr;
}

inline double spriteWidth(const std::string& name) {
    const auto it = context().sprites.find(name);
    return it == context().sprites.end() ? 0 : static_cast<double>(it->second.width);
}

inline double spriteHeight(const std::string& name) {
    const auto it = context().sprites.find(name);
    return it == context().sprites.end() ? 0 : static_cast<double>(it->second.height);
}

inline void drawSprite(const std::string& name, double worldX, double worldY) {
    const auto it = context().sprites.find(name);
    if (it == context().sprites.end() || !it->second.texture) return;
    ui::UiContext& u = ui::context();
    if (!u.renderer) return;
    const SDL_Rect dest{
        static_cast<int>(worldX - context().camX),
        static_cast<int>(worldY - context().camY),
        it->second.width,
        it->second.height,
    };
    SDL_RenderCopy(u.renderer, it->second.texture, nullptr, &dest);
}

inline void drawSpriteScaled(const std::string& name, double worldX, double worldY,
                             double width, double height) {
    const auto it = context().sprites.find(name);
    if (it == context().sprites.end() || !it->second.texture) return;
    ui::UiContext& u = ui::context();
    if (!u.renderer) return;
    const SDL_Rect dest{
        static_cast<int>(worldX - context().camX),
        static_cast<int>(worldY - context().camY),
        static_cast<int>(width),
        static_cast<int>(height),
    };
    SDL_RenderCopy(u.renderer, it->second.texture, nullptr, &dest);
}

inline void drawSpriteCell(const std::string& name, double col, double row) {
    const GridConfig& g = context().grid;
    const double size = static_cast<double>(g.cellSize);
    const double x = cellWorldX(col);
    const double y = cellWorldY(row);
    drawSpriteScaled(name, x, y, size, size);
}

inline bool loadSpriteSheet(const std::string& name, const std::string& path,
                            double frameW, double frameH) {
    ui::UiContext& u = ui::context();
    if (!u.renderer) return false;
    static bool imgInited = false;
    if (!imgInited) imgInited = (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != 0;
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) return false;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(u.renderer, surface);
    const int w = surface->w;
    const int h = surface->h;
    SDL_FreeSurface(surface);
    if (!texture) return false;

    const int fw = std::max(1, static_cast<int>(frameW));
    const int fh = std::max(1, static_cast<int>(frameH));
    SpriteSheetInfo sheet;
    sheet.texture = texture;
    sheet.width = w;
    sheet.height = h;
    sheet.frameW = fw;
    sheet.frameH = fh;
    sheet.cols = fw > 0 ? (w / fw) : 1;
    sheet.rows = fh > 0 ? (h / fh) : 1;

    Game2dContext& ctx = context();
    auto it = ctx.sheets.find(name);
    if (it != ctx.sheets.end() && it->second.texture) {
        SDL_DestroyTexture(it->second.texture);
    }
    ctx.sheets[name] = sheet;
    return true;
}

inline bool hasSpriteSheet(const std::string& name) {
    const auto it = context().sheets.find(name);
    return it != context().sheets.end() && it->second.texture != nullptr;
}

inline double sheetCols(const std::string& name) {
    const auto it = context().sheets.find(name);
    return it == context().sheets.end() ? 0 : static_cast<double>(it->second.cols);
}

inline double sheetRows(const std::string& name) {
    const auto it = context().sheets.find(name);
    return it == context().sheets.end() ? 0 : static_cast<double>(it->second.rows);
}

inline void drawSpriteFrame(const std::string& name, double frameIdx,
                            double worldX, double worldY,
                            double width, double height) {
    const auto it = context().sheets.find(name);
    if (it == context().sheets.end() || !it->second.texture) return;
    ui::UiContext& u = ui::context();
    if (!u.renderer) return;

    const SpriteSheetInfo& sh = it->second;
    const int frames = std::max(1, sh.cols * sh.rows);
    int idx = static_cast<int>(frameIdx);
    if (idx < 0) idx = 0;
    idx = idx % frames;
    const int col = sh.cols > 0 ? (idx % sh.cols) : 0;
    const int row = sh.cols > 0 ? (idx / sh.cols) : 0;
    const SDL_Rect src{col * sh.frameW, row * sh.frameH, sh.frameW, sh.frameH};
    const SDL_Rect dst{
        static_cast<int>(worldX - context().camX),
        static_cast<int>(worldY - context().camY),
        static_cast<int>(width),
        static_cast<int>(height),
    };
    SDL_RenderCopy(u.renderer, sh.texture, &src, &dst);
}

inline void drawSpriteFrameCell(const std::string& name, double frameIdx,
                                double col, double row) {
    const GridConfig& g = context().grid;
    const double size = static_cast<double>(g.cellSize);
    drawSpriteFrame(name, frameIdx, cellWorldX(col), cellWorldY(row), size, size);
}

inline bool loadSound(const std::string& name, const std::string& path) {
    ensureAudio();
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    if (!chunk) return false;
    Game2dContext& ctx = context();
    auto it = ctx.sounds.find(name);
    if (it != ctx.sounds.end() && it->second) {
        Mix_FreeChunk(it->second);
    }
    ctx.sounds[name] = chunk;
    return true;
}

inline bool playSound(const std::string& name) {
    const auto it = context().sounds.find(name);
    if (it == context().sounds.end() || !it->second) return false;
    return Mix_PlayChannel(-1, it->second, 0) != -1;
}

inline bool playSoundVolume(const std::string& name, double volume) {
    const auto it = context().sounds.find(name);
    if (it == context().sounds.end() || !it->second) return false;
    const int vol = static_cast<int>(std::max(0.0, std::min(128.0, volume)));
    Mix_VolumeChunk(it->second, vol);
    return Mix_PlayChannel(-1, it->second, 0) != -1;
}

inline void shutdown() {
    Game2dContext& ctx = context();
    for (auto& [_, sprite] : ctx.sprites) {
        if (sprite.texture) SDL_DestroyTexture(sprite.texture);
    }
    ctx.sprites.clear();
    for (auto& [_, sheet] : ctx.sheets) {
        if (sheet.texture) SDL_DestroyTexture(sheet.texture);
    }
    ctx.sheets.clear();
    for (auto& [_, sound] : ctx.sounds) {
        if (sound) Mix_FreeChunk(sound);
    }
    ctx.sounds.clear();
    for (auto& [_, mus] : ctx.music) {
        if (mus) Mix_FreeMusic(mus);
    }
    ctx.music.clear();
    if (ctx.audioReady) {
        Mix_HaltMusic();
        Mix_CloseAudio();
        ctx.audioReady = false;
    }
    IMG_Quit();
}

} // namespace afrilang::runtime::game2d
