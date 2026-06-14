#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <cmath>
#include <string>
#include <unordered_map>

namespace afrilang::runtime::ui {

struct UiContext {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::unordered_map<int, TTF_Font*> fonts;
    bool open = false;
    int mouseX = 0;
    int mouseY = 0;
    bool clickThisFrame = false;
};

inline UiContext& context() {
    static UiContext ctx;
    return ctx;
}

inline TTF_Font* fontForSize(int size) {
    UiContext& ctx = context();
    if (ctx.fonts.count(size)) return ctx.fonts[size];

    static const char* kFontPaths[] = {
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
        "/usr/share/fonts/TTF/DejaVuSans.ttf",
        "/usr/share/fonts/dejavu/DejaVuSans.ttf",
        nullptr
    };

    TTF_Font* font = nullptr;
    for (int i = 0; kFontPaths[i]; ++i) {
        font = TTF_OpenFont(kFontPaths[i], size);
        if (font) break;
    }
    if (!font) {
        font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", size);
    }
    ctx.fonts[size] = font;
    return font;
}

inline void openWindow(const std::string& title, double width, double height) {
    UiContext& ctx = context();
    if (ctx.open) return;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) return;
    if (TTF_Init() != 0) return;

    const int w = static_cast<int>(width);
    const int h = static_cast<int>(height);
    ctx.window = SDL_CreateWindow(
        title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (!ctx.window) return;

    ctx.renderer = SDL_CreateRenderer(ctx.window, -1, SDL_RENDERER_ACCELERATED);
    if (!ctx.renderer) {
        ctx.renderer = SDL_CreateRenderer(ctx.window, -1, SDL_RENDERER_SOFTWARE);
    }
    ctx.open = ctx.renderer != nullptr;
}

inline void closeWindow() {
    UiContext& ctx = context();
    for (auto& [_, font] : ctx.fonts) {
        if (font) TTF_CloseFont(font);
    }
    ctx.fonts.clear();
    if (ctx.renderer) SDL_DestroyRenderer(ctx.renderer);
    if (ctx.window) SDL_DestroyWindow(ctx.window);
    ctx.renderer = nullptr;
    ctx.window = nullptr;
    ctx.open = false;
    TTF_Quit();
    SDL_Quit();
}

inline bool isOpen() {
    return context().open;
}

inline void pollEvents() {
    UiContext& ctx = context();
    ctx.clickThisFrame = false;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            ctx.open = false;
        } else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            ctx.mouseX = event.button.x;
            ctx.mouseY = event.button.y;
            ctx.clickThisFrame = true;
        } else if (event.type == SDL_MOUSEMOTION) {
            ctx.mouseX = event.motion.x;
            ctx.mouseY = event.motion.y;
        }
    }
}

inline void beginFrame() {
    pollEvents();
}

inline void clearBackground(double r, double g, double b) {
    UiContext& ctx = context();
    if (!ctx.renderer) return;
    SDL_SetRenderDrawColor(ctx.renderer,
                           static_cast<Uint8>(r),
                           static_cast<Uint8>(g),
                           static_cast<Uint8>(b),
                           255);
    SDL_RenderClear(ctx.renderer);
}

inline void drawText(const std::string& text, double x, double y, double fontSize) {
    UiContext& ctx = context();
    if (!ctx.renderer) return;

    const int size = std::max(8, static_cast<int>(fontSize));
    TTF_Font* font = fontForSize(size);
    if (!font) return;

    SDL_Color color{240, 240, 245, 255};
    SDL_Surface* surface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if (!surface) return;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(ctx.renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) return;

    SDL_Rect dest{
        static_cast<int>(x),
        static_cast<int>(y),
        0,
        0
    };
    SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    SDL_RenderCopy(ctx.renderer, texture, nullptr, &dest);
    SDL_DestroyTexture(texture);
}

inline bool drawButton(const std::string& label, double x, double y, double w, double h) {
    UiContext& ctx = context();
    if (!ctx.renderer) return false;

    const SDL_Rect rect{
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(w),
        static_cast<int>(h)
    };

    const bool hover = ctx.mouseX >= rect.x && ctx.mouseX < rect.x + rect.w &&
                       ctx.mouseY >= rect.y && ctx.mouseY < rect.y + rect.h;

    SDL_SetRenderDrawColor(ctx.renderer, hover ? 90 : 70, hover ? 130 : 110, 220, 255);
    SDL_RenderFillRect(ctx.renderer, &rect);

    SDL_SetRenderDrawColor(ctx.renderer, 240, 240, 245, 255);
    SDL_RenderDrawRect(ctx.renderer, &rect);

    TTF_Font* font = fontForSize(22);
    if (font) {
        SDL_Color color{255, 255, 255, 255};
        SDL_Surface* surface = TTF_RenderUTF8_Blended(font, label.c_str(), color);
        if (surface) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(ctx.renderer, surface);
            SDL_FreeSurface(surface);
            if (texture) {
                SDL_Rect dest{0, 0, 0, 0};
                SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
                dest.x = rect.x + (rect.w - dest.w) / 2;
                dest.y = rect.y + (rect.h - dest.h) / 2;
                SDL_RenderCopy(ctx.renderer, texture, nullptr, &dest);
                SDL_DestroyTexture(texture);
            }
        }
    }

    return ctx.clickThisFrame && hover;
}

inline void showFrame() {
    UiContext& ctx = context();
    if (!ctx.renderer) return;
    SDL_RenderPresent(ctx.renderer);
    SDL_Delay(16);
}

} // namespace afrilang::runtime::ui
