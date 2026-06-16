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
    bool keys[SDL_NUM_SCANCODES]{};
    bool pressed[SDL_NUM_SCANCODES]{};
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

    // Prefer a renderer that actually exists on the machine.
    // Some environments show a window but fail to create a renderer (leading to a black screen).
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "software");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    if (SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, &ctx.window, &ctx.renderer) != 0) {
        ctx.window = SDL_CreateWindow(
            title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
        if (ctx.window) {
            ctx.renderer = SDL_CreateRenderer(ctx.window, -1, SDL_RENDERER_SOFTWARE);
            if (!ctx.renderer) {
                ctx.renderer = SDL_CreateRenderer(ctx.window, -1, 0);
            }
        }
    }

    if (ctx.window) SDL_SetWindowTitle(ctx.window, title.c_str());
    if (!ctx.window || !ctx.renderer) {
        // Hard fail: keep ctx.open false to avoid running a draw loop that can't draw anything.
        if (ctx.renderer) SDL_DestroyRenderer(ctx.renderer);
        if (ctx.window) SDL_DestroyWindow(ctx.window);
        ctx.renderer = nullptr;
        ctx.window = nullptr;
        ctx.open = false;
        TTF_Quit();
        SDL_Quit();
        return;
    }

    ctx.open = true;
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
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i) {
        ctx.pressed[i] = false;
    }

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
    // SDL_ttf ne gère pas les sauts de ligne dans un seul rendu.
    // On rend donc ligne par ligne pour supporter les textes multi-lignes (ex: Snake, logs, etc.).
    const int lineH = std::max(10, TTF_FontHeight(font) + 2);
    int lineIdx = 0;
    std::size_t start = 0;
    while (start <= text.size()) {
        std::size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        const std::string line = text.substr(start, end - start);

        SDL_Surface* surface = TTF_RenderUTF8_Blended(font, line.c_str(), color);
        if (surface) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(ctx.renderer, surface);
            SDL_FreeSurface(surface);
            if (texture) {
                SDL_Rect dest{
                    static_cast<int>(x),
                    static_cast<int>(y) + lineIdx * lineH,
                    0,
                    0
                };
                SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
                SDL_RenderCopy(ctx.renderer, texture, nullptr, &dest);
                SDL_DestroyTexture(texture);
            }
        } else {
            // Fallback visuel minimal si le rendu TTF échoue (permet de diagnostiquer un écran noir)
            SDL_SetRenderDrawColor(ctx.renderer, 220, 80, 90, 255);
            SDL_Rect dot{
                static_cast<int>(x),
                static_cast<int>(y) + lineIdx * lineH,
                6,
                6,
            };
            SDL_RenderFillRect(ctx.renderer, &dot);
        }

        if (end >= text.size()) break;
        start = end + 1;
        lineIdx += 1;
    }
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

inline SDL_Scancode scancodeFromName(const std::string& key) {
    if (key == "Left" || key == "ArrowLeft") return SDL_SCANCODE_LEFT;
    if (key == "Right" || key == "ArrowRight") return SDL_SCANCODE_RIGHT;
    if (key == "Up" || key == "ArrowUp") return SDL_SCANCODE_UP;
    if (key == "Down" || key == "ArrowDown") return SDL_SCANCODE_DOWN;
    if (key == "W" || key == "w") return SDL_SCANCODE_W;
    if (key == "A" || key == "a") return SDL_SCANCODE_A;
    if (key == "S" || key == "s") return SDL_SCANCODE_S;
    if (key == "D" || key == "d") return SDL_SCANCODE_D;
    if (key == "Space" || key == " ") return SDL_SCANCODE_SPACE;
    if (key == "Escape" || key == "Esc") return SDL_SCANCODE_ESCAPE;
    return SDL_SCANCODE_UNKNOWN;
}

inline bool isKeyDown(const std::string& key) {
    UiContext& ctx = context();
    const SDL_Scancode sc = scancodeFromName(key);
    if (sc == SDL_SCANCODE_UNKNOWN) return false;
    return ctx.keys[sc];
}

inline bool wasKeyPressed(const std::string& key) {
    UiContext& ctx = context();
    const SDL_Scancode sc = scancodeFromName(key);
    if (sc == SDL_SCANCODE_UNKNOWN) return false;
    return ctx.pressed[sc];
}

} // namespace afrilang::runtime::ui
