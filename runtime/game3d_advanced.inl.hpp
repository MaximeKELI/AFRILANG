// Included inside namespace afrilang::runtime::game3d (from game3d.hpp)

inline double clampd(double v, double lo, double hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

inline void resolveBoxBox(RigidBody& a, RigidBody& b) {
    if (!a.isBox || !b.isBox) return;
    const double ax0 = a.px - a.hx, ax1 = a.px + a.hx;
    const double ay0 = a.py - a.hy, ay1 = a.py + a.hy;
    const double az0 = a.pz - a.hz, az1 = a.pz + a.hz;
    const double bx0 = b.px - b.hx, bx1 = b.px + b.hx;
    const double by0 = b.py - b.hy, by1 = b.py + b.hy;
    const double bz0 = b.pz - b.hz, bz1 = b.pz + b.hz;
    const double ox = std::min(ax1, bx1) - std::max(ax0, bx0);
    const double oy = std::min(ay1, by1) - std::max(ay0, by0);
    const double oz = std::min(az1, bz1) - std::max(az0, bz0);
    if (ox <= 0 || oy <= 0 || oz <= 0) return;

    double nx = 0, ny = 0, nz = 0, overlap = 0;
    if (ox <= oy && ox <= oz) {
        overlap = ox;
        nx = a.px < b.px ? -1.0 : 1.0;
    } else if (oy <= oz) {
        overlap = oy;
        ny = a.py < b.py ? -1.0 : 1.0;
    } else {
        overlap = oz;
        nz = a.pz < b.pz ? -1.0 : 1.0;
    }

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
    const double impulse = -(1.0 + e) * vn / 2.0;
    a.vx -= impulse * nx;
    a.vy -= impulse * ny;
    a.vz -= impulse * nz;
    b.vx += impulse * nx;
    b.vy += impulse * ny;
    b.vz += impulse * nz;
}

inline void resolveSphereBox(RigidBody& sphere, RigidBody& box) {
    if (sphere.isBox || !box.isBox) return;
    const double cx = clampd(sphere.px, box.px - box.hx, box.px + box.hx);
    const double cy = clampd(sphere.py, box.py - box.hy, box.py + box.hy);
    const double cz = clampd(sphere.pz, box.pz - box.hz, box.pz + box.hz);
    const double dx = sphere.px - cx;
    const double dy = sphere.py - cy;
    const double dz = sphere.pz - cz;
    const double distSq = dx * dx + dy * dy + dz * dz;
    const double r = sphere.radius;
    if (distSq >= r * r) return;
    double nx, ny, nz, overlap;
    if (distSq < 1e-8) {
        nx = 0;
        ny = 1;
        nz = 0;
        overlap = r;
    } else {
        const double dist = std::sqrt(distSq);
        nx = dx / dist;
        ny = dy / dist;
        nz = dz / dist;
        overlap = r - dist;
    }
    sphere.px += nx * overlap;
    sphere.py += ny * overlap;
    sphere.pz += nz * overlap;
    const double vn = sphere.vx * nx + sphere.vy * ny + sphere.vz * nz;
    if (vn < 0) {
        const double e = sphere.restitution;
        const double impulse = -(1.0 + e) * vn;
        sphere.vx += impulse * nx;
        sphere.vy += impulse * ny;
        sphere.vz += impulse * nz;
    }
}

inline int skyboxFaceIndex(const std::string& face) {
    if (face == "px" || face == "+x") return 0;
    if (face == "nx" || face == "-x") return 1;
    if (face == "py" || face == "+y") return 2;
    if (face == "ny" || face == "-y") return 3;
    if (face == "pz" || face == "+z") return 4;
    if (face == "nz" || face == "-z") return 5;
    return -1;
}

inline bool loadSkyboxFace(const std::string& face, const std::string& path) {
    const int idx = skyboxFaceIndex(face);
    if (idx < 0) return false;
    ensureImageLoader();
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) return false;

    GLuint texId = 0;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    const GLenum format = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0,
                 format, GL_UNSIGNED_BYTE, surface->pixels);
    SDL_FreeSurface(surface);

    SkyboxState& sky = context().skybox;
    if (sky.faces[idx]) glDeleteTextures(1, &sky.faces[idx]);
    sky.faces[idx] = texId;
    sky.loaded[idx] = true;
    return true;
}

inline bool hasSkybox() {
    const SkyboxState& sky = context().skybox;
    for (int i = 0; i < 6; ++i) {
        if (!sky.loaded[i]) return false;
    }
    return true;
}

inline void drawSkyboxFaceQuad(GLuint tex,
                               float x0, float y0, float z0,
                               float x1, float y1, float z1,
                               float x2, float y2, float z2,
                               float x3, float y3, float z3) {
    glBindTexture(GL_TEXTURE_2D, tex);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex3f(x0, y0, z0);
    glTexCoord2f(1, 1); glVertex3f(x1, y1, z1);
    glTexCoord2f(1, 0); glVertex3f(x2, y2, z2);
    glTexCoord2f(0, 0); glVertex3f(x3, y3, z3);
    glEnd();
}

inline void drawSkybox(double halfSize) {
    if (!hasSkybox()) return;
    Game3dContext& ctx = context();
    const float s = static_cast<float>(halfSize);
    const float cx = static_cast<float>(ctx.camX);
    const float cy = static_cast<float>(ctx.camY);
    const float cz = static_cast<float>(ctx.camZ);

    glPushAttrib(GL_ENABLE_BIT | GL_DEPTH_BUFFER_BIT | GL_CURRENT_BIT);
    glDepthMask(GL_FALSE);
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);

    glPushMatrix();
    glTranslatef(cx, cy, cz);

    drawSkyboxFaceQuad(ctx.skybox.faces[0], s, -s, -s, s, -s, s, s, s, s, s, s, -s);
    drawSkyboxFaceQuad(ctx.skybox.faces[1], -s, -s, s, -s, -s, -s, -s, s, -s, -s, s, s);
    drawSkyboxFaceQuad(ctx.skybox.faces[2], -s, s, -s, s, s, -s, s, s, s, -s, s, s);
    drawSkyboxFaceQuad(ctx.skybox.faces[3], -s, -s, s, s, -s, s, s, -s, s, -s, -s, s);
    drawSkyboxFaceQuad(ctx.skybox.faces[4], -s, -s, s, s, -s, s, s, s, s, -s, s, s);
    drawSkyboxFaceQuad(ctx.skybox.faces[5], s, -s, -s, -s, -s, -s, -s, s, -s, s, s, -s);

    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopAttrib();
}

inline std::string readTextFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) return "";
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

inline GLuint compileShaderStage(GLenum type, const std::string& source) {
    const char* src = source.c_str();
    const GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    GLint ok = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

inline bool loadShader(const std::string& name, const std::string& vertPath,
                       const std::string& fragPath) {
    const std::string vertSrc = readTextFile(vertPath);
    const std::string fragSrc = readTextFile(fragPath);
    if (vertSrc.empty() || fragSrc.empty()) return false;

    const GLuint vert = compileShaderStage(GL_VERTEX_SHADER, vertSrc);
    const GLuint frag = compileShaderStage(GL_FRAGMENT_SHADER, fragSrc);
    if (!vert || !frag) {
        if (vert) glDeleteShader(vert);
        if (frag) glDeleteShader(frag);
        return false;
    }

    const GLuint program = glCreateProgram();
    glAttachShader(program, vert);
    glAttachShader(program, frag);
    glBindAttribLocation(program, 0, "aPos");
    glBindAttribLocation(program, 1, "aNormal");
    glBindAttribLocation(program, 2, "aTex");
    glLinkProgram(program);
    glDeleteShader(vert);
    glDeleteShader(frag);

    GLint linked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        glDeleteProgram(program);
        return false;
    }

    Game3dContext& ctx = context();
    auto it = ctx.shaders.find(name);
    if (it != ctx.shaders.end() && it->second.program) {
        glDeleteProgram(it->second.program);
    }
    ctx.shaders[name] = ShaderInfo{program};
    return true;
}

inline bool hasShader(const std::string& name) {
    const auto it = context().shaders.find(name);
    return it != context().shaders.end() && it->second.program != 0;
}

inline void useShader(const std::string& name) {
    const auto it = context().shaders.find(name);
    if (it == context().shaders.end() || !it->second.program) return;
    glUseProgram(it->second.program);
}

inline void stopShader() {
    glUseProgram(0);
}

inline void setShaderFloat(const std::string& shaderName, const std::string& uniform,
                           double value) {
    const auto it = context().shaders.find(shaderName);
    if (it == context().shaders.end() || !it->second.program) return;
    const GLint loc = glGetUniformLocation(it->second.program, uniform.c_str());
    if (loc >= 0) glUniform1f(loc, static_cast<GLfloat>(value));
}

inline void setShaderVec3(const std::string& shaderName, const std::string& uniform,
                          double x, double y, double z) {
    const auto it = context().shaders.find(shaderName);
    if (it == context().shaders.end() || !it->second.program) return;
    const GLint loc = glGetUniformLocation(it->second.program, uniform.c_str());
    if (loc >= 0) {
        glUniform3f(loc, static_cast<GLfloat>(x), static_cast<GLfloat>(y),
                    static_cast<GLfloat>(z));
    }
}

inline void drawModelShader(const std::string& shaderName, const std::string& modelName,
                            double x, double y, double z, double scale, double rotY) {
    if (!hasShader(shaderName)) return;
    const auto it = context().models.find(modelName);
    if (it == context().models.end()) return;
    useShader(shaderName);
    glPushMatrix();
    glTranslatef(static_cast<GLfloat>(x), static_cast<GLfloat>(y), static_cast<GLfloat>(z));
    glRotatef(static_cast<GLfloat>(rotY), 0, 1, 0);
    glScalef(static_cast<GLfloat>(scale), static_cast<GLfloat>(scale),
             static_cast<GLfloat>(scale));
    glBegin(GL_TRIANGLES);
    for (const ObjVertex& v : it->second.triangles) {
        glNormal3f(v.nx, v.ny, v.nz);
        glTexCoord2f(v.u, v.v);
        glVertex3f(v.x, v.y, v.z);
    }
    glEnd();
    glPopMatrix();
    stopShader();
}

inline std::size_t jsonFindKey(const std::string& json, const std::string& key,
                               std::size_t from = 0) {
    const std::string needle = "\"" + key + "\"";
    return json.find(needle, from);
}

inline int jsonReadIntAfter(const std::string& json, std::size_t keyPos) {
    const std::size_t colon = json.find(':', keyPos);
    if (colon == std::string::npos) return -1;
    std::size_t i = colon + 1;
    while (i < json.size() && (json[i] == ' ' || json[i] == '\t' || json[i] == '\n')) ++i;
    bool neg = false;
    if (i < json.size() && json[i] == '-') {
        neg = true;
        ++i;
    }
    int value = 0;
    bool any = false;
    while (i < json.size() && json[i] >= '0' && json[i] <= '9') {
        value = value * 10 + (json[i] - '0');
        any = true;
        ++i;
    }
    return any ? (neg ? -value : value) : -1;
}

inline std::string jsonReadStringAfter(const std::string& json, std::size_t keyPos) {
    const std::size_t colon = json.find(':', keyPos);
    if (colon == std::string::npos) return "";
    const std::size_t q0 = json.find('"', colon + 1);
    if (q0 == std::string::npos) return "";
    const std::size_t q1 = json.find('"', q0 + 1);
    if (q1 == std::string::npos) return "";
    return json.substr(q0 + 1, q1 - q0 - 1);
}

inline std::string dirnameOf(const std::string& path) {
    const std::size_t slash = path.find_last_of("/\\");
    if (slash == std::string::npos) return "";
    return path.substr(0, slash + 1);
}

inline std::vector<std::uint8_t> loadGltfBuffer(const std::string& uri,
                                                const std::string& baseDir) {
    if (uri.rfind("data:", 0) == 0) {
        const std::size_t comma = uri.find(',');
        if (comma == std::string::npos) return {};
        const std::string encoded = uri.substr(comma + 1);
        const std::string raw = base64::decode(encoded);
        return std::vector<std::uint8_t>(raw.begin(), raw.end());
    }
    std::ifstream in(baseDir + uri, std::ios::binary);
    if (!in) return {};
    return std::vector<std::uint8_t>(std::istreambuf_iterator<char>(in), {});
}

inline int gltfComponentSize(int type) {
    switch (type) {
        case 5120: case 5121: return 1;
        case 5122: case 5123: return 2;
        case 5125: case 5126: return 4;
        default: return 0;
    }
}

inline int gltfTypeCount(const std::string& type) {
    if (type == "SCALAR") return 1;
    if (type == "VEC2") return 2;
    if (type == "VEC3") return 3;
    if (type == "VEC4") return 4;
    return 0;
}

inline bool readGlbFile(const std::string& path, std::string& jsonOut,
                        std::vector<std::uint8_t>& binOut) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;
    std::uint32_t magic = 0, version = 0, length = 0;
    in.read(reinterpret_cast<char*>(&magic), 4);
    in.read(reinterpret_cast<char*>(&version), 4);
    in.read(reinterpret_cast<char*>(&length), 4);
    if (magic != 0x46546C67 || version != 2) return false;
    while (in && static_cast<std::uint32_t>(in.tellg()) < length) {
        std::uint32_t chunkLen = 0, chunkType = 0;
        in.read(reinterpret_cast<char*>(&chunkLen), 4);
        in.read(reinterpret_cast<char*>(&chunkType), 4);
        if (chunkType == 0x4E4F534A) {
            std::vector<char> buf(chunkLen);
            in.read(buf.data(), static_cast<std::streamsize>(chunkLen));
            jsonOut.assign(buf.begin(), buf.end());
        } else if (chunkType == 0x004E4942) {
            binOut.resize(chunkLen);
            in.read(reinterpret_cast<char*>(binOut.data()),
                    static_cast<std::streamsize>(chunkLen));
        } else {
            in.seekg(chunkLen, std::ios::cur);
        }
    }
    return !jsonOut.empty();
}

inline bool loadGltfFromJson(const std::string& name, const std::string& json,
                             const std::vector<std::uint8_t>& embeddedBin,
                             const std::string& baseDir) {
    if (json.empty()) return false;

    auto loadBuffer = [&](int bufferIndex) -> std::vector<std::uint8_t> {
        if (bufferIndex == 0 && !embeddedBin.empty()) return embeddedBin;
        const std::size_t bufKey = jsonFindKey(json, "buffers");
        if (bufKey == std::string::npos) return {};
        std::size_t search = bufKey;
        int idx = 0;
        while (idx <= bufferIndex) {
            const std::size_t item = json.find('{', search);
            if (item == std::string::npos) return {};
            if (idx == bufferIndex) {
                const std::size_t uriKey = jsonFindKey(json, "uri", item);
                if (uriKey == std::string::npos) return embeddedBin;
                const std::string uri = jsonReadStringAfter(json, uriKey);
                return loadGltfBuffer(uri, baseDir);
            }
            ++idx;
            search = item + 1;
        }
        return {};
    };

    const std::vector<std::uint8_t> buffer = loadBuffer(0);
    if (buffer.empty()) return false;

    auto readAccessor = [&](int accessorIndex, int& bufferView, int& byteOffset,
                            int& componentType, int& count, std::string& type) -> bool {
        const std::size_t accKey = jsonFindKey(json, "accessors");
        if (accKey == std::string::npos) return false;
        std::size_t search = accKey;
        int idx = 0;
        while (idx <= accessorIndex) {
            const std::size_t item = json.find('{', search);
            if (item == std::string::npos) return false;
            if (idx == accessorIndex) {
                bufferView = jsonReadIntAfter(json, jsonFindKey(json, "bufferView", item));
                byteOffset = jsonReadIntAfter(json, jsonFindKey(json, "byteOffset", item));
                componentType = jsonReadIntAfter(json, jsonFindKey(json, "componentType", item));
                count = jsonReadIntAfter(json, jsonFindKey(json, "count", item));
                type = jsonReadStringAfter(json, jsonFindKey(json, "type", item));
                return true;
            }
            ++idx;
            search = item + 1;
        }
        return false;
    };

    auto readBufferView = [&](int viewIndex, int& byteOffset, int& byteLength) -> bool {
        const std::size_t bvKey = jsonFindKey(json, "bufferViews");
        if (bvKey == std::string::npos) return false;
        std::size_t search = bvKey;
        int idx = 0;
        while (idx <= viewIndex) {
            const std::size_t item = json.find('{', search);
            if (item == std::string::npos) return false;
            if (idx == viewIndex) {
                byteOffset = jsonReadIntAfter(json, jsonFindKey(json, "byteOffset", item));
                byteLength = jsonReadIntAfter(json, jsonFindKey(json, "byteLength", item));
                return true;
            }
            ++idx;
            search = item + 1;
        }
        return false;
    };

    auto readAccessorFloats = [&](int accessorIndex, std::vector<float>& out) -> bool {
        int bufferView = 0, byteOffset = 0, componentType = 0, count = 0;
        std::string type;
        if (!readAccessor(accessorIndex, bufferView, byteOffset, componentType, count, type)) {
            return false;
        }
        int viewOffset = 0, viewLength = 0;
        if (!readBufferView(bufferView, viewOffset, viewLength)) return false;
        const int compSize = gltfComponentSize(componentType);
        const int typeCount = gltfTypeCount(type);
        if (compSize != 4 || typeCount <= 0 || count <= 0) return false;
        const std::size_t start = static_cast<std::size_t>(viewOffset + byteOffset);
        const std::size_t bytesNeeded = static_cast<std::size_t>(count * typeCount * compSize);
        if (start + bytesNeeded > buffer.size()) return false;
        const float* floats = reinterpret_cast<const float*>(buffer.data() + start);
        out.assign(floats, floats + count * typeCount);
        return true;
    };

    const std::size_t meshKey = jsonFindKey(json, "meshes");
    const std::size_t posKey = meshKey == std::string::npos ? std::string::npos
                                                             : jsonFindKey(json, "POSITION", meshKey);
    const int posAccessor = posKey == std::string::npos ? 0 : jsonReadIntAfter(json, posKey);

    int accBufferView = 0, accByteOffset = 0, accComponentType = 0, accCount = 0;
    std::string accType;
    if (!readAccessor(posAccessor, accBufferView, accByteOffset, accComponentType, accCount, accType)) {
        return false;
    }
    int byteOffset = 0, byteLength = 0;
    if (!readBufferView(accBufferView, byteOffset, byteLength)) return false;
    if (accComponentType != 5126 || gltfTypeCount(accType) != 3 || accCount <= 0) return false;

    const std::size_t start = static_cast<std::size_t>(byteOffset + accByteOffset);
    const std::size_t bytesNeeded = static_cast<std::size_t>(accCount * 3 * 4);
    if (start + bytesNeeded > buffer.size()) return false;

    ObjModel model;
    const float* floats = reinterpret_cast<const float*>(buffer.data() + start);
    std::vector<ObjVertex> vertices(static_cast<std::size_t>(accCount));
    for (int i = 0; i < accCount; ++i) {
        vertices[static_cast<std::size_t>(i)].x = floats[i * 3 + 0];
        vertices[static_cast<std::size_t>(i)].y = floats[i * 3 + 1];
        vertices[static_cast<std::size_t>(i)].z = floats[i * 3 + 2];
    }

    int idxAccessor = -1;
    if (meshKey != std::string::npos) {
        const std::size_t idxKey = jsonFindKey(json, "indices", meshKey);
        if (idxKey != std::string::npos) idxAccessor = jsonReadIntAfter(json, idxKey);
    }

    if (idxAccessor >= 0) {
        int iBufferView = 0, iByteOffset = 0, iComponentType = 0, iCount = 0;
        std::string iType;
        if (readAccessor(idxAccessor, iBufferView, iByteOffset, iComponentType, iCount, iType)) {
            int iByteOffsetView = 0, iByteLength = 0;
            if (readBufferView(iBufferView, iByteOffsetView, iByteLength)) {
                const std::size_t iStart = static_cast<std::size_t>(iByteOffsetView + iByteOffset);
                if (iComponentType == 5123) {
                    const std::uint16_t* idx = reinterpret_cast<const std::uint16_t*>(buffer.data() + iStart);
                    for (int t = 0; t + 2 < iCount; t += 3) {
                        model.triangles.push_back(vertices[idx[t + 0]]);
                        model.triangles.push_back(vertices[idx[t + 1]]);
                        model.triangles.push_back(vertices[idx[t + 2]]);
                    }
                } else if (iComponentType == 5125) {
                    const std::uint32_t* idx = reinterpret_cast<const std::uint32_t*>(buffer.data() + iStart);
                    for (int t = 0; t + 2 < iCount; t += 3) {
                        model.triangles.push_back(vertices[idx[t + 0]]);
                        model.triangles.push_back(vertices[idx[t + 1]]);
                        model.triangles.push_back(vertices[idx[t + 2]]);
                    }
                }
            }
        }
    } else {
        for (const ObjVertex& v : vertices) model.triangles.push_back(v);
    }

    if (model.triangles.empty()) return false;
    for (std::size_t i = 0; i + 2 < model.triangles.size(); i += 3) {
        computeTriangleNormal(model.triangles[i], model.triangles[i + 1], model.triangles[i + 2]);
    }

    const std::size_t animKey = jsonFindKey(json, "animations");
    if (animKey != std::string::npos) {
        const std::size_t sampKey = jsonFindKey(json, "samplers", animKey);
        const std::size_t chanKey = jsonFindKey(json, "channels", animKey);
        if (sampKey != std::string::npos && chanKey != std::string::npos) {
            const int inputAcc = jsonReadIntAfter(json, jsonFindKey(json, "input", sampKey));
            const int outputAcc = jsonReadIntAfter(json, jsonFindKey(json, "output", sampKey));
            const std::string path = jsonReadStringAfter(json, jsonFindKey(json, "path", chanKey));
            if (path == "rotation" && inputAcc >= 0 && outputAcc >= 0) {
                std::vector<float> times;
                std::vector<float> values;
                if (readAccessorFloats(inputAcc, times) && readAccessorFloats(outputAcc, values)) {
                    std::vector<float> rotY;
                    for (std::size_t i = 0; i + 3 < values.size(); i += 4) {
                        const float qx = values[i];
                        const float qy = values[i + 1];
                        const float qz = values[i + 2];
                        const float qw = values[i + 3];
                        const double siny = 2.0 * (qw * qy + qz * qx);
                        const double cosy = 1.0 - 2.0 * (qx * qx + qy * qy);
                        rotY.push_back(static_cast<float>(std::atan2(siny, cosy) * 180.0 / 3.141592653589793));
                    }
                    if (!times.empty() && times.size() == rotY.size()) {
                        model.animTimes.push_back(std::move(times));
                        model.animRotY.push_back(std::move(rotY));
                    }
                }
            }
        }
    }

    context().models[name] = std::move(model);
    return true;
}

inline bool loadGltf(const std::string& name, const std::string& path) {
    if (path.size() >= 4 && path.compare(path.size() - 4, 4, ".glb") == 0) {
        std::string json;
        std::vector<std::uint8_t> bin;
        if (!readGlbFile(path, json, bin)) return false;
        return loadGltfFromJson(name, json, bin, dirnameOf(path));
    }
    const std::string json = readTextFile(path);
    if (json.empty()) return false;
    const std::string baseDir = dirnameOf(path);
    const std::size_t bufKey = jsonFindKey(json, "buffers");
    if (bufKey == std::string::npos) return false;
    const std::string bufferUri = jsonReadStringAfter(json, jsonFindKey(json, "uri", bufKey));
    const std::vector<std::uint8_t> buffer = loadGltfBuffer(bufferUri, baseDir);
    return loadGltfFromJson(name, json, buffer, baseDir);
}

inline bool loadGlb(const std::string& name, const std::string& path) {
    return loadGltf(name, path);
}

inline double gltfAnimCount(const std::string& modelName) {
    const auto it = context().models.find(modelName);
    if (it == context().models.end()) return 0;
    return static_cast<double>(it->second.animTimes.size());
}

inline void playGltfAnim(const std::string& modelName, double animIndex, bool loop) {
    ModelAnimPlayback pb;
    pb.animIndex = static_cast<int>(animIndex);
    pb.timeSec = 0;
    pb.playing = true;
    pb.loop = loop;
    context().modelAnims[modelName] = pb;
}

inline void stopGltfAnim(const std::string& modelName) {
    auto it = context().modelAnims.find(modelName);
    if (it == context().modelAnims.end()) return;
    it->second.playing = false;
}

inline float sampleAnimRotY(const ObjModel& model, int animIndex, double timeSec) {
    if (animIndex < 0 || animIndex >= static_cast<int>(model.animTimes.size())) return 0;
    const std::vector<float>& times = model.animTimes[static_cast<std::size_t>(animIndex)];
    const std::vector<float>& rots = model.animRotY[static_cast<std::size_t>(animIndex)];
    if (times.empty()) return 0;
    if (timeSec <= static_cast<double>(times.front())) return rots.front();
    if (timeSec >= static_cast<double>(times.back())) return rots.back();
    for (std::size_t i = 1; i < times.size(); ++i) {
        if (timeSec <= static_cast<double>(times[i])) {
            const double t0 = times[i - 1];
            const double t1 = times[i];
            const double u = (timeSec - t0) / (t1 - t0);
            return static_cast<float>(rots[i - 1] + (rots[i] - rots[i - 1]) * u);
        }
    }
    return rots.back();
}

inline void updateGltfAnims(double deltaMs) {
    const double dt = deltaMs / 1000.0;
    Game3dContext& ctx = context();
    for (auto& [modelName, pb] : ctx.modelAnims) {
        if (!pb.playing) continue;
        const auto it = ctx.models.find(modelName);
        if (it == ctx.models.end()) continue;
        if (pb.animIndex < 0 ||
            pb.animIndex >= static_cast<int>(it->second.animTimes.size())) continue;
        const std::vector<float>& times = it->second.animTimes[static_cast<std::size_t>(pb.animIndex)];
        if (times.empty()) continue;
        pb.timeSec += dt;
        const double end = times.back();
        if (pb.timeSec > end) {
            if (pb.loop) pb.timeSec = std::fmod(pb.timeSec, end);
            else {
                pb.timeSec = end;
                pb.playing = false;
            }
        }
    }
}

inline double gltfAnimRotY(const std::string& modelName) {
    Game3dContext& ctx = context();
    const auto pbIt = ctx.modelAnims.find(modelName);
    if (pbIt == ctx.modelAnims.end() || !pbIt->second.playing) return 0;
    const auto modelIt = ctx.models.find(modelName);
    if (modelIt == ctx.models.end()) return 0;
    return static_cast<double>(sampleAnimRotY(modelIt->second, pbIt->second.animIndex, pbIt->second.timeSec));
}

inline bool hasGltf(const std::string& name) {
    return context().models.count(name) > 0;
}

inline bool rayAabbHit(double ox, double oy, double oz,
                       double dx, double dy, double dz,
                       double cx, double cy, double cz,
                       double hx, double hy, double hz,
                       double& tHit) {
    const double invX = std::abs(dx) < 1e-9 ? 1e9 : 1.0 / dx;
    const double invY = std::abs(dy) < 1e-9 ? 1e9 : 1.0 / dy;
    const double invZ = std::abs(dz) < 1e-9 ? 1e9 : 1.0 / dz;
    double t0 = (cx - hx - ox) * invX;
    double t1 = (cx + hx - ox) * invX;
    if (t0 > t1) std::swap(t0, t1);
    double ty0 = (cy - hy - oy) * invY;
    double ty1 = (cy + hy - oy) * invY;
    if (ty0 > ty1) std::swap(ty0, ty1);
    if (t0 > ty1 || ty0 > t1) return false;
    if (ty0 > t0) t0 = ty0;
    if (ty1 < t1) t1 = ty1;
    double tz0 = (cz - hz - oz) * invZ;
    double tz1 = (cz + hz - oz) * invZ;
    if (tz0 > tz1) std::swap(tz0, tz1);
    if (t0 > tz1 || tz0 > t1) return false;
    if (tz0 > t0) t0 = tz0;
    if (tz1 < t1) t1 = tz1;
    tHit = t0 > 0 ? t0 : t1;
    return tHit > 0;
}
