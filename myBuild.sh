git submodule update --init --recursive

cmake -DGLFW_BUILD_DOCS=OFF -S . -B ./build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release

cmake --build build