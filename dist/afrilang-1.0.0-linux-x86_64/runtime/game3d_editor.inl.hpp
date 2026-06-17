// Included inside namespace afrilang::runtime::game3d (from game3d.hpp)

inline void setEditMode(bool on) {
    context().editMode = on;
}

inline bool isEditMode() {
    return context().editMode;
}

inline void clearLevel() {
    context().levelObjects.clear();
}

inline void addLevelGltf(const std::string& asset, double x, double y, double z,
                         double scale, double rotY) {
    LevelObject obj;
    obj.type = "gltf";
    obj.asset = asset;
    obj.x = x;
    obj.y = y;
    obj.z = z;
    obj.scale = scale;
    obj.rotY = rotY;
    context().levelObjects.push_back(obj);
}

inline void addLevelModel(const std::string& asset, double x, double y, double z,
                          double scale, double rotY) {
    LevelObject obj;
    obj.type = "model";
    obj.asset = asset;
    obj.x = x;
    obj.y = y;
    obj.z = z;
    obj.scale = scale;
    obj.rotY = rotY;
    context().levelObjects.push_back(obj);
}

inline double levelCount() {
    return static_cast<double>(context().levelObjects.size());
}

inline std::string levelType(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return "";
    return objs[static_cast<std::size_t>(i)].type;
}

inline std::string levelAsset(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return "";
    return objs[static_cast<std::size_t>(i)].asset;
}

inline double levelX(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return 0;
    return objs[static_cast<std::size_t>(i)].x;
}

inline double levelY(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return 0;
    return objs[static_cast<std::size_t>(i)].y;
}

inline double levelZ(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return 0;
    return objs[static_cast<std::size_t>(i)].z;
}

inline double levelScale(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return 0;
    return objs[static_cast<std::size_t>(i)].scale;
}

inline double levelRotY(double index) {
    const int i = static_cast<int>(index);
    const auto& objs = context().levelObjects;
    if (i < 0 || i >= static_cast<int>(objs.size())) return 0;
    return objs[static_cast<std::size_t>(i)].rotY;
}

inline bool saveLevel(const std::string& path) {
    std::ofstream out(path, std::ios::trunc);
    if (!out) return false;
    out << "# AFRILANG level\n";
    for (const LevelObject& obj : context().levelObjects) {
        out << obj.type << ' ' << obj.asset << ' '
            << obj.x << ' ' << obj.y << ' ' << obj.z << ' '
            << obj.scale << ' ' << obj.rotY << '\n';
    }
    return true;
}

inline bool loadLevel(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    clearLevel();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::istringstream iss(line);
        LevelObject obj;
        if (!(iss >> obj.type >> obj.asset >> obj.x >> obj.y >> obj.z >> obj.scale >> obj.rotY)) {
            continue;
        }
        context().levelObjects.push_back(obj);
    }
    return true;
}

inline void drawLevel() {
    for (const LevelObject& obj : context().levelObjects) {
        if (obj.type == "gltf") {
            drawGltf(obj.asset, obj.x, obj.y, obj.z, obj.scale,
                     obj.rotY + gltfAnimRotY(obj.asset));
        } else if (obj.type == "model") {
            drawModelLit(obj.asset, obj.x, obj.y, obj.z, obj.scale, obj.rotY, "");
        }
    }
}

inline bool pickGround(double screenX, double screenY) {
    double ox, oy, oz, dx, dy, dz;
    Game3dContext& ctx = context();
    ctx.lastGroundHit = false;
    if (!rayFromScreen(screenX, screenY, ox, oy, oz, dx, dy, dz)) return false;
    if (std::abs(dy) < 1e-8) return false;
    const double t = -oy / dy;
    if (t < 0) return false;
    ctx.lastGroundX = ox + dx * t;
    ctx.lastGroundY = 0;
    ctx.lastGroundZ = oz + dz * t;
    ctx.lastGroundHit = true;
    return true;
}

inline double pickGroundX() {
    return context().lastGroundX;
}

inline double pickGroundY() {
    return context().lastGroundY;
}

inline double pickGroundZ() {
    return context().lastGroundZ;
}

inline bool pickGroundHit() {
    return context().lastGroundHit;
}
