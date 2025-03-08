
export EMSDKROOT=../libs/emsdk
export EMROOT=${EMSDKROOT}/upstream/emscripten

export EMBUILD=../build_em

source ${EMSDKROOT}/emsdk_env.sh
mkdir -p ${EMBUILD} && cd ${EMBUILD}
cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMROOT}/cmake/Modules/Platform/Emscripten.cmake
cmake --build . -j4