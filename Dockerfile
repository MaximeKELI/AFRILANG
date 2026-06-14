FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    cmake g++ build-essential git \
    libsdl2-dev libsdl2-ttf-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build -j$(nproc) && \
    ./build/afrilang_tests && \
    ./build/afrilang test .

CMD ["./build/afrilang", "repl"]
