#pragma once

#include "ui.hpp"

#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang::runtime::game2d {

struct GridConfig {
    int cols = 0;
    int rows = 0;
    int cellSize = 28;
    int padX = 32;
    int padY = 88;
};

struct Game2dContext {
    GridConfig grid;
    std::unordered_map<std::string, double> timers;
    double highScore = 0;
    double animTimeMs = 0;
    double pendingDx = 1;
    double pendingDy = 0;
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

inline double gridWindowWidth() {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padX * 2 + g.cols * g.cellSize);
}

inline double gridWindowHeight() {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padY + g.rows * g.cellSize + 40);
}

inline double cellPx(double col) {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padX + static_cast<int>(col) * g.cellSize);
}

inline double cellPy(double row) {
    const GridConfig& g = context().grid;
    return static_cast<double>(g.padY + static_cast<int>(row) * g.cellSize);
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
    SDL_SetRenderDrawColor(u.renderer,
                           static_cast<Uint8>(r),
                           static_cast<Uint8>(g),
                           static_cast<Uint8>(b),
                           255);
    const int cx = static_cast<int>(x);
    const int cy = static_cast<int>(y);
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

} // namespace afrilang::runtime::game2d
